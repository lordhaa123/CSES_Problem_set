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

#define right 0
#define left 1
#define down 2
#define up 3

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int vis[7][7] = {0};

bool is_valid(int x) {
    if(x>=0 && x<7) return true;
    return false;
}

string s;

int count_paths(int x,int y, int pos) {

    if(pos == 48 && x == 6 && y == 0) return 1;

    if(x == 6 && y == 0) return 0;

    if(vis[x][y] == 1) return 0;

    bool visited[4] = {false};

    for(int i=0;i<4;i++) {
        if(is_valid(x+dx[i]) && is_valid(y+dy[i])) {
            visited[i] = vis[x+dx[i]][y+dy[i]];
        }
    }

    if (!visited[down] && !visited[up] && visited[right]
        && visited[left])
        return 0;


    if (!visited[right] && !visited[left] && visited[down]
        && visited[up])
        return 0;

    if (is_valid(x - 1) && is_valid(y + 1)
        && vis[x - 1][y + 1] == 1)
        if (!visited[right] && !visited[up])
            return 0;

    if (is_valid(x + 1) && is_valid(y + 1)
        && vis[x + 1][y + 1] == 1)
        if (!visited[right] && !visited[down])
            return 0;

    if (is_valid(x - 1) && is_valid(y - 1)
        && vis[x - 1][y - 1] == 1)
        if (!visited[left] && !visited[up])
            return 0;

    if (is_valid(x + 1) && is_valid(y - 1)
        && vis[x + 1][y - 1] == 1)
        if (!visited[left] && !visited[down])
            return 0;
   

    vis[x][y] = 1;

    int ans = 0;

    if(s[pos] == '?') {
        for(int i=0;i<4;i++) {
            if(is_valid(x+dx[i]) && is_valid(y+dy[i])) {
                ans += count_paths(x+dx[i],y+dy[i],pos+1);
            }
        }
    } else if(s[pos] == 'R' && is_valid(y+1)) {
        ans += count_paths(x,y+1,pos+1);
    } else if(s[pos] == 'L' && is_valid(y-1)) {
        ans += count_paths(x,y-1,pos+1);
    } else if(s[pos] == 'U' && is_valid(x-1)) {
        ans += count_paths(x-1,y,pos+1);
    } else  if(s[pos] == 'D' && is_valid(x+1)) {
        ans += count_paths(x+1,y,pos+1);
    }

    vis[x][y] = 0;

    return ans;

}

void solve() {

    cin>>s;

    cout<<count_paths(0,0,0)<<endl;

}

int main() {
    init_code();
    solve();
    return 0;
}