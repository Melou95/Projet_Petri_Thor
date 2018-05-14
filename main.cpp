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
    
    S bact1;
    cout << bact1.phenotype()[0] << endl;
    bact1.division();
    cout << bact1.phenotype()[0] << endl;    
    /*Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;*/
    
    
    return 0;
    
}
