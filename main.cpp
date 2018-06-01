#include <iostream>
#include "Bacterie.h"
#include "Case.h"
#include "Env.h"
#include "L.h"
#include "S.h"
#include <fstream>
#include <string>
using namespace std;

int main(){
    srand(1); //time(NULL)
    //Vérification de la mise en place de l'environnement
    cout<< "Hello World !\0" <<endl;
    cout<< " " <<endl;

    cout << "Pour tester le constructeur de S" << endl; 
    S bact1;
    cout << bact1.phenotype()[0] << endl;
    
    cout << "Pour tester la méthode division" << endl; 
    bact1.division();
    cout << bact1.phenotype()[0] << endl;  
    
    cout << "Pour tester la méthode mutation" << endl; 
    cout << bact1.type() << endl;  
    bact1.mutation();
    cout << bact1.type() << endl;
    bact1.mutation();  
    cout << bact1.type() << endl;
    

    
    
    cout << "Pour tester le constructeur de Env" << endl; 
    Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();
    monde.affichage();
    
    
    Case c;
    c.set_milieu(0,0,0);
    cout<<c.milieu()[0]<<endl;



    cout << "Pour tester la fonction metabolise" << endl;
    c.set_milieu(3,2,1);
    cout<<c.milieu()[0]<<endl;
    cout<<c.milieu()[1]<<endl;
    cout<<c.milieu()[2]<<endl;
    S bact2;
    c.set_p_bact(bact2);
    c.bact_metabolise();
    cout<<c.milieu()[0]<<endl;
    cout<<c.milieu()[1]<<endl;
    cout<<c.milieu()[2]<<endl;
    
    
    cout << "Pour tester la fonction mort_bact" << endl;
    c.mort_bact();
    cout<<c.milieu()[0]<<endl;
    cout<<c.milieu()[1]<<endl;
    cout<<c.milieu()[2]<<endl;
    
    
    cout << "Pour tester la fonction diffusion" << endl;
    cout<<monde.grille()[0,0]->milieu()[0]<<endl;
    cout<<monde.grille()[0,0]->milieu()[1]<<endl;
    cout<<monde.grille()[0,0]->milieu()[2]<<endl;
    /*monde.diffusion_1_case(0, 0, monde.grille());*/
    cout<<monde.grille()[0,0]->milieu()[0]<<endl;
    cout<<monde.grille()[0,0]->milieu()[1]<<endl;
    cout<<monde.grille()[0,0]->milieu()[2]<<endl;
    monde.diffusion();
    cout<<monde.grille()[24,12]->milieu()[0]<<endl;
    cout<<monde.grille()[0,31]->milieu()[1]<<endl;
    cout<<monde.grille()[18,5]->milieu()[2]<<endl;
    
    cout << "Pour tester la fonction reinitialisation_env" << endl;
    monde.reinitialisation_env();
    cout<<monde.grille()[24,12]->milieu()[0]<<endl;
    cout<<monde.grille()[0,31]->milieu()[1]<<endl;
    cout<<monde.grille()[18,5]->milieu()[2]<<endl;
    
    cout << "Pour tester les fonctions run et competition" << endl;
    
    ofstream fichier("resultats.txt", ios::out | ios::trunc);
    if(fichier){   
      fichier << "T\tAinit\tEtat" << endl;
      int nb_ext=0;
      int nb_exclu=0;
      int nb_cohab=0;
      for (int T=1; T<150; T+50){
        for (float Ainit=1; Ainit<3; ++Ainit){
          Env monde;
          monde.set_T(T);
          monde.set_Ainit(Ainit);
          monde.run();
          string resultat=monde.etat();
          if (resultat=="Extinction"){
            ++nb_ext;
          }
          else if (resultat=="Exclusion"){
            ++nb_exclu;
          }
          else if (resultat=="Cohabitation"){
            ++nb_cohab;
          }
          fichier << T << "\t" << Ainit << "\t" << resultat << endl;
        }
      }
      fichier << "Nb Extinction\tNb Exclusion\tNb Cohabitation" << endl;
      fichier << nb_ext << "\t" << nb_exclu << "\t" << nb_cohab << endl;
    }
    else{
      cerr << "Impossible d'ouvrir le fichier" << endl;
    }
    

    return 0;
    
}
