#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

void solve()
{
    int n;
    string str;
    cin >> n;
    cin >> str;

    vector<int> ans(n);
    int cnt = 0, i = 0;
    int c1 = 0, c2 = 0;

    for(char c : str){
        if(c == '(') cnt++;
        else cnt--;
        if(cnt > 0) {
            ans[i++] = 1;
            c1 = 1;
        }
        else if(cnt < 0) {
            ans[i++] = 2;
            c2 = 1;
        }
        else ans[i] = ans[i-1], i++;
    }

    if(cnt == 0) {
        int d = 0;
        cout << (c1+c2) << endl;
        if(c1 == 0 && c2 == 1) d = 1;
        for(int e : ans) cout << (e-d) << " ";
        cout << endl;
    }
    else cout << -1 << endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}