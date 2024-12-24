#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

vector<string> splitString(const string& str, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(delimiter, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

vector<string> s;
vector <long long> dp(1000, - 1);
long long dfs(string x, int idx) {
    if(idx > x.length()) return 0;  
    if(dp[idx] > -1) return dp[idx];
    if(idx == x.length()) {
        return dp[idx] = 1;
    }
    long long res = 0;
    for(auto xs: s) {
        if(x.substr(idx, xs.length()) == xs) {
            res += dfs(x, idx + xs.length());
        }
    }
    return dp[idx] = res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;

    getline(cin, line);
    s = splitString(line, ", ");
    vector<string> a;
    while (getline(cin, line)) {
        if (line.length() == 0) continue;
        a.push_back(line);
    }

    long long ans = 0;

    for(auto ax : a) {
        ans += dfs(ax, 0);
        for(int i = 0; i < ax.length() + 5; i++) dp[i] = -1;
    }

    cout << ans << endl;
}   
