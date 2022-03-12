#include <iostream>
#include <iomanip>
#include<vector>
using namespace std;

int main()
{
    int n;
    vector<int> A;
    vector<int> B;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        B.push_back(tmp);
    }

    int ans1 =0;
    int ans2 =0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i]==B[j]){
                if(i==j){
                    ans1++;
                }else{
                    ans2++;
                }
            }
        }
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
}