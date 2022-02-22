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

int n;

static const int MAX = 100;
int M[MAX][MAX];

int prim(){
    int u, minv;
    int d[MAX]; //重みが最小の辺
    int p[MAX]; //頂点の親
    int color[MAX]; // 訪問状態

    rep(i,0,n){
        d[i] = inf;
        p[i] = -1;
        color[i] = -1;
    }

    d[0] = 0;

    while(true){
        minv = inf;
        u = -1;
        rep(i,0,n){
            if(minv > d[i] && color[i] != 1){
                u = i;
                minv = d[i];
            }
        }

        if(u == -1) break; //ノードの候補がなくなったら終了

        color[u] = 1; //ノードの確定

        rep(v,0,n){
            if(color[v] != 1 && M[u][v] != inf){
                if(d[v] > M[u][v]){
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = 0;
                }
            }
        }
    }

    int sum = 0;
    rep(i,0,n){
        if(p[i] != -1) sum += M[i][p[i]];
    }
    
    return sum;

}

int main(){
    cin >> n;

    rep(i,0,n){
        rep(j,0,n){
            int e;
            cin >> e;
            if(e == -1){
                M[i][j] = inf;
            }else{
                M[i][j] = e;
            }
            
        }
    }

    cout << prim() << endl;

    return 0;
}