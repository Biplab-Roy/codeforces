#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    while (n && n <= k) {
        cout << 1000 << " ";
        k -= n;
        n--;
    }

    if(n!=0){
        vector<int> v(n, -1);
        if(k > 0) {
            v[k-1] = k;
            v[k] = -2*k;
        }
        for(int e : v) {
            cout << e << " ";
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
