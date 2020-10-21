#ifndef __SINGLETREEANALYSIS_HPP__
#define __SINGLETREEANALYSIS_HPP__

#include "Analysis.hpp"
#include "phylokit/Clade.hpp"

class SingleTreeAnalysis : public Analysis {
public:
  virtual std::string analyze(TaxonSet& ts, std::vector<Clade>& clades, TripartitionScorer& tps);
  std::stringstream toTree(TaxonSet& ts, clade_bitset& bs, std::vector<Clade>& clades, TripartitionScorer& tps);
};

#endif
