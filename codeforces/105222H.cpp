#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        if(n % 3 == 0) {
            cout << 1 << " " << n/3 << "\n";
        }
        else {
            cout << 0 << " " << ((n / 3) + n % 3) << "\n";
        }
    }
    

    return 0;
}
