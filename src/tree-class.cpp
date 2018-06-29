// [[Rcpp::depends(BH)]]
#include <Rcpp.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
using namespace Rcpp;

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
typedef std::vecotr<Mutation> mut_vec;


Class Mutation{
public:
  int muttype;
  boost::uuids::uuid mid;
  Mutation(): mid(boost::uuids::random_generator()()){
    // TODO: Pass in spectrum in a way that makes the distribution work
    muttype = generator(distribution)
  }

private:
  std::default_random_engine generator;
  std::discrete_distribution distribution {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
}

Class Cell {
public:
  Cell(int size_, int mutrate_, double reprate_, mut_vec mutations_):
  size(size_), mutrate(mutrate_), reprate(reprate_), mutations(mutations_){

  }
}
