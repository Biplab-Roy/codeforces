#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin >> str;
    vector<int> arr(128, INT_MIN);
    for(int i = 'a'; i <= 'z'; i++) {
        int gaps = 0;
        for(char ch : str) {
            if(ch == i){
                arr[i] = max(arr[i], gaps); 
                gaps = 0;
            }
            else gaps++;
        }
        arr[i] = max(arr[i], gaps);
    }
    int min_gap = INT_MAX;
    for(int e : arr) if(e != INT_MIN) min_gap = min(min_gap, e);
    cout<<(min_gap==0?0:(int)log2(min_gap)+1)<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}