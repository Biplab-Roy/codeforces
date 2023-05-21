#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    int n, a;
    cin >> n;
    vector<int> bi1(n+1), bi2(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a;
        b[i] = a;
        bi1[i] = a + i;
        bi2[i] = a - i;
    }
    for(int i=2; i <= n; i++){
        bi1[i] = max(bi1[i],bi1[i-1]);
    }
    for(int i=n-1; i >= 1; i--){
        bi2[i] = max(bi2[i],bi2[i+1]);
    }
    int ans = 0;
    for(int i=2; i < n; i++){
        ans = max(ans, bi1[i-1] + bi2[i+1] + b[i]);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}