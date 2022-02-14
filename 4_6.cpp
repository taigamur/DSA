// stackを利用して、面積計算
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    stack<int> S1;
    stack<pair<int,int>> S2;

    string str;
    cin >> str;

    int ans = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '\\') S1.push(i);
        else if(str[i] == '/' && S1.size() > 0){
            int j = S1.top();
            S1.pop();
            ans += i - j;
            int a = i - j;
            while(S2.size() > 0 && S2.top().first > j){ //左から見ているため、j以上の始点のエリアは同じエリアになる。
                a += S2.top().second; //面積の加算
                S2.pop();
            }
            S2.push(make_pair(j,a));
        }
    }

    vector<int> list;
    while(!S2.empty()){
        list.push_back(S2.top().second);
        S2.pop();
    }
    cout << ans << endl;
    cout << list.size();
    for(int i = list.size()-1; i >= 0; i--){
        cout << " ";
        cout << list[i];
    }
    cout << endl;
}