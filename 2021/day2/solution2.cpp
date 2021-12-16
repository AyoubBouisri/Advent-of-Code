#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream input("input1.txt");
    string instruction;
    int amount; 

    int horizontal = 0, depth = 0, aim = 0;
    while(input >> instruction >> amount) {
        if (instruction == "forward"){
            horizontal += amount;
            depth += aim * amount;
        }
        else if (instruction == "up")
            aim -= amount;
        else if (instruction == "down")
            aim += amount;
    }
    
    cout << horizontal * depth << endl;

    return 0;
}
