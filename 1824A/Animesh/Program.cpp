#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    // //////////////////////////////// //
    int cnt1 = 0, cnt2 = 0, dem = 0;
    vector<int> freq(m+1);
    for(int i=0;i<n;i++){
        if(x[i] == -1) cnt1++;
        else if(x[i] == -2) cnt2++;
        else freq[x[i]] = 1;
    }
    for(int i=0;i<=m;i++){
        if(freq[i]>0) dem++;
    }
    long long ans = max(cnt1,cnt2)+dem;
    ////////////////////////////////////////////////////////////////
    for(int i=1;i<=m;i++){
        freq[i] += freq[i-1];
    }
    // for(auto it:freq){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<"ans = "<<ans<<endl;
    for(int i=0;i<n;i++){
        if(x[i] > 0){
            int k = x[i];
            long long demL = freq[k-1];
            long long demR = freq[m] - freq[k];
            long long valL = cnt1+demL<k-1?cnt1+demL:k-1;
            long long valR = cnt2+demR<m-k?cnt2+demR:m-k;
            ans = ans>1+valL+valR?ans:1+valL+valR;
        }
    }
    ans = ans<m?ans:m;
    cout<<ans<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}