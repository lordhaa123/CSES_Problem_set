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

    int n;cin >> n;

    queue<int> q;
    for(int i=0;i<n;i++) {
        q.push(i+1);
    }

    bool flag = true;
    while(q.size() > 1) {
        int curr = q.front();
        q.pop();
        if(!flag) {
            cout<<curr<<" ";
        } else {
            q.push(curr);
        }
        flag^=1;
    }

    cout<<q.front()<<endl;

    return;

}

int main() {
    init_code();
    solve();
    return 0;
}