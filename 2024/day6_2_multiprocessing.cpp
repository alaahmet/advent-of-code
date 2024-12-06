#include <bits/stdc++.h>
#include <thread>
#include <atomic>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("a.in", "r", stdin);
    string line;
    vector<string> s;
    int sx, sy;
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '^') {
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
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    atomic<int> ans(0);
    int num_threads = 8;

    auto process_chunk = [&](int start, int end) {
        for (int index = start; index < end; ++index) {
            int i = index / m;
            int j = index % m;

            if (s[i][j] == '#') continue;
            if (i == sx && j == sy) continue;

            vector<string> local_s = s;
            local_s[i][j] = '#';
            int x = sx, y = sy;
            int vis[n][m][4];
            memset(vis, 0, sizeof(vis));
            int idx = 0;
            bool ok = true;
            while (ok) {
                if (vis[x][y][idx] == 1) {
                    ans++;
                    break;
                }
                vis[x][y][idx] = 1;
                while (ok) {
                    int xx = x + dx[idx];
                    int yy = y + dy[idx];
                    if (!check(xx, yy)) {
                        ok = false;
                    } else if (local_s[xx][yy] == '#') {
                        idx = (idx + 1) % 4;
                    } else {
                        x = xx;
                        y = yy;
                        break;
                    }
                }
            }
        }
    };

    vector<thread> threads;
    int total_cells = n * m;
    int chunk_size = (total_cells + num_threads - 1) / num_threads;

    for (int t = 0; t < num_threads; ++t) {
        int start = t * chunk_size;
        int end = min(start + chunk_size, total_cells);
        threads.emplace_back(process_chunk, start, end);
    }

    for (auto &t : threads) {
        if (t.joinable()) t.join();
    }

    cout << ans.load() << endl;
}
