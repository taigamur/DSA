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

static const int MAX = 100;

int n;
ll d[MAX][MAX];

void floyd(){
    // kが中継点
    rep(k,0,n){
        rep(i,0,n){
            if(d[i][k] == INF) continue;
            rep(j,0,n){
                if(d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    int e;
    cin >> n >> e;

    rep(i,0,n){
        rep(j,0,n){
            if(i == j){
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }

    int u,v,c;
    rep(i,0,e){
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    floyd();
    
    bool negative = false;
    // 自分への距離が負だった場合は負閉路がある
    rep(i,0,n) if(d[i][i] < 0) negative = true;

    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        rep(i,0,n){
            rep(j,0,n){
                if(j) cout << " ";
                if(d[i][j] == INF) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
}