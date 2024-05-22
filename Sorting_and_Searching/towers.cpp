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

    int n;cin>>n;
    int ans = 0;

    multiset<ll> topElenments;

    for(int i=0;i<n;i++){

        int x;cin>>x;
        auto it = topElenments.upper_bound(x);
        if(it==topElenments.end()) {
            ans++;
            topElenments.insert(x);
        } else {
            topElenments.erase(it);
            topElenments.insert(x);
        }

    }

    // for(int i=0;i<t.size();i++) {
    //     cout<<t[i]<<" ";
    // }
    // cout<<endl;

    cout<<ans<<endl;


}

int main() {
    init_code();
    solve();
    return 0;
}