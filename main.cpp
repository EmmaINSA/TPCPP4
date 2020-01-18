#include <iostream>
#include <regex>
#include <vector>
#include <iterator>

#include "Test.h"

#define MAP

using namespace std;

int main(int argc, char** argv)
{

     Test::anonymeIntranet();

    // file names with spaces and/or weird characters not accepted
    string filenameRegex("[a-zA-Z0-9_.]{1,255}");
    regex hourRegex("[0-2]?[0-9]{1}[:h]?[0-5][0-9]");
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
            cerr << "Correct .log file name" << endl;
#endif
        }else{
            cerr << "Error : Incorrect .log file name" << endl;
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


            // read -t <hour>
            else if (*itArg == tMode)
            {
                if (itArg < (argvs.end()) - 2) // still space for hour & log file name
                {
                    if(regex_match(*(itArg+1), hourRegex))
                    {
#ifdef MAP
                        cerr << "Correct hour format" << endl;
#endif
                        ++itArg; // do not process next argv since it has already been used for -t

                    }else{
                        cerr << "Error : Incorrect hour format" << endl;
                    }
                }else{

                    cerr << "Error : no argument provided for -t option.\r\n Please provide an hour in the hh:mm format." << endl;
                }
            }

            // read -g <filename.dot>
            else if (*itArg == gMode)
            {
                if (itArg < (argvs.end()) - 2) // still space for hour & log file name
                {
                    if(regex_match(*(itArg+1), dotfilenameRegex))
                    {
#ifdef MAP
                        cout << "Correct .dot file name" << endl;
#endif
                        ++itArg; // do not process next argv since it has already been used for -g
                    }else{
                        cerr << "Error : Incorrect .dot file name" << endl;
                    }
                }else{
                    cerr << "Error : no argument provided for -g option." << endl;
                    cerr << "Please provide a .dot file name for " << endl;
                }
            }
        }
    }

    return 0;
}