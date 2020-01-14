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
#include <istream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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

    string GetRequest();

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

    Reader (string fileToRead );
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

//----------------------------------------------------- Attributs protégés
ifstream* myFile;
};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif // Reader_H

