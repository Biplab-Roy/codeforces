#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define rep(i, s, e) for(int i = s; i < e; i++)
#define rrep(i, e, s) for(int i = e; i > s; i--)
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pt pair<int, int>
#define vi vector<int>
#define vll vector<long long>

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    int n, a, b;
    cin >> n;
    vector<pt> seg;
    rep(i, 0, n) {
        cin >> a >> b;
        seg.push_back({a, b});
    }
    vector<pt> unions;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            int mf = max(seg[i].ff, seg[j].ff);
            int ml = min(seg[i].ss, seg[j].ss);
            if(mf <= ml) unions.pb({min(seg[i].ff, seg[j].ff), max(seg[i].ss, seg[j].ss)});
        }
    }
    sort(all(unions), [](const pt &a, const pt &b) {
        return a.ss < b.ss;
    });
    int lastEnd = -1, cnt = 0;
    for(auto &e : unions) {
        if(e.ff > lastEnd) {
            lastEnd = e.ss;
            cnt++;
        }
    }
    cout << n - 2*cnt << endl;
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}