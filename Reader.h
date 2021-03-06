/*************************************************************************
                           Reader  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Reader> (fichier Reader.h) ----------------
#if ! defined ( Reader_H )
#define Reader_H

//--------------------------------------------------- Interfaces utilisées
#include <sstream>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct RequestData
{
    string ip;
    string timeStamp;
    string origin;
    string destination;
    string browser;
};

//------------------------------------------------------------------------
// Rôle de la classe <Reader>
//
//
//------------------------------------------------------------------------

class Reader
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    RequestData* GetRequest();

    void ProcessRequest(RequestData& data)const;

    string GetTime(const string& timeStamp)const;

    const string GetFileExtension(const string& fileName)const;

    bool Available()const;

//------------------------------------------------- Surcharge d'opérateurs
    Reader & operator = ( const Reader & unReader );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Reader ( const Reader & unReader );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Reader (const string& fileToRead, const string& iDomain = "" );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Reader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    string readSubStrTo(char del);
    string readSubStrTo(int distance);
    void jumpTo(char del);
    void jumpTo(int distance);
//----------------------------------------------------- Attributs protégés
string internalDomain;
string myFileString;
bool hasInternalDomain;
size_t readHeadLocation;
};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif // Reader_H

