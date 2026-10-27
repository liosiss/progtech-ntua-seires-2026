#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using Road = pair<int, int>;

bool findPath(
    const vector<vector<Road>> &graph,
    int currentCity,
    int targetCity,
    int tankCapacity,
    vector<bool> &seen,
    vector<int> &route,
    int &refuels,
    int currentFuel
) {
    if (seen[currentCity]) {
        return false;
    }

    seen[currentCity] = true;

    if (currentCity == targetCity) {
        return true;
    }

    for (const auto &road : graph[currentCity]) {
        int nextCity = road.first;
        int fuelNeeded = road.second;

        if (fuelNeeded > tankCapacity) {
            continue;
        }

        route.push_back(nextCity);

        int fuelAfterTrip = currentFuel - fuelNeeded;
        bool usedRefuel = false;

        if (fuelAfterTrip < 0) {
            usedRefuel = true;
            refuels++;

            fuelAfterTrip = tankCapacity - fuelNeeded;
        }

        if (findPath(
                graph,
                nextCity,
                targetCity,
                tankCapacity,
                seen,
                route,
                refuels,
                fuelAfterTrip
            )) {
            return true;
        }

        route.pop_back();

        if (usedRefuel) {
            refuels--;
        }
    }

    return false;
}

void solveQuery(
    const vector<vector<Road>> &graph,
    int startCity,
    int endCity,
    int tankCapacity,
    int totalCities
) {
    if (startCity == endCity) {
        cout << "POSSIBLE: 0 fill(s), " << startCity << "\n";
        return;
    }

    vector<bool> seen(totalCities, false);
    vector<int> route = {startCity};

    int refuels = 1;

    bool possible = findPath(
        graph,
        startCity,
        endCity,
        tankCapacity,
        seen,
        route,
        refuels,
        tankCapacity
    );

    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << "POSSIBLE: " << refuels << " fill(s),";

    for (int city : route) {
        cout << " " << city;
    }

    cout << "\n";
}

int main() {
    int totalCities, totalRoads;
    cin >> totalCities >> totalRoads;

    vector<vector<Road>> graph(totalCities);

    int cityA, cityB, fuelCost;

    for (int i = 0; i < totalRoads; ++i) {
        cin >> cityA >> cityB >> fuelCost;

        graph[cityA].push_back({cityB, fuelCost});
        graph[cityB].push_back({cityA, fuelCost});
    }

    int queries;
    cin >> queries;

    int startCity, endCity, tankCapacity;

    for (int i = 0; i < queries; ++i) {
        cin >> startCity >> endCity >> tankCapacity;

        solveQuery(
            graph,
            startCity,
            endCity,
            tankCapacity,
            totalCities
        );
    }

    return 0;
}