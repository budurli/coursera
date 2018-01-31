#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v){
    vector<int> result;

    for (int i = v.size() - 1; i >= 0; --i)
    {   
        result.push_back(v[i]);
    }

    v = result;

}