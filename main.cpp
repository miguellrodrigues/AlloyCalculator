#include "Alloy.h"

using namespace std;

bool parse(const string &str, unsigned int *out) {
    try {
        *out = stoi(str);
        return true;
    } catch (exception &e) {
        return false;
    }
}

bool stringEquals(const string &a, const string &b) {
    return equal(a.begin(), a.end(), b.begin(),
                 [](char a, char b) {
                     return tolower(a) == tolower(b);
                 });
}

int main() {
    string ligas[] = {"Bronze de Bismuto",
                      "Bronze Corintio",
                      "Bronze",
                      "Latao",
                      "Ouro Rosa",
                      "Prata de Lei",
                      "Aco Negro",
                      "Aco Azul",
                      "Aco Vermelho"
    };

    vector<Alloy> alloys;

    for (const string &name : ligas) {
        Alloy all;

        all.name = name;

        alloys.emplace_back(all);
    }

    unsigned int counter = 0;

    for (auto &alloy : alloys) {
        if (counter == 0) {
            alloy.addMaterial("Cobre", "50/65");
            alloy.addMaterial("Bismutinita", "10/20");
            alloy.addMaterial("Zinco", "20/30");

            alloy.addMineralName("Cobre", "Cobre");
            alloy.addMineralName("Bismutinita", "Bismutinita");
            alloy.addMineralName("Zinco", "Esfarelita");
        } else if (counter == 1) {
            alloy.addMaterial("Cobre", "50/70");
            alloy.addMaterial("Ouro", "10/25");
            alloy.addMaterial("Prata", "10/25");

            alloy.addMineralName("Cobre", "Cobre");
            alloy.addMineralName("Ouro", "Ouro");
            alloy.addMineralName("Prata", "Tetraedita");
        } else if (counter == 2) {
            alloy.addMaterial("Cobre", "88/92");
            alloy.addMaterial("Estanho", "8/12");

            alloy.addMineralName("Cobre", "Cobre");
            alloy.addMineralName("Estanho", "Cassiterita");
        } else if (counter == 3) {
            alloy.addMaterial("Cobre", "88/92");
            alloy.addMaterial("Zinco", "8/12");

            alloy.addMineralName("Cobre", "Cobre");
            alloy.addMineralName("Zinco", "Esfalerita");
        } else if (counter == 4) {
            alloy.addMaterial("Cobre", "15/30");
            alloy.addMaterial("Ouro", "70/85");

            alloy.addMineralName("Cobre", "Cobre");
            alloy.addMineralName("Ouro", "Ouro");
        } else if (counter == 5) {
            alloy.addMaterial("Cobre", "20/40");
            alloy.addMaterial("Prata", "60/80");

            alloy.addMineralName("Cobre", "Cobre");
            alloy.addMineralName("Prata", "Tetraedita");
        } else if (counter == 6) {
            alloy.addMaterial("Aco", "50/70");
            alloy.addMaterial("Nickel", "15/25");
            alloy.addMaterial("Bronze Corintio", "15/25");

            alloy.addMineralName("Nickel", "Garnierita");
        } else if (counter == 7) {
            alloy.addMaterial("Aco Negro", "50/55");
            alloy.addMaterial("Bronze de Bismuto", "10/15");
            alloy.addMaterial("Prata", "10/15");
            alloy.addMaterial("Aco", "20/25");

            alloy.addMineralName("Prata", "Tetraedita");
        } else if (counter == 8) {
            alloy.addMaterial("Aco Negro", "50/55");
            alloy.addMaterial("Ouro Rosa", "10/15");
            alloy.addMaterial("Latao", "10/15");
            alloy.addMaterial("Aco", "20/25");
        }

        counter++;
    }

    unsigned int act = 1;

    string selectedName;

    do {
        printf("\n\nEscolha uma liga: \n");

        for (auto &alloy : alloys) {
            printf("\n %s", alloy.name.c_str());
        }

        printf("\n\n");

        getline(cin, selectedName);

        bool exist = false;

        for (auto &alloy : ligas) {
            if (stringEquals(alloy, selectedName)) {
                exist = true;
            }
        }

        while (!exist) {
            printf("\nLiga invalida, escolha uma liga valida: \n");
            getline(cin, selectedName);

            for (auto &alloy : ligas) {
                if (stringEquals(alloy, selectedName))
                    exist = true;
            }
        }

        Alloy selected;
        for (auto &alloy : alloys) {
            if (stringEquals(alloy.name, selectedName))
                selected = alloy;
        }

        for (size_t i = 0; i < 100; ++i) {
            printf("\n");
        }

        printf("\n%s - Materiais\n", selected.name.c_str());

        vector<string> mat = selected.getMaterialsName();

        for (auto const &material: mat) {
            printf("\n%s", material.c_str());
        }

        printf("\n");

        unsigned int ingots;
        string pars;

        printf("\nQuantas barras voce deseja fazer ? ->  ");
        getline(cin, pars);

        while (!parse(pars, &ingots)) {
            printf("\nQuantas barras voce deseja fazer ? ->  ");
            getline(cin, pars);
        }

        ingots *= 100;

        int length = mat.size();

        unsigned int percent[length];

        bool stop = false;

        for (int i = 0; i < length; ++i) {
            string s = selected.materials[mat[i]];

            vector<string> sp = Alloy::split(s, '/');

            unsigned int x[2];

            x[0] = stoi(sp[0]);
            x[1] = stoi(sp[1]);

            switch (i) {
                case 1:
                    if (length == 3) {
                        unsigned int oldX = percent[i - 1];

                        if ((100 - oldX) % 2 == 0) {
                            percent[1] = (100 - oldX) / 2;
                            percent[2] = percent[1];

                            stop = true;

                            break;
                        }

                        if (100 - oldX < 50) {
                            if (100 - oldX >= 40) {
                                x[0] = (100 - oldX) - stoi(Alloy::split(selected.materials[mat[i + 1]], '/')[1]);
                            } else {
                                percent[i] =
                                        (100 - oldX) - stoi(Alloy::split(selected.materials[mat[i + 1]], '/')[0]);
                                continue;
                            }

                        }
                    }
                    break;

                case 2:
                    if (length == 4) {
                        unsigned int sum = (100 - (percent[i - 1]) + 100 - (percent[i - 2]));

                        if (sum <= 50 && sum >= 40) {
                            percent[2] = sum - 25;
                            percent[3] = 25;

                            stop = true;

                            break;
                        }
                    }
                    break;

                default:
                    break;
            }

            if (stop) break;

            if (i == (length - 1)) {
                unsigned int total = 0;

                for (int j = 1; j < mat.size(); j++) {
                    total += percent[j - 1];
                }

                percent[i] = 100 - total;

                break;
            }

            printf("\nQuanto voce ira usar de %s ?\n\n", mat[i].c_str());

            printf("De: %d por cento A %d por cento ->  ", x[0], x[1]);
            getline(cin, pars);

            while (!parse(pars, &percent[i])) {
                printf("De: %d por cento A %d por cento ->  ", x[0], x[1]);
                getline(cin, pars);
            }

            while (percent[i] < x[0] || percent[i] > x[1]) {
                printf("\n");
                printf("Por favor, respeite os limites - De: %d por cento A %d por cento ->  ", x[0], x[1]);

                getline(cin, pars);

                while (!parse(pars, &percent[i])) {
                    printf("Por favor, respeite os limites - De: %d por cento A %d por cento ->  ", x[0], x[1]);
                    getline(cin, pars);
                }
            }
        }

        for (size_t i = 0; i < 100; ++i) {
            printf("\n");
        }

        double materials[length];

        for (size_t i = 0; i < length; ++i) {
            materials[i] = ingots * (percent[i] / 100.0);
        }

        for (size_t i = 0; i < length; i++) {
            printf("\nTotal a ser adicionado de %s: %.3lf Unidades", mat[i].c_str(), materials[i]);
        }

        printf("\n");

        for (size_t i = 0; i < length; ++i) {
            string name = mat[i];

            if (name.find("Aco") != string::npos || name.find("Bronze") != string::npos ||
                name.find("Rosa") != string::npos || name.find("Latao") != string::npos) {

                printf("\nBarra`s de %s %.3lf Unidade`s", name.c_str(), materials[i] / 100.0);

                printf("\n");
            } else {
                int values[] = {35, 25, 15, 10};

                int qtd[4];

                string mnames[] = {"rico", "normal", "pobre", "pepita", "nugget"};

                double value = materials[i];

                for (int z = 0; z < 4; z++) {
                    qtd[z] = (int) (value / values[z]);
                    value -= (double) (qtd[z] * values[z]);
                }

                for (int z = 0; z < 4; z++) {
                    printf("\nMinerio de %s %s %d Unidade`s", selected.mineralName(name).c_str(), mnames[z].c_str(),
                           qtd[z]);
                }

                printf("\n");
            }
        }

        printf("\nDeseja realizar um novo calculo? 1 (Sim) | 2 (Nao)\n");

        getline(cin, pars);

        while (!parse(pars, &act)) {
            printf("\n1 (Sim) | 2 (Nao)");
            getline(cin, pars);
        }

        for (size_t i = 0; i < 100; ++i) {
            printf("\n");
        }

    } while (act == 1);

    printf("\n");

    printf("\n");
    printf("\n");
    printf("\nEscrito por: Miguel L. Rodrigues");
    printf("\n");

    system("pause");

    return 0;
}
