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

    string s;cin>>s;
    uint n=s.size();
    set<string> st;

    sort(s.begin(), s.end());

    do {
        st.insert(s);
    } while(next_permutation(s.begin(), s.end()));

    cout<<st.size()<<endl;
    for(set<string>::iterator it=st.begin();it!=st.end();it++) {
        cout<<*it<<endl;
    }
}


int main() {
    init_code();
    solve();
    return 0;
}