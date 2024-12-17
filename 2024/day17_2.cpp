#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int f(int a) {
    return (((((a & 7) ^ 2) ^ (a >> ((a & 7) ^ 2))) ^ 3) & 7);
}
int32_t main() {
    int arr[] = {2,4,1,2,7,5,4, 5,1,3,5,5,0,3,3,0};
    int P = 9;
    int low = (1LL << (3 * (P-1) ));
    int high = (1LL << (3 * P));
    vector <int> res;
    for(int i = low; i < high; i++) {
        int idx = 16 - P;
        int a = i;
        while(a) {
            if(f(a) != arr[idx]) break;
            a >>= 3;
            if(a == 0) res.push_back(i);
            idx++;
        }
    }
    for(auto x: res) {
        x <<= (3 * (16 - P));
        low = x + 0;
        high = x + (1LL << (3 * (16 - P)));
        for(int i = low; i < high; i++) {
            int y = i;
            bool ok = true;
            int idx = 0;
            while(y) {
                if(f(y) != arr[idx]) {
                    ok = false;
                    break;
                }
                y >>= 3;
                idx++;
            }
            if(ok) cout << i;
        }
    }
}

