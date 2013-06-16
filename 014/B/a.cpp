#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

vector<string> W;

void init(){
  W.clear();
}

bool input(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string tmp;
    cin>>tmp;
    W.push_back(tmp);
  }
  return true;
}


bool same(int n){
  bool res=false;
  for(int i=0;i<n;i++){
    if(W[i]==W[n]){
      res=true;
      break;
    }
  }
  return res;
}

string solve(){
  int judge=2;
  for(int i=1;i<W.size();i++){
    if(W[i-1][W[i-1].size()-1]!=W[i][0]){
      judge=(i+1)%2;
      break;
    }
    if(same(i)){
      judge=(i+1)%2;
      break;
    }
  }
  if(judge==2){
    return "DRAW";
  }else if(judge==0){
    return "WIN";
  }else if(judge==1){
    return "LOSE";
  }else{
    return "No";
  }
}


int main(){
  init(),input();
  cout<<solve()<<endl;
}
