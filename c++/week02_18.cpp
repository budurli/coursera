#include <iostream>
#include <string>
#include <map>
#include <set>


using namespace std;


int main(int argc, char const *argv[])
{
    map<set<string>, int> stops;

    int n, q;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> q;
        set<string> newStops;
        for (int i = 0; i < q; ++i)
        {
            string stop;
            cin >> stop;
            newStops.insert(stop);
        }

        if (stops.find(newStops) != stops.end()) {
            cout << "Already exists for " << stops[newStops] << endl;
        } else {
            stops[newStops] = stops.size();
            cout << "New bus " << stops.size() << endl;
        }
    }

    return 0;
}