#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
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

struct Node{
    int parent,left,right;
};

Node node[100005];
int Depth[100005];
void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << node[u].parent << ", ";
    cout << "depth = " << Depth[u] << ", ";

    if(node[u].parent == -1) cout << "root, ";
    else if(node[u].left == -1) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    int i = node[u].left;
        if(i != -1){
        cout << i;
        i = node[i].right;
        while(i != -1){
            cout << ", ";
            cout << i;
            i = node[i].right;
        }
        
    }
    cout << "]" << endl;

}

//再帰的に深さを求める
void get_depth(int u, int p){
    Depth[u] = p;
    if(node[u].left != -1) get_depth(node[u].left, p+1);
    if(node[u].right != -1) get_depth(node[u].right, p);

}

int main(){
    int n;
    cin >> n;
    rep(i,0,n) node[i].parent = node[i].left = node[i].right = -1;

    rep(i,0,n){
        int v,d;
        cin >> v >> d;
        rep(j,0,d){
            int c;
            int l;
            cin >> c;
            if(j == 0) node[v].left = c;
            else node[l].right = c;
            l = c;
            node[c].parent = v;
        }
    }

    int root;
    rep(i,0,n){
        if(node[i].parent == -1) root = i;
    }

    get_depth(root,0);

    rep(i,0,n) print(i);

    return 0;
}