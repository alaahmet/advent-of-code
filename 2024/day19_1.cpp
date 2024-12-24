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

bool dfs(string x, int idx) {
    if(idx == x.length()) return true;
    else if(idx > x.length()) return false;
    for(auto xs: s) {
        if(xs.length() + (unsigned int) idx > (unsigned int)x.length()) continue;
        if(x.substr(idx, xs.length()) == xs) {
            if(dfs(x, idx + xs.length())) return true;
        }
    }
    return false;
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

    int ans = 0;

    for(auto ax : a) {
        if(dfs(ax, 0)) ans++;
    }


    cout << ans << endl;
}   
