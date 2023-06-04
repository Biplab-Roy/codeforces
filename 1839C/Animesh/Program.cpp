#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    //////////////////////////                  
    vector<int> res;
    if(nums[n-1] == 1){
        cout<<"NO"<<endl;
        return;
    }
    int cnt = 0;
    int numOnes = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            res.push_back(i-cnt);
            cnt++;
            while(numOnes--){
                res.push_back(0);
                cnt++;
            }
            numOnes = 0;
        }else{
            numOnes++;
        }
    }
    cout<<"YES"<<endl;
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}