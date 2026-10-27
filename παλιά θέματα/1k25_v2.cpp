#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int main() {
    ifstream F("geoip.txt");
    if(!F.is_open()) {
        cerr << "the file didn't open!" ;
        return 1;
    }

    map<string, string> ip;
    string ip_adress, country;
    while(F >> ip_adress >> country) {
        if (ip.find(ip_adress) != ip.end()) continue;
        ip[ip_adress] = country;
    }

    F.close();

    map<string, map<string, int>> log_services;
    map<string, int> total_logs;
    string service;
    while(cin >> ip_adress >> service) {
        if(ip.find(ip_adress) == ip.end()) {
            total_logs["Unknown"] ++;
            log_services["Unknown"][service]++;
        }
        else {
            string h = ip[ip_adress];
            total_logs[h]++;
            log_services[h][service]++;
        }
    }

    for (const auto &it : log_services) {
        cout << it.first << " " << total_logs[it.first];
        for (const auto &it2 : it.second) {
            cout << " " << it2.first << " " << it2.second;
        }
        cout << endl;
    }

    return 0;
}
