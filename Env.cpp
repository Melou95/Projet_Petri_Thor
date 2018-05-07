// =============================================================================
//                                 Includes
// =============================================================================
#include "Env.h"
#include "Case.h"
#include <iostream>
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Env::Env() : T_(1), D_(0.1), Ainit_(25), width_(32), height_(32), temps_simul_(5000){
  Case ** grille_ = new Case * [height_]; // [n] réserve n élément du type qui précède
  for(int i=0;i<height_;++i){
    grille_[i] = new Case [width_];
  }
  
}
// =============================================================================
//                               Destructors
// =============================================================================
Env::~Env(){
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      delete grille_[i,j];
    }
  }
}
// ===========================================================================
//                                Getters
// ===========================================================================
Case ** Env::grille(){
  return grille_;
}

int Env::T(){
  return T_;
}
  
float Env::D(){
  return D_;
}

int Env::Ainit(){
  return Ainit_;
}


int Env::width(){
  return width_;
}


int Env::height(){
  return height_;
}


int Env::temps_simul(){
  return temps_simul_;
}
// ===========================================================================
//                                Setters
// ===========================================================================
  
  
  
// =============================================================================
//                         Public function members
// =============================================================================
void Env::etat(){
  int s=0;
  int l=0;
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      if (grille_[i,j]->p_bact()->type()=='S'){
        s+=1;
      }
      else if (grille_[i,j]->p_bact()->type()=='L'){
        l+=1;
      }
    }
  }
  if(s==0){
    if (l==0){
      cout << "Extinction" << endl;
    }
    else {
      cout << "Exclusion" << endl;
    }
  }
  else {
    cout << "Cohabitation" << endl;
  }  
}

