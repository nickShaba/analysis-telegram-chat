#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>

//change values here
#define FILENAME "result.json"
#define MIN_LENGTH 5
#define MAX_LENGTH 20
#define TOTAL_WORDS 50

using namespace std;

void checkMessage(ifstream &file, string &line, unordered_map<string, int> &freqMap)
{
    while(getline(file, line))
    {
        if(line.find("\"text\"") != string::npos)
        {
            stringstream ss(line.substr(line.find(":") + 3, line.size() - line.find(":") - 5));
            string word;
            while(ss >> word)
            {
                word.erase(remove_if(word.begin(), word.end(), [](char c){ return ispunct(c); }), word.end());
                if(!word.empty())
                    freqMap[word]++;
            }
            return;
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

    int i = 0;
    while(getline(file, line))
    {
        if(line.find("\"id\"") != string::npos)
            checkMessage(file, line, freqMap);
    }

    vector<pair<string, int>> v(freqMap.begin(), freqMap.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    int j = 0;
    for(const auto& e : v)
    {
        if(e.first.size()/2 >= MIN_LENGTH && e.first.size()/2 < MAX_LENGTH)
        {
            if(j++ >= TOTAL_WORDS) break;
            cout << e.second << " -> " << e.first << endl;
        }
    }

    return 0;
}
