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
    if(val.find(x) != val.end()) {
        return;
    }
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
string toNum(int x) {
    if(x < 10) return "0" + to_string(x);
    else return to_string(x);
}
string tobin(char x, int n) {
    string s = "";
    for(int i = 0; i <= n; i++) {
        string res = x + toNum(i);
        if(val[res]) s += "1";
        else s += "0";
    }
    reverse(s.begin(), s.end());
    return s;
}
void dft(string x) {
    if(x[0] == 'x' || x[0] == 'y') {
        cout << x << " = " << val[x] << endl;
        return;
    }
    if(g[x][1] == "AND") {
        dft(g[x][0]);
        dft(g[x][2]);
        val[x] = val[g[x][0]] & val[g[x][2]];
        cout << x << " = " << val[x] << " :::" << g[x][0] << " " << g[x][1] << " " << g[x][2] << endl;
    }
    else if(g[x][1] == "OR") {
        dft(g[x][0]);
        dft(g[x][2]);
        val[x] = val[g[x][0]] | val[g[x][2]];
        cout << x << " = " << val[x] << " :::" << g[x][0] << " " << g[x][1] << " " << g[x][2] << endl;

    }
    else if(g[x][1] == "XOR") {
        dft(g[x][0]);
        dft(g[x][2]);
        val[x] = val[g[x][0]] ^ val[g[x][2]];
        cout << x << " = " << val[x] << " :::" << g[x][0] << " " << g[x][1] << " " << g[x][2] << endl;
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
    while(true) {
        string zs = "z" + toNum(it);
        if(g.find(zs) == g.end()) {
            break;
        }
        dfs(zs);
        it++;
    }
    string x = tobin('x', 44);
    string y = tobin('y', 44);
    string z = tobin('z', 45);
    cout << " " << x << endl << " " << y << endl << z << endl;
    // dft("z34");

    // did this by hand
    vector<string> ans = {"z15", "fph", "z21", "gds", "wrk", "jrs", "cqk", "z34"};
    sort(ans.begin(), ans.end());
    for (auto ss : ans) {
        cout << ss << ",";
    }
    cout << endl;
}
