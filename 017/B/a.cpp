#include<iostream>
#include<vector>
using namespace std;
int n,k;
vector<int> a;

int solve(){
  int c=1;
  int ans =0;
  for(int i=1;i<a.size();i++){
    if(a[i-1]<a[i]){
      c++;
    }else{
      ans += max(0,c-k+1);
      c=1;
    }
  }
  ans += max(0,c-k+1);
  return ans;
}

int main(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    a.push_back(tmp);
  }
  cout<<solve()<<endl;
}
