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
    if (readHeadLocation>=myFileString.length()) {
        return nullptr;
    }

    RequestData* myData = new RequestData();

    myData->ip = readSubStrTo(' ');
    jumpTo('[');

    myData->timeStamp = readSubStrTo(']');
    jumpTo('"');

    jumpTo(' ');
    myData->destination = readSubStrTo(' ');
    jumpTo('"');
    jumpTo('"');

    myData->origin = readSubStrTo('"');
    jumpTo('"');

    myData->browser = readSubStrTo('"');
    jumpTo('\n');

    //getline(*myFile, myData->ip,' ');
    //myFile->ignore(MAXSTREAMSIZE,'[');

    //getline(*myFile, myData->timeStamp, ']');
    //myFile->ignore(MAXSTREAMSIZE, '"');

    //myFile->ignore(MAXSTREAMSIZE, ' ');
    //getline(*myFile, myData->destination, ' ');
    //myFile->ignore(MAXSTREAMSIZE, '"');
    //myFile->ignore(MAXSTREAMSIZE, '"');

    //getline(*myFile, myData->origin, '"');
    //myFile->ignore(MAXSTREAMSIZE, '"');

    //getline(*myFile, myData->browser,'"');
    //myFile->ignore(MAXSTREAMSIZE, '\n');
    


   
    return myData;
}

void Reader::ProcessRequest(RequestData& data)const
{
    size_t qDel = data.destination.find_first_of('?');
    if (qDel != string::npos) {
        data.destination.erase(qDel, data.destination.length());
    }

    qDel = data.origin.find_first_of('?');
    if (qDel != string::npos) {
        data.origin.erase(qDel, data.origin.length());
    }


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

int Reader::GetTime(const string& timeStamp) const
{
    size_t startDel = timeStamp.find_first_of(':')+1;
    size_t endDel = timeStamp.find_first_of(':',startDel);

    string resS = timeStamp.substr(startDel,endDel-startDel);
    stringstream ssRes(resS);
    int res;
    ssRes >> res;
    return res;
}

const string Reader::GetFileExtension(const string& fileName) const
{
    size_t dotPos = fileName.find_last_of('.');
    if (dotPos == string::npos) {
        return "";
    }
    size_t qPos = fileName.find_first_of('?', dotPos);
    return fileName.substr(dotPos, qPos - dotPos);
}

bool Reader::Available() const
{
    return myFileString!="";
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur



Reader::Reader (const string& fileToRead, const string& iDomain)
// Algorithme :
//
{
    ifstream inFile(fileToRead, ios::binary);

    if (inFile) {
        readHeadLocation = 0;
        internalDomain = iDomain;
        if (internalDomain == "") {
            hasInternalDomain = false;
        }
        else {
            hasInternalDomain = true;
        }


        inFile.seekg(0, std::ios::end);
        myFileString.resize(inFile.tellg());
        inFile.seekg(0, std::ios::beg);
        inFile.read(&myFileString[0], myFileString.size());
        inFile.close();
    }
    else {
        myFileString = "";
        hasInternalDomain = false;
        cerr << "File does not exist" << endl;
    }

#ifdef MAP
    cout << "Appel au constructeur de <Reader>" << endl;
#endif
} //----- Fin de Reader


Reader::~Reader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
}

string Reader::readSubStrTo(char del)
{
    size_t endDel = myFileString.find_first_of(del, readHeadLocation);
    size_t startDel = readHeadLocation;
    readHeadLocation = endDel + 1;
    return myFileString.substr(startDel, endDel - startDel);
}

void Reader::jumpTo(char del)
{
    readHeadLocation = myFileString.find_first_of(del,readHeadLocation)+1;
}


//----- Fin de ~Reader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

