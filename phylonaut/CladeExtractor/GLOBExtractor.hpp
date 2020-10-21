#ifndef GLOB_CLADE_EXTRACTOR__
#define GLOB_CLADE_EXTRACTOR__

#include "CladeExtractor.hpp"
#include <unordered_set>
#include <fstream>
#include "phylokit/Clade.hpp"

class GLOBExtractor : public CladeExtractor{
private:
  std::istream& gtfile;

public:

  GLOBExtractor(std::ifstream& gtfile) :
  gtfile(gtfile)
  {  }

  GLOBExtractor(std::string gtfile) :
  gtfile(*(new std::ifstream(gtfile)))
  {  }


  virtual std::unordered_set<Clade> extract(TaxonSet& ts);

};

#endif
