#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    /*
    p(s, xi) = ci
        if(x0 == c0) then only 'a'
        if(x0 > c0) 'a', c0-3 times and then repeat 'abc'
        // x0 = 10, c0 = 8 => aaaaa abc ab
        // x0 = 4, c0 = 6 => not possible
        if(x0 <= c0) not possible

    dx = x1 - x0
    dc = c1 - c0

        if(dx == dc) then only a new charecter 'd'
        if(dx >= dc) then dc times new char 'd' then 'abc'
    */
    int n, k, p = 0, nc = 1;
    cin >> n >> k;
    vector<int> x(k), c(k);
    for(int i = 0; i < k; i++) cin >> x[i];
    for(int i = 0; i < k; i++) cin >> c[i];
    char rep[3] = {'a', 'b', 'c'};

    string ans = "";

    if(x[0] >= c[0]){
        for(int i = 0; i < c[0] - 3; i++) ans.push_back('a');
        for(int i = max(0, c[0] - 3); i < x[0]; i++) ans.push_back(rep[(p++)%3]);
    }
    else {
        cout << "NO" << endl;
        return;
    }
    bool possible = true;
    for(int i = 1; i < k; i++){

        int dx = x[i] - x[i-1];
        int dc = c[i] - c[i-1];

        if(dc > dx) {
            possible = false;
            break;
        }
        for(int j = 0; j < dc; j++) ans.push_back('c' + nc);
        for(int j = dc; j < dx; j++) ans.push_back(rep[(p++)%3]);
        nc++;
    }
    if(possible)
        cout << "YES" << endl << ans << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}