#include "phylokit/Clade.hpp"
#include "phylokit/Quartet.hpp"
#include "CladeExtractor/CladeExtractor.hpp"
#include "TripartitionScorer/TripartitionScorer.hpp"
#include "Analysis/Analysis.hpp"

#include <glog/logging.h>
#include "phylokit/util/Timer.hpp"
#include "wASTRAL.hpp"

#include <fstream>
#include <iostream>
#include <cmath>

#ifdef ENABLE_PROFILING
#include <gperftools/profiler.h>
#endif

vector<Clade>& Config::get_clades() { return wASTRAL->get_clades(); }


void wASTRAL_::uniqify_clades() {
  unordered_set<Clade> s;
  for (const Clade& c : clades) {
    s.insert(c);
  }
  clades.clear();
  for (const Clade& c : s) {
    clades.push_back(c);
  }
    
}

vector<string> wASTRAL(Config& conf) {
  wASTRAL_ w;
  return w.run(conf);  
}

vector<string> wASTRAL_::run(Config& conf) {
  conf.wASTRAL=this;
  if (conf.profile.size()) {
#ifdef ENABLE_PROFILING 
    ProfilerStart(conf.profile.c_str());
#else
    LOG(FATAL) << "wASTRAL must be compiled with ENABLE_PROFILING=ON for profiling to work!" << endl;
    return vector<string>(0);
#endif
  }
  
  //This also initializes the clades and gets them from whatever source is specified
  //This could be gene trees with ASTRAL or clades that are explicitly given

  LOG(INFO) << "Getting constraint set" << endl;
  Timer::start("GetConstraintSet");
  
  TaxonSet& ts = conf.taxon_extractor->extract();
  ts.freeze();

  for (auto extractor : conf.extractors) {
    unordered_set<Clade> thisclades = extractor->extract(ts);
    for (const Clade& c : thisclades) {
      clades.push_back(c);
    }
  }  

  clades.emplace_back(ts, ts.taxa_bs);
  
  uniqify_clades();
  
  sort(clades.begin(), clades.end(), [](const Clade& a, const Clade& b){ return a.size() < b.size(); });
  
  Timer::stop("GetConstraintSet");
  LOG(INFO) << "Got constraint set with " << clades.size() << " clades" << endl;

  LOG(INFO) << "Starting preprocessing phase" << endl;
  Timer::start("Preprocessing");  
  conf.scorer->set_ts(ts);
  conf.scorer->init(conf);
  Timer::stop("Preprocessing");  
  LOG(INFO) << "Preprocessing phase complete" << endl;
  
  LOG(INFO) << "Computing " << clades.size() << " tripartition scores" << endl;
  Timer::start("MainLoop");
  for (Clade& c : clades) {
    conf.scorer->get_score(c);
  }
  Timer::stop("MainLoop");  
  LOG(INFO) << "Done" << endl;  
  vector<string> results;
  
  LOG(INFO) << "Finding trees" << endl;
  Timer::start("Analysis");    
  for (Analysis* analysis : conf.analyses) {
    results.push_back(analysis->analyze(ts, clades, *(conf.scorer)));
  }
  Timer::stop("Analysis");      
  LOG(INFO) << "Done" << endl;  
  return results;
}
