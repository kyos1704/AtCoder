#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

int n;
string s;
void init(){
  n=0;
  s="";
}

bool input(){
  cin>>n>>s;
  return true;
}

int cul_up(char c){
  int res=0;
  for(int i=0;i<s.size();i++){
    if(s[i]==c){
      res++;
    }
  }
  return res;
}

int solve(){
  int r=cul_up('R');
  int b=cul_up('B');
  int g=cul_up('G');
  return r%2+b%2+g%2;
}


int main(){
  init(),input();
  cout<<solve()<<endl;
}
