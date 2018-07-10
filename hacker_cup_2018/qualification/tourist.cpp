#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

struct Place {
    int Position;
    string PlaceName;
    int VisitedTimes;

    Place(int position, string place)
        : Position(position)
        , PlaceName(place)
        , VisitedTimes(0)
    {}

    bool operator< (const Place& other) const {
        return (
            (VisitedTimes < other.VisitedTimes) ||
            (VisitedTimes == other.VisitedTimes && Position < other.Position)
        );
    }
};

bool comparePlaces(const vector<Place> &firstPlaces, const vector<Place> &secondPlaces) {
    for (size_t i = 0; i < firstPlaces.size(); ++i) {
        if (firstPlaces[i].PlaceName != secondPlaces[i].PlaceName) {
            return false;
        }
    }

    return true;
}

bool comparePopularity(const Place &firstPlace, const Place &secondPlace) {
    return firstPlace.Position < secondPlace.Position;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long t, k, n, v;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        cin >> n >> k >> v;
        string place;
        vector<Place> places;

        for (size_t j = 0; j < n; ++j) {
            cin >> place;
            places.emplace_back(j, place);
        }

        vector<vector<Place> > placesShifts{};

        while (true) {
            placesShifts.push_back(places);
            for (size_t i = 0; i < k; ++i) {
                ++places[i].VisitedTimes;
            }

            sort(places.begin(), places.end());
            if (comparePlaces(places, placesShifts.front())) {
                break;
            }
        }

//        cout << placesShifts.size() << endl;
//        for (const auto &v: placesShifts) {
//            for (const auto &p: v) {
//                cout << p.PlaceName << ' ' << p.Position << ' '  << p.VisitedTimes << endl;
//            }
//            cout << endl;
//        }
//        cout << endl;

        int shift = v % placesShifts.size();

        if (shift == 0) {
            shift = placesShifts.size();
        }
        vector<Place> result;

        cout << "Case #" << i + 1 << ": ";
        for (size_t j = 0; j < k; ++j) {
            result.push_back(placesShifts[shift - 1][j]);
        }
        sort(result.begin(), result.end(), comparePopularity);
        for (size_t j = 0; j < k; ++j) {
            cout << result[j].PlaceName << ' ';
        }
        cout << endl;
    }

    return 0;
}
