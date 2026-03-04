// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int binary(vector<int>& nums, int target, int s, int e) {
        if (e < s) return -1;
        int m = s + (e - s) / 2;  // Avoid potential overflow
        if (nums[m] == target) return m;
        if (nums[m] > target) return binary(nums, target, s, m - 1);
        else return binary(nums, target, m + 1, e);
    }
    
    int findRotationIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int s = 0;
        int e = n - 1;
        
        // If array is not rotated
        if (nums[s] < nums[e]) return 0;
        
        while (s <= e) {
            int m = s + (e - s) / 2;
            
            // Check if mid is the rotation point
            if (nums[m] > nums[m + 1]) 
                return m + 1;
            
            if (nums[m] < nums[s]) 
                e = m - 1;
            else 
                s = m + 1;
        }
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int rotationIndex = findRotationIndex(nums);
        
        // If array is not rotated
        if (rotationIndex == 0) {
            return binary(nums, target, 0, n - 1);
        }
        
        // Determine which half to search in
        if (target >= nums[0] && target <= nums[rotationIndex - 1]) {
            return binary(nums, target, 0, rotationIndex - 1);
        } else {
            return binary(nums, target, rotationIndex, n - 1);
        }
    }
};