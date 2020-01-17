/*************************************************************************
                           LogInterface  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- LogInterface de la classe <LogInterface> (fichier LogInterface.h) ----------------
#if ! defined ( LogInterface_H )
#define LogInterface_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include "Reader.h"
#include <set>
#include <map>
#include "File.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct StringPointerCompare {
    bool operator()(const string* l, const string* r)const {
        return (*l) < (*r);
    }
};

struct FileHitsCompare {
    bool operator()(const File* l, const File* r)const {
        return (*l).getHits() > (*r).getHits();
    }
};
//------------------------------------------------------------------------
// Rôle de la classe <LogInterface>
//
//
//------------------------------------------------------------------------

class LogInterface
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste des paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //

    bool ReadFile();

    //------------------------------------------------- Surcharge d'opérateurs
    LogInterface& operator = (const LogInterface& unLogInterface);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogInterface(const LogInterface& unLogInterface);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogInterface(const string& fileName,const string& domain = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogInterface();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Reader* myFileReader;
    map<string*, File*, StringPointerCompare> myFiles;
};

//-------------------------------- Autres définitions dépendantes de <LogInterface>

#endif // LogInterface_H

