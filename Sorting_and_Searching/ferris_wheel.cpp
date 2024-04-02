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

    int n,x;cin>>n>>x;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    int ans = 0;
    sort(p.begin(),p.end());

    int l=0,r=n-1;
    while(l<r) {
        if(p[l]+p[r]<=x) {
            ans++;
            l++;
            r--;
        }
        else {
            ans++;
            r--;
        }
    }
    if(l==r) {
        if(p[l]<=x) ans++;
    }

    cout<<ans<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}