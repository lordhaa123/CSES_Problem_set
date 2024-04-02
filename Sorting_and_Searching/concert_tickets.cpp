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

    int n,m;cin>>n>>m;
    //cout<<"hi"<<endl;
    map<int,int> h;
    vector<int> t(m);

    for(int i=0;i<n;i++) {
        int x;cin>>x;
        h[x]++;
    }

    for(int i=0;i<m;i++) cin>>t[i];

    for(int i=0;i<m;i++) {
        map<int,int>::iterator it = h.upper_bound(t[i]);
        if(it == h.begin()) {
            cout<<-1<<endl;
        } else {
            it--;
            cout<<it->first<<endl;
            it->second--;
            if(it->second == 0) {
                h.erase(it);
            }
        }
    }


}

int main() {
    init_code();
    solve();
    return 0;
}