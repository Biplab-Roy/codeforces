#include<bits/stdc++.h>
using namespace std;

int solve(){
    long long x, a = 0, b = 0, sum, c = 0;
    cin >> x;
    sum = x << 1;
    for(int i=32; i>=0; i--) {
        int sb = ((sum >> i) & 1), xb = ((x >> i) & 1), cb = ((c >> i) & 1);
        if(sb == 0 && xb == 0) {
            if(cb == 1) {
                a |= 1 << i;
                b |= 1 << i;
            }
        }
        else if(sb == 1 && xb == 0) {
            if(cb == 1) {
                a |= 1 << i;
                b |= 1 << i;
                if(i==0) return -1;
                c |= 1 << (i-1);
            }
            else {
                if(i==0) return -1;
                c |= 1 << (i-1);
            }
        }
        else if(sb == 0 && xb == 1) {
            if(cb == 1) {
                a |= 1 << i;
                if(i==0) return -1;
                c |= 1 << (i-1);
            }
            else {
                return -1;
            }
        }
        else if(sb == 1 && xb == 1) {
            if(cb == 1) {
                return -1;
            }
            else {
                a |= 1 << i;
            }
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int op = solve();
        if(op == -1) cout << -1 << endl;
    }
}