#include <iostream>
#include <regex>

#define MAP

using namespace std;

int main(int argc, char** argv) {

    regex filenameRegex("[a-z0-9_.]{1,255}.log");

    string temp;    // a virer

    if (argc < 2)
    {
#ifdef MAP
        cerr << "man-like user manual : not written yet" << endl;
#endif
    }
    else if(argc == 2)          // juste nom du fichier
    {
        temp = string(argv[1]);
        if (regex_match(temp, filenameRegex))
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