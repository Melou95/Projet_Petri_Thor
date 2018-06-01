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
#include <tuple>
#include <algorithm> // std::random_suffle
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Env::Env() : T_(1), D_(0.1), Ainit_(1.0), width_(32), height_(32), temps_simul_(10){
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
  int s=width_*height_/2;
  int l=width_*height_/2;
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
      if (x1==width_){x1=0;}
      if (x1==-1){x1=width_-1;}
      int y1 = y+j;
      if (y1==height_){y1=0;}
      if (y1==-1){y1=height_-1;}
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
  vector<int> coord;
  vector<vector<int>> coord_vides;
  vector< Case > case_fit;
  //vector< Bacterie * > bact_comp;
  float fitness=0.0;
  //Bacterie * best_bact;
  Case best_case;
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      if (grille_[i][j].p_bact()==nullptr){
        coord.push_back(i);
        coord.push_back(j);
        coord_vides.push_back(coord);
        coord.pop_back();
        coord.pop_back();
      } 
    }
  }
  random_shuffle(coord_vides.begin(), coord_vides.end()); 
  for (vector<vector<int>>::iterator it_coord=coord_vides.begin(); it_coord!=coord_vides.end(); ++it_coord){
    vector<int> positions;
    for (vector<int>::iterator it_pos=coord.begin(); it_pos!=coord.end(); ++it_pos){
      positions.push_back(*it_pos);
      for (int v=*it_pos-1;v<*it_pos+2;v++){
        for (int h=*it_pos-1;h<*it_pos+2;h++){
          if (v!=*it_pos and h!=*it_pos){
            if (v==width_){v=0;}
            if (v==-1){v=width_-1;}
            if (h==height_){h=0;}
            if (h==-1){h=height_-1;}
            if (grille_[v][h].p_bact() != nullptr){
              case_fit.push_back(grille_[v][h]);
            }
          }
        }
      }
    }
    if (case_fit.size()!=0){
      random_shuffle(case_fit.begin(), case_fit.end());
      for (vector< Case >::iterator it_case=case_fit.begin(); it_case!=case_fit.end(); ++it_case){
        if ((*it_case).p_bact()->fitness()>=fitness){
          fitness=(*it_case).p_bact()->fitness();
          best_case=*it_case;
        }
      }
      best_case.p_bact()->division();
      grille_[positions[0]][positions[1]].set_p_bact(best_case.p_bact());
    }
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
          if (grille_[i][j].p_bact() != nullptr){
            float nombre = rand() % 100;
            nombre = nombre / 100;
            p_death=this->grille_[i][j].p_bact()->Pdeath();
            if (nombre < p_death){
              grille_[i][j].mort_bact();
            }
          }
        }
      }
      this->competition();
      for(int i=0;i<height_;++i){
        for(int j=0;j<width_;++j){
          if (grille_[i][j].p_bact() != nullptr){
            this->grille_[i][j].bact_metabolise();
          }
        }
      }
    }
    time+=1;
  }
  this->reinitialisation_env();
  time=0;
}
