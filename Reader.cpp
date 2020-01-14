/*************************************************************************
                           Reader  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Reader> (fichier Reader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Reader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Reader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Reader::GetRequest() {
    string ip,timeStamp,origin,destination,browser;
    (*myFile)>>ip;
    myFile->ignore(4);
    
}

//------------------------------------------------- Surcharge d'opérateurs
Reader & Reader::operator = ( const Reader & unReader )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Reader::Reader ( const Reader & unReader )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Reader>" << endl;
#endif
} //----- Fin de Reader (constructeur de copie)


Reader::Reader (string fileToRead)
// Algorithme :
//
{
myFile = new ifstream(fileToRead);
#ifdef MAP
    cout << "Appel au constructeur de <Reader>" << endl;
#endif
} //----- Fin de Reader


Reader::~Reader ( )
// Algorithme :
//
{
myFile->close();
delete myFile;
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
}


//----- Fin de ~Reader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

