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
const int MAXSTREAMSIZE = INT32_MAX;
const int FIRSTJUMP = 5;
const int SECONDJUMP = 26;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Reader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
RequestData* Reader::GetRequest()
{
    if (readHeadLocation>=myFileString.length())
    {
        return nullptr;
    }

    RequestData* myData = new RequestData();

    myData->ip = readSubStrTo(' ');
    jumpTo(FIRSTJUMP);//jump to '['

    myData->timeStamp = readSubStrTo(SECONDJUMP); //read until ']'
    jumpTo(FIRSTJUMP);//jump to '"'

    jumpTo(' ');
    myData->destination = readSubStrTo(' ');
    jumpTo('"');
    jumpTo('"');

    myData->origin = readSubStrTo('"');
    jumpTo('"');

    myData->browser = readSubStrTo('"');
    jumpTo('\n');
   
    return myData;
}

void Reader::ProcessRequest(RequestData& data)const
{
    size_t qDel = data.destination.find_first_of('?');
    if (qDel != string::npos)
    {
        data.destination.erase(qDel, data.destination.length());
    }

    qDel = data.origin.find_first_of('?');
    if (qDel != string::npos)
    {
        data.origin.erase(qDel, data.origin.length());
    }
    qDel = data.origin.find_first_of(';');
    if (qDel != string::npos)
    {
        data.origin.erase(qDel, data.origin.length());
    }
    qDel = data.destination.find_first_of(';');
    if (qDel != string::npos)
    {
        data.destination.erase(qDel, data.destination.length());
    }


    if (hasInternalDomain)
    {
        size_t pos = data.origin.find(internalDomain);
        if (pos != string::npos)
        {
            data.origin.erase(pos, internalDomain.length());
        }
    }


    for (unsigned int i = 0; i < data.destination.length(); ++i)
    {
        data.destination[i] = tolower(data.destination[i]);
    }
    for (unsigned int i = 0; i < data.origin.length(); ++i)
    {
        data.origin[i] = tolower(data.origin[i]);
    }

    
    if (data.destination.length()>1 && data.destination[data.destination.length() - 1] == '/')
    {
        data.destination.erase(data.destination.length() - 1, 1);
    }
    if (data.origin.length()>1 && data.origin[data.origin.length() - 1] == '/')
    {
        data.origin.erase(data.origin.length() - 1, 1);
    }
}

string Reader::GetTime(const string& timeStamp) const
{
    size_t startDel = timeStamp.find_first_of(':')+1;
    size_t endDel = startDel+5;

    string resS = timeStamp.substr(startDel,endDel-startDel);
    return resS;
}

const string Reader::GetFileExtension(const string& fileName) const
{
    size_t dotPos = fileName.find_last_of('.');
    if (dotPos == string::npos)
    {
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

    if (inFile)
    {
        readHeadLocation = 0;
        internalDomain = iDomain;
        if (internalDomain == "")
        {
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
        inFile.close();
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

string Reader::readSubStrTo(int distance)
{
    size_t endDel = readHeadLocation + distance;
    size_t startDel = readHeadLocation;
    readHeadLocation = endDel + 1;
    return myFileString.substr(startDel, distance);
}

void Reader::jumpTo(char del)
{
    readHeadLocation = myFileString.find_first_of(del,readHeadLocation)+1;
}

void Reader::jumpTo(int distance)
{
    readHeadLocation += distance;
}


//----- Fin de ~Reader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

