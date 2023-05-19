#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> pos(n+1);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        pos[x] = i;
    }
    //////////////////////////////////  
    int k = n/2;
    int ll,lr,rl,rr;
    while(k){
        ll = k;
        lr = k+1;
        rl = n-k+1;
        rr = n-k;
        if(pos[ll]>=pos[lr] || pos[rl] <= pos[rr]){
            break;
        }
        k--;
    }
    cout<<k<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}