#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

	vector<string> words;
	words.push_back("hello");
	words.push_back("world");
	for (int i = 0; i < words.size(); ++i)
	{
		cout << words[i];
	}

	return 0;
}