// https://code.google.com/codejam/contest/2933486/dashboard#s=p2
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int T, N;

inline int min(int a, int b)
{
    return a>b?b:a;
}

inline bool gt(const string& prev, const string& curr)
{
    const int sz = min(prev.size(), curr.size());
    for(int i=0; i<sz; ++i)
    {
        const char& c_prev = prev.at(i);
        const char& c_curr = curr.at(i);
        if (c_prev == c_curr)
        {
            continue;
        }
        if (c_prev == ' ')
        {
            return true;
        }
        if (c_curr == ' ')
        {
            return false;
        }
        return c_prev<c_curr;
    }
    return prev.size() < curr.size();
}

int solve()
{
    cin >> N;
    string prev_max;
    cin.ignore();
    getline(cin, prev_max);
    // cout << (prev_max) << "(prev_max)\n";
    string curr;
    int ret = 0;
    for(int i=1;i<N;++i)
    {
        getline(cin, curr);
        // cout << (curr) << "(curr)\n";
        if (gt(prev_max, curr))
        {
            prev_max = curr;
        }
        else
        {
            ++ret;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
