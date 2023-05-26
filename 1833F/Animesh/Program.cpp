#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int binExpIter(int a,int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans*1LL*a)%mod;
        }
        a = (a*1LL*a)%mod;
        b = b>>1;
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ////////////////////////////// 
    
    sort(arr.begin(),arr.end());
    vector<int> nums;
    unordered_map<int,int> mp;
    nums.push_back(arr[0]);
    mp[arr[0]]++;
    for(int i=1;i<n;i++){
        mp[arr[i]]++;
        if(nums.back() != arr[i]){
            nums.push_back(arr[i]);
        }
    }
    n = nums.size();
    vector<int> freq(n);
    for(int i=0;i<n;i++){
        freq[i] = mp[nums[i]];
    }
    // for(auto it:freq){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    vector<int> freqq(n,0);
    // cout<<"DONE1"<<endl;
    // preprocess the freq array
    int mul = 1;
    int i = 0,j = 0;
    // cout<<"n = "<<n<<endl;
    while(j<n){
        // cout<<i<<" "<<j<<endl;
        if(j<m){
            mul = ((mul%mod)*1LL*(freq[j]%mod))%mod;
            freqq[j] = mul;
            j++;
        }else{
            int mmi = binExpIter(freq[i],mod-2);
            mul = (mul*1LL*mmi)%mod;
            mul = ((mul%mod)*1LL*(freq[j]%mod))%mod;
            freqq[j] = mul;
            i++; j++;
        }
    }
    // cout<<"DONE2"<<endl;
    // getting the ans
    i = 0;j = m-1;
    int cnt = 0;
    while(i<=n-m){
        if(nums[j]-nums[i] < m){
            cnt = (cnt + freqq[j])%mod;
        }
        i++;j++;
    }
    cout<<cnt<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}