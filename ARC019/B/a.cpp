#include<string>
#include<iostream>
using namespace std;

long long solve(string s){
  long long same =0;
  for(int i=0;i<s.size();i++){
    if(s[i]==s[s.size()-1-i]){
      same++;
    }
  }

  long long res=0;
  if(s.size()==1){
    return res;
  }else if(s.size()==same+2){
    res += 25*same;
    res += 24*2;
  }else if(s.size()==same){
    res += 25*same;
    res -= s.size()%2*25;
  }else{
    res += s.size()*25;
  }
  return res;
}

int main(){
  string s;
  cin>>s;
  cout<<solve(s)<<endl;
}
