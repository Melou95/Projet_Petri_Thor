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
<<<<<<< HEAD
    /*Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();*/
=======
    cout << "Pour tester le constructeur de Env" << endl; 
    Env monde;
<<<<<<< HEAD
    //cout << monde.T() << endl;
    //cout << monde.D() << endl;
    
    
    
    Case c;
    /*c.set_milieu(0,0,0);
    cout<<c.milieu()[0]<<endl;*/
    c.metabolisme();
    cout<<c.milieu()[0]<<endl;
=======
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();
<<<<<<< HEAD
=======
>>>>>>> 984ac33fae65c0fa7bb12d578a004abe9f0ec8d9

>>>>>>> refs/remotes/origin/master
>>>>>>> 549dbbade0a7fa58bb6cf851576bdd16f8cc1294
    
    return 0;
    
}
