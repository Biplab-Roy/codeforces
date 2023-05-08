#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    bool res = true;
    int posCnt = 0,negCnt = 0;
    for(auto it:nums){
        if(it>0){
            posCnt++;
        }else if(it<0){
            negCnt++;
        }
    }
    if(posCnt>=3 || negCnt>=3){
        cout<<"NO"<<endl;
    }else{
        vector<int> arr;
        int zeros = 0;
        for(auto it:nums){
            if(it == 0){
                if(zeros<2){
                    zeros++;
                    arr.push_back(it);
                }
            }else{
                arr.push_back(it);
            }
        }
        if(arr.size()<3){
            cout<<"YES"<<endl;
        }else{
            unordered_map<int,bool> mp;
            for(auto it:arr){
                mp[it] = true;
            }
            int n = arr.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<n;k++){
                        if(mp.find(arr[i]+arr[j]+arr[k]) == mp.end()){
                            res = false;
                        }
                    }
                }
            }
            if(res){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}