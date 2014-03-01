#include<iostream>
#include<vector>
using namespace std;

vector<int> prime;

void init(){
  prime.resize(1000100);
  for(int i=0;i<prime.size();i++){
    prime[i]=1;
  }
  prime[0]=prime[1]=0;
  for(int i=0;i<prime.size();i++){
    if(prime[i])for(int j=i*2;j<prime.size();j+=i){
      prime[j]=0;
    }
  }
}


int main(){
  init();
  int n;
  cin>>n;
  cout<<(prime[n]?"YES":"NO")<<endl;
}
