// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
    set<vector<int>> result_set;  
        
    sort(nums.begin(), nums.end()); 
    vector<int>::iterator it;
    for(int i = 0; i < nums.size(); i++) {
        int start = 0, end = nums.size() - 1;
        if(i > 1 && i < nums.size() - 2 && nums[i] == nums[i+1]) continue;
        int number_to_check = -1 * nums[i];
        while(start<end) {
            if(start == i) {
                start ++;
                continue;
            } 
            if(end == i) {
                end --;
                continue;
            }
            int sum_diff = nums[start] + nums[end];
            if(sum_diff == number_to_check) {
                vector<int> result_chunk;
                result_chunk.push_back(nums[start]);
                result_chunk.push_back(nums[end]);
                result_chunk.push_back(nums[i]);
                sort(result_chunk.begin(), result_chunk.end()); 
                result_set.insert(result_chunk); 
                end--;
                start++;
            } else if (sum_diff > number_to_check) {
                end--;
            } else {
                start++;
            }
        }
    }

        
    
    return vector<vector<int>>(result_set.begin(), result_set.end() );
        
    }
};