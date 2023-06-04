#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int i = n - 1;
    if(v[i] != 0) {
        no;
        return;
    }
    else {
        yes;
    }
    while(i >= 0) {
        int zeros = 0, ones = 0;
        while(i>=0 && v[i] == 0) zeros++, i--;
        while(i>=0 && v[i] == 1) ones++, i--;
        int insert_at_zero = zeros + ones - 1;
        for(int i = 0; i < insert_at_zero; i++) {
            cout << "0 ";
        }
        cout << ones << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}