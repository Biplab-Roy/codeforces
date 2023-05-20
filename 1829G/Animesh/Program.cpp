#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    
    vector<long long> dp(1e7,0);
    for(long long i=0;i<1e7;i++){
        dp[i] = i*i;
    }
    for(long long l=1;l<=2023;l++){
        long long k = 0;
        long long start = (l*(l-1)/2)+1;
        long long next = (l*(l+1)/2)+1;
        for(long long i=start;i<start+l;i++){
            // cout<<i<<" : "<<next+k<<","<<next+1+k<<endl;
            dp[next+k] += dp[i];
            dp[next+1+k] += dp[i];
            k++;
        }
        long long pl = l-1;
        long long spl = (pl*(pl-1))/2+1;
        for(long long i=next+1;pl>=1 && i<=next+l-1;i++) {
            // cout<<i<<" : "<<spl<<endl;
            dp[i] -= dp[spl++];
        }
        // cout<<endl;
    }
    // for(int i=0;i<11;i++){
    //     cout<<dp[i]<<" ";
    // }
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ////////////////////  
        cout<<dp[n]<<endl;
    }
}