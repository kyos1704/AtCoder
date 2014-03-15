#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

map<char,char> list;

void init(){
  list['O'] = '0';
  list['D'] = '0';
  list['I'] = '1';
  list['Z'] = '2';
  list['S'] = '5';
  list['B'] = '8';
}


int main(){
  init();
  string in;
  cin>>in;
  for(int i=0;i<in.size();i++){
    if(list.count(in[i])>0){
      in[i]=list[in[i]];
    }
  }
  cout<<in<<endl;
}
