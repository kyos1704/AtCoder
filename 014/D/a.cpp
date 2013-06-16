#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

int all,N,M;
vector<int> L;
vector<int> diff;
vector<int> diff_add;
int q_x,q_y;

void init(){
  L.clear();
  diff.clear();
  diff_add.clear();
}

void input(){
  cin>>all>>N>>M;
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    L.push_back(tmp);
  }
  for(int i=1;i<N;i++){
    diff.push_back(L[i]-L[i-1]);
  }
}
void make_diff_add(){
  int tmp=0;
  for(int i=0;i<diff.size();i++){
    tmp+=diff[i];
    diff_add.push_back(tmp);
  }
}

void q_input(){
  cin>>q_x>>q_y;
}

int binary(int s,int e,int n){
  if(s>=e)return e;
  int m=(s+e)/2;
  if(diff[m]<n){
    return binary(m+1,e,n);
  }else{
    return binary(s,m,n);
  }
}

int solve(){
  int res=0;
  int tmp;
  tmp=min(L[0],q_x+1);
  res+=tmp;
  
  int x=binary(0,diff.size(),q_x+q_y+1);
  if(x>0)res+=diff_add[x-1];
  //cout<<"diff "<<diff_add[x]<<endl;
  //cout<<"x:"<<x<<" "<<diff[x-1]<<":"<<diff[x]<<"::"<<q_x+q_y+1<<endl;
  res+=(q_x+q_y+1)*max(0,(int)(diff.size()-x));
  //cout<<diff.size()-x<<":::"<<(q_x+q_y+1)*(diff.size()-x)<<endl;;
  
  tmp=min(all-L[L.size()-1],q_y);
  res+=tmp;
  return res;
}


int main(){
  init(),input();
  sort(L.begin(),L.end());
  sort(diff.begin(),diff.end());
  make_diff_add();
  for(int i=0;i<M;i++){
    q_input();
    cout<<solve()<<endl;
  }
}
