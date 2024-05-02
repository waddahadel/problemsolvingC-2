#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl);

struct Node
{
    int wildCount;
};

class SegmentTree
{
private:
    int n;
    vector<Node> tree;

    void buildTree(const vector<int> &colonies, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node].wildCount = (colonies[start] % 10) % 2;
        }
        else
        {
            int mid = (start + end) / 2;
            buildTree(colonies, 2 * node, start, mid);
            buildTree(colonies, 2 * node + 1, mid + 1, end);
            tree[node].wildCount = tree[2 * node].wildCount + tree[2 * node + 1].wildCount;
        }
    }

    void updateTree(int node, int start, int end, int idx, int newValue)
    {
        if (start == end)
        {
            tree[node].wildCount = (newValue % 10) % 2;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
            {
                updateTree(2 * node, start, mid, idx, newValue);
            }
            else
            {
                updateTree(2 * node + 1, mid + 1, end, idx, newValue);
            }
            tree[node].wildCount = tree[2 * node].wildCount + tree[2 * node + 1].wildCount;
        }
    }

    int queryTree(int node, int start, int end, int left, int right)
    {
        if (start > right || end < left)
        {
            return 0;
        }
        else if (start >= left && end <= right)
        {
            return tree[node].wildCount;
        }
        else
        {
            int mid = (start + end) / 2;
            int leftCount = queryTree(2 * node, start, mid, left, right);
            int rightCount = queryTree(2 * node + 1, mid + 1, end, left, right);
            return leftCount + rightCount;
        }
    }

public:
    SegmentTree(const vector<int> &colonies)
    {
        n = colonies.size();
        tree.resize(4 * n);
        buildTree(colonies, 1, 0, n - 1);
    }

    void update(int idx, int newValue)
    {
        updateTree(1, 0, n - 1, idx - 1, newValue);
    }

    int query(int left, int right)
    {
        return queryTree(1, 0, n - 1, left - 1, right - 1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> colonies(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> colonies[i];
    }

    SegmentTree segmentTree(colonies);

    vector<int> results;
    for (int i = 0; i < q; ++i)
    {
        char type;
        int a, b;
        cin >> type >> a >> b;
        if (type == 'U')
        {
            segmentTree.update(a, b);
        }
        else if (type == 'Q')
        {
            int result = segmentTree.query(a, b);
            results.push_back(result);
        }
    }

    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}