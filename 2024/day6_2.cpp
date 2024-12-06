#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("a.in", "r", stdin);
    string line;
    vector <string> s;
    int sx, sy;
    while(getline(cin, line)) {
        for(int i = 0; i < line.length(); i++) {
            if(line[i] == '^') {
                sx = s.size();
                sy = i;
            }
        }
        s.push_back(line);
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int n = s.size();
    int m = s[0].length();
    function<bool(int, int)> check = [&](int x, int y) {
        if(x >= 0 && x < n && y >= 0 && y < m) {
            return true;
        }
        return false;
    };
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') continue;
            if(i == sx && j == sy) continue;
            int x = sx;
            int y = sy;
            s[i][j] = '#';
            int vis[n][m][4];
            memset(vis, 0, sizeof(vis));
            int idx = 0;
            bool ok = true;
            while(ok) {
                if(vis[x][y][idx] == 1) {
                    ans++;
                    break;
                }
                vis[x][y][idx] = 1;
                while(ok) {
                    int xx = x + dx[idx];
                    int yy = y + dy[idx];
                    if(check(xx, yy) == false) {
                        ok = false;
                    }
                    else if(s[xx][yy] == '#'){
                        idx = (idx + 1) % 4;
                    }   
                    else {
                        x = xx;
                        y = yy;
                        break;
                    }

                }
            }
            s[i][j] = '.';
        }
    }    
    
    cout << ans << endl;
}