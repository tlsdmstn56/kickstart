#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
using namespace std;
int T;

vector<bool> labels_odd;
vector<int> alex;
vector<int> bob;


void solve_print()
{
    labels_odd.clear();
    alex.clear();
    bob.clear();
    int N;
    cin >>N;
    for (int i=0; i<N;++i)
    {
        int tmp;
        cin >> tmp;
        if (abs(tmp) & 1)
        {
            alex.push_back(tmp);
            labels_odd.push_back(true);
        }
        else
        {
            bob.push_back(tmp);
            labels_odd.push_back(false);
        }
    }
    sort(alex.begin(), alex.end(),[](int a, int b){return a>b;});
    sort(bob.begin(), bob.end());
    for (auto is_odd: labels_odd)
    {
        if(is_odd)
        {
            printf("%d ", alex.back());
            alex.pop_back();
        }
        else
        {
            printf("%d ", bob.back());
            bob.pop_back();
        }
        
    }
}

int main(int argc, char const *argv[])
{
    labels_odd.reserve(1000);
    alex.reserve(1000);
    bob.reserve(1000);
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        printf("Case #%d: ", t);
        solve_print();
        printf("\n");
    }
    return 0;
}
