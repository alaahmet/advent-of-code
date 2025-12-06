#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    vector <string> inputs;
    string st; 
    while(getline(cin, st)) {
        if(st.empty())continue;
        inputs.push_back(st);
    }
    int row_size = 0;
    vector <int> block_sizes;
    for(int i = 0; i < inputs.size() - 1; i++) {
        istringstream iss(inputs[i]);
        string s;
        int col = 0;
        while(iss >> s) {
            if(i == 0) {
                block_sizes.push_back(s.length());
                row_size++;
            }
            else {
                block_sizes[col] = max(block_sizes[col], (int)s.length());
            }
            col++;
        }
    }
    istringstream iss(inputs[inputs.size() - 1]);
    vector <char> sop(row_size);
    for(int i = 0; i < row_size; i++) {
        iss >> sop[i];
    }
    vector <vector <string>> column(row_size);
    for(int i = 0; i < inputs.size() - 1; i++) {
        string line = inputs[i];
        int block = -1;
        for(int j = 0; j < line.length() && block < row_size; j += block_sizes[block] + 1) {
            block++;
            column[block].push_back(line.substr(j, block_sizes[block]));
        }
    }
    int ans = 0;
    for(int col = 0; col < row_size; col++) {
        vector <int> vals;
        for(int k = 0; k < block_sizes[col]; k++) {
            int num = 0;
            for(int i = 0; i < column[col].size(); i++) {
                char ch = column[col][i][k];
                if(ch != ' ') num = num * 10 + (ch - '0');
            }
            vals.push_back(num);
        }
        int res = 0;
        if(sop[col] == '*') res = 1;
        for(auto x: vals) {
            cout << x << " ";
            if(sop[col] == '*') res *= x;
            else res += x;
        }
        cout << endl;
        ans += res;
    }
    cout << ans << endl;
}