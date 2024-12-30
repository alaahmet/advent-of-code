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

#define int long long
map <string, int> val;
map <string, vector <string>> g;
void dfs(string x) {
    if(val.find(x) != val.end()) return;
    if(g[x][1] == "AND") {
        dfs(g[x][0]);
        dfs(g[x][2]);
        val[x] = val[g[x][0]] & val[g[x][2]];
    }
    else if(g[x][1] == "OR") {
        dfs(g[x][0]);
        dfs(g[x][2]);
        val[x] = val[g[x][0]] | val[g[x][2]];
    }
    else if(g[x][1] == "XOR") {
        dfs(g[x][0]);
        dfs(g[x][2]);
        val[x] = val[g[x][0]] ^ val[g[x][2]];
    }
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;

    while (getline(cin, line)) {
        if(line.length() == 0) break;
        vector <string> ss = splitString(line, ": ");
        val[ss[0]] = stoi(ss[1]);
    }
    while(getline(cin, line)) {
        if(line.length() == 0) continue;
        vector <string> ss = splitChar(line, ' ');
        bool flag = true;
        g[ss[4]] = {ss[0], ss[1], ss[2]};
    }
    int it = 0;
    int ans = 0;
    while(true) {
        string z = "z";
        if(it < 10) {
            z.append("0");
            z.append(to_string(it));
        }
        else {
            z.append(to_string(it));
        }
        if(g.find(z) == g.end()) {
            break;
        }
        dfs(z);
        // cout << z << " " << val[z] << endl;
        if(val[z] == 1) ans += (1LL << it);
        it++;
    }


    cout << ans << endl;
}
