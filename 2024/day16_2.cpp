#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector <string> g;
int n, m;
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
}
int dp[200][200][4]; // distances from start to end
int mp[4][200][200][4]; // distances from end to start
void dfs(int x, int y, int dir, int score) {
    if(dp[x][y][dir] <= score) return;
    dp[x][y][dir] = score;
    dfs(x, y, (dir + 1) % 4, score + 1000);
    dfs(x, y, (dir + 3) % 4, score + 1000);
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(valid(nx, ny)) {
        dfs(nx, ny, dir, score + 1);
    }
}
void dfs2(int x, int y, int dir, int score, int typ) {
    if(mp[typ][x][y][dir] <= score) return;
    mp[typ][x][y][dir] = score;
    dfs2(x, y, (dir + 1) % 4, score + 1000, typ);
    dfs2(x, y, (dir + 3) % 4, score + 1000, typ);
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(valid(nx, ny)) {
        dfs2(nx, ny, dir, score + 1, typ);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line)) {
        g.pb(line);
    }
    n = g.size();
    m = g[0].size();
    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if(g[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            for(int k = 0; k < 4; k++) {
                dp[i][j][k] = 1e12;
                mp[0][i][j][k] = mp[1][i][j][k] = mp[2][i][j][k] = mp[3][i][j][k] = 1e12;
            }
        }
    }

    dfs(sx, sy, 0, 0);
    
    int ans = min(dp[ex][ey][0], min(dp[ex][ey][1], min(dp[ex][ey][2], dp[ex][ey][3])));
    vector <int> v;
    if(ans == dp[ex][ey][0]) {
        dfs2(ex, ey, 2, 0, 2);
        assert(ans == mp[2][sx][sy][2]);
        v.pb(2);
    }
    if(ans == dp[ex][ey][1]) {
        dfs2(ex, ey, 3, 0, 3);
        assert(ans == mp[3][sx][sy][2]);
        v.pb(3);
    }
    if(ans == dp[ex][ey][2]) {
        dfs2(ex, ey, 0, 0, 0);
        assert(ans == mp[0][sx][sy][2]);
        v.pb(0);
    }
    if(ans == dp[ex][ey][3]) {
        dfs2(ex, ey, 1, 0, 1);
        assert(ans == mp[1][sx][sy][2]);
        v.pb(1);
    }
    set <pair <int, int>> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int sum = 1e12;
            for(int k = 0; k < 4; k++) {
                for(auto x: v) {
                    int kel = dp[i][j][k];
                    int kel2 = mp[x][i][j][(k + 2) % 4];
                    sum = min(sum, kel + kel2);
                }
            }
            if(sum == ans) {
                s.insert({i, j});
            }
        }
    }
    int ans2 = s.size();
    cout << ans2 << endl;
}
