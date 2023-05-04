#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> valid = {0, 1, 2};
    for(int i=2; i<n; i++) {
        if(v[i-2]>=v[i-1] && v[i-1]>=v[i]){
            valid.push_back(0);
        }
        else valid.push_back(1);
        valid[i+1] += valid[i];
    }
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        int ans = 0;
        if(r-l+1>=3){
            ans += valid[r] - valid[l-1];
            ans += (valid[l]==valid[l-1]);
            ans += (valid[l]==valid[l+1]);
            cout<<ans<<endl;
        }
        else
            cout<<r-l+1<<endl;
    }
}