#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    /////////////////////////////////////// 
    sort(nums.begin(), nums.end());
    int l = 0,h = nums[n-1],m;
    while(l<=h){
        m = (l+h)/2;
        int cnt = 1;
        int point = nums[0]+2*m;
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<" : "<<point<<endl;
            if(point < nums[i]){
                point = nums[i]+2*m;
                cnt++;
            }
        }
        // cout<<m<<" "<<cnt<<endl;
        if(cnt <= 3){
            h = m-1;
        }else{
            l = m+1;
        }
    }
    cout<<l<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}