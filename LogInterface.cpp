/*************************************************************************
                           LogInterface  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Realisation de la classe <LogInterface> (fichier LogInterface.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogInterface.h"
#include "File.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type LogInterface::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
bool LogInterface::ReadFile()
{
    cout << "Starting FIle read" << endl;
    RequestData* data;
    while ((data = myFileReader->GetRequest()) != nullptr)
    {
        
        myFileReader->ProcessRequest(*data);
        

        
        File* rOrigin;
        File* rTarget;

        auto originNamePos = myFiles.find(&data->origin);
        auto targetNamePos = myFiles.find(&data->destination);

        if (originNamePos == myFiles.end())
        {
            string* nString = new string(data->origin);
            rOrigin = new File(nString, "");
            myFiles[nString] = rOrigin;
        } else {
            rOrigin = originNamePos->second;
        }

        if (targetNamePos == myFiles.end())
        {
            string* nString = new string(data->destination);
            rTarget = new File(nString, "");
            myFiles[nString] = rTarget;
        } else {
            rTarget = targetNamePos->second;
        }
       

        rTarget->AddInbound(rOrigin, data->ip, data->browser, data->timeStamp);
        

        delete data;
    }
    cout << "fileread\n";

    multiset<File*,FileHitsCompare> hitsSet;

    for (auto const& x : myFiles)
    {
        File* rX = x.second;
        hitsSet.insert(rX);
    }

    int i = 0;
    for (auto const& x : hitsSet)
    {
        i++;
        cout << x->MyName() << " " << x->getHits()<<endl;
        if (i >= 10)
        {
            break;
        }
    }
    return true;
}


//------------------------------------------------- Surcharge d'op�rateurs



//-------------------------------------------- Constructeurs - destructeur





LogInterface::LogInterface(const string& fileName, const string& domain)
// Algorithme :
//
{
    myFileReader = new Reader(fileName,domain);
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

//----------------------------------------------------- M�thodes prot�g�es

