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
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    ll sum=0;
    ll max_sum=INT_MIN;

    for(int i=0;i<n;i++) {
        sum+=a[i];
        max_sum=max(max_sum,sum);
        if(sum<0) {
            sum=0;
        }
    }
    cout<<max_sum<<endl;
}

int main() {
    init_code();
    solve();
    return 0;
}