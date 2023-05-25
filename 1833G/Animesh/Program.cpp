#include<bits/stdc++.h>
using namespace std;

bool isFeasible = true;

int dfs(vector<vector<pair<int,int>>> &adj, int u,vector<bool> &vis,vector<int> &res){
    vis[u] = true;
    int cnt = 1;
    for(auto it:adj[u]){
        int v = it.first;
        int e = it.second;
        int retVal = -1;
        if(!vis[v]){
            retVal = dfs(adj,v,vis,res);
        }
        // means we can not consider that edge
        if(retVal == 0){
            res.push_back(e);
        }
        if(retVal != -1){
            cnt += retVal;
        }
        if(isFeasible == false){
            return -1;
        }
    }
    if(cnt == 3){
        return 0;
    }else if(cnt > 3){
        isFeasible = false;
        return -1;
    }else{
        return cnt;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    ////////////////////////////////////  
    vector<vector<pair<int,int>>> adj(n+1);
    int i = 1;
    // creating the tree (graph)
    for(auto edge : edges){
        adj[edge[0]].push_back({edge[1],i});
        adj[edge[1]].push_back({edge[0],i});
        i++;
    }
    vector<bool> vis(n+1,false);
    vector<int> res; 
    int root = dfs(adj,1,vis,res);
    if(isFeasible == false || root != 0){
        cout<<-1<<endl;
        return;  
    }
    cout<<res.size()<<endl;
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        isFeasible = true;
        solve();
    }
}