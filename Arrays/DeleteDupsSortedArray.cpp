// page - 81,6.5

/*
    * Time Complexity - O(n),
    * Space Complexity - O(1)
*/
#include<bits/stdc++.h>
using namespace std;

//leetcode link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
int DeleteDupsBestComplexity(vector<int> nums)
{
    if(nums.size()==0)
    return 0;
    int larger=nums.size()-1,start=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i-1]!=nums[i])
        {
            nums[start++]=nums[i];
        }
    }
    return start;
}

/*
    * variant
    * leet code link - https://leetcode.com/problems/remove-element/submissions/
*/

int removeElement(vector<int>& nums, int val) {
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[start++]=nums[i];
            }
        }
        return start;
    }
int main()
{
    vector<int> nums={1,2,3,3,5,6,6,7};
    cout<<DeleteDupsBestComplexity(nums);
}