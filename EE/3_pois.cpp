#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>   
#include <vector>
#include <map>
using namespace std;

double f_distance (const pair<double, double> &p1, const pair<double, double> &p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    int k;
    cin >> k;
    map<pair<double, double>, string> mpp;
    for (int i = 0; i < k; ++i) {
        string place;
        double x, y;
        cin >> x >> y >> place;
        mpp[{x, y}] = place;
    }

    int n;
    cin >> n;
    vector<pair<double, double>> poi(n);
    for (int i = 0; i < n; ++i) {
        cin >> poi[i].first >> poi[i].second;
    }

    
    map<int, map<string, double>> cp;
    for (int i = 0; i < n; ++i) { 
        for (const auto &it : mpp){
            double d = f_distance(poi[i], it.first);
            if ( cp[i].find(it.second) == cp[i].end() || cp[i][it.second] >= d) {
                cp[i][it.second] = d;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(0) <<  poi[i].first << " " << poi[i].second << '\n';
        for (const auto &it : cp[i]) {
            cout << "  " << it.first << " " << fixed << setprecision(3) << it.second << '\n'; 
        }
    }

    return 0;
}