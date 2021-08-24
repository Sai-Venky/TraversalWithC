// https://leetcode.com/problems/single-number-ii

// https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int ones=0, twos=0;
      for(int num:nums){
        ones=(num^ones)&~twos;
        twos=(num^twos)&~ones;
      }
      return ones;
    }
};

// https://leetcode.com/problems/single-number-ii/discuss/43297/Java-O(n)-easy-to-understand-solution-easily-extended-to-any-times-of-occurance

int singleNumber(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < 32; i++) {
		int sum = 0;
		int mask = 1 << i;
		for (auto n : nums) 
			if (n & mask) 
				sum++;
		if (sum % 3 == 1)
			res |= mask;
	}
	return res;
}