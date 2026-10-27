#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


int main () {
    int k;
    cin >> k;
    map<string, vector<int>> mpp;
    string a, b;
    int c;
    while(cin >> a >> b >> c){ 
        if (c > 0 && c <= 100) mpp[a].push_back(c);
    }
    multimap<int, string> mpp2;
    for (const auto &it : mpp) {
        int cnt = 0;
        for (const auto &it2 : it.second) {
            cnt += it2;
        }
        if (!it.second.empty()){
            mpp2.insert({cnt / it.second.size(), it.first});
        }
    }
    int cnt_diff = 0;
    for (auto itt = mpp2.rbegin(); itt != mpp2.rend(); itt++){
        cnt_diff++;
        if (cnt_diff > k) break;
        cout << itt->second << " " << itt->first << endl; 
    }
    return 0;
}



