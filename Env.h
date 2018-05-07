#ifndef Env_H_
#define Env_H_

// =============================================================================
//                               Includes
// =============================================================================
#include "Case.h"

class Env {
  public :
  // ===========================================================================
  //                              Constructors
  // ===========================================================================
  Env();
  
  // ===========================================================================
  //                               Destructor
  // ===========================================================================
  virtual ~Env();
  
  // ===========================================================================
  //                                Getters
  // ===========================================================================
  
  // ===========================================================================
  //                                Setters
  // ===========================================================================
  
  // ===========================================================================
  //                               Operators
  // ===========================================================================
  
  protected :
  
  // ===========================================================================
  //                       Protected Function members
  // ===========================================================================
  void etat();
  // ===========================================================================
  //                              Data members
  // ===========================================================================
  Case ** grille;
  int T_;
  float D_;
  int Ainit_;
  int width_;
  int height_;
  int temps_simul_;
};

#endif
