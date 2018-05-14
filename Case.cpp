// =============================================================================
//                                 Includes
// =============================================================================
#include "Case.h"
#include "Bacterie.h"
#include <map>
using namespace std;


// =============================================================================
//                              Constructors
// =============================================================================
Case::Case(){
  milieu_.push_back(1.0);
  milieu_.push_back(2.0);
  milieu_.push_back(3.0);
  p_bact_ = nullptr;
}
// =============================================================================
//                               Destructors
// =============================================================================
Case::~Case(){
  delete p_bact_;
}
// ===========================================================================
//                                Getters
// ===========================================================================
  vector<float> Case::milieu(){
    return milieu_;
  }
  
  Bacterie * Case::p_bact(){
    return p_bact_;
  }
// ===========================================================================
//                                Setters
// ===========================================================================
void Case::set_p_bact(Bacterie bact){
    p_bact_=new Bacterie;
    *p_bact_=bact;
  }
  
  
void Case::set_milieu(float a, float b, float c){
    milieu_[0]=a;
    milieu_[1]=b;
    milieu_[2]=c;
  }

// =============================================================================
//                         Public function members
// =============================================================================
void Case::metabolisme(){
  if (this->p_bact_->type()=='L'){
  float Aout=this->milieu()[0];
  float Bout=this->milieu()[1];
  float Cout=this->milieu()[2];
  float A=this->p_bact_->phenotype()[1];
  float B=this->p_bact_->phenotype()[2];
  float C=this->p_bact_->phenotype()[3];
  this->set_milieu(Aout-Aout*this->p_bact_->RAA(), Bout, Cout);
  this->p_bact_->set_phenotype(A+Aout*this->p_bact_->RAA()-A*this->p_bact_->RAB(), B+A*this->p_bact_->RAB(), C);
  }
  
}







