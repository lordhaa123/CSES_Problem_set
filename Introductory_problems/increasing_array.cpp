#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
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

int main() {
    init_code();

    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) {
        cin>>a[i];
    }

    ll ans = 0;
    ll largest = a[0];
    for(ll i=0; i<n; i++) {
        if(a[i] < largest) {
            ans += (largest - a[i]);
        }
        else {
            largest = a[i];
        }
    }
    cout<<ans<<endl;

    return 0;
}