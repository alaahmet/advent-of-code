#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
// splitCharMultiple(line, {'.', '/', '*', '&'})
vector<string> splitCharMultiple(const string& str, const vector<char>& delimiters) {
    vector<string> tokens;
    string token;
    for (char ch : str) {
        if (find(delimiters.begin(), delimiters.end(), ch) != delimiters.end()) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}
vector<string> splitChar(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
// vector<vector<string>> groups = splitByEmptyLines(s);
vector<vector<string>> splitByEmptyLines(const vector<string>& lines) {
    vector<vector<string>> result;
    vector<string> currentGroup;
    for (const string& line : lines) {
        if (line.empty()) {
            if (!currentGroup.empty()) {
                result.push_back(currentGroup);
                currentGroup.clear();
            }
        } else {
            currentGroup.push_back(line);
        }
    }
    if (!currentGroup.empty()) {
        result.push_back(currentGroup);
    }
    return result;
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
bool isNumber(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}
vector <int> getOnlyNums(const string& str) {
    vector <string> s = splitChar(str, ' ');
    vector <int> a;
    for(auto xs: s) {
        if(isNumber(xs)) a.push_back(stoi(xs));
    }
    return a;
}

vector<int> getOnlyNumsNegativesAllowed(const string& str) {
    vector<string> s = splitChar(str, ' ');
    vector<int> a;
    for (const auto& xs : s) {
        if(xs[0] == '-') a.push_back(-stoi(xs.substr(1, xs.length()-1)));
        else a.push_back(stoi(xs));
    }
    return a;
}
vector <int> getNums(const string& str) {
    stringstream ss(str);
    vector <int> a;
    int num;
    while(ss >> num) a.push_back(num);
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line)) {
    
    }
    
}
