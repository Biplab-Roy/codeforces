#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

long long int mod = 1e9 + 7;

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

unsigned long long int solve()
{
    long long int n, m, a;
    cin >> n >> m;
    map<long long int, long long int> mp;
    for(int i=0; i<n; i++){
        cin >> a;
        mp[a]++;
    }
    vector<unsigned long long int> elements, occurrences;
    for(auto &e : mp){
        elements.push_back(e.first);
        occurrences.push_back(e.second);
    }

    unsigned long long int mul = 1, ans = 0;
    if(elements.size() < m) return 0;
    for(int i = 0; i < m-1; i++) {
        mul *= occurrences[i];
        mul = mul % mod;
    }
    for(int i=m-1; i<elements.size(); i++){
        mul *= occurrences[i];
        if(elements[i] - elements[i-m+1] < m) {
            ans += mul;
        }
        // (a / b) % M = (a % M * (b^-1) % M) % M
        mul = ((mul % mod) *
            mod_inverse(occurrences[i-m+1], mod) % mod) % mod;
        ans = ans % mod;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
}