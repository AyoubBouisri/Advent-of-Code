#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sumWindow(vector<int>&measurements, int index, int windowDepth){
    int sum = 0;
    for (int i = 0; i < windowDepth; i++)
        sum += measurements[index + i];
    cout << sum << endl;
    return sum;
}

int main(){
    int currentDepth;
    int windowDepth = 3;
    vector<int> measurements = {};
    ifstream input("input1.txt");
    
    while(input >> currentDepth)
        measurements.push_back(currentDepth);
    
    int increased = 0;
    for (int i = 0; i < measurements.size() - (windowDepth); i++)
        if (sumWindow(measurements, i + 1, windowDepth) > sumWindow(measurements, i, windowDepth))
            increased++;

    cout << increased << endl;

    return 0;
}
