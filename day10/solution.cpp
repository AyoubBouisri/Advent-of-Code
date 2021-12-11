#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    ifstream input("input.txt");
    string line;

    unordered_map<string, pair<string,int>> ptMap= {
        {")", {"(", 3}},
        {"]", {"[", 57}},
        {"}", {"{", 1197}},
        {">", {"<", 25137}},
    };

    unordered_map<string, string> reverseMap = {
        {"(" , ")"},
        {"{", "}"},
        {"[", "]"},
        {"<", ">"},
    };

    unordered_map<string, int> score= {
        {")", 1},
        {"]", 2},
        {"}", 3},
        {">", 4}
    };
    
    vector<long long>results;
    while(getline(input, line)){
        vector<string>inputVec;
        for (int i = 0; i < line.size(); i++)
            inputVec.push_back(line.substr(i, 1));

        stack<string>q;
        bool broken = false;
        for (string c : inputVec){
            if (ptMap.find(c) == ptMap.end()){
                q.push(c);
            }else{
                string lastEl = q.top();
                if (lastEl != ptMap.find(c)->second.first){
                    broken = true;
                }else
                    q.pop();
            }
        }



        if (!broken){
            long long r = 0;
            while(!q.empty()){
                r =  5 * r + score.find(reverseMap.find(q.top())->second)->second;
                q.pop();
            }
            results.push_back(r);
        }
    }

    sort(results.begin(), results.end());

    cout << results.size() << endl;
    cout << results[results.size() / 2] << endl;

    return 0;
}
