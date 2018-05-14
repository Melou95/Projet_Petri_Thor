#ifndef L_H_
#define L_H_

// =============================================================================
//                               Includes
// =============================================================================
#include "Bacterie.h"


class L : public Bacterie{
  public :
  // ===========================================================================
  //                              Constructors
  // ===========================================================================
  L();
  
  // ===========================================================================
  //                               Destructor
  // ===========================================================================
  virtual ~L();
  
  // ===========================================================================
  //                                Getters
  // ===========================================================================
  virtual float RAA();
  virtual float RAB();
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

  // ===========================================================================
  //                              Data members
  // ===========================================================================
  float RAA_;
  float RAB_;
};

#endif
