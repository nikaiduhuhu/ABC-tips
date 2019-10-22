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
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

// dijkstra with priority queue
// weight -> ans
void dijkstra(int n, vector< pair<int, ll> > adj[], ll weight[]){

  priority_queue<pair<int,int> >pq;
  int color[MAX]; //color -> visit status
  
  for(int i = 0;i < n;++i){
    weight[i] = INFTY;
    color[i] = WHITE;
  }
  
  weight[0] = 0;
  color[0] = GRAY;
  pq.push(make_pair(0,0));
  
  while(!pq.empty()){

    pair<int,int> first = pq.top();
    pq.pop();
    int u = first.second;
    color[u] = BLACK;
    
    if(weight[u] < first.first * -1) continue;
    //Tour
    for(int i = 0;i < adj[u].size();++i){
      int v = adj[u][i].first;
      if(color[v] == BLACK)continue;
      //Update
      if(weight[v] > weight[u] + adj[u][i].second){
        weight[v] = weight[u] + adj[u][i].second;
        pq.push(make_pair(weight[v] * -1, v));
        color[v] = GRAY;
      }
    }
  }
  // Output
  //for(int i = 0;i < n;++i){
  //    cout << i << " " << ( weight[i] == INFTY ? -1 : weight[i] ) << endl;
  //}
}

int main(){

  vector< pair<int, ll> > ikiAdj[MAX], kaeriAdj[MAX];
  int N, M, T;
  ll money, MaxMoney = 0;
  ll A[MAX];
  int a, b, c, n;
  ll ikiWeight[MAX], kaeriWeight[MAX];

  cin >> N >> M >> T;

  for( int i = 0; i < N; i++){
    cin >> A[i];
  }

  for( int i = 0; i < M; i++ ){
    cin >> a >> b >> c;
    a--; b--;
    ikiAdj[a].push_back(make_pair(b, c));
    kaeriAdj[b].push_back(make_pair(a, c));
  }

  dijkstra(N, ikiAdj, ikiWeight);
  dijkstra(N, kaeriAdj, kaeriWeight);
    
  for( int i = 0; i < N; i++ ){
    money = (T - ( ikiWeight[i] + kaeriWeight[i] )) * A[i];
    MaxMoney = max( MaxMoney, money );
  }

  cout << MaxMoney << endl;

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