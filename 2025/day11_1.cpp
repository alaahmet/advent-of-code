#include <bits/stdc++.h>
using namespace std;
#define int long long
map <string, int> ans;
map <string, vector <string>> g;
map <string, int> vis;
void dfs(string x) {
    vis[x] = 1;
    if(x == "out") {
        ans[x] = 1;
        return;
    } 
    for(auto y: g[x]) {
        if(vis[y] == 0) dfs(y);
        ans[x] += ans[y];
    }
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
    dfs("you");
    cout << ans["you"] << endl;
}