#include "DefaultTaxonSetExtractor.hpp"
#include <unordered_set>
#include <string>
#include <fstream>
#include "phylokit/Clade.hpp"
#include "phylokit/newick.hpp"
#include <glog/logging.h>

/* virtual */ TaxonSet& DefaultTaxonSetExtractor::extract()  {
    unordered_set<string> taxa;
    ifstream in(treefile);

    string s;
    int i = 0;
    while(!in.eof()) {
      // /* DEBUG */ LOG(INFO) << "Tree " << i << endl;
      getline(in, s);
      if (s.size() == 0)
	continue;
      newick_to_ts(s, taxa);
      // /* DEBUG */ LOG(INFO) << taxa.size() << endl;
      i++;
    }

    ts = new TaxonSet(taxa.size());

    for (const string& s : taxa) {
      ts->add(s);
      // /* DEBUG */ LOG(INFO) << s << endl;
    }
    
    return *ts;
}