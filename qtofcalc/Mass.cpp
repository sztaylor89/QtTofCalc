#include <fstream>
#include <iostream>

#include <cstdlib>

#include "Mass.hpp"
#include "Tokenizer.hpp"

using namespace std;

Mass::Mass() {
    ifstream infile("../qtofcalc/masses.dat");
    Tokenizer t;
    t.SetDelimiter(" ");
    if(!infile) {
        cerr << "Cannot open input file. Try again, son." << endl;
    } else {
        while(infile) {
            string s;
            getline(infile, s);
            t.SetString(s);
            const vector<string> *tokenized = t.GetTokenizedString();
            if(tokenized->size() > 2) {
                masses_.insert(make_pair(make_pair(atoi(tokenized->at(0).c_str()),
                                               atoi(tokenized->at(1).c_str())),
                                         atof(tokenized->at(2).c_str())));
            }

        }
    }
}

double Mass::GetMass(const int &z, const int &a) {
    map<pair<int,int>,double>::iterator found = masses_.find(make_pair(z,a));
    if(found != masses_.end())
        return((*found).second);
    return(0.0);
}
