//page-80,

/*
    * Time Complexity - O(n),
    * Space Complexity - O(1),
    * solutions to both main problem and variant,
    * it is often better to read book and do problems on leet code
    * we can also ensure our codes are well tested by submitting in leetcode 
    
*/
#include<bits/stdc++.h>
using namespace std;
//Leetcode Link - https://leetcode.com/problems/jump-game/
bool CanReachEnd(vector<int> nums)
{
    int Farthest_reachable=0;
    int curr_reachable=0;
    for(int i=0;i<nums.size() && i<=Farthest_reachable;i++)
    {
        curr_reachable=nums[i]+i;
        Farthest_reachable=max(curr_reachable,Farthest_reachable);
    }
    return Farthest_reachable >= nums.size()-1;
}

//variant - https://leetcode.com/problems/jump-game-ii/

int jump(vector<int> nums)
{
    int Farthest_reachable=0,curr_reachable=0;
    int jumps=0;
    for(int i=0;i<nums.size()-1;i++)
    {
        Farthest_reachable=max(Farthest_reachable,nums[i]+i);
        if(curr_reachable==i)
        {
            jumps++;
            curr_reachable=Farthest_reachable;
            if(Farthest_reachable>=nums.size()-1)break;
        }
    }
    return jumps;
}
int main()
{
    vector<int> nums={2,3,1,1,4};
    cout<<jump(nums)<<"\n";
}