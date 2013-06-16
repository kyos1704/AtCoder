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

int cul(int ID){
  string tmp="";
  for(int i=0;i<n;i++){
    if(ID&(1<<i)){
      tmp=tmp+s[i];
    }else{
      tmp=s[i]+tmp;
    }
  }
  //cout<<tmp;
  string::size_type pos=0;
  string ttmp="";
  while(ttmp!=tmp){
    ttmp=tmp;
    while(pos=tmp.find("RR"),pos!=string::npos){
      tmp.replace(pos,2,"");
    }
    while(pos=tmp.find("BB"),pos!=string::npos){
      tmp.replace(pos,2,"");
    }
    while(pos=tmp.find("GG"),pos!=string::npos){
      tmp.replace(pos,2,"");
    }
  }
  //cout<<" "<<tmp<<" "<<tmp.size()<<endl;
  return tmp.size();
}

int solve(){
  int res=100;
  if(n>15)return 0;
  for(int i=0;i<(1<<n);i++){
    res=min(res,cul(i));
  }
  return res;
}


int main(){
  init(),input();
  cout<<solve()<<endl;
}
