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
    float n;cin>>n;
    if(n==1) {
        cout<<1<<endl;
        return;
    }

    if(n<=3) {
        cout<<"NO SOLUTION"<<endl;
        return;
    }

    if(n==4) {
        cout<<"2 4 1 3"<<endl;
        return;
    }

    int curr = 1;
    for(int i=0;i<ceil(n/(float)2);i++) {
        cout<<curr<<" ";
        curr+=2;
    }

    curr = 2;
    for(int i=0;i<floor(n/(float)2);i++) {
        cout<<curr<<" ";
        curr+=2;
    }

    //cout<<curr<<endl;
    return;

}

int main() {
    init_code();

    solve();

    return 0;
}