#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> mp(n,1);
    if(n>1){
        mp[1] = 2;
    }
    for(int i=2;i<n;i++){
        if(arr[i-1] < arr[i]){
            mp[i] = mp[i-1]+1;
        }else{
            if(arr[i-2] < arr[i-1]){
                mp[i] = mp[i-1]+1;
            }else{
                mp[i] = mp[i-1];
            }
        }
    }
    // for(auto it:mp){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int res;
        if(l>0)
            res = mp[r] - mp[l-1];
        else
            res = mp[r];
        if(1<=l && l<n){
            if(mp[l-1] == mp[l]) res++;
            if(mp[l] == mp[l+1]) res++;
        }
        if(r-l+1<3){
            cout<<r-l+1<<endl;
        }else{
            cout<<res<<endl;
        }
    }
}