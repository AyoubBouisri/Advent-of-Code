#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define LOG(vector) for (auto el : vector) cout << el << " "; cout << endl; 

using namespace std;

vector<int> split(string& str ){
    vector<int> result;

    string delimiter = ",";

    string::size_type start = 0, end = 0;

    while( (end = str.find(delimiter, start)) != string::npos ){
        string substr = str.substr(start, end - start);
        result.push_back(stoi(substr));
        start = end + 1;
    }

    result.push_back(stoi(str.substr(start)));

    return result;
}

int findMedian(vector<int>& list){
    sort(list.begin(), list.end());
    return list[list.size() / 2];
}

void solvePart1(vector<int>list ){
    int median = findMedian(list);

    long long sumFuel = 0;
    for (int el : list)
        sumFuel += max(el, median) - min(el, median);

    cout << sumFuel << endl;
}

int getScore(int fuel){
    return fuel * (fuel + 1) / 2;
}

void solvePart2(vector<int>list){
     // brute force it
     int bestScore = INT_MAX;
     int maxValue = *max_element(list.begin(), list.end());
     for (int i = 0; i <= maxValue ;i++){
         int score = 0;
         for (int el : list){
             score += getScore(abs(el - i));
         }

         if (score < bestScore){
             bestScore = score;
         }

     }

     cout << bestScore << endl;
}

int main(){

    ifstream input("input.txt");

    string line; 
    getline(input, line);
    vector<int> list = split(line);

    solvePart2(list);

    return 0;

}
