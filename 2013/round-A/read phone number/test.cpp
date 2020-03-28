#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int T;

string multi_str[9] = {
    "double","triple","quadruple",
    "quintuple","sextuple","septuple",
    "octuple","nonuple","decuple"
};

string num[10] = {
    "zero","one","two","three",
    "four","five","six","seven",
    "eight","nine"
};

void read(const string& s, int start, int end)
{
    int multiple = -1;
    char prev = s.at(start);
    for(int i=start+1;i<end;++i)
    {
        const char& curr = s.at(i);
        if (prev == curr)
        {
            ++multiple;
        }
        else
        {
            if (multiple == -1)
            {
                cout << num[prev - '0'] << ' ';
            }
            else if(multiple>=9)
            {
                // cout << "|";
                for(int i=-1;i<=multiple;++i)
                {
                    cout << num[prev - '0'] << ' ';
                }
                // cout << "|";
            }
            else
            {
                cout << multi_str[multiple] << ' ' << num[prev - '0'] << ' ';
            }
            prev = curr;
            multiple = -1;
        }
    }
    if (multiple == -1)
    {
        cout << num[prev - '0'] << ' ';
    }
    else if(multiple>=9)
    {
        // cout << "|";
        for(int i=-1;i<=multiple;++i)
        {
            cout << num[prev - '0'] << ' ';
        }
        // cout << "|";
    }
    else
    {
        cout << multi_str[multiple] << ' ' << num[prev - '0'] << ' ';
    }
}

vector<int> split(string& str) {
    vector<int> internal;
    stringstream ss(str);
    string temp; 
    while (getline(ss, temp, '-')) {
        internal.push_back(stoi(temp));
    }
    return internal;
}

void solve()
{
    string num, format;
    cin >> num >> format;
    // cout << num;
    // cout << num.size();
    auto nums = split(format);
    int start = 0;
    for(int n : nums)
    {
        read(num, start, start + n);
        start += n;
    }
}

int main(int argc, char const *argv[])
{
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }
    return 0;
}
