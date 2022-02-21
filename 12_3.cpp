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
int M[100][100];
int visit[100];
int d[100]; // 到達
int f[1000]; // 帰り

int cnt = 1;

void dfs_calc(int u){
    visit[u] = 1; //訪問した
    d[u] = cnt++;
    rep(i,0,n){
        if(M[u][i] == 0) continue;
        if(visit[i] == 0){
            dfs_calc(i);
        }
    }
    visit[u] = 2; // 終わり
    f[u] = cnt++;
}

void dfs(){

    rep(i,0,n) visit[i] = 0; // 訪問していない

    rep(i,0,n){
        if(visit[i] == 0) dfs_calc(i);
    }
    rep(i,0,n){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }
}

// 再帰による深さ優先
int main(){
    cin >> n;

    rep(i,0,n){
        rep(j,0,n){
            M[i][j] = 0;
        }
    }

    int u,k;
    rep(i,0,n){
        cin >> u >> k;
        u--;
        rep(j,0,k){
            int v;
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    dfs();
    
}