#include <iostream>
#include <fstream>
#include <map>

using namespace std;

struct connections {
    int total;
    map<string, int> whc;
};


int main() {
    ifstream file ("geoip.txt", fstream::in);
    map<string, string> mpp1;
    string id, country;
    while(cin >> id >> country) {
        mpp1[id] = country;
    }
    file.close();

    string service;
    map<string, connections> mpp2;
    while(cin >> id >> service) {
        if (mpp1.find(id) == mpp1.end()) {
            if(mpp2.find("Unknown") == mpp2.end()) {
                mpp2["Unknown"].total = 1;
                mpp2["Unknown"].whc[service] = 1;
            }
            mpp2["Unknown"].total++;
            if(mpp2["Unknown"].whc.find(service) == mpp2["Unknown"].whc.end())  mpp2["Unknown"].whc[service] = 1;
            else mpp2["Unknown"].whc[service]++;
    }
    else {
        string c = mpp1[id];
        if(mpp2.find(c) == mpp2.end()){
            mpp2[c].total = 1;
            mpp2[c].whc[service] = 1;
        }
        mpp2[c].total++;
        if(mpp2[c].whc.find(service) == mpp2[c].whc.end())  mpp2[c].whc[service] = 1;
        else mpp2[c].whc[service]++;

    }
}


for(const auto &it : mpp2) {
    cout << it.first << " " << it.second.total;
    for(const auto &it2 : it.second.whc) {
        cout << " " << it2.first << " " << it2.second;
    }
    cout << endl;
}



return 0;
}