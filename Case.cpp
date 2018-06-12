// =============================================================================
//                                 Includes
// =============================================================================
#include "Case.h"
#include "Bacterie.h"
#include "L.h"
#include "S.h"
#include <map>
#include <iostream>
#include <algorithm> 
using namespace std;


// =============================================================================
//                              Constructors
// =============================================================================
Case::Case(){
  milieu_.push_back(0.0);
  milieu_.push_back(0.0);
  milieu_.push_back(0.0);
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
  
void Case::set_p_bact(Bacterie* bact){ // Si ça marche les deux précédents ne servent plus et il faut modif le code en conséquence
    if (p_bact_!=nullptr){
      delete p_bact_;
    }
    if (bact->type()=='S'){
      p_bact_=new S(bact);
    }
    else if (bact->type()=='L'){
      p_bact_=new L(bact);
    }
    
  }

void Case::set_milieu(float a, float b, float c){
    milieu_[0]=a;
    milieu_[1]=b;
    milieu_[2]=c;
  }

// =============================================================================
//                         Public function members
// =============================================================================

void Case::mort_bact(){
  //float nombre = rand()%101;
  //nombre = nombre / 100;
  //if (nombre < p_bact_->Pdeath()){
    float A=this->p_bact_->phenotype()[0];
    float B=this->p_bact_->phenotype()[1];
    float C=this->p_bact_->phenotype()[2];
    set_milieu(this->milieu()[0]+A,this->milieu()[1]+B,this->milieu()[2]+C);
    delete p_bact_;
    p_bact_=nullptr;
    //cout << this->milieu()[1] << endl;
  //}
}

void Case::bact_metabolise(){
  if (this->p_bact_->type()=='L'){
  float Aout=this->milieu()[0];
  float Bout=this->milieu()[1];
  float Cout=this->milieu()[2];
  //cout << Aout << ' ' << Bout << ' ' << Cout << endl;
  float A=this->p_bact_->phenotype()[0];
  float B=this->p_bact_->phenotype()[1];
  float C=this->p_bact_->phenotype()[2];
  this->set_milieu(Aout-Aout*this->p_bact_->RAA(), Bout, Cout);
  this->p_bact_->set_phenotype(A+Aout*this->p_bact_->RAA()-A*this->p_bact_->RAB(), B+A*this->p_bact_->RAB(), C);
  //cout << Aout << ' ' << Bout << ' ' << Cout << endl;
  if (this->p_bact_->phenotype()[1]>this->p_bact_->Wmin()){
    this->p_bact_->set_fitness(this->p_bact_->phenotype()[1]);
  }
  else{
    this->p_bact_->set_fitness(0);
  }
  }
  else if (this->p_bact_->type()=='S'){
  float Aout=this->milieu()[0];
  float Bout=this->milieu()[1];
  float Cout=this->milieu()[2];
  float A=this->p_bact_->phenotype()[0];
  float B=this->p_bact_->phenotype()[1];
  float C=this->p_bact_->phenotype()[2];
  this->set_milieu(Aout, Bout-Bout*this->p_bact_->RBB(), Cout);
  this->p_bact_->set_phenotype(A, B+Bout*this->p_bact_->RBB()-B*this->p_bact_->RBC(), C+B*this->p_bact_->RBC());
  if (this->p_bact_->phenotype()[2]>this->p_bact_->Wmin()){
    this->p_bact_->set_fitness(this->p_bact_->phenotype()[2]);
  }
  else{
    this->p_bact_->set_fitness(0);
  }
  //cout << this->p_bact_->phenotype()[1] << endl;
  }
}







