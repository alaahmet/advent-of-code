#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
vector<string> splitChar(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dash[100][100];
int vis[100][100];
bool valid(int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    n = 70, m = 70;
    vector <pair <int, int>> a;
    while (getline(cin, line)) {
        if(line.length() == 0) break;
        vector <string> nums = splitChar(line, ',');
        a.pb(mp(stoi(nums[1]), stoi(nums[0])));
    }
    int l = 1;
    int r = a.size();
    while(l+1 < r) {
        queue <pair <int, int>> q;
        q.push(mp(0, 0));
        int steps = (l + r + 1) / 2;
        for(int i = 0; i < steps; i++) {
            int x = a[i].first;
            int y = a[i].second;
            dash[x][y] = 1;
        }
        bool ok = false;
        while(!q.empty()) {
            auto el = q.front();
            q.pop();
            int x = el.first;
            int y = el.second;
            if(dash[x][y] == 1 || vis[x][y] == 1) continue;
            vis[x][y] = 1;
            if(x == n && y == m) {
                ok = true;
            }
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(valid(nx, ny)) {
                    q.push(mp(nx, ny));
                }
            }
        }   
        if(ok) l = steps + 1;
        else r = steps - 1;
        for(int i = 0; i < steps; i++) {
            int x = a[i].first;
            int y = a[i].second;
            dash[x][y] = 0;
        }
        memset(vis, 0, sizeof(vis));
    }
    cout << a[l].second << "," << a[l].first << endl;
}
