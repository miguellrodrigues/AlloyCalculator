/*

*  **
*  * Created by Miguel on 18/09/2020.
*  **

*/

#ifndef ALLOYC_ALLOY_H
#define ALLOYC_ALLOY_H

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Alloy {

public:
    string name;

    void addMaterial(const string &name, string data);

    void addMineralName(const string& metal, string mineral);

    string getMaterials();

    string mineralName(const string& key);

    vector<string> getMaterialsName();

    vector<string> split(const string &str, char delim);

    map<string, string> correspondente;

    map<string, string> materials;
};

#endif //ALLOYC_ALLOY_H
