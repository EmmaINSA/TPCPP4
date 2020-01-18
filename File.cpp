/*************************************************************************
                           File  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <File> (fichier File.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "File.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type File::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



int File::GetHits()const
{
    return nbHits;
}

const string& File::MyName()const
{
    return *label;
}

bool File::AddInbound(const File* const & origin, const string*& ip, const string*& webBrowser,const string*& timeStamp) {
    ++nbHits;
    auto oldPos = inBound.find(origin->MyName());
    if (oldPos != inBound.end()) {
        (*oldPos).second->AddRequest(timeStamp, ip, webBrowser);
        return true;
    }
    Link* newLink = new Link();
    inBound[origin->MyName()] = newLink;
    newLink->AddRequest(timeStamp, ip, webBrowser);

    return false;
}


//------------------------------------------------- Surcharge d'opérateurs

bool File::operator<(const File& unFile) const
{
    return (label < unFile.label);
}

bool File::operator==(const File& unFile) const
{
    return (label == unFile.label);
}

//-------------------------------------------- Constructeurs - destructeur


File::File (const string* myLabel)
// Algorithme :
//
{
    label = myLabel;

    static int idCounter = 0;
    myId = idCounter;
    ++idCounter;

    nbHits = 0;
#ifdef MAP
    cout << "Appel au constructeur de <File>" << endl;
#endif
} //----- Fin de File


File::~File ( )
// Algorithme :
//
{
    map<string, Link*>::iterator it;

    for (auto const& x : inBound) {
        delete x.second;
    }
#ifdef MAP
    cout << "Appel au destructeur de <File>" << endl;
#endif
} //----- Fin de ~File


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

