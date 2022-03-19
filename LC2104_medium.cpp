/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/sum-of-subarray-ranges/
*/


class Solution {
public:
    typedef long long int ll;
    
    ll getSubArrayMaxHelper(vector < int >& nums)
    {
        ll n = nums.size();
        vector < ll > left(n);
        vector < ll > right(n);
        
        for(ll i = 0 ; i < n ; i++) left[i] = i + 1;
        for(ll i = 0 ; i < n ; i++) right[i] = n - i;
        
        stack < pair < ll , ll > > pge;
        stack < pair < ll , ll > > nge;
        
        for(ll i = 0 ; i < n ; i++)
        {
            // Calculating previous greater element
            
            while(!pge.empty() && pge.top().first <= nums[i])
            {
                pge.pop();
            }
            left[i] = (pge.empty()) ? i + 1 : i - pge.top().second;
            pge.push({nums[i] , i});
            
            // Calculating next greater element
            
            while(!nge.empty() && nge.top().first <= nums[i])
            {
                right[nge.top().second] = i - nge.top().second;
                nge.pop();
            }
            nge.push({nums[i] , i});
        }
        
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++)
        {
            ans += (left[i] * right[i] * nums[i]);
        }
        return ans;
    }
    
    ll getSubArrayMinHelper(vector < int >& nums)
    {
        ll n = nums.size();
        vector < ll > left(n);
        vector < ll > right(n);
        
        for(ll i = 0 ; i < n ; i++) left[i] = i + 1;
        for(ll i = 0 ; i < n ; i++) right[i] = n - i;
        
        stack < pair < ll , ll > > ple;
        stack < pair < ll , ll > > nle;
        
        for(ll i = 0 ; i < n ; i++)
        {
            // Calculating previous lesser element
            
            while(!ple.empty() && ple.top().first >= nums[i])
            {
                ple.pop();
            }
            left[i] = (ple.empty()) ? i + 1 : i - ple.top().second;
            ple.push({nums[i] , i});
            
            // Calculating next lesser element
            
            while(!nle.empty() && nle.top().first >= nums[i])
            {
                right[nle.top().second] = i - nle.top().second;
                nle.pop();
            }
            nle.push({nums[i] , i});
        }
        
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++)
        {
            ans += (left[i] * right[i] * nums[i]);
        }
        return ans;
    }
    
    long long subArrayRanges(vector<int>& nums) 
    {   
        ll subArrayMin = getSubArrayMinHelper(nums);
        //cout << subArrayMin << endl;
        ll subArrayMax = getSubArrayMaxHelper(nums);
        //cout << subArrayMax << endl;
        
        return subArrayMax - subArrayMin;
    }
};
