#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream input("input1.txt");
    string instruction;
    int amount; 

    int horizontal = 0, depth = 0;
    while(input >> instruction >> amount) {
        if (instruction == "forward")
            horizontal += amount;
        else if (instruction == "up")
            depth -= amount;
        else if (instruction == "down")
            depth += amount;
    }
    
    cout << horizontal * depth << endl;

    return 0;
}
