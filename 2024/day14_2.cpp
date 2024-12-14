#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int px[1000], py[1000], vx[1000], vy[1000];
int npx[1000], npy[1000];
int n, m;
int robots;
int vis[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    robots = 0;
    freopen("output.txt", "w", stdout);
    while (getline(cin, line)) {
        regex re("-?\\d+");
        sregex_iterator next(line.begin(), line.end(), re);
        sregex_iterator end;
        vector<int> numbers;
        while (next != end) {
            smatch match = *next;
            numbers.push_back(stoi(match.str()));
            next++;
        }
        px[robots] = numbers[1];
        py[robots] = numbers[0];
        vx[robots] = numbers[3];
        vy[robots] = numbers[2];
        vis[px[robots]][py[robots]] = 1;
        robots++;
    }
    // n = 7;
    // m = 11;
    n = 103;
    m = 101;
    int minx = 0;
    while((minx++) < 10000) {
        map <pair<int, int>, int> cnt;
        bool ok = false;
        for (int i = 0; i < robots; i++) {
            vis[px[i]][py[i]]--;
            px[i] += vx[i];
            py[i] += vy[i];
            px[i] = (px[i] + n) % n;
            py[i] = (py[i] + m) % m;
            vis[px[i]][py[i]]++;
            cnt[mp(px[i], py[i])]++;
            bool mk = true;
            for(int k = 0; k < 5; k++) {
                if(cnt[mp(px[i] + k, py[i])] == 0) mk = false;
            }
            if(mk) ok = true;
        }
        if(!ok) continue;
        cout << minx << '\n'; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] > 0) cout << '#';
                else cout << '.';
        }
            cout << '\n';
        }
        cout << '\n';
    }


}
