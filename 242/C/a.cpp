#include <iostream>
#include<vector>

using namespace std;

int d = 998244353 ;

vector<vector<long long>> dp;

long long solve(long long x,long long i){
    if(dp[x][i]!=-1){
        return dp[x][i];
    }

    cout << x <<" " << i << endl;
    if(i==0){
        return 1;
    }
    dp[x][i] = 0;
    if(x!=9){
        dp[x][i] += solve(x + 1,i -1);
        dp[x][i]%=d;
    }
    dp[x][i] += solve(x,i -1);
    dp[x][i]%=d;
    if(x!=1){
        dp[x][i] += solve(x-1,i -1);
        dp[x][i]%=d;
    }
    return dp[x][i];
}

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    dp.resize(11);
    for(int i=0;i<11;i++){
        dp[i].resize(n);
        for(int j = 0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    //cout << "dp initialize end" << endl;

    for(int i=1;i<10;i++){
        dp[i][0] = 1;
    }

    for(int j=1;j<n;j++){
        for(int i=1;i<10;i++){
            dp[i][j] = 0;
            if(i!=9) dp[i][j] += dp[i+1][j-1];
            dp[i][j] += dp[i][j-1];
            if(i!=1) dp[i][j] += dp[i-1][j-1];
            dp[i][j]%=d;
        }
    }
    /*
    for(int i=1;i<10;i++){
        ans+=solve(i,n-1);
        ans%=d;
        cout<<ans<<endl;
    }*/
    for(int i=1;i<10;i++){
        ans+=dp[i][n-1];
    }
    ans%=d;
    cout<<ans<<endl;
}