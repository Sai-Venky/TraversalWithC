// https://leetcode.com/problems/3sum-closest

/*  
  Logic - SF
  Code  - Using two pointers for each triplets and finding nearest.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int min_distance = INT_MAX, closest_sum;
        
        for(int i = 0; i < nums.size(); i++) {
            
            int start = i+1, end = nums.size() - 1;
            while (start < end) {
                int three_sum = (nums[start] + nums[end] + nums[i]);
                int cur_distance = abs(target - three_sum);
                
                if(cur_distance < min_distance) {
                    min_distance = cur_distance;
                    closest_sum = three_sum;
                }
                
                if(three_sum < target) {
                    start++;
                } else if(three_sum > target) {
                    end --;
                } else if(three_sum  == target) {
                    closest_sum = three_sum;
                    return closest_sum;
                }
                

            }
        }
        return closest_sum;
    }
};