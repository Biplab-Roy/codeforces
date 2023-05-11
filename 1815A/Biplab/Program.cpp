#include<bits/stdc++.h>
using namespace std;

string solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(n%2==1) return "YES";
    // if(n == 2) return v[1] >= v[0]? "YES" : "NO";
    long long int diff_sum = 0;
    for(int i = 1; i < n; i+=2) {
        diff_sum += (v[i] - v[i-1]);
    }
    return diff_sum < 0? "NO" : "YES";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}