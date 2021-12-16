#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ifstream input("input.txt");
    string currentBin;
    input >> currentBin;

    int len = currentBin.size(), totalNumbers = 0;
    vector<int> binarySum(len, 0);

    do{
        for (int i = 0; i < len; i++)
            if (currentBin[i] == '1')
                binarySum[i]++;

        totalNumbers++;
    }while(input >> currentBin);
    

    string gamma, epsilon;
    for(int i = 0;i < len; i++){
        if (binarySum[i] >= totalNumbers / 2){
            gamma += '1';
            epsilon += '0';
        }else{
            gamma += '0';
            epsilon += '1';
        }
    }

    int result = stoi(gamma, 0, 2) * stoi(epsilon, 0, 2);
    cout << result << endl;
    return 0;
}
