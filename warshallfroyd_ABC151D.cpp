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
static const int MAX = 10000;
static const ll INFTY = 1e12;

int dp[500][500];

void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
}


int main(){

  int H, W;
  char s[30][30];
  int dp_h;
  int ans = 0;

  //入力
  cin >> H >> W;
  REP(i, H){
    REP(j, W){
      cin >> s[i][j];
    }
  }

  //初期化
  REP(i, H*W){
    REP(j, H*W){
      dp[i][j] = MAX;
    }
  }


  REP(i, H){
    dp_h = W * i;
    REP(j, W){
      if( s[i][j+1] == '.' && s[i][j] == '.' ){
        dp[dp_h + j][dp_h + j+1] = dp[dp_h + j+1][dp_h + j] = 1;
      }
      if( s[i][j] == '.' && s[i+1][j] == '.' ){
        dp[dp_h + j][dp_h + j + W] = dp[dp_h + j + W][dp_h + j] = 1;
      }
    }
  }

  //REP(i, H*W){
  //  REP(j, H*W){
  //    cout << dp[i][j] << " ";
  //  }
  //  cout << endl;
  //}


  warshall_floyd(H*W);
  
  for (int i = 0; i < H*W; i++) {
    for (int j = 0; j < H*W; j++) {
      if (i != j && dp[i][j] != MAX)
        ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << endl;

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