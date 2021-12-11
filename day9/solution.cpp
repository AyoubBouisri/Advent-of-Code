#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<pair<int, int>> findNeigh(const vector<vector<pair<bool, int>>>& map, int x, int y){
    vector<pair<int, int>> neighs;
    for (int h = -1; h < 2; h += 1){
        for (int v = -1; v < 2; v += 1){
            if ((v == 0 || h == 0) && !(v == 0 && h == 0)){
                int newX = x + h;
                int newY = y + v;
                if (newX >= 0 && newX < map[0].size() && newY >= 0 && newY < map.size()){
                    if (!map[newY][newX].first){
                        neighs.push_back(pair<int, int>(newX, newY));
                    }
                }
            }
        }
    }
    return neighs;
}

void findBasins(vector<vector<pair<bool, int>>>& map, int x, int y, int& currentSum){
    cout << " on : " << map[y][x].second << endl;
    if (map[y][x].second == 9 || map[y][x].first)
        return;

    map[y][x].first = true;
    currentSum++;
    vector<pair<int, int>> neighs = findNeigh(map, x, y);
    for (auto n : neighs)
        findBasins(map, n.first, n.second, currentSum);
    
    return;
}

int main(){
    ifstream input("input.txt");
    string line;
    
    vector<vector<pair<bool, int>>> map;
    while(getline(input, line)){
        vector<pair<bool, int>>currentVec;
        for(int i = 0;i < line.size(); i++){
            currentVec.push_back(pair<bool, int>(false, stoi(line.substr(i, 1))));
        }
        map.push_back(currentVec);
    }
    
    vector<int>basins;
    for (int x = 0; x < map[0].size(); x++){
        for(int y = 0; y < map.size(); y++){
            if (!map[y][x].first && map[y][x].second != 9){
                cout << "starting on : " << map[y][x].second << endl;
                int currentSum = 0;
                findBasins(map, x, y, currentSum);
                basins.push_back(currentSum);
            }
        }
    }
    
    sort(basins.begin(), basins.end());

    cout << basins[basins.size() - 1] * basins[basins.size() - 2] * basins[basins.size() - 3] << endl;

    return 0;

}
