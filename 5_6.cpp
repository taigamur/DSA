// 二分探索で最適解を探す
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<int> w;
int n,k;


// 必要な台数を返す
int check(ll key){
    int ans = 1;
    ll sum = 0;
    rep(i,0,w.size()){

        if(w[i] > key) return -1;

        if(sum + w[i] <= key){
            sum += w[i];
        }else{
            sum = w[i];
            ans++;
        }
    }

    if(ans > k) return -1;
    else return 1;
}

int main(){
    
    cin >> n >> k;
    
    rep(i,0,n){
        int t;
        cin >> t;
        w.push_back(t);
    }

    ll left = 0;
    ll right = INF;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        int v = check(mid);
        if(v == 1) right = mid;
        else left = mid;
    }

    cout << right << endl;

}