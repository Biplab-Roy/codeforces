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

void solve()
{
    
}

int main()
{
    fast;
    pre_fac();
    int t;
    cin >> t;
    while (t--)
        solve();
}