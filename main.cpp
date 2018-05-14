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
    S bact1;
    cout << bact1.phenotype()[0] << endl;
    bact1.division();
    cout << bact1.phenotype()[0] << endl;    
    /*Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;*/
    
=======
    //Pour tester le constructeur de Env
    Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();
>>>>>>> 98ab3784acdd0d1926b7e8efa6353adc7a9591c6
    
    return 0;
    
}
