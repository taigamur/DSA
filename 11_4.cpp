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


int main(){
    int n;
    cin >> n;

    int p[n+1];
    rep(i,1,n+1){
        cin >> p[i-1] >> p[i];
    }

    int m[n+1][n+1];
    for(int i = 1; i <= n; i++) m[i][i] = 0;
    
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i + l - 1;
            m[i][j] = inf;
            for(int k = i; k <= j-1; k++){
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
            }
        }
    }
   l cout << m[1][n] << endl;

}