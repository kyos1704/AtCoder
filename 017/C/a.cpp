#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,x;
vector<int> w;
vector<int> dp;

int solve(){
  dp.resize(x+100);
  dp[0]=1;
  for(int i=0;i<w.size();i++){
    for(int j=dp.size()-1;j>=w[i];j--){
      dp[j] += dp[j-w[i]];
    }
  }
  return dp[x];
}


int main(){
  cin>>n>>x;
  for(int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    w.push_back(tmp);
  }
  cout<<solve()<<endl;
}
