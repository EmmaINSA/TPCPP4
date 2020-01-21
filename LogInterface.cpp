/*************************************************************************
                           LogInterface  -  description
                             -------------------
    debut                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Realisation de la classe <LogInterface> (fichier LogInterface.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "LogInterface.h"
#include "File.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type LogInterface::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode
bool LogInterface::ReadFile(bool removeExtraFiles, const string& startTime, const string& endTime)
{
    if (!myFileReader->Available())
    {
        cerr << "Cannot read : FILE DOES NOT EXIST!" << endl;
        return false;
    }

    set<string> extraExtensions;
    if(removeExtraFiles){
    extraExtensions.insert(".png");
    extraExtensions.insert(".jpg");
    extraExtensions.insert(".bmp");
    extraExtensions.insert(".gif");
    extraExtensions.insert(".css");
    extraExtensions.insert(".ico");
    extraExtensions.insert(".js");
    }

    bool readRequest;

    std::cout << "Starting to read file" << endl;
    RequestData* data;
    while ((data = myFileReader->GetRequest()) != nullptr)
    {
        readRequest = true;
        string oldS = data->destination;

        if (removeExtraFiles &&
        extraExtensions.find(myFileReader->GetFileExtension(data->destination))!=extraExtensions.end())
        {
            readRequest = false;
        }

        if (readRequest && startTime != endTime)
        {
            string requestTime = myFileReader->GetTime(data->timeStamp);
            if (requestTime < startTime || requestTime >= endTime)
            {
                readRequest = false;
            }
        }


        if (readRequest)
        {
            myFileReader->ProcessRequest(*data);

            File* rOrigin = addOrGetFile(data->origin);

            File* rTarget = addOrGetFile(data->destination);

            const string* dIp = addOrGetString(data->ip, ipSet);
            const string* dBrowser = addOrGetString(data->browser, browserSet);
            const string* dTimeStamp = addOrGetString(data->timeStamp, timeStampSet);

            rTarget->AddInbound(rOrigin, dIp, dBrowser, dTimeStamp);
        }

        delete data;
    }
    std::cout << "File has been read\n";

    multiset<File*,FileHitsCompare> hitsSet;
    classByHits(hitsSet);
    
    printTop10(hitsSet);
   
    return true;
}

bool LogInterface::DrawGraph(const string& fileLocation)
{
    ofstream outputFile(fileLocation);
    if (outputFile)
    {

        stringstream ss;
        ss << "digraph {" << endl;

        for (auto const& x : myFiles)
        {
            ss << "node" << x.second->GetID() << " [label=\"" << x.second->MyName() << "\"];" << endl;
        }

        for (auto const& dest : myFiles)
        {
            for (auto const& orig : dest.second->GetInbounds())
            {
                ss << "node" << orig.second->GetOriginFile()->GetID() << " -> node" << dest.second->GetID() << " [label=\"" << orig.second->GetLinkUses() << "\"];" << endl;
            }
        }
        ss << "}";

        outputFile << ss.rdbuf();
        outputFile.close();
        return true;
    }
    cerr << "Can not write file" << endl;
    outputFile.close();
    return false;
}


//------------------------------------------------- Surcharge d'operateurs



//-------------------------------------------- Constructeurs - destructeur

LogInterface::LogInterface(const string& fileName, const string& domain)
// Algorithme :
//
{
    myFileReader = new Reader(fileName, domain);
#ifdef MAP
    cout << "Appel au constructeur de <LogInterface>" << endl;
#endif
} //----- Fin de LogInterface


LogInterface::~LogInterface()
// Algorithme :
//
{
    delete myFileReader;
    for (auto const& x : myFiles)
    {
        delete x.first;
        delete x.second;
    }

    for (auto const& x : ipSet)
    {
        delete x;
    }
    for (auto const& x : browserSet)
    {
        delete x;
    }
    for (auto const& x : timeStampSet)
    {
        delete x;
    }

#ifdef MAP
    cout << "Appel au destructeur de <LogInterface>" << endl;
#endif
} //----- Fin de ~LogInterface

File* LogInterface::addOrGetFile(const string& fileName)
{
    File* rFile;
    auto fileNamePos = myFiles.find(&fileName);

    if (fileNamePos == myFiles.end())
    {
        string* nString = new string(fileName);
        rFile = new File(nString);
        myFiles[nString] = rFile;
    }
    else {
        rFile = fileNamePos->second;
    }
    return rFile;
}

void LogInterface::classByHits(multiset<File*, FileHitsCompare>& hitsSet) const
{
    for (auto const& x : myFiles)
    {
        File* rX = x.second;
        hitsSet.insert(rX);
    }
}

void LogInterface::printTop10(multiset<File*, FileHitsCompare>& hitsSet) const
{
    cout << endl << "============= TOP 10 MOST VISITED PAGES ===========" << endl;
    int i = 0;
    for (auto const& x : hitsSet)
    {
        i++;
        cout << x->MyName() << "    (" << x->GetHits() << " hits)" << endl;
        if (i >= 10)
        {
            break;
        }
    }
}

const std::string* LogInterface::addOrGetString(const string& stringName, set<const std::string*,
        StringPointerCompare>& theSet) const
{
    const string* nString;
    auto strPos = theSet.find(&stringName);

    if (strPos == theSet.end()) {
        nString = new string(stringName);
        theSet.insert(nString);
    }
    else {
        nString = (*strPos);
    }
    
    return nString;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

