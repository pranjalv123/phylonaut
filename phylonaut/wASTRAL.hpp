#ifndef WASTRAL_HPP__
#define WASTRAL_HPP__

#include <vector>
#include <string>
#include "phylokit/Clade.hpp"
#include "Config.hpp"

class wASTRAL_ ;

std::vector<std::string> wASTRAL(Config& conf);

class wASTRAL_ {
public:
  std::vector<std::string> run(Config& conf);  
  void uniqify_clades();  
  template<class InputIterator>
  void add_clades(InputIterator first, InputIterator last) {
    while (first !=last) {
      clades.push_back(*first);
      first++;
    }

    uniqify_clades();
    sort(clades.begin(), clades.end(), [](const Clade& a, const Clade& b){ return a.size() < b.size(); });

    

  }
  std::vector<Clade>& get_clades() { return clades; }

private:
  std::vector<Clade> clades;

    
};

template<class InputIterator>
void Config::add_clades(InputIterator first, InputIterator last)
{
  wASTRAL->add_clades(first, last);
}
#endif
