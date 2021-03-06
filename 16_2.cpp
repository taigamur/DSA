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
static const int MAX = 100005;
#define SIZE 10005

class Point{
    public:
    double x,y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}       

    Point operator + (Point p) {return Point(x + p.x, y + p.y);}
    Point operator - (Point p) {return Point(x - p.x, y - p.y);}
    Point operator * (double a) {return Point(a * x, a * y);}
    Point operator / (double a) {return Point(x / a, y / a);}

    double abs() {return sqrt(norm());}
    double norm() {return x*x + y*y;}

};

//内積
double dot(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}

//外積
double cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

//直交判定
bool isOrthgonal(Point a, Point b){
    return abs(dot(a,b)) < 1e-10; //小さな誤差対応
}


//平行判定
bool isParallel(Point a, Point b){
    return abs(cross(a,b)) < 1e-10;
}

int main(){
    int N;
    cin >> N;

    rep(i,0,N){
        int x0,x1,x2,x3;
        int y0,y1,y2,y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point a(x1-x0, y1-y0);
        Point b(x3-x2, y3-y2);

        if(isParallel(a,b)){
            cout << "2" << endl;
        }else if(isOrthgonal(a,b)){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
}