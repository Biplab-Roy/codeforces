#include<bits/stdc++.h>
using namespace std;

long long nc2(long long n){
    if(n>=2)
        return n*(n-1)/2;
    return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    vector<int> dp(m+n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> pv(m,vector<int>(2));
    // cout<<"m : "<<m<<endl;
    for(int i=0;i<m;i++){
        cin>>pv[i][0]>>pv[i][1];
        pv[i][0]--;
    }
    // cout<<"DONE"<<endl;
    // ---------------------------   
    vector<int> stInd(m+n+1,-5),endInd(m+n+1,-5);
    for(int i=0;i<n;i++){
        stInd[arr[i]] = -1;
    }
    for(int i=0;i<m;i++){
        int ind = pv[i][0];
        int newVal = pv[i][1];
        // endpoint of the old value at ind
        endInd[arr[ind]] = i;
        // cout<<arr[ind]<<" : "<<stInd[arr[ind]]<<" "<<endInd[arr[ind]]<<endl;
        dp[arr[ind]] += (endInd[arr[ind]] - stInd[arr[ind]]);
        arr[ind] = newVal;
        stInd[newVal] = i;
        endInd[newVal] = -5;
    }
    for(int i=0;i<=m+n;i++){
        if(endInd[i] == -5 && stInd[i] != -5){
            dp[i] += (m-stInd[i]);
        }
    }
    // for(auto it:stInd){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:endInd){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:dp){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // for(auto it:dp){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    long long total = m+1; // total number of arrays
    long long sum = 0;
    for(int i=0;i<=m+n;i++){
        // cout<<"dp :"<<dp[i]<<endl;
        sum += (nc2(total) - nc2(total - dp[i]));
        // cout<<sum<<endl;
    }
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}