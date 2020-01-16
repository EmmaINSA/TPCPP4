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
#include <set>
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


//------------------------------------------------- Surcharge d'opérateurs
    Link & operator = ( const Link & unLink );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator == (const Link& unLink)const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator < (const Link& unLink)const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Link ( const Link & unLink );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Link (File* lOrigin,File* lTarget );
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
    set<Request> myRequests;
    int numOFRequests;
    File* target;
    File* origin;

};

//-------------------------------- Autres définitions dépendantes de <Link>

#endif // LINK_H

