#include<bits/stdc++.h>
using namespace std;

string solve(){
    int n, a;
    cin >> n;
    vector<int> arr;

    int pos=0, neg=0, zeros=0;
    bool inc_series = false, dec_series = false;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a == 0) {
            zeros++;
            if(zeros <= 1) arr.push_back(a);
        }
        else if(a > 0) {
            pos++;
            if(pos < 3) arr.push_back(a);
            else inc_series = true;
        }
        else if(a < 0) {
            neg++;
            if(neg < 3) arr.push_back(a);
            else dec_series = true;
        }
    }

    if(inc_series || dec_series) return "NO";
    unordered_set<int> hash(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            for(int k=j+1; k<arr.size(); k++) {
                if(hash.find(arr[i] + arr[j] + arr[k]) == hash.end()) return "NO";
            }
        }
    }

    return "YES";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout<<solve()<<endl;
    }
}