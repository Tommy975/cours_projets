#include <iostream>
#include <time.h>
#include "tampon.h"

using namespace std;


// Ma propre fonction de génération de nombres aléatoires.
int monRandFile()
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

int main() {
    
    srand(time(NULL)); 
    
    //instruction test; 
    instruction programme1[10000] = {};
    instruction programme2[10000] = {};
    instruction programme3[10000] = {};
    
    int secteurs[4][5];

    char again;
    int prog;

    do{
        bassin buffer;
        HDD C;

        cout << endl << "Quel heuristique voulez-vous utiliser? (taper 1 ou 2 puis entrer): ";
        cin >> buffer.H ;
        cout << endl << endl;
        cout << endl <<  "Quel programme voulez vous utiliser? ( 1, 2 ou 3): " ;
        cin >> prog;
        cout << endl << endl << endl;

        if ( 1 == prog){
            for (int i(0); i<10000; i++) {
                programme1[i].oP = maRandOp();
                programme1[i].file = monRandFile();
            }
    
            for (int i(0); i<10000; i++) {
                if (programme1[i].oP == 'r') {
                    C.readFileHDD(programme1[i].file);
                    buffer.readFile(programme1[i].file, buffer.compteur);}
                if (programme1[i].oP == 'w') buffer.writeFile(programme1[i].file);
                if (programme1[i].oP == 'm') {
                    C.modifyFileHDD(programme1[i].file);
                    buffer.modifyFile(programme1[i].file);
                }
            }
        }
        if ( prog == 2 ){
            for (int i(0); i<10000; i++) {
                programme2[i].oP = maRandOp();
                programme2[i].file = monRandFile();
            }  
            for(int i(0); i<10000; i++){
                if(programme2[i].oP == 'r') {
                    C.readFileHDD(programme2[i].file);
                    buffer.readFile(programme2[i].file, buffer.compteur);
                }
                if(programme2[i].oP == 'w') buffer.writeFile(programme2[i].file);
                if(programme2[i].oP == 'm') {
                    C.modifyFileHDD(programme2[i].file);
                    buffer.modifyFile(programme2[i].file);
                }
            }
        }
        if ( prog == 3 ){
            for (int i(0); i<10000; i++) {
                programme3[i].oP = maRandOp();
                programme3[i].file = monRandFile();
            }  
            for(int i(0); i<10000; i++){
                if(programme3[i].oP == 'r') {
                    C.readFileHDD(programme3[i].file);
                    buffer.readFile(programme3[i].file, buffer.compteur);
                }
                if(programme3[i].oP == 'w') buffer.writeFile(programme3[i].file);
                if(programme3[i].oP == 'm') {
                    C.modifyFileHDD(programme3[i].file);
                    buffer.modifyFile(programme3[i].file);
                }
            }
        }
        
        cout << "Heuristique " << buffer.H << endl << endl;
        cout << "Buffer: \t" ; 
        for (int i(0); i<5; i++) cout << buffer.tampons[i].file << "\t";
        cout << endl << "Dirty bits: \t";
        for (int i(0); i<5; i++) cout << buffer.tampons[i].dirty << "\t";
        float dif = ((C.timerHDD - buffer.timer));///C.timerHDD);//*100;
        float percent = (dif / C.timerHDD) * 100;
        cout << endl << endl << "Temps avec buffer: \t" << buffer.timer << " ms" << endl;
        cout << "Temps sans Buffer: \t" << C.timerHDD << " ms"<< endl;
        cout << "Pourcentage: \t\t" << percent << " %" << endl << endl;
        cout << "Voulez vous continuer? ";
        cin >> again;
        cout << endl << endl << endl << endl;


        buffer.closeBuffer();
        C.reset(C.lastFileHDD, C.timerHDD);
        }while ( again=='y' || again == 'Y' );
              

    
    cout << endl ;




    return 0;
}
