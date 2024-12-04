#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    vector<vector<int>> grid;
    while (getline(cin, line)) {
        vector<int> row;
        for (char c : line) {
            if (c == 'X') row.push_back(1);
            else if (c == 'M') row.push_back(2);
            else if (c == 'A') row.push_back(4);
            else row.push_back(8);
        }
        grid.push_back(row);
    }
    int n = grid.size();
    int ans = 0;
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 8; k++) {
                    int x = i + 3 * dx[k];
                    int y = j + 3 * dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[i][j] * 2 + 
                            grid[i + dx[k]][j + dy[k]] * 3  +
                            grid[i + 2 * dx[k]][j + 2 * dy[k]] * 5 +
                            grid[i + 3 * dx[k]][j + 3 * dy[k]] * 7 == 84) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
