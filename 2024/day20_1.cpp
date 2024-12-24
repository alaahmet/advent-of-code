#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
vector <string> g;
int n, m;
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ds[150][150];
int de[150][150];
int stx, sty, etx, ety;
void dijkstra(int x, int y, int dp[150][150]) {

    priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater <pair <int, pair <int, int>>>> pq;
    pq.push({0, {x, y}});
    dp[x][y] = 0;

    while (!pq.empty()) {
        auto [dist, pos] = pq.top();
        pq.pop();
        int cx = pos.first;
        int cy = pos.second;

        if (dist > dp[cx][cy]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (check(nx, ny) && dp[nx][ny] > dp[cx][cy] + 1) {
                dp[nx][ny] = dp[cx][cy] + 1;
                pq.push({dp[nx][ny], {nx, ny}});
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    vector <pair <int, int>> dashes;
    while (getline(cin, line)) {
        if(line.length() == 0) continue;
        g.pb(line);
        for(int j = 0; j < line.length(); j++) {
            if(line[j] == '#') {
                dashes.pb({g.size() - 1, j});
            }
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
            ds[i][j] = 1e12;
            de[i][j] = 1e12;
        }
    }
    dijkstra(stx, sty, ds);
    dijkstra(etx, ety, de);
    int cx[] = {0, 0, 2, -2, 1, 1, -1, -1};
    int cy[] = {2, -2, 0, 0, 1, -1, 1, -1};
    map <int, int> mp;
    int res = ds[etx][ety];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] != '#') {
                for(int k = 0; k < 8; k++) {
                    int nx = i + cx[k];
                    int ny = j + cy[k];
                    if(check(nx, ny)) {
                        int dis = ds[i][j] + de[nx][ny] + 2;
                        mp[dis]++;
                        if(dis <= res - 100) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    // for(auto [k, v] : mp) {
        // cout << res - k << " " << v << endl;
    // }
}
