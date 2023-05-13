#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,c,d;
    cin>>n>>c>>d;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }
    // -------------------------- 
    sort(nums.begin(),nums.end());
    // duplicate elements must be removed
    long long cntDup = 0;
    long long prev = nums[0];
    vector<long long> temp;
    temp.push_back(prev);
    for(long long i=1;i<n;i++){
        if(nums[i]==prev){
            cntDup++;
        }else{
            prev = nums[i];
            temp.push_back(prev);
        }
    }
    // cout<<"cntDup: "<<cntDup<<endl;
    n = temp.size();
    // cout<<"n : "<<n<<endl;
    // is 1 there?
    bool isOne = false;
    if(temp[0] == 1){
        isOne = true;
    }
    long long res = LONG_LONG_MAX;
    if(isOne){
        prev = 0;
        long long skip = 0;
        for(long long i=0;i<n;i++){
            skip += temp[i]-prev-1;
            prev = temp[i];
            long long del = n-i-1;
            // cout<<skip<<" "<<del<<endl;
            res = res>skip*d+del*c?skip*d+del*c:res;
        }
    }else{
        prev = 1;
        long long skip = 0;
        for(long long i=0;i<n;i++){
            skip += temp[i]-prev-1;
            prev = temp[i];
            long long del = n-i-1;
            res = res>skip*d+del*c?skip*d+del*c:res;
        }
        res += d;
        // all delete
        res = res>d+n*c?d+n*c:res;
    }
    res = res+cntDup*c;
    if(res == 1e9){
        cout<<0<<endl;
    }else{
        cout<<res<<endl;
    }
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}