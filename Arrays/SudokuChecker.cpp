// page- 99,6.16

/*
    * Direct implementation,checking each row,column and sub grids satisfying constrains or not.
    * Time Complexity - O(n^2)+O(n^2)+O(n^2 or n*(sqtr(n)*sqrt(n))) => O(n^2)
    * Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

bool hasDuplicate(vector<vector<int>> &assignment,int startRow,int endRow,int startCol,int endCol)
{
    vector<bool> isPresent(assignment.size(),false);
    for(int i=startRow;i<endRow;i++)
    {
        for(int j=startCol;j<endCol;j++)
        {
            if(isPresent[assignment[i][j]] && assignment[i][j]!=0)
            {
                return true;
            }
            isPresent[assignment[i][j]]=true;
        }
    }
    return false;
}
bool isValidSudoku(vector<vector<int>> &assignment)
{
    //check row validity
    for(int i=0;i<assignment.size();i++)
    {
        if(hasDuplicate(assignment,i,i+1,0,assignment.size()))
        {
            return false;
        }
        
    }

    //check column validity
    for(int i=0;i<assignment.size();i++)
    {
        if(hasDuplicate(assignment,0,assignment.size(),i,i+1))
        {
            return false;
        }
    }
    //check subgrids validity
    int subGrid=sqrt(assignment.size());
    for(int i=0;i<subGrid;i++)
    {
        for(int j=0;j<subGrid;j++)
        {
            if(hasDuplicate(assignment,subGrid*i,subGrid*(i+1),subGrid*j,subGrid*(j+1)))
            {
                return false;
            }
        }
    }
    return true;    
}
int main()
{

}