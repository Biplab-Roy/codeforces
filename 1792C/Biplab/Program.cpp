#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, k;
    cin >> n;
    vector<int> pos(n+1);
    for(int i=0; i<n; i++) {
        cin >> a;
        pos[a] = i+1;
    }
    
    int l = (n+1)/2, r = (n+2)/2;
    while(l > 1 && r < n && pos[l+1] > pos[l] && pos[r-1] < pos[r]) l--, r++;
    int ans = n - (r - l - 1);
    cout << ans/2 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}