/*

ligo argo

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct PoI {
    double x;
    double y;
    string category;
};

double distance_between(double x1, double y1,
                        double x2, double y2) {

    double dx = x1 - x2;
    double dy = y1 - y2;

    return sqrt(dx * dx + dy * dy);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<PoI> pois(N);

    for (int i = 0; i < N; ++i) {

        cin >> pois[i].x
            >> pois[i].y
            >> pois[i].category;
    }

    int K;
    cin >> K;

    vector<pair<double,double>> track(K);

    for (int i = 0; i < K; ++i) {

        cin >> track[i].first
            >> track[i].second;
    }

    cout << fixed;

    for (int i = 0; i < K; ++i) {

        double tx = track[i].first;
        double ty = track[i].second;

        // map => αλφαβητική ταξινόμηση
        map<string,double> closest;

        for (const auto& poi : pois) {

            double dist = distance_between(
                tx, ty,
                poi.x, poi.y
            );

            auto it = closest.find(poi.category);

            if (it == closest.end() ||
                dist < it->second) {

                closest[poi.category] = dist;
            }
        }

        cout << setprecision(0)
             << tx << " " << ty << '\n';

        for (const auto& entry : closest) {

            cout << "  "
                 << entry.first
                 << " "
                 << setprecision(3)
                 << entry.second
                 << '\n';
        }
    }

    return 0;
}