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
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int idxa=0,idxb=0;

    int ans = 0;

    while(idxa<n && idxb<m) {
        if(a[idxa]>=b[idxb]-k && a[idxa]<=b[idxb]+k) {
            ans++;
            idxa++;
            idxb++;
        } else if(a[idxa] < b[idxb]-k) {
            idxa++;
        } else if(a[idxa] > b[idxb]+k) {
            idxb++;
        }
    }

    cout<<ans<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}