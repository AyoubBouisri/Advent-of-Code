#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#define LOG(vector) for(auto el : vector) cout << el << " "; cout << endl;

using namespace std;

vector<int> split(const string &str, string delimiter) {
    vector<int> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(delimiter, start)) != string::npos) {
        string el = str.substr(start, end - start);

        if (el != "")
            tokens.push_back(stoi(el));

        start = end + 1;
    }

    tokens.push_back(stoi(str.substr(start)));

    return tokens;
};

class Board{
    public: 
        void addRow(string row){
            vector<int> rowVec= split(row, " ");
            board.push_back(rowVec);
        }

        bool isWinning(vector<int>numbers){
            for (int i = 0; i < board.size(); i++){
                bool colWinning = true, rowWinning = true;
                for (int j = 0; j < board.size(); j++){
                    if (rowWinning || colWinning){
                        if (rowWinning && find(numbers.begin(), numbers.end(), board[i][j]) == numbers.end())
                            rowWinning = false;

                        if (colWinning && find(numbers.begin(), numbers.end(), board[j][i]) == numbers.end())
                            colWinning = false;
                        
                        // assuming that the board is squared here
                        if (j == board.size() - 1 && (colWinning || rowWinning))
                            return true;
                    }else{
                        break;
                    }
                }
            }
            return false;
        }

        int sumUnmarked(vector<int>numbers){
            int sum = 0;
            for(int i = 0; i < board.size(); i++){
                for (int j = 0; j < board.size(); j++){
                    if (find(numbers.begin(), numbers.end(), board[i][j]) == numbers.end()){
                        sum = sum + board[i][j];
                    }
                }
            }
            return sum;
        }

        void print(){
            for (int i = 0; i < board.size(); i++){
                for (int j = 0; j < board[0].size(); j++ ){
                    if (board[i][j] < 10)
                        cout << " ";
                    cout << board[i][j] << " " ;
                }
                cout << endl;
            }
            cout << endl;
        }

        vector<vector<int>> board;
};


vector<Board*> loadBoards(ifstream &input){
    vector<Board*> boards;
    string row;
    Board* currentBoard = new Board();
    getline(input, row);
    while(getline(input, row)){
        if (row.size() != 0){
            currentBoard->addRow(row);
        }
        else{
            boards.push_back(currentBoard);
            currentBoard = new Board();
        }
    }
    boards.push_back(currentBoard);
    return boards;
};

void solvePart1(vector<int>numbers, vector<Board*>boards){
    for( int i = boards[0]->board.size(); i < numbers.size(); i++){
        vector<int> sub = {numbers.begin(), numbers.begin() + i};
        for (auto el : boards)
            if (el->isWinning(sub)){
                el->print();
                cout << el->sumUnmarked(sub) * sub[sub.size() - 1] << endl;
                return;
            }
    }
};


void solvePart2(vector<int>numbers, vector<Board*>boards){
    vector<Board*>winningBoards;
    vector<int>lastSub;

    for( int i = boards[0]->board.size(); i < numbers.size(); i++){
        vector<int> sub = {numbers.begin(), numbers.begin() + i};
        for( int j = 0; j < boards.size() - 1; j++){
            Board* el = boards[j];
            if (el->isWinning(sub)){
                lastSub = sub;
                winningBoards.push_back(el);
                boards.erase(boards.begin() + j);
                j--;
            }
        }
    }
    Board* el = winningBoards[winningBoards.size() - 1];
    cout << el->sumUnmarked(lastSub) * lastSub[lastSub.size() - 1] << endl;
};

int main(){
    ifstream input("input.txt");
    string numbersLine;
    getline(input, numbersLine);

    vector<int> numbers= split(numbersLine, ",");
    vector<Board*> boards = loadBoards(input);

    solvePart1(numbers, boards);

    solvePart2(numbers, boards);

    return 0;
}
