#include<bits/stdc++.h>

using namespace std;

class DSU {
    public:
    vector<int> parent;
    DSU(int n) {
        parent.clear();
        parent = vector<int>(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int getParent(int element){
        if(parent[element] != element) return parent[element] = getParent(parent[element]);
        return element;
    }
    bool unionSet(int e1, int e2){
        int p1 = getParent(e1);
        int p2 = getParent(e2);
        if(p1 == p2) return false;
        parent[p1] = p2;
        return true;
    }
    bool isSameSet(int e1, int e2){
        int p1 = getParent(e1);
        int p2 = getParent(e2);
        return p1 == p2;
    }
    int count_components() {
        unordered_set<int> components;
        for(int i = 0; i < parent.size(); i++) {
            components.insert(getParent(i));
        }
        return components.size();
    }
};
