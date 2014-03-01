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
///
class union_find{
private:
  vector<int> parents;
  vector<int> rank;
public:
  union_find(int n){
    parents.resize(n);
    rank.resize(n);
    for(int i=0;i<n;i++){
      parents[i]=i;
      rank[i]=0;
    }
  }
  int find(int x){
    if(parents[x]==x){
      return x;
    }else{
      return parents[x]=find(parents[x]);
    }
  }
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
      parents[x]=y;
    }else{
      parents[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  bool same(int x,int y){
    return (find(x)==find(y));
  }
  bool all_same(){
    for(int i=0;i<parents.size()-1;i++){
      if(!same(i,i+1)){
        return false;
      }
    }
    return true;
  }
};
///
struct S{
  int a,b,c;
};
int n,m;
vector<S> in;
bool S_c(S a,S b){
  return a.c<b.c;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    in.push_back(S{a,b,c});
  }
  sort(in.begin(),in.end(),S_c);
  union_find uf(n);
  int ans = 0;
  for(int i=0;i<in.size();i++){
    if(!uf.same(in[i].a,in[i].b)){
      ans += in[i].c;
      uf.unite(in[i].a,in[i].b);
    }
  }
  cout<<ans<<" "<<1<<endl;
}
