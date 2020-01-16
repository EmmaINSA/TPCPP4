/*************************************************************************
                           LogInterface  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogInterface> (fichier LogInterface.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogInterface.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogInterface::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
LogInterface& LogInterface::operator = (const LogInterface& unLogInterface)
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogInterface::LogInterface(const LogInterface& unLogInterface)
// Algorithme :
//
{
    myFileReader = nullptr;
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogInterface>" << endl;
#endif
} //----- Fin de LogInterface (constructeur de copie)


LogInterface::LogInterface(string fileName)
// Algorithme :
//
{
    myFileReader = new Reader(fileName);
#ifdef MAP
    cout << "Appel au constructeur de <LogInterface>" << endl;
#endif
} //----- Fin de LogInterface


LogInterface::~LogInterface()
// Algorithme :
//
{
    delete myFileReader;
#ifdef MAP
    cout << "Appel au destructeur de <LogInterface>" << endl;
#endif
} //----- Fin de ~LogInterface


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

