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
    
    Env monde;
    //cout << monde.T() << endl;
    //cout << monde.D() << endl;
    
    
    
    Case c;
    /*c.set_milieu(0,0,0);
    cout<<c.milieu()[0]<<endl;*/
    c.metabolisme();
    cout<<c.milieu()[0]<<endl;
    
    return 0;
    
}
