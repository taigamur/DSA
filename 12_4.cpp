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
int d[100];

void bfs(int s){
    queue<int> q;
    q.push(s);
    rep(i,0,n) d[i] = -1;
    d[s] = 0;
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        rep(v,0,n){
            if(M[u][v] == 0) continue;//辺がない場合
            if(d[v] != -1) continue; //既に訪問済み
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    rep(i,0,n){
        cout << i + 1 << " " << d[i] << endl;
    }
}

int main(){
    cin >> n;
    rep(i,0,n){
        rep(j,0,n){
            M[i][j] = 0;
        }
    }

    rep(i,0,n){
        int u,k;
        cin >> u >> k;
        u--;
        rep(j,0,k){
            int v;
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    bfs(0);

    return 0;
}