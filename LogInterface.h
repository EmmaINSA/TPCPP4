/*************************************************************************
                           LogInterface  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- LogInterface de la classe <LogInterface> (fichier LogInterface.h) ----------------
#if ! defined ( LogInterface_H )
#define LogInterface_H

//--------------------------------------------------- Interfaces utilisees
using namespace std;
#include <string>
#include "Reader.h"
#include <set>
#include <map>
#include "File.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct StringPointerCompare
        {
    bool operator()(const string* l, const string* r) const
    {
        return (*l) < (*r);
    }
};

struct FileHitsCompare {
    bool operator()(const File* l, const File* r) const
    {
        return (*l).getHits() > (*r).getHits();
    }
};
//------------------------------------------------------------------------
// Role de la classe <LogInterface>
//
//
//------------------------------------------------------------------------

class LogInterface
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Methodes publiques
        // type Methode ( liste des parametres );
        // Mode d'emploi :
        //
        // Contrat :
        //

    bool ReadFile();

    //------------------------------------------------- Surcharge d'operateurs
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
    //----------------------------------------------------- Methodes protegees

    //----------------------------------------------------- Attributs proteges
    Reader* myFileReader;
    map<string*, File*, StringPointerCompare> myFiles;
};

//-------------------------------- Autres definitions dependantes de <LogInterface>

#endif // LogInterface_H

