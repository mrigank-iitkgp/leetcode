/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
*/


class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int n = nums.size();
        bool leftSmaller;
        bool rightSmaller;
        bool leftGreater;
        bool rightGreater;
        int ans = 0;
        
        for(int i = 1 ; i < n - 1 ; i++)
        {
            leftGreater = false;
            rightGreater = false;
            leftSmaller = false;
            rightSmaller = false;
            cout << nums[i] << endl;
            if(i >= 2)
            {
                if(nums[i] == nums[i - 1]) continue;
            }
            for(int j = i ; j >= 0 ; j--)
            {
                if(nums[j] > nums[i])
                {
                    leftGreater = true;
                    cout << "leftGreater" << " " << nums[j] << endl;
                    break;
                }
                if(nums[j] < nums[i])
                {
                    leftSmaller = true;
                    cout << "leftSmaller" << " " << nums[j] << endl;
                    break;
                }
            }
            for(int j = i + 1 ; j < n ; j++)
            {
                if(nums[j] > nums[i])
                {
                    rightGreater = true;
                    cout << "rightGreater" << " " << nums[j] << endl;
                    break;
                }
                if(nums[j] < nums[i])
                {
                    rightSmaller = true;
                    cout << "rightSmaller" << " " << nums[j] << endl;
                    break;
                }
            }
            if((leftSmaller && rightSmaller) || (leftGreater && rightGreater)) ans++;
            cout << ans << endl;
        }
        return ans;
    }
};
