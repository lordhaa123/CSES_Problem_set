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

vector<int> dx(4),dy(4);
string step;

void solve() {

    int n,m;cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }

    vector<vector<bool> > vis(n,vector<bool>(m));

    pair<int,int> start,end;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') {
                vis[i][j] = 1;
            } else if(grid[i][j] == 'A') {
                start = make_pair(i,j);
            } else if(grid[i][j] == 'B') {
                end = make_pair(i,j);
            }
        }
    }
    // cout<<end.first<<":::" << end.second<<endl;

    queue<pair<int,int> > q;
    q.push(start);
    vis[start.first][start.second] = 1;
    bool flag=false;

    vector<vector<int> > parent(n,vector<int>(m));

    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();

        if(curr.first == end.first && curr.second == end.second) {
            flag = true;
            cout<<"YES"<<endl;
            break;
        }

        for(int i=0;i<4;i++) {
            int x = curr.first + dx[i];
            int y = curr.second + dy[i];

            if(x >= 0 && x < n && y >= 0 && y < m &&!vis[x][y]) {
                vis[x][y] = 1;
                q.push(make_pair(x,y));
                parent[x][y] = curr.first*m + curr.second;
            }
        }
    }
    if(flag == false) {
        cout<<"NO"<<endl;
        return;
    }

    string res = "";
    while(end.first != start.first || end.second !=start.second) {
        // cout<<end.first<<"::::"<<end.second<<"::::";
        int currVal = parent[end.first][end.second];
        // cout<<currVal<<endl;
        // if(currVal == 0) {
        //     break;
        // }
        int x = currVal/m;
        int y = currVal%m;


        if(x==end.first) {
            if(y < end.second) {
                res+='R';
            } else {
                res+='L';
            }
        } else {
            if(x<end.first) {
                res+='D';
            } else {
                res+='U';
            }
        }

        end.first = x;
        end.second = y;
    }

    reverse(res.begin(),res.end());
    cout<<res.size()<<endl;
    cout<<res<<endl;

    // cout<<endl<<endl;

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout<<parent[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<start.first<<":::" << start.second<<endl;
    // cout<<end.first<<":::" << end.second<<endl;

}


int main() {
    init_code(); 
    dx[0]=0; dy[0]=1;dx[1]=0; dy[1]=-1;dx[2]=1;dy[2]=0;dx[3]=-1;dy[3]=0;
    step = "RLDU";
    solve();
    return 0;
}