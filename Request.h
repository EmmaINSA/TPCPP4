/*************************************************************************
                           Request  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Request> (fichier Request.h) ----------------
#if ! defined ( REQUEST_H )
#define REQUEST_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//
//
//------------------------------------------------------------------------

class Request
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const string& GetTimeStamp()const;

//------------------------------------------------- Surcharge d'opérateurs
    Request & operator = ( const Request & unRequest );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator == (const Request& unRequest)const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator < (const Request& unRequest)const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Request ( const Request & unRequest );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Request (const string*& mTime,const string*& mIp,const string*& mBrowser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const string* timeStamp;
    const string* ip;
    const string* webBrowser;
};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // REQUEST_H

