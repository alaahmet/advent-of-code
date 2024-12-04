#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    vector<vector<int>> grid;
    vector <pair <int, int>> A;
    int n;
    bool flag = true;
    while (getline(cin, line)) {
        if(flag) n = line.length();
        flag = false;
        vector<int> row;
        for (char c : line) {
            if (c == 'A') {
                if(grid.size() > 0 && grid.size() < n-1 && row.size() > 0 && row.size() < n-1)
                    A.push_back({grid.size(), row.size()});
                row.push_back(0);
            }
            else if (c == 'M') row.push_back(1);
            else if (c == 'S') row.push_back(2);
            else row.push_back(0);
        }
        grid.push_back(row);
    }
    int ans = 0;
    for(auto x: A) {
        int i = x.first;
        int j = x.second;
        int ok = 0;
        // M:1 S:2 1*3 + 2*5 = 13
        if(grid[i + 1][j + 1] * 3 + grid[i - 1][j - 1] * 5 == 13) ok++;
        else if(grid[i + 1][j + 1] * 5 + grid[i - 1][j - 1] * 3 == 13) ok++;
        if(grid[i + 1][j - 1] * 3 + grid[i - 1][j + 1] * 5 == 13) ok++;
        else if(grid[i + 1][j - 1] * 5 + grid[i - 1][j + 1] * 3 == 13) ok++;
        if(ok == 2) ans++;
    }
    cout << ans;
    return 0;
}
