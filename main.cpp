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
    
    //Pour tester le constructeur de Env
    cout << "Pour tester le constructeur de Env" << endl; 
    Env monde;
    cout << monde.T() << endl;
    cout << monde.D() << endl;
    monde.initialise();
    monde.etat();

    Case c;
    /*c.set_milieu(0,0,0);
    cout<<c.milieu()[0]<<endl;*/
    c.metabolisme();
    cout<<c.milieu()[0]<<endl;
    
    return 0;
    
}
