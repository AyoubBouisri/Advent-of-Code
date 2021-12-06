#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Vec2{
    public:
        Vec2(int x, int y): x(x), y(y){};
        string toString(){
            return to_string(x) +","+ to_string(y);
        };

        int x,y;
};

Vec2 readVector(string str){
    string delimiter = ",";
    string::size_type index = str.find(delimiter, 0);

    string xStr = str.substr(0, index);
    string yStr = str.substr(index + 1, str.size() - index);

    return Vec2(stoi(xStr), stoi(yStr));
};

pair<Vec2, Vec2> split(string& str){
    string delimiter = " ->";
    string::size_type delimiterIndex;

    delimiterIndex = str.find(delimiter, 0);

    Vec2 start = readVector(str.substr(0, delimiterIndex));
    Vec2 end = readVector(str.substr(delimiterIndex + 4, str.size() - delimiterIndex + 5));

    return pair<Vec2, Vec2>(start, end);
};


void putPixel(unordered_map<string, int>&map, int x, int y){
    string key = Vec2(x ,y).toString();
    auto it = map.find(key);
    if (it == map.end())
        map.insert(pair<string, int>(key, 1));
    else{
        it->second = it->second + 1;
    }
}
// Bresenham's Line Drawing Algorithm : https://www.javatpoint.com/computer-graphics-bresenhams-line-algorithm
void drawLine(unordered_map<string, int>&map, pair<Vec2, Vec2> line){

    int x1 = line.first.x, x2 = line.second.x, y1 = line.first.y, y2 = line.second.y;

    int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
    dx=x2-x1;
    dy=y2-y1;
    dx1=fabs(dx);
    dy1=fabs(dy);
    px=2*dy1-dx1;
    py=2*dx1-dy1;
    if(dy1<=dx1)
    {
        if(dx>=0)
        {
            x=x1;
            y=y1;
            xe=x2;
        }
        else
        {
            x=x2;
            y=y2;
            xe=x1;
        }
        putPixel(map, x,y);
        for(i=0;x<xe;i++)
        {
            x=x+1;
            if(px<0)
            {
                px=px+2*dy1;
            }
            else
            {
                if((dx<0 && dy<0) || (dx>0 && dy>0))
                {
                    y=y+1;
                }
                else
                {
                    y=y-1;
                }
                px=px+2*(dy1-dx1);
            }
            putPixel(map, x,y);
        }
    }
    else
    {
        if(dy>=0)
        {
            x=x1;
            y=y1;
            ye=y2;
        }
        else
        {
            x=x2;
            y=y2;
            ye=y1;
        }
        putPixel(map, x,y);
        for(i=0;y<ye;i++)
        {
            y=y+1;
            if(py<=0)
            {
                py=py+2*dx1;
            }
            else
            {
                if((dx<0 && dy<0) || (dx>0 && dy>0))
                {
                    x=x+1;
                }
                else
                {
                    x=x-1;
                }
                py=py+2*(dx1-dy1);
            }
            putPixel(map, x,y);
        }
    }
}

int main(){
    ifstream input("input.txt");
    string currentLine;
    
    unordered_map<string, int> intersectionMap; 

    while(getline(input, currentLine)){
        pair<Vec2, Vec2> line = split(currentLine);
        drawLine(intersectionMap, line);
    }

    int intersectionCount = 0;
    for_each(intersectionMap.begin(), intersectionMap.end(), [&](const pair<string, int>& el) -> void {
        if (el.second > 1) {
            intersectionCount++;
        }
    });

    cout << intersectionCount << endl;

    return 0;
}
