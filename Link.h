/*************************************************************************
                           Link  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Link> (fichier Link.h) ----------------
#if ! defined ( LINK_H )
#define LINK_H

//--------------------------------------------------- Interfaces utilisées
class File;
#include <list>
#include <string>
#include "Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Link>
//
//
//------------------------------------------------------------------------

class Link
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool AddRequest(const string*& timeStamp, const string*& ip, const string*& webBrowser);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Link ( const Link & unLink );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Link ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Link ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    list<Request> myRequests;
    int numOFRequests;

};

//-------------------------------- Autres définitions dépendantes de <Link>

#endif // LINK_H

