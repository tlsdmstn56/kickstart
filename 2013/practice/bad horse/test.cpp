// https://code.google.com/codejam/contest/2933486/dashboard
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

#define next_status(s) ((s == 2)?3:2)

using namespace std;

int T, M, N;

int graph[200][200];
int graphStatus[200];

void print_status()
{
    for(int i=0;i<N;++i)
    {
        cout << graphStatus[i] << " ";
    }
    cout << "\n";
}

void print_graph()
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

bool dfs(int curr, int status)
{
    // print_status();
    graphStatus[curr] = status;
    bool ret = true;
    for(int i=0; i<N; ++i)
    {
        if (!graph[curr][i])
        {
            continue;
        }
        if (graph[curr][i] && !graphStatus[i]) // connected, not visited
        {
            ret &= dfs(i, next_status(status));
            if(!ret)
                return ret;
        }
        else if (graph[curr][i] && graphStatus[i] == status)
        {
            return false;
        }
    }
    return ret;
}

bool solve()
{
    memset(graph, 0, sizeof(graph));
    memset(graphStatus, 0, sizeof(graphStatus));
    unordered_map<string, int> dict;
    int id = 0;
    cin >> M;
    for(int i=0;i<M;++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (dict.count(s1) == 0)
        {
            graph[id][id] = 0;
            dict[s1] = id++;
        }
        if (dict.count(s2) == 0)
        {
            graph[id][id] = 0;
            dict[s2] = id++;
        }
        const auto& i1 = dict[s1];
        const auto& i2 = dict[s2];
        graph[i1][i2] = graph[i2][i1] = 1; // 
    }
    N = id;
    // print_graph();
    bool ret = true;
    for(int i=0;i<N;++i)
    {
        if (!graphStatus[i])
        {
            ret &= dfs(i, 2);
            if (!ret)
            {
                return ret;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    for(int i=1;i<=T;++i)
    {
        if (solve())
            cout << "Case #"<<i<<": Yes\n";
        else
            cout << "Case #"<<i<<": No\n";
    }
    return 0;
}
