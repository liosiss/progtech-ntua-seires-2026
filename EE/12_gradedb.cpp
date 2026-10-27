#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

int main () {
    int problem;
    cin >> problem;

    struct info {
        int year, grade;
        string course, student;
    };

    info d;
    int y;
    string subject, n;

    if (problem == 1) {
        map<string, int> mpp1;
        cin >> y >> subject;
        while(cin >> d.year >> d.course >> d.student >> d.grade) {
            if (d.year == y && d.course == subject) mpp1[d.student] = d.grade; 
        }

        for (const auto &it : mpp1) {
            cout << it.first << " " << it.second << endl;
        }
    }
    
    else if (problem == 2){
        cin >> subject;
        map<int, vector<int>> mpp2;
        while(cin >> d.year >> d.course >> d.student >> d.grade) {
            if (d.course == subject) mpp2[d.year].push_back(d.grade);
        }
        for (auto it1 = mpp2.begin(); it1 != mpp2.end(); ++it1) {
            int sum = 0;
            for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) sum += *it2;
            cout << fixed << setprecision(2) << it1->first << " " << it1->second.size() << " " << sum*1.0 / it1->second.size() << endl;
        }
    }
   
    else if (problem == 3) {
        map<string, multiset<int>> mpp3;
        map<string, int> passed;
        while(cin >> d.year >> d.course >> d.student >> d.grade) {
            mpp3[d.course].insert(d.grade);
            if (d.grade >= 5) passed[d.course]++;
        }
        for (auto it = mpp3.begin(); it != mpp3.end(); ++it){
            cout << it->first << " " << fixed << setprecision(2) << passed[it->first]*100.0 / it->second.size() << endl;
            int times;
            for (int i = 0; i < 11; ++i) {
                times = it->second.count(i);
                if (times > 0) {
                    cout << "- " << i << " " << fixed << setprecision(2) << times*100.0 / it->second.size() << endl;
                }
            }
        }
    } 
   
    else if (problem == 4) {
        cin >> n;
        map<string, pair<int, int>> mpp4;
        while(cin >> d.year >> d.course >> d.student >> d.grade) {
            if (d.student == n) {
                auto it = mpp4.find(d.course);
                if (it == mpp4.end() || it->second.first < d.year) mpp4[d.course] = {d.year, d.grade};
            }
        }

        for (const auto &it : mpp4) {
            cout << it.first << " " << it.second.first << " " << it.second.second << endl;
        }
    }

    return 0;
}

