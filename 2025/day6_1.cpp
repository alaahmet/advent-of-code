#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    vector <string> inputs;
    string st; 
    while(getline(cin, st)) {
        if(st.empty())continue;
        inputs.push_back(st);
        cout << st << endl;
    }
    vector <vector <int>> vs;
    for(int i = 0; i < inputs.size() - 1; i++) {
        vector <int> nums;
        istringstream iss(inputs[i]);
        long long s;
        while(iss >> s) {
            nums.push_back(s);
        }
        vs.push_back(nums);
    }
    int ans = 0;
    istringstream iss(inputs[inputs.size() - 1]);
    for(int i = 0; i < vs[vs.size() - 1].size(); i++) {
        string ch;
        iss >> ch;
        function <int(int, int)> op;
        int res = 0;
        if(ch == "*") {
            op = [](int a, int b) {return a*b;};
            res = 1;
        }
        else if(ch == "+") {
            op = [](int a, int b) {return a + b;};
            res = 0;
        }
        else assert(false);
        for(int j = 0; j < vs.size(); j++) {
            res = op(res, vs[j][i]);
        }
        ans += res;
    }
    cout << ans << endl;
}