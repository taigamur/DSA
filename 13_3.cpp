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
static const int inf = numeric_limits<int>::max();
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int n;
static const int MAX = 10000;
int M[MAX][MAX];

void dijkstra(){
    int minv;
    int d[n];
    int color[n]; //訪問したかどうか

    rep(i,0,n){
        d[i] = inf;
        color[i] = -1;
    }

    d[0] = 0;
    color[0] = 0; //候補

    while(true){
        minv = inf;
        int u = -1;
        // 候補から重みが最小のものを1つ選択
        rep(i,0,n){
            if(minv > d[i] && color[i] != 1){
                u = i;
                minv = d[i];
            }
        }
        if(u == -1) break;
        //候補の確定
        color[u] = 1;
        //候補に隣接したノードの更新
        rep(v,0,n){
            if(color[v] != 1 && M[u][v] != inf){
                if(d[v] > d[u] + M[u][v]){
                    d[v] = d[u] + M[u][v];
                    color[v] = 0;
                }
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
    rep(i,0,n){
        rep(j,0,n){
            M[i][j] = inf;
        }
    }

    int u,k;
    int v,c;
    rep(i,0,n){
        cin >> u >> k;
        rep(j,0,k){
            cin >> v >> c;
            M[u][v] = c;
        }
    }

    dijkstra();

    return 0;
}