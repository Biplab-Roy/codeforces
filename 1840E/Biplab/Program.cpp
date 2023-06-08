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
    string s1, s2;
    cin >> s1 >> s2;
    int t, q;
    int q_t, p1, p2, p, sp1, sp2, time = 0;
    cin >> t >> q;
    queue<pair<int, int>> blocked;
    set<int> differs;

    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) {
            differs.insert(i);
        }
    }

    for(int i = 0; i < q; i++) {
        while(!blocked.empty() && blocked.front().first == time) {
            auto front = blocked.front();
            blocked.pop();
            if(s1[front.second] != s2[front.second]) {
                differs.insert(front.second);
            }
        }
        cin >> q_t;

        if(q_t == 1) {
            cin >> p;
            if(differs.find(p - 1) != differs.end()) differs.erase(p - 1);
            blocked.push({time + p, p - 1});
        }

        else if(q_t == 2) {
            cin >> sp1 >> p1 >> sp2 >> p2;
            p1--, p2--;
            
            if(differs.find(p1) != differs.end()) differs.erase(p1);
            if(differs.find(p2) != differs.end()) differs.erase(p2);

            if(sp1 == 1 && sp2 == 1) {
                swap(s1[p1], s1[p2]);
            }
            else if(sp1 == 1 && sp2 == 2) {
                swap(s1[p1], s2[p2]);
            }
            else if(sp1 == 2 && sp2 == 1) {
                swap(s2[p1], s1[p2]);
            }
            else if(sp1 == 2 && sp2 == 2) {
                swap(s2[p1], s2[p2]);
            }

            if(s1[p1] != s2[p1]) differs.insert(p1);
            if(s1[p2] != s2[p2]) differs.insert(p2);
        }

        else if(q_t == 3) {
            if(differs.empty()) yes;
            else no;
        }
        time++;

    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}