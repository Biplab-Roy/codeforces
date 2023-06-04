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
    int n, q, a;
    cin >> n >> q;
    string str;
    cin >> str;
    set<int> ss;
    for(int i = 0; i < str.size(); i++) {
        if(i%2 == 0 && str[i] == ')') ss.insert(i);
        if(i%2 == 1 && str[i] == '(') ss.insert(i);
    }
    for(int i = 0; i < q; i++) {
        cin >> a;
        if(n&1) {
            no;
            continue;
        }
        a--;
        if(a%2 == 0 && str[a] == ')') ss.erase(a);
        else if(a%2 == 0 && str[a] == '(') ss.insert(a);
        else if(a%2 == 1 && str[a] == '(') ss.erase(a);
        else ss.insert(a);

        if(str[a] == '(') str[a] = ')';
        else str[a] = '(';

        if(ss.empty()) {
            yes;
            continue;
        }

        int low = *ss.begin();
        auto e = ss.end();
        e--;
        int high = *e;
        if(low % 2 == 0 || high % 2 == 1) {
            no;
        }
        else {
            yes;
        }
    }
}

int main()
{
    fast;
    int t = 1;
    while (t--)
        solve();
}