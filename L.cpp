// =============================================================================
//                                 Includes
// =============================================================================
#include "L.h"
#include "Bacterie.h"


#include <iostream>
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
L::L(){
  type_='L';
  RAA_=0.1;
  RAB_=0.1;
}
// =============================================================================
//                               Destructors
// =============================================================================
L::~L()=default;
// =============================================================================
//                         Public function members
// =============================================================================


// =============================================================================
//                                GETTERS
// =============================================================================
float L::RAA(){
    return RAA_;
}

float L::RAB(){
    return RAB_;
}


