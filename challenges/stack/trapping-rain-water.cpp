// https://leetcode.com/problems/trapping-rain-water/

/*

arr[left] or arr[right] always is a pointer to a value which is the max value found so far, searching from left and right.

If arr[left] <= arr[right], this means that arr[right] is the max value found so far. This also means that maxLeft will be less than or equal to arr[right], which means that maxLeft will be bounding the addition to the answer(res variable, in this solution), since it has be less than or equal to arr[right] e, so we don't have to consider maxRight when adding to the counter.

If arr[left] > arr[right] , this means at arr[left] is the max value found so far. Same thing applies as explained in the paragraph above.

class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    int trap(vector<int>& height) {
      
      int m=0, n=height.size(), capwater=0;
      vector<int> lft(n,-1);
      
      for(int i=0;i<n;i++) {
        
        if(m>height[i]) {
          lft[i]=m;
        }
        m = max(m, height[i]);
      }
      
      for(int i=n-1, m=-1;i>=0;i--) {
        m = max(m, height[i]);
        if(lft[i] == -1 || m == -1) continue;
        capwater+= (min(lft[i], m) - height[i]);
      }
      
      return capwater;
      
    }
};

class Solution {
public:
    int trap(vector<int>& heights) {
        
        vector<int> dq;
        int total_area = 0;

        for(int i=0; i<heights.size(); i++) {

            while(!dq.empty() && heights[dq.back()] < heights[i]) {
                int height = heights[dq.back()];
                dq.pop_back();
                int minHgt = !dq.empty() ? min(heights[dq.back()], heights[i]): 0;

                total_area +=  minHgt > 0 ? (minHgt - height) * (i - dq.back() - 1): 0;
            }

            dq.push_back(i);
        }

        return total_area;
    }
};