#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    int Q, i;
    string stop;
    map<vector<string>, int> bus_stops;
    cin >> Q; 
    for (Q; Q > 0; Q--) {
        vector<string> v;
        cin >> i;
        for (int z = 0; z < i; z++) {
            cin >> stop;
            v.push_back(stop);
        }

        if (bus_stops.find(v) != bus_stops.end()) {
            cout << "Already exists for " << bus_stops[v] << endl;
        }
        else {
            const int r = bus_stops.size();
            bus_stops[v] = r + 1;
            cout << "New bus " << bus_stops[v] << endl;
        }
    }
    return 0;
}