#include<bits/stdc++.h>
using namespace std;

int solve(){
    long long int n, c, d, a;
    cin >> n >> c >> d;
    set<unsigned long long int> set;
    for(int i=0; i<n; i++){
        cin >> a;
        set.insert(a);
    }
    unsigned long long int fixed_cost = (n - set.size()) * c, cost = LONG_LONG_MAX;
    vector<unsigned long long int> nums(set.begin(), set.end());
    unsigned long long int m = nums.size();
    
    for(int i=nums.size(); i>0; i--){
        cost = min(cost, (unsigned long long int)((m-i)*c + (nums[i-1] - i)*d));
    }
    cost = min(cost, m*c + d);
    cout << cost + fixed_cost << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}