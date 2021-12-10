#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#define LOG(vector) for (auto el : vector) cout << el << " "; cout << endl;

using namespace std;

vector<string> split(string& str){
    vector<string> result;

    string delimiter = " ";

    string::size_type start = 0;
    string::size_type end = 0;

    while((end = str.find(delimiter, start)) != string::npos){
        string substr = str.substr(start , end - start);
        result.push_back((substr));
        start = end + 1;
    }

    result.push_back((str.substr(start)));

    return result;
}

int main(){
    ifstream input("input.txt");
    string line;

    vector<int>numbers = {2,4,3,7};
    int result = 0;

    while(getline(input, line)){
        line = line.substr(line.find("|") + 2);
        vector<string> signals = split(line);

        LOG(signals)
        for (string str : signals){
            if (find(numbers.begin(), numbers.end(), str.size()) != numbers.end())
                result++;
        }
    }

    cout << result;

    return 0;
}
