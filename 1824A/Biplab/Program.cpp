#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

int solve()
{
    int n, left=0, right=0, a, m, total = 0;
    cin >> n >> m;
    vector<int> v(m+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == -1) left++;
        else if(a == -2) right++;
        else {
            if(v[a]==0) total ++;
            v[a] = 1;
        }
    }
    int l = 0;
    int r = m - total;
    int ans = max(left, right) + total;
    for(int i=1; i <= m; i++){
        if(v[i] != 1){
            l++, r--;
        }
        if(v[i] == 1) {
            ans = max(ans, min(left, l) + min(r, right) + total);
        }
        
        // else total --;
        if(r == 0) break;
    }
    return min(ans, m);
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        int ans = solve();
        cout << ans << endl;
    }

}