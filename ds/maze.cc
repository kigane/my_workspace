#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "myutils.h"
using namespace std;

typedef struct offsets
{
    int a, b;
    char *dir;
}offsets;

const int m = 13;
const int p = 14;
offsets moves[8];
int maze[m + 2][p + 1];
int mark[m + 2][p + 1];

offsets* get_offsets()
{
    char *d[8] {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    int h[8] {-1, -1, 0, 1, 1, 1, 0, -1};
    int v[8] {0, 1, 1, 1, 0, -1, -1, -1};
    for (int i = 0; i < 8; i++)
    {
        moves[i].dir = d[i];
        moves[i].a = h[i];
        moves[i].b = v[i];
    }
    return moves;
}

int SeekPath(int x, int y)
{
    int g,h;
    char *d;

    if (x == m && y == p)
        return 1;
    
    for (int i = 0; i < 8; i++) // 如果一个方向走不通，则尝试下一个
    {
        // 走一步
        g = x + moves[i].a;
        h = y + moves[i].b;
        d = moves[i].dir;

        // 能走通？
        if (maze[g][h] == 0 && mark[g][h] == 0)
        {
            mark[g][h] = 1;
            if (SeekPath(g, h)) // 递归求解
            {
                cout << "(" << g << "," << h << ")" << "Direction:" << d << endl;
                return 1;
            }
            mark[g][h] = 0;
        }
    }
    if (x == 1 && y == 1)
        cout << "no path in Maze" << endl;
    return 0;
}

struct items
{
    int x, y, dir; // 位置和前进方向序号
} tmp;

void SeekPathStackVersion(int x, int y)
{
    int i, j, g, h, d;
    mark[1][0] = 1;
    stack<items> st;
    tmp.x = 1;
    tmp.y = 0;
    tmp.dir =2;
    st.push(tmp);
    while (!st.empty())
    {   
        tmp = st.top();
        st.pop();
        i = tmp.x; j = tmp.y; d = tmp.dir;
        while (d < 8)
        {
            g = i + moves[d].a;
            h = j + moves[d].b;

            if (g == m && h == p)
            {
                cout << "Finished" << endl;
                return;
            }

            if (maze[g][h] == 0 && mark[g][h] == 0)
            {
                mark[g][h] = 1;
                tmp.x = i; tmp.y = j; tmp.dir = d;
                st.push(tmp);
                i = g; j = h; d = 0;
            }
            else
                d++;
        }
        
    }
    cout << "no path in Maze" << endl;
    
}

int main(){
    string path = "maze.txt";
    ifstream fs(path.c_str());
    string s = "";    

    for (int i = 0; i <m+2; i++)
    {
        getline(fs, s);
        for (int j = 0; j < p+2; j++)
        {
            maze[i][j] = ctoi(s[j]);
            mark[i][j] = 0;
        }
    }

    get_offsets();

    SeekPathStackVersion(1,1);

    for (int i = 0; i < 15; i++)
    {
        printArr(mark[i], 15);
    }
    
    
    fs.close();
}