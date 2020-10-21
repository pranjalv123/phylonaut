#ifndef __COUNTTREESANALYSIS_HPP__
#define __COUNTTREESANALYSIS_HPP__

#include "Analysis.hpp"

#ifdef __linux__
typedef __float128 count_type;
#else
typedef long double count_type;
#endif

class CountTreesAnalysis : public Analysis {
public:
  std::unordered_map<clade_bitset, count_type> run(TaxonSet& ts, std::vector<Clade>& clades, TripartitionScorer& tps);
  virtual std::string analyze(TaxonSet& ts, std::vector<Clade>& clades, TripartitionScorer& tps);
  virtual bool requireAllBest() { return true; };
};

#endif
