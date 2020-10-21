#ifndef DEFAULT_TAXON_SET_EXTRACTOR__
#define DEFAULT_TAXON_SET_EXTRACTOR__

#include <vector>
#include "CladeExtractor.hpp"

using namespace std;

class DefaultTaxonSetExtractor : public TaxonSetExtractor {
public:
  string treefile;
  TaxonSet* ts;
  DefaultTaxonSetExtractor(const string& treefile) : treefile (treefile) {
  }
  virtual TaxonSet& extract();
  
  
};
#endif
