#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    // -------------------------------------
    vector<long long> pref(n,0);
    pref[0] = b[0];
    for(int i=1; i<n; i++){
        pref[i] = pref[i-1]+b[i];
    }
    vector<long long> freq(n+1), rem(n+1);
    for(int i=0; i<n; i++){
        long long val = a[i];
        if(i>0) val += pref[i-1];
        long long ind = upper_bound(pref.begin(),pref.end(),val) - pref.begin();
        freq[ind]++;
        long long remaining = val;
        if(ind>0){
            remaining = remaining-pref[ind-1];
        }
        rem[ind] += remaining;
    }
    for(int i=1;i<=n;i++){
        freq[i] += freq[i-1];
    }
    for(int i=0;i<n;i++){
        long long v = (long long)(i+1-freq[i])*b[i]  + rem[i];
        cout<<v<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}