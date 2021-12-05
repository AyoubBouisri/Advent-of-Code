#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


string findRating(vector<string>list, bool isOxygenGeneratorRating, int currentIndex){

    if (list.size() == 1)
        return list[0];

    vector<string> zeroes;
    vector<string> ones;

    for (auto el : list){
        if (el[currentIndex] == '0')
            zeroes.push_back(el);
        else
            ones.push_back(el);
    }

    if (isOxygenGeneratorRating){
        if (ones.size() >= zeroes.size())
            return findRating(ones, isOxygenGeneratorRating, currentIndex + 1);
        else
            return findRating(zeroes, isOxygenGeneratorRating, currentIndex + 1);
    }else{
        if (ones.size() >= zeroes.size())
            return findRating(zeroes, isOxygenGeneratorRating, currentIndex + 1);
        else
            return findRating(ones, isOxygenGeneratorRating, currentIndex + 1);
    }
};


int main(){

    ifstream input("input.txt");
    string currentBin;

    vector<string>numbers;

    while(input >> currentBin)
        numbers.push_back(currentBin);

    cout << stoi(findRating(numbers, true, 0), 0, 2) * stoi(findRating(numbers, false, 0), 0, 2) << endl;

    return 0;
}
