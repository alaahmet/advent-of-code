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
    map <pair <int, int>, int> vis;
    int x = sx;
    int y = sy;
    int idx = 0;
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
    bool ok = true;
    
    
    while(ok) {
        vis[{x, y}] = 1;
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

    int ans = vis.size();
    cout << ans << endl;
}
