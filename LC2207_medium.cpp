/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
*/


class Solution {
public:
    typedef long long int ll;
    
    ll helper(vector < int >& arr , int k)
    {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int leftGreater = n;
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(arr[mid] > k)
            {
                leftGreater = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return n - leftGreater;
        
    }
    
    ll helper1(vector < int > arr , int k)
    {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int leftSmaller = 0;
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(arr[mid] < k)
            {
                leftSmaller = mid + 1;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return leftSmaller;
    }
    
    long long maximumSubsequenceCount(string text, string pattern) 
    {
        vector < int > idx1;
        vector < int > idx2;
        
        int n = text.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(text[i] == pattern[0])
            {
                idx1.push_back(i);
            }
            
            if(text[i] == pattern[1])
            {
                idx2.push_back(i);
            }
        }
        ll cnt = 0;
        for(int i = 0 ; i < idx1.size() ; i++)
        {
            cnt += helper(idx2 , idx1[i]);
        }
        ll temp = 0;
        for(int i = 0 ; i <= n ; i++)
        {
            ll val = helper(idx2 , i - 1);
            temp = max(temp , val + cnt);
        }
        for(int i = 0 ; i <= n ; i++)
        {
            ll val = helper(idx1 , i - 1);
            temp = max(temp , val + cnt);
        }
        return temp;
    }
};
