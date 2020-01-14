/*************************************************************************
                           File  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <File> (fichier File.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "File.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type File::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
File & File::operator = ( const File & unFile )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
File::File ( const File & unFile )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <File>" << endl;
#endif
} //----- Fin de File (constructeur de copie)


File::File ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <File>" << endl;
#endif
} //----- Fin de File


File::~File ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <File>" << endl;
#endif
} //----- Fin de ~File


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

