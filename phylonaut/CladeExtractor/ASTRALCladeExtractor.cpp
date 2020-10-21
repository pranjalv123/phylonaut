#include "ASTRALCladeExtractor.hpp"

#include <glog/logging.h>
#include "phylokit/newick.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

#ifdef _WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif

#include "whereami++.hpp"

using std::endl;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::istream;
using std::unordered_set;

string findAstralJar() {
  string edir = whereami::executable_dir();
  LOG(INFO) << "Looking for ASTRAL in " << edir << "/Astral/" << endl;
  DIR* d = opendir((edir + string("/Astral")).c_str());
  if (d == NULL)
    LOG(ERROR) << "Directory " << edir + string("/Astral") << " could not be accessed" << endl;
    LOG(INFO) << strerror(errno) << endl;
  dirent* entry;
  while(d && (entry = readdir(d))) {
    string fname = entry->d_name;
    // /* DEBUG */ LOG(INFO) << "testing " << fname << endl;
    if (fname.substr(0, 7) == "astral." && fname.substr(fname.size() - 4) == ".jar") {
      // /* DEBUG */ LOG(INFO) << "Found" << endl;
      return edir + string("/Astral/") + fname;
    }
  }
  // /* DEBUG */ LOG(INFO) << "Couldn't find ASTRAL jar" << endl;
  return "";
}

#if (_WIN32)

#include <io.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#define mkstemp _mktemp
#define popen _popen
#endif
string remapped_treefile(istream& input, TaxonSet& ts) {
  string line;
  //  ifstream ifile(input);
#if _WIN32
  char name[] = "fileXXXXXX";
#else
  char name[] = "/tmp/fileXXXXXX";
#endif

  mkstemp(name);

  ofstream of(name);
  while(!input.eof()) {
    getline(input, line);
    if (line.size())
      of << map_newick_names(line, ts) << endl;
  }

  return name;
}


unordered_set<Clade> ASTRALCladeExtractor::extract(TaxonSet& ts) {
  stringstream clade_stream;
#ifdef _WIN32
  string s = "java -jar " + astralpath + " -i " + remapped_treefile(gtfile, ts) + " -k searchspace_norun -o NUL";
#else
  string s = "java -jar " + astralpath + " -i " + remapped_treefile(gtfile, ts) + " -k searchspace_norun -o /dev/null";
#endif
  if (exact)
    s += " -x ";
  if (limited)
    s += " -p0 ";
  if (extragtfile.good())
    s += " -e " + remapped_treefile(extragtfile, ts);
  // if (!Logger::isEnabled("DEBUG") )
  //   s += " 2> /dev/null";


  // /* DEBUG */ LOG(INFO) << s << endl;

  char buffer[128];

  FILE* stream = popen(s.c_str(), "r");

  stringstream result;
  while(!feof(stream)) {
    if(fgets(buffer,128,stream) != NULL) {
      result << buffer;
    }
  }


  stringstream cladestream_mapped(result.str());
  string line;

  stringstream unmapped;

  unordered_set<Clade> clades;

  while (!cladestream_mapped.eof()) {
    getline(cladestream_mapped, line);
    // /* DEBUG */ LOG(INFO) << line << endl;
    if (line[0] != '{') {
      continue;
    }
    string clade_s = unmap_clade_names(line, ts);
	// /* DEBUG */ LOG(INFO) << clade_s << endl;
	if (clade_s.size())
		clades.insert(Clade(ts, clade_s));
  }



  return clades;
}
