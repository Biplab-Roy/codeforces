#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    // =----------------------------------  
    // Calculate row sum and column sum of the B matrix
    vector<int> rowMat(m,0),colMat(n,0);
    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += mat[i][j];
        }
        rowMat[i] = sum;
    }
    for(int j=0;j<n;j++){
        int sum = 0;
        for(int i=0;i<m;i++){
            sum += mat[i][j];
        }
        colMat[j] = sum;
    }
    // If any cell is 0, means all the row and columns corresponding to that cell will be zero in original matrix
    vector<int> rowInd(m,1),colInd(n,1);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 0){
                rowInd[i] = 0;
                colInd[j] = 0;
            }
        }
    }
    // Generate the A matrix
    vector<vector<int>> res(m,vector<int>(n,1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(rowInd[i] == 0 || colInd[j] == 0){
                res[i][j] = 0;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(res[i][j] == 1){
                if(rowMat[i] != n || colMat[j] != m){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    rowMat.assign(m,0);
    colMat.assign(n,0);
    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += res[i][j];
        }
        rowMat[i] = sum;
    }
    for(int j=0;j<n;j++){
        int sum = 0;
        for(int i=0;i<m;i++){
            sum += res[i][j];
        }
        colMat[j] = sum;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1 && rowMat[i] == 0 && colMat[j] == 0){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    solve();
}