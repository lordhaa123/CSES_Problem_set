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
    vector<ll> arr(n);

    for(ll i=0;i<n;i++) cin>>arr[i];

    ll ans = 1LL;

    sort(arr.begin(),arr.end());

    for(ll i=0;i<n;i++) {
        if(arr[i]>ans) {
            cout<<ans<<endl;
            return;
        }
        ans+=arr[i];
    }

    cout<<ans<<endl;
    return;
}

int main() {
    init_code();
    solve();
    return 0;
}