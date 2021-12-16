#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <numeric>

#define LOG(vector) for (auto el : vector) cout << el << " "; cout << endl;

using namespace std;

vector<int> split(string& str){
    vector<int> result;

    string delimiter = ",";

    string::size_type start = 0;
    string::size_type end = 0;

    while((end = str.find(delimiter, start)) != string::npos){
        string substr = str.substr(start , end - start);
        result.push_back(stoi(substr));
        start = end + 1;
    }

    result.push_back(stoi(str.substr(start)));

    return result;

}

int main(){

    int nbDays;
    cin >> nbDays;

    ifstream input("input.txt");

    const int childDays = 7;

    string currentLine;
    getline(input, currentLine);
    vector<int> lanternFish = split(currentLine);
    vector<long long> map(9, 0);

    for (auto fish : lanternFish){
        map[fish] += 1;
    }
    
    // Each day shift the number of fish to the left
    for (int day = 0; day < nbDays; day++){
        for (int i = 0; i < map.size() - 1; i++ ){
            swap(map[i], map[i + 1]);
        }
        map[6] += map[map.size() - 1];
    }


    // calculate numebr of fish
    long long sum = 0;
    for (auto el : map)
        sum += el;
    
    cout << sum << endl;

    return 0;
}
