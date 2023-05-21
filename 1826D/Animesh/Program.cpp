#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> b(n),pref(n),suff(n);
    for(int i=0; i<n; i++){
        cin>>b[i];
        pref[i] = b[i] + i;
        suff[i] = b[i] - i;
    }
    /////////////////////////////////  
    for(int i=1;i<n;i++){
        pref[i] = max(pref[i],pref[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        suff[i] = max(suff[i],suff[i+1]);
    }
    int maxi = -1e9;
    for(int i=1;i<n-1;i++){
        maxi = max(maxi,b[i]+pref[i-1]+suff[i+1]);
    }
    cout<<maxi<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}