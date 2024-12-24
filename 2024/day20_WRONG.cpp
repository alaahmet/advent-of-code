#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
vector <string> g;
int n, m;
map <vector <pair <int ,int>>, vector <vector <vector <int>>>> dp;
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
}
bool soft_check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '#';
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans;
void dfs(int x, int y, vector <pair <int, int>> v, int state, int dist) {
    if(state == 1) {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(soft_check(nx, ny)) {
                dfs(nx, ny, state + 1, dist + 1);
            }
        }
        return;
    }
    if(dp[state][x][y] <= dist) return;
    dp[state][x][y] = dist;
    if(g[x][y] == 'E') {
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx, ny)) {
            dfs(nx, ny, state, dist + 1);
        }
        if(state == 0) {
            if(soft_check) {
                (nx, ny, state + 1, dist + 1);
            } 
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    int stx, sty;
    int etx, ety;
    while (getline(cin, line)) {
        if(line.length() == 0) continue;
        g.pb(line);
        for(int j = 0; j < line.length(); j++) {
            if(line[j] == 'S') {
                stx = g.size() - 1;
                sty = j;
            }
            if(line[j] == 'E') {
                etx = g.size() - 1;
                ety = j;
            }
        }
    }
    n = g.size();
    m = g[0].length();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[0][i][j] = 1e12;
            dp[1][i][j] = 1e12;
        }
    }

    vector <pair <int, int>> v;

    dfs(stx, sty, v, 0, 0);

    cout << ans << endl;
    
}
