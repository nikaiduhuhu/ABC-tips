#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define radrad(a)  180.0 * a / M_PI
#define pow(x) x*x
#define ll long long
static const int MAX = 1000010;
static const ll INFTY = 1e12;
static const int NUMMAX = 300;

int change( int N,  int a, int b ){

  int ans = 0;
  int tmp;

  if(a > b) swap(a, b);
  tmp = a - 1;
  REP(i, tmp){
    N--; 
    ans += N;
  }
  return ans + ( b-a-1 );

}

int toposort( int N, vector<int> G[MAX], int h[MAX] ){

  //入次数が0の頂点の集合
  stack<int> st;
  int ansans = 0;
  int dp[MAX] = {0,};

  //入次数が0の頂点であればstに追加
  REP(i, N) if(h[i] == 0) st.push(i);

  //ソートされた後のグラフ
  vector<int> ans;
  //stがなくなるまでループ
  while(st.size()) {
    //stの集合のから一つ取り出す
    int i = st.top(); st.pop();
    ans.push_back(i);
    for(auto& j: G[i]) {
      //隣接する頂点の入次数をマイナス1
      h[j]--;
      dp[j] = max( dp[j], dp[i] + 1 );
      ansans = max(ansans, dp[j]);
      //これによって入次数が0になればstに追加
      if(h[j] == 0) st.push(j);
    }
  }

  if( ans.size() != N ){
    ansans = -2;
  }

  return ansans;
}


int main() {

  //int M[MAX][MAX] = {0,};
  int hash;
  int tmpi, tmpj;
  int maehash;
  int N;
  int hyouN;
  vector<int> G[MAX];
  //頂点の入次数を管理
  int h[MAX] = {0,};
  int ans;

  cin >> N;

  REP(i, N){
    tmpi = i+1;
    REP(j, N-1){
      cin >> tmpj;
      hash = change(N, tmpi, tmpj);
      if(j != 0){
        G[maehash].push_back(hash);
        h[hash]++;
      } 
      maehash = hash;
    }
  }

  hyouN = 1;
  for(int i = 2; i < N; i++){
    hyouN += i; 
  }

  ans = toposort(hyouN, G, h);

  cout << ans + 1<< endl;

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