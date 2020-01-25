#include <iostream>
#include <regex>
#include <vector>

#include "Test.h"

//#define MAP

using namespace std;

int main(int argc, char** argv)
{

    //Test::anonymeIntranet();

    string domain("http://intranet-if.insa-lyon.fr");
    string manual("ANALOG\t\t\t\tApache log analysis\t\t\t\t\tANALOG\n"
                  "\n"
                  "NAME\n"
                  "\tanalog - an analysis tool for Apache logs\n"
                  "\n"
                  "SYNOPSIS\n"
                  "\t./analog [-e] [-g dotfile] [-t hour] logfile\n"
                  "\t./analog\n"
                  "\t\t\n"
                  "DESCRIPTION\n"
                  "\tanalog is a tool for analysing Apache logs by reading .log files. As long as the .log file name is provided, it displays the 10 most visited pages according to the logs.\n"
                  "\tIt is possible to narrow down the result to an interval of one hour, and also to exclude images, CSS and JS files from this process.\n"
                  "\tIt can also create a .dot file containing the graph from the analysis previously ran according to the other options.\n"
                  "\t\n"
                  "EXAMPLES\n"
                  "\t./analog\n"
                  "\t\tDisplays the user manual (what you are reading right now)\n"
                  "\t\n"
                  "\t./analog file.log\n"
                  "\t\tDisplays the ten most visited pages according to the logs in the given file, if existing.\n"
                  "\t\n"
                  "\t./analog -e file.log\n"
                  "\t\tDisplays the ten most visited pages that are not images, CSS or JS files, according to the logs in the given file, if existing.\n"
                  "\t\t\n"
                  "\t./analog -t 13\n"
                  "\t\tDisplays the ten most visited pages between 13:00 (included) and 14:00 (excluded) according to the logs in the given file, if existing.\n"
                  "\t\n"
                  "\t./analog -t 13:45\n"
                  "\t\tDisplays the ten most visited pages between 13:45 (included) and 14:45 (excluded) according to the logs in the given file, if existing.\n"
                  "\t\t\n"
                  "\t./analog -g graph.dot file.log\n"
                  "\t\tDisplays the ten most visited pages that are not images, CSS or JS files, according to the logs in the given file, if existing. Then creates the graph.dot file containing the graph that the application previously created.\n"
                  "\t\t\n"
                  "OPTIONS\n"
                  "\tDuplicated options are not harmful as long as they are correctly written. If they require an argument, each occurrence will override the previous one.\n"
                  "\t\n"
                  "\t-e\n"
                  "\t\tExclude images, CSS and JS files from processing.\n"
                  "\t\t\n"
                  "\t-t hour\n"
                  "\t\tTake into account only hits that are between hour (included) and hour+1 (excluded). Format for hour can be either an integer between 0 and 23 included, or written as hh:mm between 00:00 and 23:59 (the first digit can be omitted if 0). In this case too, only hits that happened between this time and an hour after will be taken into account. However, if this time is more than 23:00, only hits until 23:59 included will be taken into account.\n"
                  "\t\t\n"
                  "\t-g file\n"
                  "\t\tGenerates a .dot file bearing the given file name according to the data processed by the application. This only takes into account hits that were not excluded by other options. If a file with the same name as the one given already exists, it will be overwritten.\n"
                  "\t\t\n"
                  "\t\t\t\n"
                  "1.0\t\t\t\t\t\t2020-01-21\t\t\t\t\tANALOG");

    enum {emode, gmode, tmode};
    bool modes[3] = {false, false, false};

    // file names with spaces and/or weird characters not accepted, but file paths are accepted
    string filenameRegex("[a-zA-Z0-9_./]{1,255}");
    regex hourMinRegex("([0-1]?[0-9]|2[0-3]){1}:[0-5][0-9]");
    regex hourRegex("[0-1]?[0-9]|2[0-3]");
    string h23("23");
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
        cout << manual << endl;
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
#ifndef MAP
        return 1;
#endif
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
                if(regex_match(*(itArg+1), hourMinRegex) || regex_match(*(itArg+1), hourRegex))  // correct hour format
                {
#ifdef MAP
                    cerr << "Correct hour format" << endl;
#endif
                    modes[tmode] = true;
                    beginTime = *(itArg+1);

                    if (beginTime.length() < 3)     // hour only
                    {
                        beginTime += ":00";
                    }

                    if (beginTime.length() == 4)   // 0 missing at the beginning of the string
                    {
                        beginTime = string("0").append(endTime);
#ifdef MAP
                        cerr << "Adding 0 to beginTime" << endl;
#endif
                    }

                    if (beginTime.substr(0,2) == h23)
                    {
                        endTime = string("24:00");
                    }else {
                        // end time as a string
                        endTime = to_string((stoi(beginTime.substr(0, 2)) + 1) % 24)
                                  + beginTime.substr(2, 3);

                        if (endTime.length() == 4)   // 0 missing at the beginning of the string
                        {
                            endTime = string("0").append(endTime);
#ifdef MAP
                            cerr << "Adding 0 to endTime" << endl;
#endif
                        }
                    }

#ifdef MAP
                    cerr << "Begin time : " << beginTime << endl;
                    cerr << "End time : " << endTime << endl;
#endif

                    ++itArg; // do not process next argv since it has already been used for -t

                }else{
                    cerr << "Error : Incorrect hour format." << endl;
                    cerr << "Please provide an hour as an integer between 0 and 23 or in the hh:mm format." << endl;
#ifndef MAP
                    return 1;
#endif
                }
            }else{

                cerr << "Error : No argument provided for -t option." << endl;
                cerr << "Please provide an hour as an integer between 0 and 23 or in the hh:mm format." << endl;
#ifndef MAP
                return 1;
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
                    dotFile = *(itArg + 1);
                    modes[gmode] = true;

                    ++itArg; // do not process next argv since it has already been used for -g
                }else{
                    cerr << "Error : Incorrect .dot file name." << endl;
#ifndef MAP
                    return 1;
#endif
                }
            }else{
                cerr << "Error : No argument provided for -g option." << endl;
                cerr << "Please provide a .dot file name for the output file." << endl;
#ifndef MAP
                return 1;
#endif
            }
        }else{
            cerr << "Error : Unrecognized syntax : '" << *itArg << "'." << endl;
            cerr << "Please refer to the user manual for help." << endl;
#ifndef MAP
            return 1;
#endif
        }
    }

    // read log file & create associated structures according to execution parameters
    LogInterface log(logFile, domain);

    if (modes[emode])
    {
        cout << "Images, CSS and JS files ignored" << endl;
    }

    // search between given t and t+1 excluded
    if (modes[tmode])
    {
        cout << "Hits between " << beginTime << " and " << endTime << " taken into account" << endl;
        log.ReadFile(modes[emode], beginTime, endTime);
    }else{
        log.ReadFile(modes[emode]);
    }

    if (modes[gmode])
    {
        log.DrawGraph(dotFile);
        cout << endl << "Dot file " << dotFile << " successfully generated" << endl;
    }

    return 0;
}