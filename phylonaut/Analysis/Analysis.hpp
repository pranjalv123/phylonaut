#ifndef ANALYSIS_HPP__
#define ANALYSIS_HPP__

#include <vector>
#include "phylokit/TaxonSet.hpp"
#include "phylokit/Clade.hpp"

class TripartitionScorer;

class Analysis {
protected: 
public:  
  
  virtual std::string analyze(TaxonSet& ts, std::vector<Clade>& clades, TripartitionScorer& tps) = 0;

  
  virtual bool   requireMatrix() { return false; };
  virtual bool   requireAllBest() { return false; };
};

#endif
