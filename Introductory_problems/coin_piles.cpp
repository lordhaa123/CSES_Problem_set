#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
    ll a,b;cin>>a>>b;
    if(b>a) swap(a,b);
    ll diff = a-b;

    a -= (2*diff);

    b -= diff;

    if(a<0 || b<0) {
        cout<<"NO"<<endl;
        return;
    }

    if(a%3 == 0 && b%3 == 0) {
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
    return;

}

int main() {
    init_code();
    ll t;cin>>t;
    while(t--)
        solve();
    return 0;
}