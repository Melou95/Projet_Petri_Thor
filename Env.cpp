// =============================================================================
//                                 Includes
// =============================================================================
#include "Env.h"
#include "Case.h"
#include "Bacterie.h"
#include "L.h"
#include "S.h"
#include <iostream>
#include <time.h>
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Env::Env() : T_(1), D_(0.1), Ainit_(25), width_(32), height_(32), temps_simul_(5000){
  grille_ = new Case * [height_]; // [n] réserve n élément du type qui précède
  for(int i=0;i<height_;++i){
    grille_[i] = new Case [width_];
  }
  /*for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      cout<<grille_[i,j]<<endl;
    }
  }*/
}
// =============================================================================
//                               Destructors
// =============================================================================
/*Env::~Env(){
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      delete grille_[i,j];
    }
  }
}*/
// ===========================================================================
//                                Getters
// ===========================================================================
Case ** Env::grille(){
  return grille_;
}

/*Case * Env::grille(){
    return grille_;   
}
*/
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


void Env::initialise(){
  int s=512;
  int l=512;
  int nombre_aleatoire=0;
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      nombre_aleatoire = rand()%2;
      if(l>0){
        if (s>0){
          if (nombre_aleatoire == 0){
            L bact;
            grille_[i,j]->set_p_bact(bact);
            s-=1;
          }
          else if (nombre_aleatoire ==1){
            S bact;
            grille_[i,j]->set_p_bact(bact);
            l-=1;
          }
        }
        else {
          L bact;
          grille_[i,j]->set_p_bact(bact);
          s-=1;
        }
      }
      else {
        if (s>0){
          S bact;
          grille_[i,j]->set_p_bact(bact);
          l-=1;
        }
      }
    }
  }
}


/*void Env::diffusion_1_case(int x,int y){
  int A=this->grille_[x,y]->milieu()[0];
  int B=this->grille_[x,y]->milieu()[1];
  int C=this->grille_[x,y]->milieu()[2];
  for (int i=-1;i<2;++i){
    for (int j=-1;j<2;++j){
      int x1 = (x+i)%32;
      if (x1==-1){x1=31;}
      //cout<<"x"<<x1<<endl;
      int y1 = (y+j)%32;
      if (y1==-1){y1=31;}
      //cout<<"y"<<y1<<endl;
      this->grille_[x,y]->milieu()[0]+=D_*this->grille_[x1,y1]->milieu()[0];
      this->grille_[x,y]->milieu()[1]+=D_*this->grille_[x1,y1]->milieu()[1];
      this->grille_[x,y]->milieu()[2]+=D_*this->grille_[x1,y1]->milieu()[2];
    }
  }
  this->grille_[x,y]->milieu()[0]=A+9*D_*this->grille_[x,y]->milieu()[0];
  this->grille_[x,y]->milieu()[1]=B+9*D_*this->grille_[x,y]->milieu()[1];
  this->grille_[x,y]->milieu()[2]=C+9*D_*this->grille_[x,y]->milieu()[2];
}*/
//faire une grille de copie pour le temps t puis modifier chaque case de this.

/*void Env::diffusion(){
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      this->diffusion_1_case(i,j);
    }
  }
}*/



