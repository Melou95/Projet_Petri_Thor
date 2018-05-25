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
#include <vector>
#include <algorithm> // std::random_suffle
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Env::Env() : T_(1), D_(0.1), Ainit_(1.0), width_(32), height_(32), temps_simul_(5000){
  grille_ = new Case * [height_]; // [n] réserve n élément du type qui précède
  for(int i=0;i<height_;++i){
    grille_[i] = new Case [width_];
  }
}

// =============================================================================
//                               Destructors
// =============================================================================
Env::~Env(){
  for(int i=0;i<height_;++i){
      delete [] grille_[i];
  }
  delete [] grille_;
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
  srand(time(NULL));
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
      /*cout<<grille_[x][y].milieu()[0]<<endl;
      cout<<grille_[x][y].milieu()[1]<<endl;
      cout<<grille_[x][y].milieu()[2]<<endl;*/
    }
  }
  this->grille_[x][y].set_milieu(this->grille_[x][y].milieu()[0]-9*D_*grille1[x][y].milieu()[0],
  this->grille_[x][y].milieu()[1]-9*D_*grille1[x][y].milieu()[1],
  this->grille_[x][y].milieu()[2]-9*D_*grille1[x][y].milieu()[2]);
  /*cout<<grille_[x][y].milieu()[0]<<endl;
  cout<<grille_[x][y].milieu()[1]<<endl;
  cout<<grille_[x][y].milieu()[2]<<endl;*/
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
  delete [] grille1;
}

void Env::reinitialisation_env_1_case(int x,int y){
  this->grille_[x][y].set_milieu(Ainit_,0,0);
}

void Env::reinitialisation_env(){
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      this->reinitialisation_env_1_case(i,j);
    }
  }
}

void Env::competition(){
  vector< Case > cases_vides;
  vector< Bacterie * > bact_comp;
  float fitness=0.0;
  Bacterie * best_bact;
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      if (grille_[i][j].p_bact()==nullptr){
        cases_vides.push_back(grille_[i][j]);
      } 
    }
  }
  random_shuffle(cases_vides.begin(), cases_vides.end()); // connaitre la position des cases !!!!!
  for (vector< Case >::iterator it_case=cases_vides.begin(); it_case!=cases_vides.end(); ++it_case){
    for (int k=-1;k<2;k++){
      for (int l=-1;l<2;l++){
        if (k!=0 and l!=0){
          bact_comp.push_back(grille_[k][l].p_bact());
        }
      }
    }
    random_shuffle(bact_comp.begin(), bact_comp.end());
    for (vector< Bacterie * >::iterator it_bact=bact_comp.begin(); it_bact!=bact_comp.end(); ++it_bact){
       if ((*it_bact)->fitness()>=fitness){
          fitness=(*it_bact)->fitness();
          best_bact=*it_bact;
       }
    }
    best_bact->division();
    (*it_case).set_p_bact(best_bact);
  }
}

void Env::run(){
  int time=0;
  while (time < T_){
    this->initialise();
    float p_death;
    for (int i=0;i<temps_simul_;++i){
      this->diffusion();
      int nombre_aleatoire=0;
      for(int i=0;i<height_;++i){
        for(int j=0;j<width_;++j){
          float nombre = rand() % 100;
          nombre = nombre / 100;
          p_death=this->grille_[i][j].p_bact()->Pdeath();
          if (nombre < p_death){
            grille_[i][j].mort_bact();
          }
        }
      }
      this->competition();
      for(int i=0;i<height_;++i){
        for(int j=0;j<width_;++j){
          this->grille_[i][j].bact_metabolise();
        }
      }
    }
  }
  this->reinitialisation_env();
  time=0;
}
