#ifndef Case_H_
#define Case_H_

// =============================================================================
//                               Includes
// =============================================================================
#include "Bacterie.h"
#include "L.h"
#include "S.h"
#include <map>
using namespace std;

class Case {
  public :
  // ===========================================================================
  //                              Constructors
  // ===========================================================================
  Case();
  
  // ===========================================================================
  //                               Destructor
  // ===========================================================================
  virtual ~Case();
  
  // ===========================================================================
  //                                Getters
  // ===========================================================================
  Bacterie * p_bact();
  vector<float> milieu();
  // ===========================================================================
  //                                Setters
  // ===========================================================================
  void set_p_bact(const L& bact);
  void set_p_bact(const S& bact);
  void set_milieu(float a, float b, float c);
  // ===========================================================================
  //                       Protected Function members
  // ===========================================================================
  
  void bact_metabolise();
  void mort_bact();
  

  protected :
  
  // ===========================================================================
  //                       Protected Function members
  // ===========================================================================

  // ===========================================================================
  //                              Data members
  // ===========================================================================
  vector<float> milieu_;
  Bacterie * p_bact_;
  
};

#endif
