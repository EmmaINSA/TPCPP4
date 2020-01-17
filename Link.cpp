/*************************************************************************
                           Link  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Link> (fichier Link.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Link.h"
#include "File.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Link::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Link::AddRequest(const string& timeStamp, const string& ip, const string& webBrowser)
{
    Request newRequest(timeStamp, ip, webBrowser);

   
    myRequests.push_back(newRequest);
    ++numOFRequests;
    return true;
   
   
}

//------------------------------------------------- Surcharge d'opérateurs




//-------------------------------------------- Constructeurs - destructeur




Link::Link()
// Algorithme :
//
{
    numOFRequests = 0;
    
#ifdef MAP
    cout << "Appel au constructeur de <Link>" << endl;
#endif
} //----- Fin de Link


Link::~Link()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Link>" << endl;
#endif
} //----- Fin de ~Link


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées




