#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    // //////////////////////////////////////////////////////////////////////////
    map<int,pair<int,int>> mp;
    for(int i=0;i<n;i++){
        if(mp.find(nums[i]) == mp.end()){
            mp[nums[i]] = {i,i};
        }else{
            mp[nums[i]].second = i;
        }
    }
    // finding the MEX
    int mex = 0;
    while(true){
        if(mp.find(mex) == mp.end()){
            break;
        }else{
            mex++;
        }
    }
    //
    // cout<<"MEX : "<<mex<<endl;
    // for(auto it:mp){
    //     cout<<it.first<<" : "<<it.second.first<<","<<it.second.second;
    //     cout<<endl;
    // }
    
    bool mexP1 = false;
    if(mp.find(mex+1) != mp.end()){
        mexP1 = true; // mex+1 is present in the array
    }
    int dubLesMex = 0;
    for(int i=0;i<n;i++){
        if(nums[i]<mex){
            dubLesMex += mp[nums[i]].second - mp[nums[i]].first;
        }
    }
    int greaterThanmexp1 = 0;
    for(int i=0;i<n;i++){
        if(nums[i]>mex+1){
            greaterThanmexp1 = 1;
            break;
        }
    }
    // cout<<dubLesMex<<" "<<cntMexp1<<endl;
    if(!mexP1){
        if(dubLesMex >0 || greaterThanmexp1){
             cout<<"YES"<<endl;
            return;
        }
    }
    // if more than one mex+1 is present, theh cehck if all the index of some of  the value < mex, completely lies in the range of lb and up then "NO"
    int lb = mp[mex+1].first;
    int ub = mp[mex+1].second;
    for(int i=0;i<n;i++){
        if(nums[i]<mex){
            if(lb <= mp[nums[i]].first && mp[nums[i]].second <= ub){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}