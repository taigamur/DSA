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

#define SIZE 10005
struct Node{
    int right, left, parent;
};
struct Node node[SIZE];

static const int MAX = 10000;

int n;
vector<pair<int,int>> M[MAX];

void dijkstra(){
    priority_queue<pair<int,int>> PQ;
    int color[MAX]; //　-1:未訪問, 0:候補, 1:確定
    int d[MAX];
    rep(i,0,n){
        d[i] = inf;
        color[i] = -1;
    }

    d[0] = 0;
    PQ.push(make_pair(0,0)); // 距離, node
    color[0] = 0;

    while(!PQ.empty()){

        // 候補の中からの探索がO(logV)になり効率化
        pair<int,int> p = PQ.top();
        PQ.pop();

        int u = p.second;
        color[u] = 1;

        if(d[u] < p.first * (-1)) continue;

        rep(i,0,M[u].size()){
            int v = M[u][i].first;
            if(color[v] == 1) continue;
            if(d[v] > d[u] + M[u][i].second){
                d[v] = d[u] + M[u][i].second;
                //降順にするため、-1をかける
                PQ.push(make_pair(d[v]*(-1), v));
                color[v] = 0;
            }
        }
    }

    rep(i,0,n){
        cout << i << " ";
        if(d[i] == inf){
            cout << -1 << endl;
        }else{
            cout << d[i] << endl;
        }
    }
}

int main(){
    cin >> n;
    int u,k;
    int v,c;
    rep(i,0,n){
        cin >> u >> k;
        rep(j,0,k){
            cin >> v >> c;
            M[u].push_back(make_pair(v,c));
        }
    }

    dijkstra();

    return 0;
}