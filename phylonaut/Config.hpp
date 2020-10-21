#ifndef PHYLONAUT_CONFIG_HPP__
#define PHYLONAUT_CONFIG_HPP__

class wASTRAL_;
class Analysis;
class CladeExtractor;
class TaxonSetExtractor;
class TripartitionScorer;

struct Config {

  TripartitionScorer*  scorer;
  TaxonSetExtractor* taxon_extractor;

  vector<CladeExtractor*> extractors;  
  
  vector<Analysis*>    analyses;
  
  bool matrix;      //save the entire |X|^2 matrix
  
  string profile;     

  template<class InputIterator>
  void add_clades(InputIterator first, InputIterator last);
  vector<Clade>& get_clades();

  wASTRAL_* wASTRAL;
};

#endif