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

Node node[10005];
int Depth[10005], Height[10005];

void setDepth(int u, int d){
    if(u == -1) return;
    Depth[u] = d;
    setDepth(node[u].left, d + 1);
    setDepth(node[u].right, d+1);
}

int setHeight(int u){
    int h1 = 0;
    int h2 = 0;
    if(node[u].left != -1) h1 = setHeight(node[u].left) + 1;
    if(node[u].right != -1) h2 = setHeight(node[u].right) + 1;
    
    if(h1 > h2) return Height[u] = h1;
    else return Height[u] = h2;
}

int getSibling(int u){
    if(node[u].parent == -1) return -1;
    if(node[node[u].parent].left != u && node[node[u].parent].left != -1) return node[node[u].parent].left;
    if(node[node[u].parent].right != u && node[node[u].parent].right != -1) return node[node[u].parent].right;
    return -1;
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << node[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    int deg = 0;
    if(node[u].left != -1) deg++;
    if(node[u].right != -1) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << Depth[u] << ", ";
    cout << "height = " << Height[u] << ", ";

    if(node[u].parent == -1) cout << "root" << endl;
    else if(node[u].left == -1 && node[u].right == -1) cout << "leaf" << endl;
    else cout << "internal node" << endl;

}

int main(){

    int n;
    cin >> n;
    rep(i,0,n) node[i].parent = -1;

    rep(i,0,n){
        int v, l, r;
        cin >> v >> l >> r;
        node[v].left = l;
        node[v].right = r;
        if(l != -1) node[l].parent = v;
        if(r != -1) node[r].parent = v;
    }

    int root;
    rep(i,0,n) if(node[i].parent == -1) root = i;

    setDepth(root,0);
    setHeight(root);

    rep(i,0,n) print(i);

}