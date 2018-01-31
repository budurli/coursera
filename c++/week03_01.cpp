#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    vector<int> numbers;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {   
        int next_number;
        cin >> next_number;
        numbers.push_back(next_number);
    }

    sort(begin(numbers), end(numbers), [](int x, int y){ return abs(x) < abs(y);});
    for (int& i : numbers){
        cout << i << " ";
    }

    return 0;
}