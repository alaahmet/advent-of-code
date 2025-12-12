#include <bits/stdc++.h>
using namespace std;
#define int long long
map <string, int> ans[4];
map <string, vector <string>> g;
map <string, int> vis;
void dfs(string x) {
    vis[x] = 1;
    if(x == "out") {
        ans[0][x] = 1;
        return;
    } 
    int state = 0;
    if(x == "fft") state = 2;
    if(x == "dac") state = 1;
    for(auto y: g[x]) {
        if(vis[y] == 0) dfs(y);
        if(state == 0) {
            ans[0][x] += ans[0][y];
            ans[1][x] += ans[1][y];
            ans[2][x] += ans[2][y];
            ans[3][x] += ans[3][y];
        }
        else if(state == 1) {
            ans[1][x] += ans[0][y] + ans[1][y];
            ans[3][x] += ans[2][y] + ans[3][y];
        }
        else if(state == 2) {
            ans[2][x] += ans[0][y] + ans[2][y];
            ans[3][x] += ans[1][y] + ans[3][y];
        }
    }
    // cout << x << " " << ans[0][x] << " " << ans[1][x] << " " << ans[2][x] << " "<< ans[3][x] << endl;
}
int32_t main() {
    string st;
    while(getline(cin, st)) {
        if(st.empty())continue;
        istringstream iss(st);
        string src;
        iss >> src;
        src = src.substr(0, src.length() - 1);
        string adj;
        while(iss >> adj) {
            g[src].push_back(adj);
            // cout << src << " " << adj << endl;
        }
    }
    dfs("svr");
    cout << ans[3]["svr"] << endl;
}