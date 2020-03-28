#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
using namespace std;
int T;
int sx, sy, ex, ey;
char map[102][102];

const char D[4] = {'S','W','N','E'};

const int dr[8] = {1, 1, 0,-1,-1,-1, 0,1};
const int dc[8] = {0,-1,-1,-1, 0, 1, 1,1};

int rotate90(int i)
{
    int f = (i+2);
    return f>=8?f-8:f;
}

int rotate90r(int i)
{
    int f = (i-2);
    return f<0?f+8:f;
}

int rotate45(int i)
{
    int f = (i+1);
    return f>=8?f-8:f;
}

void solve_print()
{
    int N;
    cin >> N;
    memset(map, 0, sizeof(map));
    for(int r = 0; r<=(N+1); ++r)
    {
        if (r==0 || r==(N+1))
        {
            for(int c = 0; c<=(N+1); ++c) 
            {
                map[r][c] = map[r][c] = '#';
            }
        }
        else
        {
            scanf("%s", &map[r][1]);
            map[r][0] = map[r][N+1] = '#';
        }
    }
    // cout << "\n";
    // for (int r = 0; r<=(N+1); ++r)
    // {
    //     for (int c = 0; c<=(N+1); ++c)    
    //     {
    //         cout << map[r][c];
    //     }
    //     cout << "\n";
    // }
    cin >> sx >> sy >> ex >> ey;
    vector<char> path;
    int curr_r = sx, curr_c= sy;
    int wall_i=-1;
    {
        int num_wall = 0;
        for(int i=0;i<8;i+=2)
        {
            if(map[curr_r+dr[i]][curr_c+dc[i]] == '#')
            {
                wall_i = i;
                ++num_wall;
            }
        }
        if (num_wall == 4)
        {
            goto fail;
        }
    }
    
    while(path.size()<=10000)
    {
        const int next_move_i = rotate90(wall_i);
        const int next_r = curr_r + dr[next_move_i];
        const int next_c = curr_c + dc[next_move_i];
        if (map[next_r][next_c] == '#')
        {
            wall_i = next_move_i;
            continue;
        }
        curr_r = next_r;
        curr_c = next_c;
        path.push_back(D[next_move_i>>1]);
        if(curr_c == ey && curr_r == ex)
        {
            goto success;
        }
        const int next_wall_i = rotate90r(next_move_i);
        const int next_wall_r = curr_r + dr[next_wall_i];
        const int next_wall_c = curr_c + dc[next_wall_i];
        if (map[next_wall_r][next_wall_c] == '#')
        {
            wall_i = next_wall_i;
            continue;
        }
        curr_r = next_wall_r;
        curr_c = next_wall_c;
        path.push_back(D[next_wall_i>>1]);
        wall_i = rotate90r(next_wall_i);
        if(curr_c == ey && curr_r == ex)
        {
            goto success;
        }
    }
fail:
    std::cout << "Edison ran out of energy.";
    // std::cout << path.size() << "\n";
    // for(auto c : path)
    // {
    //     std::cout << c;
    // }
    return;
success:
    std::cout << path.size() << "\n";
    for(auto c : path)
    {
        std::cout << c;
    }
}

int main(int argc, char const *argv[])
{   
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        printf("Case #%d: ", t);
        solve_print();
        printf("\n");
    }
    return 0;
}
