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
Env::Env(){
  int T_=1;
  float D_=0.1;
  int Ainit_=25;
  int width_=32;
  int height_=32;
  int temps_simul=5000;
  Case ** grille = new Case * [height_]; // [n] réserve n élément du type qui précède
  for(int i=0;i<height_;++i){
    grille[i] = new Case [width_];
  }
  
}
// =============================================================================
//                               Destructors
// =============================================================================

// =============================================================================
//                         Public function members
// =============================================================================
void Env::etat(){
  int s=0;
  int l=0;
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      if (grille[i,j]->p_bact()->type()=="S"){
        s+=1;
      }
      else if (grille[i,j]->p_bact()->type()=="L"){
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

