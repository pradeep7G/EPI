// 6.2 ,  page - 78

#include<bits/stdc++.h>
using namespace std;

vector<int> PlusOne(vector<int> A)
{
    ++A.back();
    for(int i=A.size()-1;i>0 && A[i]==10;i--)
    {
        A[i]=0,++A[i-1];
    }
    if(A[0]==10)
    {
        A[0]=1;A.emplace_back(0);
    }
    
    return A;
}
int main()
{
    vector<int> A={9,9,9,9,9,9,7};
    A=PlusOne(A);
    for(auto x:A)cout<<x<<" ";cout<<"\n";
}