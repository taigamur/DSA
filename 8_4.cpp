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

#define SIZE 10005
struct Node{
    int right, left, parent;
};
struct Node node[SIZE];

// 行きがけ順
void preParse(int u){
    if(u == -1) return;
    cout << " " << u;
    preParse(node[u].left);
    preParse(node[u].right);
}

// 通りがけ順
void inParse(int u){
    if(u == -1) return;
    inParse(node[u].left);
    cout << " " << u;
    inParse(node[u].right);
}

// 帰りがけ順
void postParse(int u){
    if(u == -1) return;
    postParse(node[u].left);
    postParse(node[u].right);
    cout << " " << u;
}

int main(){

    int n;
    cin >> n;
    rep(i,0,n) node[i].parent = -1;

    rep(i,0,n){
        int v,left,right;
        cin >> v >> left >> right;
        node[v].left = left;
        node[v].right = right;
        if(left != -1) node[left].parent = v;
        if(right != -1) node[right].parent = v;
    }

    int root;
    rep(i,0,n) if(node[i].parent == -1) root = i;

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;

    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;

    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;


}