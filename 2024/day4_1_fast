#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    string line;
    vector <string> s;
    while(getline(cin, line)) {
        s.pb(line);
    }
    int ans = 0;
    int n = s[0].length();
    assert(s.size() == n);
    int dx[] = {1,-1,0,0,1,1,-1,-1};
    int dy[] = {0,0,1,-1,-1,1,-1,1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 8; k++) {
                int resx = i + 3 * dx[k];
                int resy = j + 3 * dy[k];
                if(resx < 0 || resy < 0) continue;
                if(resx >= n || resy >= n) continue;
                string t = {s[i][j], s[i + dx[k]][j + dy[k]], s[i + 2 * dx[k]][j + 2 * dy[k]], s[i + 3 * dx[k]][j + 3 * dy[k]]};
                if(t == "XMAS") ans++;
            }
        }
    }
    cout << ans << endl;
}
