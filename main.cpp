#include <iostream>
#include <regex>
#include <vector>
#include <iterator>

#include "Test.h"

#define MAP

using namespace std;

int main(int argc, char** argv)
{

    //Test::anonymeIntranet();

    string domain("http://intranet-if.insa-lyon.fr");

    enum {emode, gmode, tmode};
    bool modes[3] = {false, false, false};

    // file names with spaces and/or weird characters not accepted
    string filenameRegex("[a-zA-Z0-9_.]{1,255}");
    regex hourRegex("([0-1]?[0-9]|2[0-3]){1}:[0-5][0-9]");
    regex logfilenameRegex(filenameRegex+ "\\.log");
    regex dotfilenameRegex(filenameRegex+"\\.dot");
    string temp;
    vector<string> argvs;

    string eMode("-e");
    string gMode("-g");
    string tMode("-t");

    string beginTime, endTime;
    string dotFile, logFile;

    if (argc < 2) // no argument given, print user manual
    {
#ifdef MAP
        cerr << "man-like user manual : not written yet" << endl;
#endif
        return 0;
    }

    // arguments given -> parse them
    for (int i = 1; i < argc; ++i)
    {
        argvs.emplace_back(argv[i]);    // build a string object directly at the right place in the vector
#ifdef MAP
        cout << i << " : " << argvs[i - 1] << endl;
#endif
    }

    // check if log file name (last argv) is correct
    if (regex_match(argvs[argc - 2], logfilenameRegex))
    {
#ifdef MAP
        cerr << "Correct .log file name" << endl;
#endif
        logFile = argvs[argc - 2];
    }else{
        cerr << "Error : Incorrect .log file name." << endl;
        return -1;
    }

    // parse other arguments for options
    vector<string>::iterator itArg;

    for (itArg = argvs.begin(); itArg != --(argvs.end()); ++itArg)
    {
        // read -e
        if (*itArg == eMode)
        {
            modes[emode] = true;
#ifdef MAP
            cerr << "-e mode activated" << endl;
#endif
        }

        // read -t <hour>
        else if (*itArg == tMode)
        {
            if (itArg < (argvs.end()) - 2) // still space for hour & log file name
            {
                if(regex_match(*(itArg+1), hourRegex))  // correct hour format
                {
#ifdef MAP
                    cerr << "Correct hour format" << endl;
#endif
                    modes[tmode] = true;
                    beginTime = *(itArg+1);

                    if (beginTime.length() == 4)   // 0 missing at the beginning of the string
                    {
                        beginTime = "0" + beginTime;
#ifdef MAP
                        cerr << "Adding 0 to beginTime" << endl;
#endif
                    }

                    // end time as a string
                    endTime = to_string((stoi(beginTime.substr(0,2)) + 1) % 24)
                            + beginTime.substr(2,3);

                    if (endTime.length() == 4)   // 0 missing at the beginning of the string
                    {
                        endTime = "0" + endTime;
#ifdef MAP
                        cerr << "Adding 0 to endTime" << endl;
#endif
                    }

#ifdef MAP
                    cerr << "Begin time : " << beginTime << endl;
                    cerr << "End time : " << endTime << endl;
#endif



                    ++itArg; // do not process next argv since it has already been used for -t

                }else{
                    cerr << "Error : Incorrect hour format." << endl;
                    cerr << "Please provide an hour in the hh:mm format." << endl;
#ifndef MAP
                    return -1;
#endif
                }
            }else{

                cerr << "Error : No argument provided for -t option." << endl;
                cerr << "Please provide an hour in the hh:mm format." << endl;
#ifndef MAP
                return -1;
#endif
            }
        }

        // read -g <filename.dot>
        else if (*itArg == gMode)
        {
            if (itArg < (argvs.end()) - 2) // still space for dot & log file names
            {
                if(regex_match(*(itArg+1), dotfilenameRegex))   // correct file name
                {
#ifdef MAP
                    cout << "Correct .dot file name" << endl;
#endif
                    dotFile = *(itArg+1);
                    modes[gmode] = true;

                    ++itArg; // do not process next argv since it has already been used for -g
                }else{
                    cerr << "Error : Incorrect .dot file name." << endl;
#ifndef MAP
                    return -1;
#endif
                }
            }else{
                cerr << "Error : No argument provided for -g option." << endl;
                cerr << "Please provide a .dot file name for the output file." << endl;
#ifndef MAP
                return -1;
#endif
            }
        }else{
            cerr << "Error : Unrecognized syntax : '" << *itArg << "'." << endl;
            cerr << "Please refer to the user manual for help." << endl;
#ifndef MAP
            return -1;
#endif
        }
    }

    // read log file & create associated structures according to execution parameters
    LogInterface log(logFile, domain);

    // search between given t and t+1 excluded
    if (modes[tmode])
    {
        log.ReadFile(modes[emode], beginTime, endTime);
    }else{
        log.ReadFile(modes[emode]);
    }

    if (modes[gmode])
    {
        log.DrawGraph(dotFile);
    }

    return 0;
}