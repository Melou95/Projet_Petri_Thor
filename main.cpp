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
<<<<<<< HEAD
    
=======

    // Pour tester le contructeur de S
>>>>>>> 49bd3ddc8ac19083c1de73e1ba2d72fa57d186d2
    S bact1;
    cout << bact1.phenotype()[0] << endl;
    
    //Pour tester la méthode division
    bact1.division();
    cout << bact1.phenotype()[0] << endl;    
    
    //Pour tester le constructeur de Env
    cout << "Pour tester le constructeur de Env" << endl; 
    Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();
<<<<<<< HEAD
=======

>>>>>>> 49bd3ddc8ac19083c1de73e1ba2d72fa57d186d2
    
    return 0;
    
}
