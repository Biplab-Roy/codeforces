#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    // ---------------------------------------------------------------
    long long res = 1e18;
    long long temp;
    for(int i=0;i<n;i++){ // considering ith position as 0
        long long cnt = 0;
        long long prev = 0;
        for(int j=i-1;j>=0;j--){
            temp = prev/nums[j]+1;
            cnt += temp;
            prev = temp*nums[j];
        }
        prev = 0;
        for(int j=i+1;j<n;j++){
            temp = prev/nums[j]+1;
            cnt += temp;
            prev = temp*nums[j];
        }
        res = cnt<res?cnt:res;
    }
    cout<<res<<endl;
}