// =============================================================================
//                                 Includes
// =============================================================================
#include "Case.h"
#include "Bacterie.h"
#include "L.h"
#include "S.h"
#include <map>
using namespace std;


// =============================================================================
//                              Constructors
// =============================================================================
Case::Case(){
  milieu_.push_back(1.0);
  milieu_.push_back(1.0);
  milieu_.push_back(1.0);
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
void Case::set_p_bact(const L& bact){
    if (p_bact_!=nullptr){
      delete p_bact_;
    }
    p_bact_=new L(bact);
  }

void Case::set_p_bact(const S& bact){
    if (p_bact_!=nullptr){
      delete p_bact_;
    }
    p_bact_=new S(bact);
  }

void Case::set_milieu(float a, float b, float c){
    milieu_[0]=a;
    milieu_[1]=b;
    milieu_[2]=c;
  }

// =============================================================================
//                         Public function members
// =============================================================================
void Case::metabolise(){
  if (this->p_bact_->type()=='L'){
  float Aout=this->milieu()[0];
  float Bout=this->milieu()[1];
  float Cout=this->milieu()[2];
  float A=this->p_bact_->phenotype()[0];
  float B=this->p_bact_->phenotype()[1];
  float C=this->p_bact_->phenotype()[2];
  this->set_milieu(Aout-Aout*this->p_bact_->RAA(), Bout, Cout);
  this->p_bact_->set_phenotype(A+Aout*this->p_bact_->RAA()-A*this->p_bact_->RAB(), B+A*this->p_bact_->RAB(), C);
  }
  else{
  float Aout=this->milieu()[0];
  float Bout=this->milieu()[1];
  float Cout=this->milieu()[2];
  float A=this->p_bact_->phenotype()[0];
  float B=this->p_bact_->phenotype()[1];
  float C=this->p_bact_->phenotype()[2];
  this->set_milieu(Aout, Bout-Bout*this->p_bact_->RBB(), Cout);
  this->p_bact_->set_phenotype(A, B+Bout*this->p_bact_->RBB()-B*this->p_bact_->RBC(), C+B*this->p_bact_->RBC());
  }
}







