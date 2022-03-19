/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
*/

class Solution {
public:
    typedef long long int ll;
    int halveArray(vector<int>& nums) 
    {
        ll sum = 0;
        for(auto num : nums)
        {
            sum += num;
        }
        priority_queue < long double , vector < long double > > pq;
        
        for(auto num : nums)
        {
            pq.push(1.0 * num);
        }
        ll ans = 0;
        long double val = 1.0 * sum;
        //cout << val << endl;
        while(2 * val > sum)
        {
            long double curr = pq.top();
            pq.pop();
            val = val - curr + curr / 2.0;
            //cout << val << endl;
            pq.push(curr / 2.0);
            ans++;
        }
        return ans;
    }
};
