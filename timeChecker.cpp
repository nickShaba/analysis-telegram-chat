#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define FILENAME "result.json"

using namespace std;

void checkMessage(ifstream &file, string &line, unordered_map<int, int> &freqMap)
{
    while(getline(file, line))
    {
        if(line.find("\"date\"") != string::npos)
        {
            int pos = line.find('T');
            if(pos != string::npos)
            {
                int hour = stoi(string(line, pos+1, 2));
                freqMap[hour]++;
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

    unordered_map<int, int> freqMap;

    while(getline(file, line))
    {
        if(line.find("\"date\"") != string::npos)
        {
            checkMessage(file, line, freqMap);
        }
    }

    vector<pair<int, int>> v(freqMap.begin(), freqMap.end());

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    int total = 0;
    for(const auto& e : v)
    {
        cout  << e.second << endl;
        total += e.second;
    }

    cout << endl << "total: " << total << endl;

    return 0;
}
