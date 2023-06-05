#include<bits/stdc++.h>
using namespace std;

// Query Segment Tree
class SegmentTree {
    vector<int> segmentTree;
    vector<int> v;
    int n;

    public:
    SegmentTree(vector<int> &v) {
        this->v = v;
        this->n = v.size();
        segmentTree = vector<int>(4*n + 1);
        buildTree(0, n - 1, 0);
    }
    SegmentTree(int n) {
        v = vector<int>(n, 0);
        this->n = v.size();
        segmentTree = vector<int>(4*n + 1);
        buildTree(0, n - 1, 0);
    }

    int buildTree(int l, int r, int ind) {
        // Base Case
        if(l == r) {
            segmentTree[ind] = v[l];
            return segmentTree[ind];
        }

        // Solve for children
        int m = (l + r) / 2;
        buildTree(l, m, 2*ind + 1);
        buildTree(m + 1, r, 2*ind + 2);

        // Merge Solution
        segmentTree[ind] = min(segmentTree[2*ind + 1], 
                                segmentTree[2*ind + 2]);
    }

    private:
    int __query(int l, int r, int a, int b, int pos) {
        // Base Case
        if(l >= a && r <= b) {
            return segmentTree[pos];
        }
        
        // Out of Range Case
        if(l > b || r < a) {
            return INT_MAX;
        }

        // Solve for children
        int m = (l + r) / 2;
        int left = __query(l, m, a, b, 2*pos + 1);
        int right = __query(m + 1, r, a, b, 2*pos + 2);

        // Merge Solution
        return min(left, right);
    }

    public:
    int query(int a, int b) {
        return __query(0, n - 1, a, b, 0);
    }
};

// Point update SegmentTree
class SegmentTree
{
    vector<int> segmentTree;
    vector<int> v;
    int n;

public:
    SegmentTree(vector<int> &v)
    {
        this->v = v;
        this->n = v.size();
        segmentTree = vector<int>(4 * n + 1);
        buildTree(0, n - 1, 0);
    }
    SegmentTree(int n)
    {
        v = vector<int>(n, 0);
        this->n = v.size();
        segmentTree = vector<int>(4 * n + 1);
        buildTree(0, n - 1, 0);
    }

    void buildTree(int l, int r, int ind)
    {
        // Base Case
        if (l == r)
        {
            segmentTree[ind] = v[l];
            return;
        }

        // Solve for children
        int m = (l + r) / 2;
        buildTree(l, m, 2 * ind + 1);
        buildTree(m + 1, r, 2 * ind + 2);

        // Merge Solution
        segmentTree[ind] = segmentTree[2 * ind + 1] +
                           segmentTree[2 * ind + 2];
    }

private:
    int __query__(int l, int r, int a, int b, int pos)
    {
        // Base Case
        if (l >= a && r <= b)
        {
            return segmentTree[pos];
        }

        // Out of Range Case
        if (l > b || r < a)
        {
            return 0;
        }

        // Solve for children
        int m = (l + r) / 2;
        int left = __query__(l, m, a, b, 2 * pos + 1);
        int right = __query__(m + 1, r, a, b, 2 * pos + 2);

        // Merge Solution
        return left + right;
    }

public:
    int query(int a, int b)
    {
        return __query__(0, n - 1, a, b, 0);
    }

private:
    void __pointUpdate__(int l, int r, int ind, int a, int val)
    {
        // Base Case
        if (l == r)
        {
            segmentTree[ind] += val;
            return;
        }

        // Solve for children
        int m = (l + r) / 2;
        if (a <= m)
        {
            __pointUpdate__(l, m, 2 * ind + 1, a, val);
        }
        else
        {
            __pointUpdate__(m + 1, r, 2 * ind + 2, a, val);
        }

        // Merge Solution
        segmentTree[ind] = segmentTree[2 * ind + 1] +
                           segmentTree[2 * ind + 2];
    }

public:
    void pointUpdate(int a, int val)
    {
        __pointUpdate__(0, n - 1, 0, a, val);
    }

};

// Range lazy update segment tree
class SegmentTree
{
    vector<int> segmentTree;
    vector<int> lazy;
    vector<int> v;
    int n;

public:
    SegmentTree(vector<int> &v)
    {
        this->v = v;
        this->n = v.size();
        segmentTree = vector<int>(4 * n + 1);
        lazy = vector<int>(4 * n + 1, 0);
        buildTree(0, n - 1, 0);
    }
    SegmentTree(int n)
    {
        v = vector<int>(n, 0);
        this->n = v.size();
        segmentTree = vector<int>(4 * n + 1);
        buildTree(0, n - 1, 0);
    }

    void buildTree(int l, int r, int ind)
    {
        // Base Case
        if (l == r)
        {
            segmentTree[ind] = v[l];
            return;
        }

        // Solve for children
        int m = (l + r) / 2;
        buildTree(l, m, 2 * ind + 1);
        buildTree(m + 1, r, 2 * ind + 2);

        // Merge Solution
        segmentTree[ind] = segmentTree[2 * ind + 1] +
                           segmentTree[2 * ind + 2];
    }

private:
    int __query__(int l, int r, int a, int b, int ind)
    {
        // lazy query
        if (lazy[ind] != 0)
        {
            segmentTree[ind] += (r - l + 1) * lazy[ind];
            if (l != r)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // Base Case
        if (l >= a && r <= b)
        {
            return segmentTree[ind];
        }

        // Out of Range Case
        if (l > b || r < a || r < l)
        {
            return 0;
        }

        // Solve for children
        int m = (l + r) / 2;
        int left = __query__(l, m, a, b, 2 * ind + 1);
        int right = __query__(m + 1, r, a, b, 2 * ind + 2);

        // Merge Solution
        return left + right;
    }

public:
    int query(int a, int b)
    {
        return __query__(0, n - 1, a, b, 0);
    }

private:
    void __rangeUpdate__(int l, int r, int ind, int a, int b, int val)
    {
        // lazy query
        if (lazy[ind] != 0)
        {
            segmentTree[ind] += (r - l + 1) * lazy[ind];
            if (l != r)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // Out of Range Case
        if (l > b || r < a || r < l)
        {
            return;
        }
        // Base Case
        if (l >= a && r <= b)
        {
            segmentTree[ind] += (r - l + 1) * val;
            if (l != r)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        // Solve for child
        int m = (l + r) / 2;
        __rangeUpdate__(l, m, 2 * ind + 1, a, b, val);
        __rangeUpdate__(m + 1, r, 2 * ind + 2, a, b, val);
        // Merge solution
        segmentTree[ind] = segmentTree[2 * ind + 1] +
                           segmentTree[2 * ind + 2];
    }

public:
    void rangeUpdate(int a, int b, int val)
    {
        __rangeUpdate__(0, n - 1, 0, a, b, val);
    }
};