#ifndef ASTRAL_CLADE_EXTRACTOR__
#define ASTRAL_CLADE_EXTRACTOR__

#include "CladeExtractor.hpp"
#include <unordered_set>
#include "phylokit/Clade.hpp"
#include <fstream>

std::string findAstralJar();

class ASTRALCladeExtractor : public CladeExtractor {
public:
  ASTRALCladeExtractor(std::string astralpath, std::string gtfile, std::string extragtfile, bool exact=false, bool limited=false) :
    astralpath(astralpath),
    gtfile(*(new std::ifstream(gtfile))),
    extragtfile(*(new std::ifstream(extragtfile))),
    exact(exact),
    limited(limited)
  {}

  ASTRALCladeExtractor(std::string astralpath, std::istream& gtfile, bool exact=false, bool limited=false) :
    astralpath(astralpath),
    gtfile(gtfile),
    extragtfile(*(new std::ifstream(""))),
    exact(exact),
    limited(limited){}

  ASTRALCladeExtractor(std::string gtfile, std::string extragtfile="", bool exact=false, bool limited=false) :
    astralpath(findAstralJar()),
    gtfile(*(new std::ifstream(gtfile))),
    extragtfile(*(new std::ifstream(extragtfile))),
    exact(exact),
    limited(limited)  {}

  ASTRALCladeExtractor(std::istream& gtfile, bool exact=false, bool limited=false) :
    astralpath(findAstralJar()),
    gtfile(gtfile),
    extragtfile(*(new std::ifstream(""))),
    exact(exact),
    limited(limited){}


  virtual std::unordered_set<Clade> extract(TaxonSet& ts);

private:
  std::string astralpath;
  std::istream& gtfile;
  std::istream& extragtfile;
  bool exact;
  bool limited;
};


#endif
