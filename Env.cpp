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
#include <string>
#include <algorithm> // std::random_suffle
using namespace std;

// =============================================================================
//                              Constructors
// =============================================================================
Env::Env() : T_(1), D_(0.1), Ainit_(1), width_(32), height_(32), temps_simul_(5000){
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

void Env::set_T(int T){
  T_=T;
}
  
void Env::set_D(float D){
  D_=D;
}

void Env::set_Ainit(int Ainit){
  Ainit_=Ainit;
}  
  
// =============================================================================
//                         Public function members
// =============================================================================
string Env::etat(){
  int s=0;
  int l=0;
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      if (grille_[i][j].p_bact() != nullptr){
        if (grille_[i][j].p_bact()->type()=='S'){
          s+=1;
        }
        else if (grille_[i][j].p_bact()->type()=='L'){
          l+=1;
        }
      }
    }
  }
  if(s==0){
    if (l==0){
      return("Extinction");
    }
    else {
      return("Exclusion");
    }
  }
  else {
    return("Cohabitation");
  }  
}


void Env::initialise(){
  int s;
  int l;
  if (width_*height_%2==0){
    s=width_*height_/2;
    l=width_*height_/2;
  }
  else{
    s=(width_*height_-1)/2;
    l=(width_*height_+1)/2;
  }
  int nombre_aleatoire=0;
  for(int i=0;i<height_;++i){
    for(int j=0;j<width_;++j){
      this->grille_[i][j].set_milieu(Ainit_,0,0);
      nombre_aleatoire = rand()%2;
      if(l>0){
        if (s>0){
          if (nombre_aleatoire == 0){
            L bact;
            grille_[i][j].set_p_bact(bact);
            l-=1;
          }
          else if (nombre_aleatoire ==1){
            S bact;
            grille_[i][j].set_p_bact(bact);
            s-=1;
          }
        }
        else {
          L bact;
          grille_[i][j].set_p_bact(bact);
          l-=1;
        }
      }
      else {
        if (s>0){
          S bact;
          grille_[i][j].set_p_bact(bact);
          s-=1;
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
  //this->affichage();
  //cout<<grille_[0][1].p_bact()->type()<<endl; affiche la case d'abscisse 0 et d'ordonnée 1
  vector<int> coord;  //initialise un vecteur : coordonnées
  vector<vector<int>> coord_vides;  //initialise un vecteur de vecteur : coordonnées vides
  float fitness=0.0;  //initialise la fitness de comparaison à 0
  //Bacterie * best_bact;
  Case best_case; //on crée une case : best_case
  for (int i=0; i<height_; ++i){
    for (int j=0; j<width_; ++j){
      if (grille_[i][j].p_bact()==nullptr){  //si la case de coord i,j ne contient pas de bactérie, on ajoute à coord  les coord de cette case et on ajoute à coord_vides ce vecteur de coord
        //this->affichage();
        coord.push_back(i);
        coord.push_back(j);
        coord_vides.push_back(coord);
        coord.pop_back();
        coord.pop_back();
      } 
    }
  }
  //coord est un vecteur contenant des vecteurs de coordonnées des cases vides de la grille
  random_shuffle(coord_vides.begin(), coord_vides.end()); //mélange les vecteurs de coord
  int a = 1;
  for (int it_coord=0; it_coord<coord_vides.size(); ++it_coord){ //pour chaque vecteur de coordonnées de coord_vide : pour chaque coordonnées de case vide :
    vector<int> positions;  //initialise un vecteur positions
    //a += 1;
    //cout<<a<<endl;
    //cout<<coord_vides.size()<<endl;
    for (int it_pos=0; it_pos<2; ++it_pos){  //la boucle ajoute à positions les coordonnées de la case vide en cours
      positions.push_back(coord_vides[it_coord][it_pos]);
    }
    vector<Case *> case_fit;
    for (int x=-1;x<2;++x){
      int x1 = positions[0]+x;
      if (x1==height_){x1=0;}
      if (x1==-1){x1=height_-1;}
      for (int y=-1;y<2;++y){
        int y1 = positions[1]+y;
        if (y1==width_){y1=0;}
        if (y1==-1){y1=width_-1;}
        //détermine les coordonnées des cellules autour de la bactérie en cours de traitement
        if (x1!=positions[0] or y1!=positions[1]){  //si la cellule en question n'est pas celle de la bactérie
          if (grille_[x1][y1].p_bact() != nullptr){  //et si elle possède une bactérie
          
          //commandes d'affichages
            //cout<<a<<endl;
            //this->affichage();
            case_fit.push_back(&grille_[x1][y1]);   //on ajoute cette case au vecteur case_fit
          }
        }
      }
    }
    Case * best_case=nullptr;
    if (case_fit.size()!=0){
      random_shuffle(case_fit.begin(), case_fit.end());
      //for (vector< Case * >::iterator it_case=case_fit.begin(); it_case!=case_fit.end(); ++it_case){
      for (int it_case=0; it_case<case_fit.size(); ++it_case){
        if (case_fit[it_case]->p_bact()->fitness()>fitness){
          fitness=case_fit[it_case]->p_bact()->fitness();
          best_case=case_fit[it_case];
        }
      }
      if (best_case != nullptr){
      //cout << "phen 1"<<best_case->p_bact()->fitness()<<endl;
        best_case->p_bact()->division();
        char type_bact = best_case->p_bact()->type();
        if (type_bact=='S') {
          S new_bact = S(best_case->p_bact());
          grille_[positions[0]][positions[1]].set_p_bact(& new_bact);
          //cout << 's' << endl;
        }
        if (type_bact=='L') {
          L new_bact = L(best_case->p_bact());
          grille_[positions[0]][positions[1]].set_p_bact(& new_bact);
        }
      }
    }
    
    positions.pop_back();
    positions.pop_back();
    //for (int ind=0; ind<count_bact; ++ind){
      //delete [] case_fitness;
    //}
  }
}











void Env::run(){
  int time=0;
  this->initialise();
  //this->affichage();
  for (int i=0;i<temps_simul_;++i){
    //cout << grille_[0][0].milieu()[0] << ' ' << grille_[0][0].milieu()[1] << ' ' << grille_[0][0].milieu()[2] <<endl;
    if (time == T_) {
      this->reinitialisation_env();
      time=0;
    }
      float p_death;
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
      //cout << grille_[25][12].milieu()[1] << endl;
      for(int i=0;i<height_;++i){
        for(int j=0;j<width_;++j){
          if (grille_[i][j].p_bact() != nullptr){
            this->grille_[i][j].bact_metabolise();
          }
        }
      }
      time+=1;
      //this->affichage();
  }
}

void Env::affichage(){
  for(int i=0;i<this->height_;++i){
    cout << "----"; //première ligne
  }
  cout << "" << endl;
  for (int i=0;i<this->height_;i++){
    for(int j=0;j<this->width_;++j){
      if (grille_[i][j].p_bact() == nullptr){
        cout << "|   ";
      }
      else if (grille_[i][j].p_bact()->type()=='L'){
        cout << "| L ";
      } 
      else {
        cout << "| S ";
      } 
    }
    cout << "| ";     
    cout << "" << endl;   
  }    
  for(int i=0;i<this->height_;++i){
    cout << "----"; 
  }
  cout << "" << endl;
}
