//Page - 74

/*
    * Time Complexity O(n),
    * Space Complexity O(1).
    * dividing into sub arrays,invariants.....
*/

#include<bits/stdc++.h>
using namespace std;

typedef enum {Red,White,Blue} Color;

void DutchFlagPartition(vector<Color> &ar,int pivot_index)
{
    Color pivot=ar[pivot_index];

    //First Pass
    int smaller=0,larger=ar.size()-1;
    for(int i=0;i<ar.size();i++)
    {   
        if(ar[i]<pivot)
        {
            swap(ar[smaller++],ar[i]);
        }
    }   

    for(int j=ar.size()-1;j>=0 && ar[j]>=pivot;j--)
    {
        if(ar[j]>pivot)
        swap(ar[larger--],ar[j]);
    }
    for(auto x:ar)cout<<x<<" ";cout<<"\n";
}

void DutchNationalFlagSinglePass(vector<Color> &ar,int pivot_index)
{
    int pivot=ar[pivot_index];

    /*
        we devide it into 4 regions ,invariants -->>

        * bottom group : ar[0:smaller-1],
        * middle group : ar[smaller: equal-1],
        * unclassified group : ar[equal:larger-1],
        * top group :ar[larger:ar.size()-1].
        
    */
   int smaller=0,larger=ar.size(),unclassified=0;
   while(unclassified < larger)
   {
       if(ar[unclassified]<pivot)
       {
           swap(ar[unclassified],ar[smaller]);
           smaller++;
           unclassified++;
       }
       else if(ar[unclassified]==pivot)
       {
           unclassified++;
       }
       else
       {
           swap(ar[larger],ar[unclassified]);
           larger--;
       }
       
   }
   for(auto x:ar)cout<<x<<" ";cout<<"\n";
}

int main()
{
    vector<Color> ar={Red,Blue,Blue,White,Blue,Red,White,White,Red};
    // DutchFlagPartition(ar,3);
    DutchNationalFlagSinglePass(ar,2);
    // for(auto x:ar)cout<<x<<" ";cout<<"\n";
    

}