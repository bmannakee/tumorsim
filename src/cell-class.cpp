
#include <Rcpp.h>
#include <boost/random.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <random>
#include <array>
// [[Rcpp::depends(BH)]]
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
typedef std::vector<double> double_vec ;
typedef std::array<double,96> spec_vec ;
// TODO: This needs to be passed in once implemented in Cell

boost::uuids::random_generator uuidgen;
boost::mt19937 generator(2333) ;
class Mutation{
  std::array<double,96> spectrum ;
public:
  int muttype ;
  boost::uuids::uuid mid;

  // Constructor - requires a spectrum
  Mutation(spec_vec spectrum_): spectrum(spectrum_) {
    boost::random::discrete_distribution<int> distribution (spectrum.begin(),spectrum.end()) ;
    int muttype = distribution(generator) ;
    mid = uuidgen();
  }

  const boost::uuids::uuid get_mutation_id() { return mid ; }
  const int get_muttype() { return muttype ; }


};

typedef std::vector<Mutation> mut_vec ;


class Cell {
    const int mutrate ;
    const double bdratio ;
    const mut_vec mutations ;
    const spec_vec spectrum ;
  public:
    Cell(int mutrate_, double bdratio_, mut_vec mutations_, spec_vec spectrum_):
    mutrate(mutrate_), bdratio(bdratio_), mutations(mutations_), spectrum(spectrum_){}

    int get_mutrate() const { return mutrate ; }
    double get_bdratio() const {return bdratio ; }
    mut_vec get_mutations() const { return mutations ; }
    spec_vec get_spectrum() const { return spectrum ; }
} ;

typedef std::vector<Cell> cell_vec ;
std::random_device device ;
std::mt19937 gen(device()) ;

// Cell replication
const cell_vec replicate(const Cell cell) {
  cell_vec out_cells ;

  mut_vec mutations = cell.get_mutations() ;
  int mutrate = cell.get_mutrate() ;
  double bdratio = cell.get_bdratio() ;
  spec_vec spectrum = cell.get_spectrum ;

  double repprob = bdratio/(1 - bdratio) ; // if b/d = .72, p = .58
  std::bernoulli_distribution flip(repprob) ;
  bool rep = flip(gen) ;

  if (rep) {
    mut_vec mutations1, mutations2;
    for ( int i = 1; i < mutrate; i++) {
      mutations1.append(new Mutation(spectrum)) ;
      mutations2.append(new Mutation(spectrum)) ;
    }
    Cell new1 = Cell(mutrate, bdratio, mutations1) ;
    Cell new2 = Cell(mutrate, bdration, mutations2) ;
  }
} ;

