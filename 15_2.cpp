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
static const int MAX = 100000;
#define SIZE 10005
struct Node{
    int right, left, parent;
};
struct Node node[SIZE];

vector<int> G[MAX];
vector<int> ans;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s){
    queue<int> q;
    q.push(s);
    V[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        rep(i,0,G[u].size()){
            int v = G[u][i];
            indeg[v]--;
            if(indeg[v]== 0 && !V[v]){
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void tsort(){
    rep(i,0,N){
        indeg[i] = 0;
    }

    rep(u,0,N){
        rep(i,0,G[u].size()){
            int v = G[u][i];
            indeg[v]++; // vが依存している個数
        }
    }

    rep(u,0,N){
        if(indeg[u] == 0 && !V[u]) bfs(u);
    }

    rep(i,0,ans.size()){
        cout << ans[i] << endl;
    }

    
}


int main(){

    int M;
    cin >> N >> M;

    rep(i,0,N) V[i] = false;

    int s,t;
    rep(i,0,M){
        cin >> s >> t;
        G[s].push_back(t);
    }

    tsort();


}