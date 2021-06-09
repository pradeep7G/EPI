
// Page-100,6.17

/*
    * Divide And Conquer ,2D Array ,can also be generalised to mulitdimenstions,Sol ->  select first n-1 element of first row ->select first n-1 element of last col -> select last n-1 element of last row-> select last n-1 element of first column and 
    * .. so dimensions for every walk will be n*n, (n-2)*(n-2) , (n-4)*(n-4) , .... if n is odd there will be an edge case which is middle element(single element)...
    * Time Complexity - O(n^2),
    * Space Complexity - O(1) other than storing spiral Ordering
*/

/*
    * Leetcode- https://leetcode.com/problems/spiral-matrix/
    * have a look at leetcode,it has many variants of this problem,Do them..
*/
#include<bits/stdc++.h>
using namespace std;

void walk(vector<int> &spiralOrdering,int offset,vector<vector<int>> &nums)
{
    if(nums.size()-1==2*offset)
    {
        spiralOrdering.emplace_back(nums[offset][offset]);
        return ;
    }
    for(int i=offset;i<nums.size()-offset-1;i++)
    {
        spiralOrdering.emplace_back(nums[offset][i]);
    }
    for(int i=offset;i<nums.size()-offset-1;i++)
    {
        spiralOrdering.emplace_back(nums[i][nums.size()-offset-1]);
    }
    for(int i=nums.size()-offset-1;i>offset;i--)
    {
        spiralOrdering.emplace_back(nums[nums.size()-offset-1][i]);
    }
    for(int i=nums.size()-offset-1;i>offset;i--)
    {
        spiralOrdering.emplace_back(nums[i][offset]);
    }
}
void SpiralWalk(vector<vector<int>> &nums)
{
    vector<int> spiralOrdering;
    for(int offset=0;offset<ceil((nums.size()*(0.5)));offset++)
    {
        walk(spiralOrdering,offset,nums);
    }
}

//Single Pass...
vector<int> spiralSinglePass(vector<vector<int>> &nums)
{
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralNums;
    int x=0,y=0,shift=0;
    for(int i=0;i<nums.size()*nums.size();i++)
    {
        spiralNums.push_back(nums[x][y]);
        nums[x][y]=0;
        int next_x=x+dir[shift][0],next_y=y+dir[shift][1];
        if(next_x >= nums.size() || next_y>=nums[0].size() || next_x<0 || next_y<0 || nums[next_x][next_y]==0  )
        {
            shift=(shift+1)%4;
            next_x=x+dir[shift][0],next_y=y+dir[shift][1];
        }
        x=next_x,y=next_y;
    }
    return spiralNums;
}

//variant

/*
    *Leetcode - https://leetcode.com/problems/spiral-matrix-ii/description/
*/
vector<vector<int>> generate(int d)
{
    int currVal=1;
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}},matrix(d,vector<int> (d,0));
    int x=0,y=0,shift=0;
    for(;currVal<=d*d;currVal++)
    {
        matrix[x][y]=currVal;
        int next_x=x+dir[shift][0],next_y=y+dir[shift][1];
        if(next_x < 0 || next_y < 0 || next_x >= d || next_y >= d)
        {
            shift=(shift+1)%4;
            next_x=x+dir[shift][0],next_y=y+dir[shift][1];
        }
        x=next_x,y=next_y;
    }

}
vector<vector<int>> generatespiral(int d)
{
    vector<vector<int>> matrix(d,vector<int>(d));
    int left=0;int down=d-1;int right=d-1;int top=0,cnt=1;
    while(top<=down && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            matrix[top][i]=cnt;
            cnt++;
        }
        top++;
        for(int i=top;i<=down;i++)
        {
            matrix[i][right]=cnt;
            cnt++;
        }
        right--;
        for(int i=right;i>=left;i--)
        {
            matrix[down][i]=cnt;
            cnt++;
        }
        down--;
        for(int i=down;i>=top;i--)
        {
            matrix[i][left]=cnt;
            cnt++;
        }
        left++;
    }
    return matrix;
}
int main()
{

}