#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream text("Wild-Wild-West.txt");
    string mot;
    map<string, int> map;
    bool enable = false;

    char NoChara[7] = {'?', ')', '(', ',', '.', '"'};

    while (text >> mot) {
        ++map[mot];
    }
    
    for (std::map<string, int>::iterator it = map.begin(); it != map.end(); ++it) {
        enable = true;
        for (int i = 0; i < it->first.length(); i++) {
            for (int y = 0; y < 6; y++) {
                if (it->first[i] == NoChara[y]) {
                    enable = false;
                }
            }
        }
        if (enable) {
            cout << "le nombre d'occurence du mot |" << it->first << "| est : " << it->second << endl;
        }
    }

    return 0;
}