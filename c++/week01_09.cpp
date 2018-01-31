#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(int argc, char const *argv[])
{
    int n;
    vector<bool> result;
    cin >> n;

    while (n > 1) {
        result.push_back(n % 2);
        n /= 2;
    }

    result.push_back(1);

    std::reverse(result.begin(), result.end());


    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
    }
    return 0;
}