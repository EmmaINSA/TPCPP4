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
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Reader.h"

//------------------------------------------------------------- Constantes
const int MAXSTREAMSIZE = INT32_MAX;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Reader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
RequestData* Reader::GetRequest() {
    if (myFile->eof()) {
        return nullptr;
    }
    RequestData* myData = new RequestData();
    getline(*myFile, myData->ip,' ');
    myFile->ignore(MAXSTREAMSIZE,'[');

    getline(*myFile, myData->timeStamp, ']');
    myFile->ignore(MAXSTREAMSIZE, '"');

    myFile->ignore(MAXSTREAMSIZE, ' ');
    getline(*myFile, myData->destination, ' ');
    myFile->ignore(MAXSTREAMSIZE, '"');
    myFile->ignore(MAXSTREAMSIZE, '"');

    getline(*myFile, myData->origin, '"');
    myFile->ignore(MAXSTREAMSIZE, '"');

    getline(*myFile, myData->browser,'"');
    myFile->ignore(MAXSTREAMSIZE, '\n');
    


   
    return myData;
}

void Reader::ProcessRequest(RequestData& data)const
{
    stringstream ssd(data.destination);
    getline(ssd, data.destination, '?');

    stringstream sso(data.origin);
    getline(sso, data.origin, '?');


    if (hasInternalDomain) {
        size_t pos = data.origin.find(internalDomain);
        if (pos != string::npos) {
            data.origin.erase(pos, internalDomain.length());
        }
    }


    for (int i = 0; i < data.destination.length(); ++i) {
        data.destination[i] = tolower(data.destination[i]);
    }
    for (int i = 0; i < data.origin.length(); ++i) {
        data.origin[i] = tolower(data.origin[i]);
    }

    
    if (data.destination.length()>1 && data.destination[data.destination.length() - 1] == '/') {
        data.destination.erase(data.destination.length() - 1, 1);
    }
    if (data.origin.length()>1 && data.origin[data.origin.length() - 1] == '/') {
        data.origin.erase(data.origin.length() - 1, 1);
    }
}

//------------------------------------------------- Surcharge d'opérateurs
Reader & Reader::operator = ( const Reader & unReader )
// Algorithme :
//
{
    return *this;
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


Reader::Reader (string fileToRead,string iDomain)
// Algorithme :
//
{
    internalDomain = iDomain;
    if (internalDomain == "") {
        hasInternalDomain = false;
    }
    else {
        hasInternalDomain = true;
    }

    ifstream inFile(fileToRead,ios::binary);
    string fileString;
    inFile.seekg(0, std::ios::end);
    fileString.resize(inFile.tellg());
    inFile .seekg(0, std::ios::beg);
    inFile.read(&fileString[0], fileString.size());
    inFile.close();
    myFile = new stringstream(fileString);


#ifdef MAP
    cout << "Appel au constructeur de <Reader>" << endl;
#endif
} //----- Fin de Reader


Reader::~Reader ( )
// Algorithme :
//
{
delete myFile;
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
}


//----- Fin de ~Reader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

