//Page 59

//with O(n) space it is so obvious ,we can optimise space complexity to O(1) through swappings and by maintaining Even,Odd,and unclassified regions


//I.E Inplace Operations 

/*
    **Time Complexity** = O(n)

    *Space Complexity*  = O(1) //since only some temporary variable are used..
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++)cin>>ar[i];

    int even=0,odd=ar.size()-1;
    while(even < odd)
    {
        if(ar[even]%2==0)
        {
            even++;
            continue;
        }
        else
        {
            swap(ar[even],ar[odd]);
            odd--;
        }
    }
    for(auto &i:ar)cout<<i<<" ";

    cout<<"\n";
}

