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
      cout<<&grille_[i][j]<<endl;
    }
  }*/
}
// =============================================================================
//                               Destructors
// =============================================================================
Env::~Env(){
  for(int i=0;i<height_;++i){
      delete [] grille_[i];
  }
}
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
      if (grille_[i][j].p_bact()->type()=='S'){
        s+=1;
      }
      else if (grille_[i][j].p_bact()->type()=='L'){
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
            grille_[i][j].set_p_bact(bact);
            s-=1;
          }
          else if (nombre_aleatoire ==1){
            S bact;
            grille_[i][j].set_p_bact(bact);
            l-=1;
          }
        }
        else {
          L bact;
          grille_[i][j].set_p_bact(bact);
          s-=1;
        }
      }
      else {
        if (s>0){
          S bact;
          grille_[i][j].set_p_bact(bact);
          l-=1;
        }
      }
    }
  }
}


void Env::diffusion_1_case(int x,int y, Case ** grille1){
  for (int i=-1;i<2;++i){
    for (int j=-1;j<2;++j){
      int x1 = x+i;
      if (x1==32){x1=0;}
      if (x1==-1){x1=31;}
      int y1 = y+j;
      if (y1==32){y1=0;}
      if (y1==-1){y1=31;}
      this->grille_[x][y].set_milieu(this->grille_[x][y].milieu()[0]+D_*grille1[x1][y1].milieu()[0],
      this->grille_[x][y].milieu()[1]+D_*grille1[x1][y1].milieu()[1],
      this->grille_[x][y].milieu()[2]+D_*grille1[x1][y1].milieu()[2]);
      /*cout<<grille_[i][j].milieu()[0]<<endl;
      cout<<grille_[i][j].milieu()[1]<<endl;
      cout<<grille_[i][j].milieu()[2]<<endl;*/
    }
  }
  this->grille_[x][y].set_milieu(this->grille_[x][y].milieu()[0]-9*D_*grille1[x][y].milieu()[0],
  this->grille_[x][y].milieu()[1]-9*D_*grille1[x][y].milieu()[1],
  this->grille_[x][y].milieu()[2]-9*D_*grille1[x][y].milieu()[2]);
}

//fait la copie d'une grille
Case ** Env::copie_grille(){
  Case ** grille1= new Case * [this->height_];
  for(int i=0;i<this->height_;++i){
    grille1[i] = new Case [this->width_];
    }
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      grille1[i][j].set_milieu(this->grille_[i][j].milieu()[0],this->grille_[i][j].milieu()[1],this->grille_[i][j].milieu()[2]);
    }
  }
  return (grille1); 
}

void Env::diffusion(){
  Case ** grille1 = copie_grille();
  /*for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      cout<<grille_[i][j].milieu()[0]<<endl;
      cout<<grille_[i][j].milieu()[1]<<endl;
      cout<<grille_[i][j].milieu()[2]<<endl;
    }
  }*/
  //applique à toutes les cases de this la fonction diffusion_1_case
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      (*this).diffusion_1_case(i,j,grille1);
      //this->diffusion_1_case(i,j,this->grille_);
    }
  }
  for(int i=0;i< this->height_;++i){
      delete [] grille1[i];
  }
}



