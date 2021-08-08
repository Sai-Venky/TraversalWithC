// https://leetcode.com/problems/reach-a-number

// https://leetcode.com/problems/reach-a-number/discuss/112968/Short-JAVA-Solution-with-Explanation
// Nice maths and logic question 
/*
Step 0: Get positive target value (step to get negative target is the same as to get positive value due to symmetry).
Step 1: Find the smallest step that the summation from 1 to step just exceeds or equalstarget.
Step 2: Find the difference between sum and target. The goal is to get rid of the difference to reach target. For ith move, if we switch the right move to the left, the change in summation will be 2*i less. Now the difference between sum and target has to be an even number in order for the math to check out.
Step 2.1: If the difference value is even, we can return the current step.
Step 2.2: If the difference value is odd, we need to increase the step until the difference is even (at most 2 more steps needed).
*/

// Binary Search - https://leetcode.com/problems/reach-a-number/discuss/990875/Python-3-Binary-SearchMath-Explained

class Solution {
public:
    int reachNumber(int target) {
      target = abs(target);
      int step = 0;
      int sum = 0;
      while (sum < target) {
          step++;
          sum += step;
      }
      while ((sum - target) % 2 != 0) {
          step++;
          sum += step;
      }
      return step;
    }
};