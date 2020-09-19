/*

*  **
*  * Created by Miguel on 18/09/2020.
*  **

*/

#include "Alloy.h"

#include "string"
#include "vector"
#include "sstream"

using namespace std;

vector<string> Alloy::split(const string &str, char delim) {
    std::stringstream ss(str);
    string tok;
    vector<string> vec;
    while (getline(ss, tok, delim)) {
        if (!tok.empty())
            vec.push_back(tok);
    }
    return vec;
}

void Alloy::addMaterial(const string& materialName, string data) {
    materials[materialName] = move(data);
}

string Alloy::getMaterials() {
    string back;

    for (auto const &entry: materials) {
        vector<string> qtd = split(materials[entry.first], '/');

        back += entry.first + ": de " + qtd[0] + "% A " + qtd[1] + "% \n";
    }

    return back;
}

vector<string> Alloy::getMaterialsName() {
    vector<string> back;

    for (auto const &entry: materials) {
        back.push_back(entry.first);
    }

    return back;
}

string Alloy::mineralName(const string& key) {
    return correspondente[key];
}

void Alloy::addMineralName(const string& metal, string mineral) {
    correspondente[metal] = move(mineral);
}
