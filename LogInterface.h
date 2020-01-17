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

//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <LogInterface>
//
//
//------------------------------------------------------------------------

class LogInterface
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
        // type M�thode ( liste des param�tres );
        // Mode d'emploi :
        //
        // Contrat :
        //

    bool ReadFile();

    //------------------------------------------------- Surcharge d'op�rateurs
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
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s
    Reader* myFileReader;
    map<string*, File*, StringPointerCompare> myFiles;
};

//-------------------------------- Autres d�finitions d�pendantes de <LogInterface>

#endif // LogInterface_H

