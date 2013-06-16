#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;


void init(){
}


int n;
bool input(){
  cin>>n;
  return true;
}



string solve(){
  if(n%2==0){
    return "Blue";
  }else{
    return "Red";
  }
}


int main(){
  init(),input();
  cout<<solve()<<endl;
}
