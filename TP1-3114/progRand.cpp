#include <iostream> 
#include <fstream>
#include <time.h>
using namespace std; 



// Ma propre fonction de génération de nombres aléatoires pour réduire les probabilités de doublons.
int monRand9chiffres()
{
	int valeur = 0 ;

	valeur = rand() % 20 ; // On génère un chiffre décimal à la fois.
	return valeur ;
} 

char maRandOp(){
    int valeur = 0;
    char oP;
    valeur = rand()%3 + 1;
    //cout << valeur;
    if (valeur==1) oP ='r';
    if (valeur==2) oP ='w';
    if (valeur==3) oP ='m';

    return oP;
}

int main(){
    /*
    for (int i(0); i<100; i++)
        cout << monRand9chiffres() << endl;

    */
    int taille(50);
    srand(time(NULL));
    ofstream out( "program1.in" , ios::out | ios::ate );
    
    out << 1 << endl;

    //cout << taille << endl;

    for (int i(0); i<10000; i++)
        out << maRandOp() << monRand9chiffres()  << endl;

    out.close();

	return 0;
}
