#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

int T, cmd;

vector<bool> path;

void process1()
{
    uint64_t n;
    cin >> n;
    if (n == 1)
    {
        printf("1 1");
        return;
    }
    path.clear();
    while(n>1)
    {
        if (n&1)
        {
            path.push_back(true);
            --n;
        }
        else
        {
            path.push_back(false);
        }
        n >>= 1;
    }
    uint64_t p = 1, q = 1;
    for(auto it = path.rbegin(); it != path.rend();++it){
        if (*it)
        {
            p += q;
        }
        else
        {
            q += p;
        }
        
    }
    printf("%llu %llu", p, q);
}

void process2()
{
    path.clear();
    uint64_t p, q;
    cin >> p >> q;
    while (p != 1 || q != 1)
    {
        if (p<q) // even, left
        {
            q -= p;
            path.push_back(false);
        }
        else // odd, right
        {
            p -= q;
            path.push_back(true);
        }
        
    }
    uint64_t ret = 1;
    for(auto it = path.rbegin(); it != path.rend();++it)
    {
        ret <<= 1;
        if(*it)
        {
            ++ret;
        }
    }
    printf("%llu", ret);
}



int main(int argc, char const *argv[])
{
    path.reserve(64);
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        printf("Case #%d: ", t);
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            process1();
            break;
        case 2:
            process2();
            break;
        }
        printf("\n");
    }
    return 0;
}
