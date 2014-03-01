#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> a;
int m;
vector<int> t,l,r;

int main(){
  cin>>n;
  a.resize(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>m;
  t.resize(m);
  l.resize(m);
  r.resize(m);
  for(int i=0;i<m;i++){
    cin>>t[i]>>l[i]>>r[i];
  }


}
