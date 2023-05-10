#include<bits/stdc++.h>
using namespace std;

long long int find_optimal(vector<long long int> &v, long long int pos, long long int n){
    long long int total_operations = 0, prev = 0;
    for(int i = pos + 1; i < n; i++){
        long long int curr_operations = (prev / v[i] + 1);
        total_operations += curr_operations;
        prev = v[i] * curr_operations;
        // cout << i << curr_operations << endl;
    }
    prev = 0;
    for(int i = pos - 1; i >= 0; i--){
        long long int curr_operations = (prev / v[i] + 1);
        total_operations += curr_operations;
        prev = v[i] * curr_operations;
        // cout << i << curr_operations << endl;
    }
    return total_operations;
}

long long int solve() {
    long long int n, operations = 1e18;
    cin >> n;
    vector<long long int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int pos = 0; pos < n; pos++){
        operations = min(operations, find_optimal(v, pos, n));
    }
    
    // return find_optimal(v, 3, n);
    return operations;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}