#include<bits/stdc++.h>
/*
Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/

Solution Approach : 

Since we can increase and decrease numbers at two different indices by 2 we won't be able to change the parity of the number and therefore we will need to work on odd and even numbers separately.

To find the minimum operations we can greedily select the smallest number from nums and target array, take there difference, sum all the differneces and divide by 2

*/
class Solution {
public:
    typedef long long int ll;
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {
        vector < vector < int > > even(2);
        vector < vector < int > > odd(2);
        for(auto& num : nums) {
            if(num % 2) {
                odd[0].push_back(num);
            } else {
                even[0].push_back(num);
            }
        }
        for(auto& x : target) {
            if(x % 2) {
                odd[1].push_back(x);
            } else {
                even[1].push_back(x);
            }
        }
        ll ans = 0;
        sort(odd[0].begin() , odd[0].end());
        sort(odd[1].begin() , odd[1].end());
        sort(even[0].begin() , even[0].end());
        sort(even[1].begin() , even[1].end());
        
        for(int i = 0 ; i < even[0].size() ; i++) {
            ans += abs(even[0][i] - even[1][i]) / 2;
        }
        for(int i = 0 ; i < odd[0].size() ; i++) {
            ans += abs(odd[0][i] - odd[1][i]) / 2;
        }
        return ans / 2;
    }
};