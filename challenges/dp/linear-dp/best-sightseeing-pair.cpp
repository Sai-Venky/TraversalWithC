// https://leetcode.com/problems/best-sightseeing-pair

/*
    Logic - 
    Self Explanatory
    https://leetcode.com/problems/best-sightseeing-pair/discuss/261411/Java-O(N)-Easy-to-Understand-Clean-Code-beats-100
*/


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {   
    int i=0;
		int max = A[i] + i;
    for(int j=1;j<A.size();j++){
      max = std::max(max, A[i]+i+A[j]-j);
      // update the value of i to the one that maximizes
      i=A[i]+i<A[j]+j?j:i;
    }
    return max;
    }
};
