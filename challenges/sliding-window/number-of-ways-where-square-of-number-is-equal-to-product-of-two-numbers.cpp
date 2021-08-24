// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers

// Similar to three sum 
class Solution {
public:
    #define ll long long
    
	// returns count of valids triplets (i, j, K) of type 1
	// note that to find of type 2, just swap nums1 and nums2 while calling 
    int returnCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int count = 0;
        
        for(int k=0; k<n; k++) {
            ll target = nums1[k]*1ll*nums1[k];
			// we'll find two numbers in nums2 such that their product equals target 
            int i=0, j=m-1;
            while(i<j) {
                ll prod = nums2[i]*1ll*nums2[j];
                if(prod == target) {
					// case 1 : nums[i] == nums[j]
					// this means all numbers in between i & j are same and
					// we can choose any two out of all of them, hence Nc2 possibilities
                    if(nums2[i] == nums2[j]) {
                        int len = j-i+1;
                        count += len*(len-1)/2;
                        i = j+1;
                    }
					// case 2 : if not so
					// find the number of elements equal to nums2[i] (say n1) and
					// that equal to nums2[j] ( ssay n2)
					// add n1*n2 to ans
                    else {
                        int left_len = 1, right_len = 1;
                        while(i<j && nums2[i] == nums2[i+1]) {
                            i++;
                            left_len++;
                        }
                        while(j>i && nums2[j-1] == nums2[j]) {
                            j--;
                            right_len++;
                        }
                        
                        count += left_len * right_len;
                        i++; j--;
                    }
                    
                }
				// accordingly move pointer i or j
                else if(prod < target)
                    i++;
                else
                    j--;
            }
        }
        
        return count;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        return returnCount(nums1, nums2) + returnCount(nums2, nums1);
        
    }
};
