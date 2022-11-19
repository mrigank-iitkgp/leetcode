/*
  Author: Mrigank
 Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
 Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwap(vector < int >& arr) {
        int n = arr.size();
        vector < pair < int , int > > idxArr(n);
        for(int i = 0 ; i < n ; i++) {
            idxArr[i] = {arr[i] , i};
        }
        sort(idxArr.begin() , idxArr.end());
        vector < bool > visited(n , false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(visited[i] || idxArr[i].second == i) continue;
            int cycleSize = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                j = idxArr[j].second;
                cycleSize++;
            }
            ans += (cycleSize - 1);
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if(root == NULL) return 0;
        queue < TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector < int > temp;
            for(int i = 0 ; i < sz ; i++) {
                auto curr = q.front();
                q.pop();
                if(curr->left) {
                    temp.push_back(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right) {
                    temp.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }
            if(temp.size() > 0) ans += minSwap(temp);
        }
        return ans;
    }
};
