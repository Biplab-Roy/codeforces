#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<long long int> &prefix_sum, long long int stub, long long int key, int l) {
    int ans = prefix_sum.size();
    int r = prefix_sum.size()-1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix_sum[mid] - stub >= key){
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<long long int> a(n), b(n), prefix_sum(n), taste_times(n+1, 0), left_tea(n+1, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(i!=0) prefix_sum[i] = prefix_sum[i-1] + b[i];
        else prefix_sum[i] = b[i];
    }
    long long int stub = 0;
    for(int i = 0; i < n; i++){
        int pos = binary_search(prefix_sum, stub, a[i], i);
        taste_times[i]++;
        taste_times[pos]--;
        if(pos!=0) left_tea[pos] += (a[i] - prefix_sum[pos-1] + stub);
        else left_tea[pos] += (a[i] + stub);
        stub += b[i];
    }

    for(int i=1; i<=n; i++) taste_times[i] += taste_times[i-1];

    for(int i=0; i<n; i++){
        cout << (taste_times[i]*b[i] + left_tea[i]) << " ";
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
/*

*/