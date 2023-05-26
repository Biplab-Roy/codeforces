#include<bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1e9+7;

ll f(vector<int> &nums,int ind, int andVal,int k,vector<vector<int>> &dp){
    // cout<<ind<<" "<<andVal<<endl;
    if(ind < 0){
        if(__builtin_popcount(andVal) == k) return 1;
        return 0;
    }
    if(dp[ind][andVal] != -1) return dp[ind][andVal];
    ll take = f(nums,ind-1,nums[ind]&andVal,k,dp);
    ll notTake = f(nums,ind-1,andVal,k,dp);
    ll res = (take+notTake) % mod;
    return dp[ind][andVal] = res;
}   

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    ////////////////////////////////// 
    vector<vector<int>> dp(n,vector<int>(128,-1));  
    cout<<f(nums,n-1,127,k,dp)<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}