#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1000;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        vector <int> a;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
        int m = a.size();
        bool ok = true;
        int mindif = a[1] - a[0];
        int maxdif = a[1] - a[0];
        for(int j = 1; j < m; j++) {
            maxdif = max(maxdif, a[j] - a[j-1]);
            mindif = min(mindif, a[j] - a[j-1]);
        }
        if(maxdif <= 3 && mindif >= 1) cnt++;
        else if(maxdif <= -1 && mindif >= -3) cnt++;
        else {
            for(int j = 0; j < m; j++) {
                vector <int> b = a;
                b.erase(b.begin() + j);
                ok = true;
                int mindif = b[1] - b[0];
                int maxdif = b[1] - b[0];
                for(int j = 1; j < m-1; j++) {
                    maxdif = max(maxdif, b[j] - b[j-1]);
                    mindif = min(mindif, b[j] - b[j-1]);
                }
                if(maxdif <= 3 && mindif >= 1) {cnt++; break;}
                else if(maxdif <= -1 && mindif >= -3) {cnt++; break;}
            }
        }
    }
    cout << cnt << endl;
}