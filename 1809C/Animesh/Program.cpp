#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int n1 = (-1+sqrt(1+4*2.0*k))/2;
    vector<int> res;
    for(int i=0;i<n1;i++){
        res.push_back(2);
    }
    if(n1*(n1+1) == 2*k){
        for(int i=n1;i<n;i++){
            res.push_back(-1000);
        }
    }else{
        int remaining = k-(n1*(n1+1))/2;
        // if(remaining>0 && n-n1 == 1){

        // }else{
        //     res.push_back(-n1-2);
        //     res.push_back(remaining);
        //     for(int i=n1+2;i<n;i++){
        //         res.push_back(-1000);
        //     }
        // }
        res.push_back(-(2*(n1-remaining)+1));
        for(int i=n1+1;i<n;i++){
            res.push_back(-1000);
        }
    }
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}