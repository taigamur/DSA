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

class DisjoinSet{
    public:
        vector<int> rank, p;

        DisjoinSet(){}
        DisjoinSet(int size){
            rank.resize(size,0);
            p.resize(size,0);
            rep(i,0,size) makeSet(i);
        }

        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }

        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }

        void link(int x, int y){
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }

        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

int main(){

    int n,q;
    cin >> n >> q;
    DisjoinSet ds = DisjoinSet(n);

    int t,a,b;
    rep(i,0,q){
        cin >> t >> a >> b;
        if(t == 0) ds.unite(a,b);
        else if(t == 1){
            if(ds.same(a,b)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}