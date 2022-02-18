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


vector pre,in,post
int n;
int pos = 0;

void rec(int left, int right){
    if(left >= right) return;
    int root = pre[pos++];
}

void solve(){
    rec(0,pre.size());
    rep(i,0,n){}
}

int main(){

    cin >> n;

    int k;
    rep(i,0,n){
        cin >> k;
        pre.push_back(k);
    }

    rep(i,0,n){
        cin >> k;
        in.push_back(k);
    }

    solve();

}