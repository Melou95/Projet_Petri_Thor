#ifndef Bacterie_H_
#define Bacterie_H_

// =============================================================================
//                               Includes
// =============================================================================
#include <vector>
using namespace std;

class Bacterie {
  public :
  // ===========================================================================
  //                              Constructors
  // ===========================================================================
  Bacterie();
  
  // ===========================================================================
  //                               Destructor
  // ===========================================================================
  virtual ~Bacterie();
  
  // ===========================================================================
  //                                Getters
  // ===========================================================================
  vector<float> phenotype();
  float Pmut();
  float Pdeath();
  float Wmin();
  float fitness();
  char type();
  // ===========================================================================
  //                                Setters
  // ===========================================================================
  void set_phenotype(float a, float b, float c);
  void fitness(float fit);
  void set_type(char nom);

//===========================================================================
//                         Public Function members
//===========================================================================
virtual void division();


  protected :
  
// 
  //                       Protected Function members
  // ===========================================================================
  
  // ===========================================================================
  //                              Data members
  // ===========================================================================
  vector<float> phenotype_;
  float Pmut_;
  float Pdeath_;
  float Wmin_;
  float fitness_;
  char type_;
};


#endif
