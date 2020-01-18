#include <iostream>
#include <regex>
#include <vector>

#include "Test.h"

#define MAP

using namespace std;

int main(int argc, char** argv)
{

    testAnonyme();

    // file names with spaces and/or weird characters not accepted
    string filenameRegex("[a-zA-Z0-9_.]{1,255}");
    regex logfilenameRegex(filenameRegex+ "\\.log");
    regex dotfilenameRegex(filenameRegex+"\\.dot");
    string temp;
    vector<string> argvs;

    string eMode("-e");
    string gMode("-g");
    string tMode("-t");

    if (argc < 2) // no argument given
    {
#ifdef MAP
        cerr << "man-like user manual : not written yet" << endl;
#endif
    }else{

        for (int i = 1; i < argc; ++i)
        {
            argvs.emplace_back(argv[i]);    // build a string object directly at the right place in the vector
#ifdef MAP
            cout << i << " : " << argvs.at(i - 1) << endl;
#endif
        }

        // check if log file name (last argv) is correct
        if (regex_match(argvs.at(argc - 2), logfilenameRegex))
        {
#ifdef MAP
            cerr << "Correct file name" << endl;
#endif
        }else{
            cerr << "Incorrect file name for .log file" << endl;
            return -1;
        }

        // chech other arguments

        vector<string>::iterator itArg;

        for (itArg = argvs.begin(); itArg != --(argvs.end()); ++itArg)
        {
            if (*itArg == eMode)
            {
#ifdef MAP
                cerr << "-e mode activated" << endl;
#endif
            }
            else if (*itArg == tMode)
            {
                if (itArg < (argvs.end()) - 2) // still space for hour & log file name
                {
                    //if
                }
            }
        }
    }

}