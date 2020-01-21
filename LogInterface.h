/*************************************************************************
                           LogInterface  -  description
                             -------------------
    debut                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- LogInterface de la classe <LogInterface> (fichier LogInterface.h) ----------------
#if ! defined ( LogInterface_H )
#define LogInterface_H

//--------------------------------------------------- Interfaces utilisees
#include <string>
#include "Reader.h"
#include <set>
#include <map>
#include "File.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


struct FileHitsCompare {

    bool operator()(const File* l, const File* r) const
    {
        return (*l).GetHits() > (*r).GetHits();
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

    bool ReadFile(bool removeExtraFiles = false, const string& startTime = "", const string& endTime = "");

    bool DrawGraph(const string& fileLocation);

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

    LogInterface(const string& fileName, const string& domain = "");
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
    File* addOrGetFile(const string& fileName);

    void classByHits(multiset<File*, FileHitsCompare>& hitsSet) const;

    void printTop10(multiset<File*, FileHitsCompare>& hitsSet) const;

    const std::string* addOrGetString(const string& stringName,
            set<const std::string*, StringPointerCompare>& theSet) const;

    //----------------------------------------------------- Attributs proteges
    Reader* myFileReader;
    map<const std::string*, File*, StringPointerCompare> myFiles;
    set<const std::string*, StringPointerCompare> ipSet;
    set<const std::string*, StringPointerCompare> timeStampSet;
    set<const std::string*, StringPointerCompare> browserSet;
};

//-------------------------------- Autres definitions dependantes de <LogInterface>

#endif // LogInterface_H

