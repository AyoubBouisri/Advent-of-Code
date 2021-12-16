#include <fstream>
#include <vector>
#include <iostream>

#define LOG(map) for (auto row : map) {cout << endl; for (auto el : row) cout << el << " ";};

using namespace std;

vector<pair<int, int>> getN(const vector<vector<int>>& map, int x, int y){
    // only get neighbours who have not flashed yet
    vector<pair<int, int>> n;
    for (int h = -1; h < 2; h++){
        for(int v = -1; v < 2; v++){
            if ( h != 0 || v != 0 ){
                int newX = x + h, newY = y + v;
                if (newX >= 0 && newX < map[0].size() && newY >= 0 && newY < map.size()){
                    if (map[newX][newY] <= 9)
                        n.push_back({newX, newY});
                }
            }
        }
    }

    return n;
}

void increment(vector<vector<int>>&map, int x, int y){
    if (map[x][y] == 10){
        auto ns = getN(map, x, y);
        for (auto n : ns){
            map[n.first][n.second]++;
            increment(map, n.first, n.second);
        }
        map[x][y]++;
    }
}

int main(){
    ifstream input("input.txt");
    string line;
    vector<vector<int>> map;
    while (getline(input, line)){
        vector<int> v;
        for (int i = 0; i < line.size(); i++){
            v.push_back(stoi(line.substr(i, 1)));
        }
        map.push_back(v);
    }

    int step = 1;
    while(true){
        // increment all
        for (auto &row : map)
            for ( auto &el : row )
                el++;

        // increment by fish 
        for (int i = 0;i < map[0].size(); i++){
            for (int j = 0; j < map.size(); j++){
                increment(map, i, j);
            }
        }

        // flash
        int flashed = 0;
        for (auto& row : map)
            for (auto& el : row)
                if (el > 9){
                    flashed++;
                    el = 0;

                }
        if (flashed == map[0].size() * map.size())
            break;

        step++;
    }

    cout << step;
            
    return 0;
}
