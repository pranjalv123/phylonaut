#ifndef PHYLONAUT_CONFIG_HPP__
#define PHYLONAUT_CONFIG_HPP__

#include <vector>
#include <string>

class wASTRAL_;
class Analysis;
class CladeExtractor;
class TaxonSetExtractor;
class TripartitionScorer;

struct Config {

  TripartitionScorer*  scorer;
  TaxonSetExtractor* taxon_extractor;

  std::vector<CladeExtractor*> extractors;  
  
  std::vector<Analysis*>    analyses;
  
  bool matrix;      //save the entire |X|^2 matrix
  
  std::string profile;     

  template<class InputIterator>
  void add_clades(InputIterator first, InputIterator last);
  std::vector<Clade>& get_clades();

  wASTRAL_* wASTRAL;
};

#endif