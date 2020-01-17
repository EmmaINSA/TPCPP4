#include <iostream>
#include <regex>
#include <vector>

#include "Test.h"

#define MAP

using namespace std;

int main(int argc, char** argv)
{

    Test::anonymeIntranet();

    // file names with spaces and/or weird characters not accepted
    regex logfilenameRegex("[a-zA-Z0-9_.]{1,255}\\.log");
    string temp;
    vector<string> argvs;

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
            cerr << "Incorrect file name" << endl;
            return -1;
        }

    }

}