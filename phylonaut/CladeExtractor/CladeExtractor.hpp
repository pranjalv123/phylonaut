#ifndef CLADE_EXTRACTOR__
#define CLADE_EXTRACTOR__
#include <vector>
#include <string>
#include "phylokit/Clade.hpp"


class TaxonSetExtractor {
public:
  virtual TaxonSet& extract() = 0;  
};

class CladeExtractor {
public:
  virtual std::unordered_set<Clade> extract(TaxonSet& ts) = 0;  
};



#endif
