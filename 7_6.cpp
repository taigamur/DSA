// マージソートの応用　発想が難しい
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
int MAX = 200000;

vector<int> L(MAX/2 + 2);
vector<int> R(MAX/2 + 2);

// マージソートの応用部分
ll sort(vector<int> &A, int n, int left, int mid, int right){
    int i,j,k;
    ll ans = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i,0,n1) L[i] = A[left + i];
    rep(i,0,n2) R[i] = A[mid + i];
    L[n1] = R[n2] = inf; // 最後の要素の比較用

    i = j = 0;
    rep(k,left,right){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
            ans += n1 - i; //Lを追い抜いた個数
        }
    }
    return ans;
}


ll calc(vector<int> &A, int n, int left, int right){
    int mid;
    ll v1,v2,v3;
    if(left + 1 < right){ // midを計算して分割しているため、要素2個では不可。
        mid = (left + right) / 2;
        v1 = calc(A, n, left, mid);
        v2 = calc(A, n, mid, right);
        v3 = sort(A, n, left, mid, right);
        return v1 + v2 + v3;
    }else return 0;
}

// 下の要素が変更されていいない？


int main(){
    int n;
    cin >> n;
    vector<int> A(MAX);
    rep(i,0,n) cin >> A[i];

    ll ans = calc(A, n, 0, n);
    cout << ans << endl;
}