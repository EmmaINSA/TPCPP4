/*************************************************************************
                           Link  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Link> (fichier Link.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Link.h"
#include "File.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Link::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

bool Link::AddRequest(const string*& timeStamp, const string*& ip, const string*& webBrowser)
{
    Request newRequest(timeStamp, ip, webBrowser);

   
    myRequests.push_back(newRequest);
    ++numOFRequests;
    return true;
   
   
}

const File* Link::GetOriginFile() const
{
    return myOriginFile;
}

int Link::GetLinkUses() const
{
    return numOFRequests;
}

//------------------------------------------------- Surcharge d'op�rateurs




//-------------------------------------------- Constructeurs - destructeur




Link::Link(const File* const & origFile)
// Algorithme :
//
{
    numOFRequests = 0;
    myOriginFile = origFile;
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

//----------------------------------------------------- M�thodes prot�g�es




