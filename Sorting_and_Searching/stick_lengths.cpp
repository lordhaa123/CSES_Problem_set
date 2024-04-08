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

    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    ll res1 = 0,res2 = 0;
    for(ll i=0;i<n;i++) {
        res1 += abs(a[i]-a[n/2]);
        res2 += abs(a[i]-a[n/2+1]);
    }

    cout<<min(res1,res2)<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}