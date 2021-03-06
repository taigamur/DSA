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

struct UnionFind{
    vector<int> par,siz;

    //初期化
    UnionFind(int n) : par(n,-1),siz(n,1){}
    //根を求める
    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    //x,yが同じグループかどうか
    bool issame(int x, int y){
        return root(x) == root(y);
    }
    //xを含むグループとyを含むグループを合併
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        //union by size (y側のサイズが小さくなるように)
        if(siz[x] < siz[y]) swap(x,y);
        //yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    //xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};

class Edge{
    public:
    int source, target, cost;
    Edge(int source = 0, int target = 0, int cost = 0):
    source(source), target(target), cost(cost){}
    bool operator < (const Edge &e) const{
        return cost < e.cost;
    }
};

int kruskal(int N, vector<Edge> edges){
    int totalCost = 0;
    sort(edges.begin(), edges.end());
    UnionFind uf(N+1);
    int source, target;
    for(int i = 0; i < edges.size(); i++){
        Edge e = edges[i];
        if( !uf.issame(e.source, e.target)){
            totalCost += e.cost;
            uf.unite(e.source, e.target);
        }
    }
    return totalCost;
}

int main(){
    int N,M,cost;
    int source, target;
    cin >> N >> M;

    vector<Edge> edges;
    for(int i = 0; i < M; i++){
        cin >> source >> target >> cost;
        edges.push_back(Edge(source, target, cost));
    }

    cout << kruskal(N, edges) << endl;
}