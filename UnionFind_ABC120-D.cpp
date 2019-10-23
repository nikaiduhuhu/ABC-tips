#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pow(x) x*x
#define ll long long
static const int MAX = 100010;
static const ll INFTY = 1e12;

class UnionFind {
  public:

  vector<ll> Parent;
  vector<ll> Size;

  //Constructor
  UnionFind( ll InitSize ) : Parent( InitSize ), Size( InitSize, 1LL ) {
    for( ll i = 0; i < InitSize; i++ ) Parent[i] = i; //myself
  } 

  void Init( ll InitSize ){
    Parent.resize( InitSize );
    Size.assign( InitSize, 1LL );
    for( ll i = 0; i < InitSize; i++ ) Parent[i] = i; //myself   
  }

  //Member Function
  //FindRoot
  ll FindRoot( ll x ){
    while( Parent[x] != x ){
      x = Parent[x] = Parent[Parent[x]];
    }
    return x;
  }

  //Merge
  void Merge( ll x, ll y ){
    x = FindRoot(x);
    y = FindRoot(y);
    if (x == y) return;
    if (Size[x] < Size[y]) swap(x, y);
    Size[x] += Size[y];
    Parent[y] = x;
    return;
  }

  bool IsSame(ll x, ll y) { 
      return FindRoot(x) == FindRoot(y);
  }

  ll CalcSize(ll x) { 
      return Size[FindRoot(x)];
  }
};

int main(){

  ll N, M, a, b;
  vector< pair<ll, ll> > Bridge(MAX);

  cin >> N >> M;

  REP(i, M) {
        cin >> a >> b; --a, --b;
        Bridge[i].first = a;
        Bridge[i].second = b;
  }

  vector<ll> ans(M);
  ll node1, node2;
  UnionFind UF(N);
  ans[M-1] = ( N * ( N - 1 ) ) / 2;

  for( ll i = M-1; i >= 1; i-- ){
    node1 = Bridge[i].first, node2 = Bridge[i].second;
    if( UF.IsSame( node1, node2 ) ){
      ans[i-1] = ans[i];
    } else{
      ans[i-1] = ans[i] - ( UF.CalcSize(node1) * UF.CalcSize(node2) );
      UF.Merge( node1, node2 );
    }
  }

  REP(i, M) {
        cout << ans[i] << "\n";
  }

  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/