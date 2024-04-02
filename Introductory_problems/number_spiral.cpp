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

    ll x,y;cin>>x>>y;

    if(y>x) {
        //cout<<"here"<<endl;
        ll area = (y-1)*(y-1);

        if(y%2!=0) {
            area += (2*y-x);
        } else {
            area += x;
        }

        cout<<area<<endl;

    } else {

        ll area = (x-1)*(x-1);
        if(x%2!=0) {
            area += y;
        } else {
            area += (2*x-y);
        }
        cout<<area<<endl;

    }

    return;

}

int main() {
    init_code();

    int t;cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}