#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    string s;
    int res = 0;
    int val = 50;
    while(cin >> s) {
        char d = s[0];
        int num = stoi(s.substr(1));
        if(d == 'L' && val == 0 && num > 0) res--;
        if(d == 'R') val += num;
        else val -= num;
        if(val >= 100) res += val / 100;
        else if(val <= 0) res += (abs(val) + 100) / 100;
        val = (val + 2000) % 100;
    }
    cout << res << endl;
}