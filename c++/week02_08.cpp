#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, mean=0;
    cin >> n;
    vector<int> numbers(n), indexes;
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
        mean += numbers[i];
    }
    
    mean = mean / n;    
    n = 0;

    for (int i = 0; i < numbers.size(); ++i){

        if (numbers[i] > mean){
            n++;
            indexes.push_back(i);

        }
    }
    
    cout << n << endl;
    
    for (int i : indexes){
        cout << i << " ";
    }
    return 0;
}