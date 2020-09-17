#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

// vectorの重複削除
// std::sort(test.begin(), test.end()); 昇順
// test.erase(std::unique(test.begin(), test.end()), test.end());

using namespace std;
using ll = long long;
using P = pair<int, int>; // vector<P> ba(n); みたいな感じですぐ使える ba[i] = P(a, b); make_pairをしなくてもいい
// typedef vector<int> v;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}
#define rep(i, c) for(int i = 0; i < int(c); i++)
#define ALL(x) (x).begin(), (x).end() //sort(ALL(obj))みたいな
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値
#define pb push_back //
// const int MOD = 1000000007;
// string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// printf("%.20f\n", ans); あれ
// const double PI = 3.141592653589793238462643383;

int n,k;
ll t[100000];

int check(ll p) {
  int i = 0;
  for (int j=0; j<k; j++) {
    ll s = 0;
    while (s + t[i] <= p) {
      s += t[i];
      i++;
      if (i == n) return n;
    }
  }
  return i;
}

int solve() {
  ll left = 0;
  ll right = 100000 * 10000;
  ll mid;
  while (right - left > 1) {
    mid = (left + right) / 2;
    int v = check(mid); // mid == P を決めて何個詰めるかチェック
    if (v >= n) right = mid;
    else left = mid;
  }
  return right;
}

int main() {
  cin>>n>>k;
  for (int i=0; i<n; i++) cin>>t[i];
  ll ans = solve();
  cout << ans << endl;
  int mid = 15 / 2;
  cout << mid << endl;
}

