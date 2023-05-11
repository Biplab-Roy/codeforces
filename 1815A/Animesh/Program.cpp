#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // ------------------------- 
    vector<int> b(n-1);
    for(int i=1;i<n;i++){
        b[i-1] = nums[i] - nums[i-1];
    }
    if(n%2 == 0){ // b assray is odd
        long long sum = 0;
        for(int i=0;i<n-1;i+=2){
            sum += b[i];
        }
        if(sum >= 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{ // b array is even
        cout<<"YES"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}