#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct entry {
    string team1, team2;
    int goal1, goal2, year;
};

bool comp(const pair<int, string> &p1, const pair<int, string> &p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}


int main() {
    int tc;
    cin >> tc;
    int y;
    string t;
    entry game;
    if (tc == 1) {
        cin >> y >> t;
        map <string, pair<int, int>> mpp1; 
        while (cin >> game.year >> game.team1 >> game.team2 >> game.goal1 >> game.goal2) {
            if (game.team1 != t || game.year != y) continue;
            mpp1[game.team2] = {game.goal1, game.goal2};
         }
         for (const auto &it : mpp1){
            cout << it.first << " " << it.second.first <<  " " << it.second.second << '\n';
         }
    }
    else if (tc == 2) {
        cin >> t;
        map<int, vector<int>> mpp2;
        vector<int> help(3, 0);
        while (cin >> game.year >> game.team1 >> game.team2 >> game.goal1 >> game.goal2) {
            if (game.team1 == t) {
                if(mpp2[game.year].empty()) mpp2[game.year] = help;
                mpp2[game.year][0]++;
                mpp2[game.year][1] += game.goal1;
                mpp2[game.year][2] += game.goal2;
            }
            else if (game.team2 == t) {
                if(mpp2[game.year].empty()) mpp2[game.year] = help;
                mpp2[game.year][0]++;
                mpp2[game.year][1] += game.goal2;
                mpp2[game.year][2] += game.goal1;
            }
        }
        for (const auto &it : mpp2) {
            cout << it.first << " " << it.second[0] << " " << it.second[1] << " " << it.second[2] << '\n';
        }
    }
    else if (tc == 3){
        vector<int> help(11, 0);
        vector<int> help2(4, 0);
        map<string, vector<int>> gwld;
        map<string, vector<int>> gprc;
        while (cin >> game.year >> game.team1 >> game.team2 >> game.goal1 >> game.goal2) {
            if (gprc[game.team1].empty()) {
                gprc[game.team1] = help;
                gwld[game.team1] = help2;
            }
            if (gprc[game.team2].empty()) {
                gprc[game.team2] = help;
                gwld[game.team2] = help2;
            }


            gwld[game.team1][0]++;
            gwld[game.team2][0]++;
            if (game.goal1 > game.goal2) {
                gwld[game.team1][1]++;
                gwld[game.team2][3]++;
            }  
            else if (game.goal1 < game.goal2) {
                gwld[game.team1][3]++;
                gwld[game.team2][1]++;
            }
            else if (game.goal1 == game.goal2){
                gwld[game.team1][2]++;
                gwld[game.team2][2]++;
            }


            gprc[game.team1][game.goal1]++;
            gprc[game.team2][game.goal2]++;
        }
        
        for (const auto &it : gwld){
            int div = it.second[0] ;
            cout << it.first << " " << fixed << setprecision(2) << it.second[1]*100.0 / div << " " << it.second[2]*100.0 / div << " " << it.second[3]*100.0 / div << '\n'; 
            for (int i = 0; i < 11; ++i) {
                if (gprc[it.first][i] == 0) continue;
                cout << "- " << i << " " << gprc[it.first][i]*100.0 / div << '\n';
            }
        }
    }
    else if (tc == 4) {
        cin >> y;
        map<string, int> mpp4;
        while (cin >> game.year >> game.team1 >> game.team2 >> game.goal1 >> game.goal2) {
            if (game.year != y) continue;
            if (game.goal1 > game.goal2) mpp4[game.team1] += 3;
            else if (game.goal1 < game.goal2) mpp4[game.team2] += 3;
            else {
                mpp4[game.team1]++;
                mpp4[game.team2]++;
            }
        }
        vector<pair<int, string>> vec;
        for (const auto &it : mpp4){
            vec.emplace_back(it.second, it.first);
        }
        
        sort(vec.begin(), vec.end(), comp);

        for (const auto &it : vec) {
            cout << it.second << " " << it.first << '\n';
        }
    }
    return 0;
}