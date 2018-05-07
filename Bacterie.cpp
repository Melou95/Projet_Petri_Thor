// =============================================================================
//                                 Includes
// =============================================================================
#include "Bacterie.h"
#include <map>
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Bacterie::Bacterie(){
  phenotype_['A']=0.0;
  phenotype_['B']=0.0;
  phenotype_['C']=0.0;
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
map<char,float> Bacterie::phenotype(){
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
  phenotype_['A']=a;
  phenotype_['B']=b;
  phenotype_['C']=c;
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

