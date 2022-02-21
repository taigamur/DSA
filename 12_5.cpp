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

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<vector<int>> G(100005,vector<int>()); 
vector<int> color(100005);
int n;

void dfs(int s, int id){
    stack<int> S;
    S.push(s);
    color[s] = id;
    while(!S.empty()){
        int u = S.top();
        S.pop();

        rep(i,0,G[u].size()){
            int v = G[u][i];
            if(color[v] == -1){
                color[v] = id;
                S.push(v);
            }
        }
    }
}

void assignColor(){
    int id = 1;
    rep(i,0,n) color[i] = -1;
    rep(i,0,n){
        if(color[i] == -1) dfs(i,id);
        id++;
    }
}

int main(){

    int m;
    cin >> n >> m;

    rep(i,0,m){
        int s,t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    assignColor(); //連結成分ごとに色づけ

    int k;
    cin >> k;
    rep(i,0,k){
        int a,b;
        cin >> a >> b;
        if(color[a] == color[b]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;

}