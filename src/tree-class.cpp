// [[Rcpp::depends(BH)]]
#include <Rcpp.h>
#include <boost>
#include <random>
#include <array>
using namespace Rcpp;
using boost::uuids;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//
typedef std::vector<double> double_vec;
// TODO: This needs to be passed in once implemented in Cell
static const std::array<double,4> spectrum = {.25,.25,.25,.25};


class Mutation{
  private:
    std::default_random_engine generator;
    std::discrete_distribution<int> distribution(spectrum.begin(),spectrum.end());

  public:
    int muttype;
    boost::uuids::uuid mid;
    Mutation(): mid(boost::uuids::random_generator()()){
    // TODO: Pass in spectrum in a way that makes the distribution work
      muttype = generator(dist);
    };


};


typedef std::vector<Mutation> mut_vec;

class Cell {
  public:
    Cell(int size_, int mutrate_, double reprate_, mut_vec mutations_):
    size(size_), mutrate(mutrate_), reprate(reprate_), mutations(mutations_){};

  private:
}
