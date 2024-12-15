#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n, m = 0;
vector <string> g;
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int mx, my;
stack <pair<int, int>> loc;
bool bum(int x, int y, char c) {
    if(g[x][y] == '#') {
        return false;
    }
    else if(g[x][y] == '.') {
        return true;
    }
    if(g[x][y] == '[') {
        if(c == '^') {
            loc.push({x-1, y});
            loc.push({x-1, y+1});
            return bum(x-1, y, c) && bum(x - 1, y + 1, c);
        }
        else if(c == 'v') {
            loc.push({x+1, y});
            loc.push({x+1, y+1});
            return bum(x+1, y, c) && bum(x + 1, y + 1, c);
        }
    }
    else if(g[x][y] == ']') {
        if(c == '^') {
            loc.push({x-1, y});
            loc.push({x-1, y-1});
            return bum(x-1, y, c) && bum(x - 1, y - 1, c);
        }
        else if(c == 'v') {
            loc.push({x+1, y});
            loc.push({x+1, y-1});
            return bum(x+1, y, c) && bum(x + 1, y - 1, c);
        }
    }
    else {
        assert(g[x][y] == '@');
        if(c == '^') {
            loc.push({x-1, y});
            return bum(x-1, y, c);
        }
        else if(c == 'v') {
            loc.push({x+1, y});
            return bum(x+1, y, c);
        }
    }
    assert(false);
    return true;
}
bool check(int x, int y, char c) {
    if(g[x][y] == '#') {
        return false;
    }
    else if(g[x][y] == '.') {
        mx = x;
        my = y;
        return true;
    }
    if(c == '<') {
        return valid(x, y-1) && check(x, y-1, c);
    }
    else if(c == '>') {
        return valid(x, y+1) && check(x, y+1, c);
    }
    assert(false);
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line)) {
        if(line.size() == 0) break;
        string s = "";
        for(auto c: line) {
            if(c == '#') s.append("##");
            else if(c == 'O') s.append("[]");
            else if(c == '.') s.append("..");
            else if(c == '@') s.append("@.");
        }
        g.push_back(s);
    }
    string moves = "";
    while(getline(cin, line)) {
        moves += line;
    }
    n = g.size();
    m = g[0].size();
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '@') x = i, y = j;
        }
    }
    map <pair <int, int>, int> vis;
    for(int idx = 0; idx < moves.length(); idx++) {
        char c = moves[idx];
        while (!loc.empty()) loc.pop();
        if(c == '^' && bum(x, y, c)) {
            while (!loc.empty()) {
                auto [i, j] = loc.top();
                loc.pop();
                if(vis[{i, j}] == idx) continue;
                vis[{i, j}] = idx;
                g[i][j] = g[i + 1][j];
                g[i + 1][j] = '.';
            }
            g[x - 1][y] = '@';
            g[x][y] = '.';
            x -= 1;
        }   
        else if(c == 'v' && bum(x, y, c)) {
            while (!loc.empty()) {
                auto [i, j] = loc.top();
                loc.pop();
                if(vis[{i, j}] == idx) continue;
                vis[{i, j}] = idx;
                g[i][j] = g[i - 1][j];
                g[i - 1][j] = '.';
            }
            g[x + 1][y] = '@';
            g[x][y] = '.';
            x += 1;
        }
        else if(c == 'v' || c == '^');
        else if(check(x, y, c) == true) {
            if(c == '<') {
                assert(my < y);
                for(int i = my; i < y; i++) g[x][i] = g[x][i + 1];
                g[x][y - 1] = '@';
                g[x][y] = '.';
                y -= 1;
            }
            else if(c == '>') {
                assert(my > y);
                for(int i = my; i > y; i--) g[x][i] = g[x][i - 1];
                g[x][y + 1] = '@';
                g[x][y] = '.';
                y += 1;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '[') ans += 100LL * i + 1LL * j;
        }
    }
    cout << ans << endl;
}