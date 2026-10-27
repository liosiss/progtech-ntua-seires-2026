#include <iostream>
#include <string>
#include <set>
#include <map>
#include <array>
#include <iomanip>
using namespace std;

struct my_comparator {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first.length() < b.first.length(); 
    }
};



int main () {
    int tc;
    cin >> tc;
    struct match {
        int date, g1, g2;
        string team1, team2;
    };

    match m;
    string t;
    int y;
    if (tc == 1){
        cin >> y >> t;
        map<string, pair<int, int>> mpp1;    // <===== maybe this needs to be a multimap<====
        while (cin >> m.date >> m.team1 >> m.team2 >> m.g1 >> m.g2) {
            if (m.team1 == t) mpp1[m.team2] = {m.g1, m.g2};
        }
        for(const auto &it : mpp1) {
            cout << it.first << " " << it.second.first << " " << it.second.second << endl;
        }
    }
    else if (tc == 2) {
        cin >> t;
        map<int ,int> games;
        map<int ,pair<int, int>> goals;
        while (cin >> m.date >> m.team1 >> m.team2 >> m.g1 >> m.g2) {
            if (m.team1 == t) {
                games[m.date]++;
                goals[m.date].first += m.g1;
                goals[m.date].second += m.g2;
            }
            else if (m.team2 ==t) {
                games[m.date]++;
                goals[m.date].first += m.g2;
                goals[m.date].second += m.g1;
            }
    }

    for (const auto &it : games) {
        cout << it.first << " " << it.second <<  " " << goals[it.first].first << " " << goals[it.first].second << endl;
    }
}
else if (tc == 3) {
    map<string, pair< array<int, 3>, array<int, 8> >> mpp3;
    while (cin >> m.date >> m.team1 >> m.team2 >> m.g1 >> m.g2) {
   
        mpp3[m.team1].first[0]++;
        mpp3[m.team2].first[0]++;
      
        if (m.g1 > m.g2) {
            mpp3[m.team1].first[1]++;
            mpp3[m.team2].first[3]++;
        }
        else if (m.g2 > m.g1) {
            mpp3[m.team1].first[3]++;
            mpp3[m.team2].first[1]++;
        }
        else {
            mpp3[m.team1].first[2]++;
            mpp3[m.team2].first[2]++;
        }
        mpp3[m.team1].second[0] += m.g1;
         mpp3[m.team2].second[0] += m.g2;
        mpp3[m.team1].second[m.g1 + 1]++;
        mpp3[m.team2].second[m.g2 + 1]++;
    }

    for (const auto &it : mpp3) {
        cout << it.first;
        int div1 = it.second.first[0];
        int div2 = it.second.second[0];
        for (int i = 0; i < 3; ++i) {
            if (it.second.first[i] != 0) cout << fixed << setprecision(2) << " " <<it.second.first[i] / div1;
        }
        cout << endl;
        for (int i = 1; i < 9; ++i) {
            if (it.second.second[i] != 0) cout << fixed << setprecision(2) << "- " << it.second.second[i] / div2 << endl;
        }
    }


}
else if (tc == 4) {
    cin >> y;
    map<string, int> mpp4;
    while (cin >> m.date >> m.team1 >> m.team2 >> m.g1 >> m.g2) {
        if (y == m.date) {
            if (m.g1 > m.g2) mpp4[m.team1] += 3;
            else if (m.g2 > m.g1) mpp4[m.team2] += 3;
            else {
                mpp4[m.team1]++;
                mpp4[m.team2]++;
            }
        }
    }
    set<pair<string, int>, my_comparator> st;
    for (const auto &it : mpp4) {
        st.insert({it.first, it.second});
    }
    
    for(const auto &it : st) {
        cout << it.first << " " << it.second << endl;
    }
}
return 0;
}