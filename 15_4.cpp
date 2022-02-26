#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <math.h>
#include <iomanip>
#include <limits>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100005;
#define SIZE 10005
struct Node{
    int right, left, parent;
};
// struct Node node[MAX];

class Edge{
    public: 
    int t, w;
    Edge();
    Edge(int t, int w): t(t), w(w){};
};
vector<Edge> G[MAX];

int n;
int d[MAX];

void bfs(int s){
    rep(i,0,n) d[i] = inf; //距離の初期化
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    int u;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        rep(i,0,G[u].size()){
            Edge e = G[u][i];
            if(d[e.t] == inf){
                d[e.t] = d[u] + e.w;
                Q.push(e.t);
            }
        }
    }
}

void solve(){
    //適当に遠い点を求める
    bfs(0);
    int maxv = 0;
    int tgt = 0;
    rep(i,0,n){
        if(d[i] == inf) continue;
        if(maxv < d[i]){
            maxv = d[i];
            tgt = i;
        }
    }

    bfs(tgt);
    maxv = 0;
    rep(i,0,n){
        if(d[i] == inf) continue;
        maxv = max(maxv, d[i]);
    }

    cout << maxv << endl;
}

int main(){
    int s,t,w;
    cin >> n;

    rep(i,0,n-1){
        cin >> s >> t >> w;
        G[s].push_back(Edge(t,w));
        G[t].push_back(Edge(s,w));
    }

    solve();

}