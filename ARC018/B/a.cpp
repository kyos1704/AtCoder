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
vector<long long > x,y;
int main(){
  int n;
  x.clear();y.clear();
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    x.push_back(a);
    y.push_back(b);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        long long  tmp = abs(
                    (x[i]-x[k])*(y[j]-y[i])
                    -(x[i]-x[j])*(y[k]-y[i])
                  );
        if(tmp%2==0&&tmp!=0){
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}
