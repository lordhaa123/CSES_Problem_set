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

const int maxN = 2e5+1;
ll ds[maxN];

void update(int idx,ll val,int n) {
    for(int i=idx;i<=n;i += -i&i) {
        ds[i]+=val;
    }
}

ll query(int idx,int n) {
    ll sum = 0;
    for(int i=idx;i>0;i-= -i&i) {
        sum+=ds[i];
    }
    return sum;
}

void solve() {

    int n,q;cin>>n>>q;
    vector<ll> arr(n);
    for(int i=1;i<=n;i++){ 
        int x;cin>>x;
        update(i+1,-x,n);
        update(i,x,n);
    }

    while(q--) {
        int type;cin>>type;
        if(type==1) {
            int a,b,val;cin>>a>>b>>val;
            update(b+1,-val,n);
            update(a,val,n);
        } else {
            int k;cin>>k;
            cout<<query(k,n)<<endl;
        }
    }
    
}


int main() {
    init_code(); 
    solve();
    return 0;
}
