#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cmath>
#include<cstdio>
#include<limits>
#include<climits>
using namespace std;

long long n,m,a,p;
typedef long long ll;
typedef pair<ll,ll> Pll;
vector<Pll> all_list;//now,pre
vector<vector<Pll> > end_s;
bool Pll_second(Pll a,Pll b){
  if(a.second==b.second){
    return a.first<b.first;
  }else{
    return a.second<b.second;
  }
  return 0;
}

int main(){
  long long pre;
  cin>>n>>m>>pre>>a>>p;
  long long ans = 0;
  all_list.push_back(Pll(pre,0));
  for(int i=1;i<n*m;i++){
    all_list.push_back(Pll((long long)(all_list[i-1].first+a)%p,i));
  }
  sort(all_list.begin(),all_list.end());
  
  end_s.resize(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      Pll tmp = all_list[i*m+j];
      ans += abs(tmp.second/m-i);
      tmp.second = tmp.second%m;
      end_s[i].push_back(tmp);
    }
    sort(end_s[i].begin(),end_s[i].end(),Pll_second);
    for(int j=0;j<end_s[i].size();j++){
      ans+= abs(end_s[i][j].second - j);
    }
  }
  /*cout<<"v::"<<ans<<endl; 
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<i*m+j<<" ";
    }cout<<endl;
  }cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<all_list[i*m+j].first<<" ";
    }cout<<endl;
  }cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<all_list[i*m+j].second<<" ";
    }cout<<endl;
  }cout<<endl;
  

  for(int i=0;i<end_s.size();i++){
    for(int j=0;j<end_s[i].size();j++){
      cout<<end_s[i][j].first<<" ";
    }cout<<endl;
  }cout<<endl;
  for(int i=0;i<end_s.size();i++){
    for(int j=0;j<end_s[i].size();j++){
      cout<<end_s[i][j].second<<" ";
    }cout<<endl;
  }cout<<endl;*/
  cout<<ans<<endl;
}
