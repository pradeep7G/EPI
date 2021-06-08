//Know Your array ibraries ...

//Page - 60

#include<bits/stdc++.h>
using namespace std;
int main()
{
    //static array initialization

    array<int,4> A={1,2,3,4};
    array<array<int,2>,3> _2d={{{1,2},{3,4},{5,6}}};

    // cout<<A[2]<<"\n";
    // cout<<_2d[1][1]<<"\n";

    //Dynamic Array i.e vector..

    vector<int> AA={1,2,3,6,7,5,4};
    vector<vector<int>> _2dAA={{1,2},{3,4},{5,6}};
    // cout<<AA[2]<<endl;
    // cout<<_2dAA[1][1]<<"\n";
    // _2dAA.emplace_back((vector<int>){7,8,9});
    _2dAA.push_back((vector<int>){7,8,9});
    // for(auto x:_2dAA){for(auto y:x)cout<<y<<" ";cout<<"\n";}


    //extracting a sub array from an array/vector 
    int i=2,j=6;
    vector<int> subArray_AA(AA.begin()+i,AA.begin()+j);
    // for(auto x:subArray_AA)cout<<x<<" ";
    // cout<<endl;

    //Key methods in algorihms like binary_search,lower_bound,upper_bound etc,,,

    vector<int> sortedAr={101,2,3,102,5,6,7,7,7,8,9,10};
    //cout<<binary_search(begin(sortedAr),end(sortedAr),77)<<"\n";

    //lower_bound upper_bound returns iterator of that element if lower bound x>= if upper bound x > (strictly..)
    // cout<<lower_bound(begin(sortedAr),end(sortedAr),7)-begin(sortedAr)<<"\n";
    // cout<<upper_bound(begin(sortedAr),end(sortedAr),7)-begin(sortedAr)<<"\n";

    //fill assigns a value to any subarray including complete array...

    fill(begin(sortedAr)+2,sortedAr.begin()+3,34);
    // for(auto x:sortedAr)cout<<x<<" ";

    // min_element,max_elements return iterator same as upperbound,lowerbound...

    // cout<<min_element(begin(sortedAr),end(sortedAr))-sortedAr.begin()<<"\n";
    // cout<<max_element(begin(sortedAr),end(sortedAr))-sortedAr.begin()<<"\n";

    /* std::reverse reverses the container... */

    vector<int> rotateAr={3,2,1,6,4,5};
    rotate(begin(rotateAr),begin(rotateAr)+3,end(rotateAr));
    // for(auto x:rotateAr)cout<<x<<" ";

    sort(begin(rotateAr),end(rotateAr),[&](int x,int y){
        if(x>y)return true;
        return false;
    });

    for(auto x:rotateAr)cout<<x<<" ";
}