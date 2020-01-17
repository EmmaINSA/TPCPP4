/*************************************************************************
                           File  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <File> (fichier File.h) ----------------
#if ! defined ( FILE_H )
#define FILE_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include "Link.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <File>
//
//
//------------------------------------------------------------------------

class File
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int getHits()const;

    const string& MyName()const;

    bool AddInbound(const File* origin, const string& ip, const string& webBrowser,const string& timeStamp);

//------------------------------------------------- Surcharge d'opérateurs
    bool operator < (const File& unFile) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator == (const File& unFile) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    File& operator = (const File& unFile);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    File ( const File & unFile );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    File (const string* myLabel, const string& myType);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~File ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const string* label;
    string fileType;
    int myId;
    int nbHits;
    map<string,Link*> inBound;
};

//-------------------------------- Autres définitions dépendantes de <File>

#endif // FILE_H

