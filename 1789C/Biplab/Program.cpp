#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> last_index(n+m+1, -10);
    vector<int> present(n+m+1, 0);
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        last_index[v[i]] = -1;
    }
    long long ans = 0, pi, vi;
    for(int i=0; i<m; i++) {
        cin >> pi >> vi;
        present[v[pi-1]] += (i - last_index[v[pi-1]]);
        last_index[v[pi-1]] = -10;
        v[pi-1] = vi;
        last_index[vi] = i;
    }
    for(int i=0; i<=n+m; i++) {
        if(last_index[i] != -10) present[i] += m-last_index[i];
    }
    for(int i=0; i<=n+m; i++) {
        if(present[i] != 0) {
            ans += ((long long int)m*(m+1))/2 - ((long long)(m-present[i])*(m+1-present[i]))/2;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}