#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a;
    string line;
    const int MAXX = 100;
    vector<bitset<MAXX>> adj(MAXX);
    bitset <MAXX> exists;
    while (getline(cin, line)) {
        if(line.length() == 0) break;
        int a = (line[0] - '0') * 10 + (line[1] - '0');
        int b = (line[3] - '0') * 10 + (line[4] - '0');
        exists[a] = true;
        exists[b] = true;
        adj[a][b] = true;
    }
    long long ans = 0;
    while(getline(cin, line)) {
        if(line.length() == 0) continue;
        vector <int> a;
        for(int i = 0; i < line.length(); i += 3) {
            int x = (line[i] - '0') * 10 + (line[i + 1] - '0');
            a.push_back(x);
        }
        int n = a.size();
        vector <int> b = a;
        sort(a.begin(), a.end(), [&](int x, int y) {
            if(adj[x][y]) return true;
            else if(adj[y][x]) return false;
            else return false; // strict weak ordering goes brr
        });
        bool ok = false;
        if(a == b) ok = true;
        // if(ok == false) ans += a[n / 2]; // disable if part-1
        if(ok == true) ans += b[n / 2]; // enable if part-1
    }
    cout << ans << endl;
}
