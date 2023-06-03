#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

long long int mod = 1e9 + 7;
unsigned long long int fac[100010];

unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1;
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}

unsigned long long mod_inverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    return (fac[n] * mod_inverse(fac[r], p) % p * mod_inverse(fac[n - r], p) % p) % p;
}

void pre_fac()
{
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++)
        fac[i] = (fac[i - 1] * i) % mod;
}

int dfs(vector<vector<ll>> &tree, int node, int parent, ll &ans, int n) {
    vector<int> child_cnt;
    ll num_child = 0;
    for(int child : tree[node]) {
        if(child != parent) {
            int cnt = dfs(tree, child, node, ans, n);
            child_cnt.push_back(cnt);
            num_child += cnt;
        }
    }
    child_cnt.push_back(n - num_child - 1);
    ll prefix_sum = 0;
    for(int num : child_cnt) {
        ans += (num*prefix_sum)%mod;
        prefix_sum += num;
        prefix_sum %= mod;
        ans %= mod;
    }
    ans += n - 1;
    ans %= mod;
    return num_child + 1;
}

void solve()
{
    ll n, k, a, b;
    cin >> n >> k;
    vector<vector<ll>> tree(n+1);
    for(int i = 0; i < n-1; i ++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ll ans = 0;
    if(k == 1 || k == 3){
        cout << 1 << endl;
        return;
    }
    dfs(tree, 1, 0, ans, n);
    cout << (ans * mod_inverse((n*(n-1))/2 % mod, mod))%mod << endl;
    return;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}