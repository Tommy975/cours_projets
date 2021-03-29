#include <iostream>
#include "tampon.h"

using namespace std;




bassin::bassin() {
	
    cout << "INFO-3114 \t \t Devoir1 \t \t Simulations des accès au disque dur avec et sans buffer." << endl << endl
         << "Travail réalisé par : \t Tommy Urdanabia \t NI: A00155855" << endl << endl << endl;
   // cout << "Quel heuristique voulez vous utiliser? (taper 1 ou 2 puis entrer): " ;

    //cin >> H;

}

bassin::~bassin() {
    closeBuffer();
}

int bassin::lessUsed(){
    
    int temp;

    for (int i(0); i<4; i++){
        if( tampons[i].ite < tampons[i+1].ite ) temp = i;
        else temp = i+1;
    }

    //cout << "less:" << temp << "\t \t  used: " << tampons[temp].ite << endl << endl;
    
    return temp;
}

void bassin::readFile(int file, int &compteur) {

    if (fileInBuffer(file)!=-1){ 
        //cout << "file: " << file << " \t  already in buffer" << endl;
        tampons[fileInBuffer(file)].ite++;
    }
    else{
        if (compteur<5 && H == 1){

            returnTime(file, lastFile, timer);

            if ( tampons[compteur].dirty && full == 1) {
               returnTime(tampons[compteur].file, lastFile, timer);
               //writeFile(tampons[compteur].file);
            };

            tampons[compteur].file = file;
            //cout << "1file: "<< tampons[compteur].file << " \t  read in position: " << compteur << endl;

            compteur++;
           
            if (compteur > 4){ 
                full = 1;
                compteur = 0;
            }
        }
        else {
            if (compteur < 5){

                returnTime(file, lastFile, timer);

                tampons[compteur].file = file;
                tampons[compteur].ite++;
                //cout << "2file: "<< tampons[compteur].file << " \t  read in position: " << compteur << endl;
                compteur++;
                if (compteur>4) full = 1;
            }
            else{

                returnTime(file, lastFile, timer);
                
                if ( tampons[compteur].dirty && full == 1) {
                   // returnTime(tampons[compteur].file, lastFile, timer);
                    writeFile(tampons[compteur].file);
                };

                int less = lessUsed();


                tampons[less].file = file;
                //cout << "2file: "<< tampons[less].file << " \t  read in position: " << less << endl;
                tampons[less].ite = 1;            
            }
        }
    }
}

void bassin::writeFile(int file) {
    int temp = fileInBuffer(file);
	//if (fileInBuffer(file) == -1){}
	//else {
        //returnTime(file, lastFile, timer);
		if (tampons[temp].dirty == true) {
            returnTime(file, lastFile, timer);
            tampons[temp].dirty = false;
        }
//	}

}

void bassin::modifyFile(int file) {

	readFile(file, compteur);
	markDirty(file);
}

/*
void bassin::closeFile(int file) {
	
}
*/

void bassin::closeBuffer() {
	for(int i(0); i<5; i++)
		if (tampons[i].dirty)
			writeFile(tampons[i].file);

    H = 0;
    timer = 0;
    //ite = 0;
    less = 0;
    compteur = 0;
    full = -1;
    lastFile = -1;
}

void bassin::markDirty(int block) {
	tampons[block].dirty = true;
}

int bassin::fileInBuffer(int file) {

	for (int i(0); i<5; i++)
		if (tampons[i].file == file)
			return i;

	return (-1);
}

bool bassin::isFull(int compteur) {
	return compteur>=4;
}

void bassin::returnTime( int file, int &lastFile, int &timer ){
    
    if ( file == lastFile+1 )// && file%5 == lastFile%5 )
        timer = timer + 2;
    else
        timer = timer + 12;

    lastFile = file;
}




void HDD::readFileHDD(int file){
    bassin::returnTime(file, lastFileHDD, timerHDD);
}

void HDD::modifyFileHDD(int file){
    readFileHDD(file);
    bassin::returnTime(file, lastFileHDD, timerHDD);
}

void HDD::reset(int &lastFileHDD, int &timerHDD){
    lastFileHDD = -1;
    timerHDD = 0;
}
