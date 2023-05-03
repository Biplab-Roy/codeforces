#include<bits/stdc++.h>
using namespace std;

void factorize(int a, unordered_map<int, int> &factor_counts){
    while(a%2==0){
        factor_counts[2]++;
        a /= 2;
    }
    int bound = sqrt(a);
    for(int i=3; i<=bound; i+=2){
        while (a%i == 0)    
        {
            factor_counts[i]++;
            a/=i;
        }
    }
    if(a!=1) factor_counts[a]++;
}

void solve(){
    int n, a;
    cin>>n;
    unordered_map<int, int> factor_counts;
    for(int i=0; i<n; i++){
        cin>>a;
        factorize(a, factor_counts);
    }
    int ans = 0;
    int single_factors = 0;
    for(auto &e : factor_counts){
        ans += e.second/2;
        single_factors += e.second % 2;
    }
    cout<<ans + single_factors/3<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}