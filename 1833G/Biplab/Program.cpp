#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
long long int mod = 1e9 + 7;

int remove_edges(vector<vector<pair<int, int>>> &tree, int s,
    int parent, vector<int> &removals){
    int connected_children = 0;
    for(auto &e : tree[s]){
        if(e.first != parent){
            int child = remove_edges(tree, e.first, s, removals);
            if(child == 0){
                removals.push_back(e.second);
            }
            connected_children += child;
        }
    }
    connected_children++;
    if(connected_children == 3) {
        return 0;
    }
    else if(connected_children > 3){
        return 4;
    }
    else {
        return connected_children;
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    vector<vector<pair<int, int>>> tree(n+1);
    vector<int> removals;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        tree[u].push_back({v, i});
        tree[v].push_back({u, i});
    }
    int ans = remove_edges(tree, 1, 0, removals);
    if(ans != 0){
        cout << "-1" << endl;
    }
    else {
        cout << removals.size() << endl;
        for(int &e : removals) cout << e << " ";
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}