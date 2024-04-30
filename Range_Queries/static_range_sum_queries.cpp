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

void solve() {

    ll n,q;cin >> n >> q;
    vector<ll> prefix(n+1,0);
    for(ll i=1;i<n+1;i++) {
        cin>>prefix[i];
    }

    for(ll i=1;i<n+1;i++) {
        prefix[i] = prefix[i] + prefix[i-1];
    }


    while(q--) {
        ll l,r;cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << endl;
    }

}


int main() {
    init_code(); 
    solve();
    return 0;
}
