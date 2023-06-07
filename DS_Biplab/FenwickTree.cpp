#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;
    public: 
    FenwickTree(vector<int> &arr) {
        n = arr.size();
        tree = vector<int>(n);
        for(int i = 1; i <= n; i++) {
            add(i, arr[i], n);
        }
    }

    void add(int ind, int element, int n) {
        while(ind <= n) {
            tree[ind] += element;
            ind = ind + ((-ind) & ind);
        }
    }

    int sum(int ind) {
        int s = 0;
        while(ind) {
            s += tree[ind];
            ind = ind - ((-ind) & ind);
        }
        return s;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    int lower_bound(int element) {
        int ind = 0, prev_sum = 0;
        for(int i = log2(n); i>=0; i--) {
            if(prev_sum + tree[ind + (1 << i)] < element) {
                ind += (1 << i);
                prev_sum += tree[ind];
            }
        }
        return 1 + ind;
    }

    void printTree() {
        for(int e : tree) cout << e << " ";
        cout << endl;
    }
    
};