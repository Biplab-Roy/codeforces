#include<bits/stdc++.h>
using namespace std;
/*
    link-> https://codeforces.com/problemset/problem/1823/C
    APPROACH:
        
*/
void getAllPrimeFactor(unordered_map<int,int> &mp, int num){
    int tnum = num;
    for(int i=2;i*i<=tnum;i++){
        while(num%i == 0){
            mp[i]++;
            num = num/i;
        }
        if(num == 1) break;
    }
    if(num>1){
        mp[num]++;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        //......................................
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        //---------------------------------------- 
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            getAllPrimeFactor(mp,nums[i]);
        }
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        ///----------------------------------------
        vector<int> temp;
        for(auto it:mp){
            temp.push_back(it.second);
        }
        //----------------------------------------- 
        // cout<<"--------------------------------"<<endl;
        // for(auto it:temp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int cnt = 0;
        for(int i=0;i<temp.size();i++){
            cnt += temp[i]/2;
            temp[i] = temp[i]%2;
        }
        // cout<<cnt<<endl;
        // for(auto it:temp){
        //     cout<<it<<" ";
        // }
        // cout<<"\n--------------------------------"<<endl;

        int sum = accumulate(temp.begin(),temp.end(),0);
        cnt += sum/3;
        cout<<cnt<<endl;
    }
}