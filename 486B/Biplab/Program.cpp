#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m, n, a;
    cin >> m >> n;
    vector<int> rowsum(m, 0), colsum(n, 0);
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            cin >> a;
            mat[i][j] = a;
            rowsum[i] += a;
            colsum[j] += a;
        }
    }
    bool valid = true, one = false;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            if(mat[i][j]==1){
                one = true;
                if(rowsum[i] == n || colsum[j] == m) continue;
                else {
                    valid = false;
                    break;
                }
            }
        }
    }
    if(!valid) {
        cout << "NO" << endl;
    }
    else {
        if(one){
            bool row = false, col = false;
            for(int e : rowsum) if(e == n) row = true;
            for(int e : colsum) if(e == m) col = true;
            if(!row || !col){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(rowsum[i] == n && colsum[j] == m) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
}
/*
3 3
1 0 0
1 0 0
1 0 0
*/

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}