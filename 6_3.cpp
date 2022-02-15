// コッホ曲線、再帰関数
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

void calc(int n, pair<double,double> a, pair<double,double> b){
    if(n == 0){
        return;
    }

    pair<double,double> s,t,u;
    s.first = (2*a.first + b.first) / 3;
    s.second = (2*a.second + b.second) / 3;
    t.first = (a.first + 2*b.first) / 3;
    t.second = (a.second + 2*b.second) / 3;
    double th = M_PI * 60 / 180;
    u.first = (t.first - s.first) * cos(th) - (t.second - s.second) * sin(th) + s.first;
    u.second = (t.first - s.first) * sin(th) + (t.second - s.second) * cos(th) + s.second;
    calc(n-1, a, s);
    cout << setprecision(10) << s.first << " " << s.second << endl;
    calc(n-1, s, u);
    cout << setprecision(10) << u.first << " " << u.second << endl;
    calc(n-1, u, t);
    cout << setprecision(10) << t.first << " " << t.second << endl;
    calc(n-1, t, b);
}

int main(){

    int n;
    cin >> n;

    pair<double,double> a,b;
    a.first = 0;
    a.second = 0;
    b.first = 100;
    b.second = 0;
    cout << a.first << " " << a.second << endl; 
    calc(n, a, b);
    cout << b.first << " " << b.second << endl;

}