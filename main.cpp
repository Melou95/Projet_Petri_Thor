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
    
    //Pour tester le constructeur de Env
    Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();
    
    return 0;
    
}
