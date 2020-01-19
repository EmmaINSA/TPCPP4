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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct StringPointerCompare
{
    bool operator()(const std::string* l, const std::string* r) const
    {
        return (*l) < (*r);
    }
};
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
    int GetHits()const;

    int GetID()const;

    const string& MyName()const;

    bool AddInbound(const File* const & origin, const string*& ip, const string*& webBrowser,const string*& timeStamp);


    const map<const std::string*, Link*,StringPointerCompare>& GetInbounds()const ;
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

    File (const string* myLabel);
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
    int myId;
    int nbHits;
    map<const std::string*,Link*,StringPointerCompare> inBound;
};

//-------------------------------- Autres définitions dépendantes de <File>

#endif // FILE_H

