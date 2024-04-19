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

void solve() {

    ll n,m;cin >> n >> m;

    vector<vector<pair<ll,ll> > > grid(n);

    for(ll i=0;i<m;i++) {
        ll a,b,c;cin>>a>>b>>c;
        grid[a-1].push_back(make_pair(b-1,c));
    }

    vector<ll> res(n,LLONG_MAX);
    vector<ll> vis(n,0);
    res[0] = 0;

    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()) {
        ll u = pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(uint i=0;i<grid[u].size();i++) {
            ll v = grid[u][i].first;
            ll w = grid[u][i].second;
            if(res[v] > res[u]+w) {
                res[v] = res[u]+w;
                pq.push(make_pair(res[v],v));
            }
        }

    }



    for(ll i=0;i<n;i++) {
        cout<<res[i]<<" ";
    }

    return;
}


int main() {
    init_code(); 
    solve();
    return 0;
}
