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

int lcs(string X, string Y){
    int m = X.size();
    int n = Y.size();
    int c[m+1][n+1];

    rep(i,0,m+1) c[i][0] = 0;
    rep(i,0,n+1) c[0][i] = 0;  

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int a = 0;
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    return c[m][n];
}


int main(){

    
    int n;
    cin >> n;

    rep(i,0,n){
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1,s2) << endl;
    }


}