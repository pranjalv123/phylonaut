#ifndef __CONSENSUSTREEANALYSIS_HPP__
#define __CONSENSUSTREEANALYSIS_HPP__

#include "Analysis.hpp"

class ConsensusTreeAnalysis : public Analysis {
  double level;
public:
  ConsensusTreeAnalysis(double level_) : level(level_) {}
  virtual std::string analyze(TaxonSet& ts, std::vector<Clade>& clades, TripartitionScorer& tps);
  virtual bool   requireAllBest() { return true; };
  std::vector<Clade> compatible_clades(std::vector<Clade>& clades);
  std::vector<Clade> children(Clade& c, std::vector<Clade>& clades);
};

#endif
