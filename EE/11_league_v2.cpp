#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

struct game { 
    int year;
    string team1, team2;
    int goals1, goals2;
};

int main() {
    int tc;
    cin >> tc;
    int a, d, e, ytc; //year, goals1, goals2
    string b, c, ttc; // team1, team2


    if (tc == 1) {
        cin >> ytc >> ttc;
        map<string, pair<int, int>> mpp1;

        while (cin >> a >> b >> c >> d >> e) {
            if (ytc == a && ttc == b) {
                mpp1[c] = {d, e};
            }
        }

        for (const auto &it : mpp1) {
            cout << it.first << " " << it.second.first << " " << it.second.second << '\n';
        }
    }
    else if (tc == 2) {
        cin >> ttc;

        struct gg {
            int tg = 0;
            int gm = 0;
            int gc = 0;
        };
        map<int, gg> mpp2; 

        while (cin >> a >> b >> c >> d >> e) {
            if (ttc == b) {
                mpp2[a].tg ++;
                mpp2[a].gm += d;
                mpp2[a].gc += e;
            }
            else if (ttc == c) {
                mpp2[a].tg ++;
                mpp2[a].gm += e;
                mpp2[a].gc += d;
            }
        }

        for (const auto &it : mpp2) {
            cout << it.first << " " << it.second.tg << " " << it.second.gm << " " << it.second.gc << '\n';
         }
    }
    else if (tc == 3) {
        struct prc {
           int tg = 0;
           int wins = 0;
           int losses = 0;
           int draws = 0;
           int total_goals = 0;
           map<int, int> goals;
        };
        map<string, prc> mpp3;
        while (cin >> a >> b >> c >> d >> e) {
            
            mpp3[b].tg ++;
            mpp3[c].tg ++;
            
            mpp3[b].total_goals += d;
            mpp3[c].total_goals += e;
            
            if (d > e) {
                mpp3[b].wins ++;
                mpp3[c].losses ++;
            }
            else if (d < e) {
                mpp3[b].losses ++;
                mpp3[c].wins ++;
            }
            else {
                mpp3[b].draws ++;
                mpp3[c].draws ++;
            }

            
            mpp3[b].goals[d] ++;
            mpp3[c].goals[e] ++;
        }

        for (const auto &it : mpp3) {
            int div = it.second.tg;
            cout << it.first << " " << fixed << setprecision(2) << it.second.wins *100.0 / div << " " 
            << it.second.draws*100.0 / div << " " << it.second.losses*100.0 / div << '\n';
            for (const auto &it2 : it.second.goals) {
                if(it.second.tg== 0 ) break;
                cout << "- " << it2.first << " " << it2.second*100.0 / it.second.tg << '\n';
            }
            }
        }
        /*
        prepei nma ftiajw auto to testcase<==============
        */
        else if (tc == 4) {
            cin >> ytc;
            map<string, int> mpp4;

             while (cin >> a >> b >> c >> d >> e) {
                if (ytc != a) continue;
                if (d > e) mpp4[b] += 3;
                else if (d < e) mpp4[c] += 3;
                else {
                    mpp4[b] ++;
                    mpp4[c] ++;
                }

                vector<pair<string, int>> vec4;
                for (const auto &it : mpp4) {
                    vec4.emplace_back(it.first, it.second);
                }

                sort(vec4.begin(), vec4.end(), [](const pair<string, int> &p1,const pair<string, int> &p2) {
                    if (p1.second != p2.second) return p1.second > p2.second;
                    return p1.first < p2.first;
                });

                for (const auto &it : vec4) {
                    cout << it.first << " " << it.second << '\n';
                }

             }
        }

        return 0;

    }


    

  