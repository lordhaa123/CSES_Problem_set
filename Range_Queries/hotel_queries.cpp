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
#define ll long long
#define ull unsigned long long
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

const int N = 2000005;
int tree[2*N];

void update(int k,int x,int n) {
    k+=n;
    tree[k] = x;
    k=k>>1;
    while(k>=1) {
        tree[k] = max(tree[2*k],tree[2*k+1]);
        k=k>>1;
    }
}


int query(int x,int n) {
    if(tree[1]<x) return -1;
    int k = 1;
    while(k<n) {
        if(tree[2*k]>=x) {
            k = k<<1;
        } else {
            k = k<<1;
            k++;
        }
    }
    return k-n;
}

void solve() {

    int n,m;cin>>n>>m;
    int nn = n;
    n = ceil(log2(n*1.0));
    n = 1<<n;

    for(int i=0;i<nn;i++) {
        int x;cin>>x;
        update(i,x,n);
    }

    while(m--) {
        int x;cin>>x;
        int idx = query(x,n);
        if(idx>=0) {
            cout<<idx+1<<endl;
            update(idx,tree[idx+n]-x,n);
        } else {
            cout<<0<<endl;
        }
    }


}


int main() {
    init_code(); 
    solve();
    return 0;
}
