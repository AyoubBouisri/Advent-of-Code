#include <iostream>
#include <fstream>

using namespace std;
int main(){
    int previousDepth, currentDepth;
    int increased = 0;
    ifstream input("input1.txt");
    
    input >> previousDepth;
    
    while(input >> currentDepth){
        if (currentDepth > previousDepth)
            increased++;
        previousDepth = currentDepth;
    }
    
    cout << increased << endl;

    return 0;
}
