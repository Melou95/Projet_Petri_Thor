#ifndef S_H_
#define S_H_

// =============================================================================
//                               Includes
// =============================================================================
#include "Bacterie.h"
#include "Case.h"

class S : public Bacterie{
  public :
  // ===========================================================================
  //                              Constructors
  // ===========================================================================
  S();
  
  // ===========================================================================
  //                               Destructor
  // ===========================================================================
  virtual ~S();
  
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
  
  // ===========================================================================
  //                              Data members
  // ===========================================================================
  float RBB_;
  float RBC_;
};

#endif
