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

    void addMineralName(const string &metal, string mineral);

    string mineralName(const string &key);

    vector<string> getMaterialsName();

    static vector<string> split(const string &str, char delimiter);

    map<string, string> materials;

private:
    map<string, string> linked;
};

#endif //ALLOYC_ALLOY_H
