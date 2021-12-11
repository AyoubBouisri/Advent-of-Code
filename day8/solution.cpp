#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define LOG(vector) for (auto el : vector) cout << el << " "; cout << endl;

using namespace std;

vector<string> split(string str){
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

void solvePart1(ifstream& input){
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
}

void solvePart2(ifstream& input){
    // Brute force it by checking every possible permutation 
    // checks out with the input

    unordered_map<string, int> mapping = {
        {"abcefg", 0},
        {"cf", 1},
        {"acdeg", 2},
        {"acdfg", 3},
        {"bcdf", 4},
        {"abdfg", 5},
        {"abdefg", 6},
        {"acf", 7},
        {"abcdefg", 8},
        {"abcdfg", 9}
    };

    string line; 
    while(getline(input, line)){
        string base = "abcdefg";
        do{
           vector<string>inputSignals = split(line.substr(0, line.find(" | ")));
           LOG(inputSignals)
           vector<string>outputSignals = split(line.substr(line.find("|") + 2));
        }while(next_permutation(base.begin(), base.end()));
    }
}

int main(){
    ifstream input("input.txt");
    
//    solvePart1(input);
    solvePart2(input);

    return 0;
}
