#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define FILENAME "result.json"

using namespace std;

void checkMessage(ifstream &file, string &line, unordered_map<string, int> &freqMap)
{
    while(getline(file, line))
    {
        if(line.find("\"date\"") != string::npos)
        {
            int pos = line.find('T');
            if(pos != string::npos)
            {
                freqMap[string(line, pos-5, 2)]++;
            }
        }
    }
}

int main()
{
    ifstream file(FILENAME);

    string line;

    for(int i = 0; i < 5; i++)
        getline(file, line);

    unordered_map<string, int> freqMap;

    while(getline(file, line))
    {
        if(line.find("\"date\"") != string::npos)
        {
            checkMessage(file, line, freqMap);
        }
    }

    vector<pair<string, int>> v(freqMap.begin(), freqMap.end());

    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return stoi(a.first) < stoi(b.first);
    });

    int total = 0;
    for(const auto& e : v)
    {
        cout << e.second << endl;
        total += e.second;
    }

    cout << endl << "total: " << total << endl;

    return 0;
}
