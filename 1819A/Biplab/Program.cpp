#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

int lowest_missing(map<int, pair<int, int>> &m) {
    int i = 0;
    for(auto e : m) {
        if(e.first != i) return i;
        i++;
    }
    return i;
}

string solve()
{
    int n, max_element = 0;
    cin >> n;
    vector<int> v(n);
    map<int, pair<int, int>> m;
    bool rep = false;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(m.find(v[i]) != m.end()){
            rep = true;
            m[v[i]].second = i;
        }
        else {
            m[v[i]] = {i, i};
        }
        max_element = max(max_element, v[i]);
    }
    
    int lm = lowest_missing(m);
    if(m.find(lm+1)==m.end()) {
        if(rep || lm < max_element ) return "YES";
        else return "NO";
    }
    else {
        auto range = m[lm+1];
        for(int i = 0; i < lm; i++) {
            if(m[i].first > range.first && m[i].second < range.second) {
                return "NO";
            }
        }
        return "YES";
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
}