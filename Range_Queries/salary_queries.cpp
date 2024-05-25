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
#define ull unsigned long long
#define MOD 1000000007
#define endl "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void init_code() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}


void solve() {

    int n,q;cin>>n>>q;
    ordered_set<pair<int,int> > st;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        st.insert({arr[i],i});
    }

    while(q--) {
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='!') {
            st.erase({arr[a],a});
            st.insert({b,a});
            arr[a]=b;
        } else if(c=='?'){
            cout<<st.order_of_key({b+1,0})-st.order_of_key({a,0})<<endl;
        }
    }
    
}


int main() {
    init_code(); 
    solve();
    return 0;
}
