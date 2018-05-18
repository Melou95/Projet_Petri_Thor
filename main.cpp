#include <iostream>
#include "Bacterie.h"
#include "Case.h"
#include "Env.h"
#include "L.h"
#include "S.h"
using namespace std;

int main(){
    //Vérification de la mise en place de l'environnement
    cout<< "Hello World !\0" <<endl;
    cout<< " " <<endl;

    // Pour tester le contructeur de S
    S bact1;
    cout << bact1.phenotype()[0] << endl;
    
    //Pour tester la méthode division
    bact1.division();
    cout << bact1.phenotype()[0] << endl;  
    
    //Pour tester la méthode mutation
    cout << bact1.type() << endl;  
    bact1.mutation();
    cout << bact1.type() << endl;
    bact1.mutation();  
    cout << bact1.type() << endl;
    

    
    
    //Pour tester le constructeur de Env
    cout << "Pour tester le constructeur de Env" << endl; 
    Env monde;

    
    
    Case c;
    /*c.set_milieu(0,0,0);
    cout<<c.milieu()[0]<<endl;*/
    c.bact_metabolise();
    cout<<c.milieu()[0]<<endl;


    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();

    cout << "Pour tester la fonction metabolise" << endl;
    //Case c;
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
    

    return 0;
    
}
