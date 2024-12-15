#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n, m = 0;
vector <string> g;
int mx, my;
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
        return check(x, y-1, c);
    }
    else if(c == '>') {
        return check(x, y+1, c);
    }
    else if(c == '^') {
        return check(x-1, y, c);
    }
    else if(c == 'v') {
        return check(x+1, y, c);
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
        g.push_back(line);
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
        if(check(x, y, c) == true) {
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
            else if(c == '^') {
                assert(mx < x);
                for(int i = mx; i < x; i++) g[i][y] = g[i + 1][y];
                g[x - 1][y] = '@';
                g[x][y] = '.';
                x -= 1;
            }
            else if(c == 'v') {
                assert(mx > x);
                for(int i = mx; i > x; i--) g[i][y] = g[i - 1][y];
                g[x + 1][y] = '@';
                g[x][y] = '.';
                x += 1;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'O') ans += 100LL * i + 1LL * j;
        }
    }
    cout << ans << endl;
}