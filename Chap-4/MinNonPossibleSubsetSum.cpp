#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(begin(ar),end(ar));
    int max_constructable_value=0;
    for(auto x:ar){
        if(x > max_constructable_value+1)
        {
            break;
        }
        else
        {
            max_constructable_value+=x;
        }
        
    }
    cout<<max_constructable_value+1<<"\n";
}
