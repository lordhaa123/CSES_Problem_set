#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <cstring>
#include <bitset>
#include <limits.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
#define endl "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

void init_code() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}

template<typename valueType, typename tagType>
class segmentTreeNode
{
public:
    int id, left, right;
    valueType val;
    tagType tag;
};

template<typename valueType,
         typename tagType,
         valueType (*merge)(valueType, valueType),
         void (*update)(segmentTreeNode<valueType, tagType>&, tagType)>
class segmentTree
{
private:
    std::vector<segmentTreeNode<valueType, tagType> > nodes;
    int leftRange, rightRange;
    valueType valueZero;
    tagType tagZero;
    
    void pushup(int cur)
    {
        nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
    }
    
    void pushdown(int cur)
    {
        update(nodes[cur << 1], nodes[cur].tag);
        update(nodes[cur << 1 | 1], nodes[cur].tag);
        nodes[cur].tag = tagZero;
    }
    
    void build(int cur, int l, int r, const std::vector<valueType>& initValue)
    {
        nodes[cur].id = cur;
        nodes[cur].left = l;
        nodes[cur].right = r;
        nodes[cur].tag = tagZero;
        if (l == r - 1) nodes[cur].val = initValue[l - leftRange];
        else
        {
            build(cur << 1, l, (l + r) >> 1, initValue);
            build(cur << 1 | 1, (l + r) >> 1, r, initValue);
            pushup(cur);
        }
    }
    
    void init(const std::vector<valueType>& _initValue,
              const valueType& _valueZero,
              const tagType& _tagZero)
    {
        valueZero = _valueZero;
        tagZero = _tagZero;
        nodes.resize((rightRange - leftRange) << 2);
        build(1, leftRange, rightRange, _initValue);
    }
    
    void modify(int cur, int l, int r, int L, int R, const tagType& tag)
    {
        if (l >= R || r <= L) return;
        if (L <= l && r <= R) update(nodes[cur], tag);
        else
        {
            pushdown(cur);
            modify(cur << 1, l, (l + r) >> 1, L, R, tag);
            modify(cur << 1 | 1, (l + r) >> 1, r, L, R, tag);
            pushup(cur);
        }
    }
    
    valueType query(int cur, int l, int r, int L, int R)
    {
        if (l >= R || r <= L) return valueZero;
        if (L <= l && r <= R) return nodes[cur].val;
        pushdown(cur);
        return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                     query(cur << 1 | 1, (l + r) >> 1, r, L, R));
    }
    
public:
    segmentTree() {}
    
    segmentTree(int _leftRange,
                int _rightRange,
                const std::vector<valueType>& _initValue,
                const valueType& _valueZero,
                const tagType& _tagZero)
    {
        leftRange = _leftRange;
        rightRange = _rightRange;
        init(_initValue, _valueZero, _tagZero);
    }
    
    segmentTree(int size,
                const std::vector<valueType>& _initValue,
                const valueType& _valueZero,
                const tagType& _tagZero)
    {
        leftRange = 1;
        rightRange = size + 1;
        init(_initValue, _valueZero, _tagZero);
    }
    
    void modify(int l, int r, const tagType& tag)
    {
        modify(1, leftRange, rightRange, l, r, tag);
    }
    
    void modify(int p, const tagType& tag)
    {
        modify(p, p + 1, tag);
    }
    
    valueType query(int l, int r)
    {
        return query(1, leftRange, rightRange, l, r);
    }
    
    valueType query(int p)
    {
        return query(p, p + 1);
    }
};

ll merge(ll x,ll y) {
    return x+y;
}

void update(segmentTreeNode<ll,int>& node,int x) {
    if(x!=int()) {
        if(node.val != 0) {
            node.val = x;
            return;
        }
        node.val+=x;
    }
}

void solve() {

    int n,q;cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    segmentTree<ll,int,merge,update> segTree(n,arr,0,0);

    while(q--) {
        int opt,l,r;cin>>opt>>l>>r;
        if(opt == 1) {
            segTree.modify(l,r);
        } else {
            cout<<segTree.query(l,r+1)<<endl;
        }
    }
    
}


int main() {
    init_code(); 
    solve();
    return 0;
}
