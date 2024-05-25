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

    int n;cin>>n;
    ordered_set<int> st;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        st.insert(i);
    }

    for(int i=0;i<n;i++) {
        int x;cin>>x;
        auto idx = st.find_by_order(x-1);
        cout<<arr[*idx]<<endl;
        st.erase(idx);
    }


    
}


int main() {
    init_code(); 
    solve();
    return 0;
}
