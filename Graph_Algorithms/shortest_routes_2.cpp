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

    ll n,m,q;cin >> n >> m >> q;
    ll large = 1000000000000;
    vector<vector<ll> > res(n,vector<ll>(n,large));
    for(ll i=0;i<m;i++) {
        ll a,b,c;cin>>a>>b>>c;
        a--;
        b--;
        res[a][a] = 0;
        res[b][b] = 0;
        res[a][b] = min(res[a][b],c);
        res[b][a] = min(res[b][a],c);
    }

    for(int k=0;k<n;k++) {
        for(int j=0;j<n;j++) {
            for(int i=0;i<n;i++) {
                res[i][j] = min(res[i][j] , res[i][k] + res[k][j]);
            }
        }
    }

    while(q--) {
        ll src,dest;cin>>src>>dest;
        src--;
        dest--;
        if(res[src][dest] < large) {
            cout<<res[src][dest]<<endl;
        } else {
            cout<<-1<<endl;
        }
    }


}


int main() {
    init_code(); 
    solve();
    return 0;
}
