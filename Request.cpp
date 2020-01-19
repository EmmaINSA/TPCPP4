/*************************************************************************
                           Request  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Request.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Request::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

const string& Request::GetTimeStamp() const
{
    return *timeStamp;
}

bool Request::operator==(const Request& unRequest) const
{
	return timeStamp==unRequest.timeStamp;
}

bool Request::operator<(const Request& unRequest) const
{
	return timeStamp<unRequest.timeStamp;
}


//-------------------------------------------- Constructeurs - destructeur



Request::Request(const Request& unRequest)
{
    timeStamp = unRequest.timeStamp;
    ip = unRequest.ip;
    webBrowser = unRequest.webBrowser;
}

Request::Request (const string*& mTime, const string*& mIp, const string*& mBrowser)
// Algorithme :
//
{
    timeStamp = mTime;
    ip = mIp;
    webBrowser = mBrowser;
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif
} //----- Fin de Request


Request::~Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Request>" << endl;
#endif
} //----- Fin de ~Request


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

