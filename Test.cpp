/*************************************************************************
                           Test  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Test> (fichier Test.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Test.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Test::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void testAnonyme()
{
    Reader test("anonyme.log","http://intranet-if.insa-lyon.fr");

    RequestData* data;

    while ((data = test.GetRequest()) != nullptr) {
        cout << data->ip << " " << data->timeStamp << " " << data->destination << " " << data->origin << " " << data->browser << endl;
        delete data;
    }
    cout << "fileread\n";
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

