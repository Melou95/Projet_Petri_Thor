// =============================================================================
//                                 Includes
// =============================================================================
#include "Bacterie.h"
#include <vector>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Bacterie::Bacterie(){
  phenotype_ = vector<float>(3, 2.0);
  Pmut_=0;
  Pdeath_=0.02;
  Wmin_=0.001;
  fitness_=0.0;
  type_=' ';
}
// =============================================================================
//                               Destructors
// =============================================================================
Bacterie::~Bacterie()=default;

// ===========================================================================
//                                Getters
// ===========================================================================
vector<float> Bacterie::phenotype(){
  return phenotype_;
}

float Bacterie::Pmut(){
  return Pmut_;
}

float Bacterie::Pdeath(){
  return Pdeath_;
}

float Bacterie::Wmin(){
  return Wmin_;
}

float Bacterie::fitness(){
  return fitness_;
}

char Bacterie::type(){
  return type_;
}


// ===========================================================================
//                                Setters
// ===========================================================================
void Bacterie::set_phenotype(float a, float b, float c){
  phenotype_[0]=a;
  phenotype_[1]=b;
  phenotype_[2]=c;
}

void Bacterie::fitness(float fit){
  fitness_=fit;
}

void Bacterie::set_type(char nom){
  type_=nom;
}

// =============================================================================
//                         Public function members
// =============================================================================
void Bacterie::division(){
  for (int i=0 ; i<phenotype_.size(); ++i)
  {
   phenotype_[i]/=2;
  }
}
  


