// https://leetcode.com/problems/find-k-closest-elements

/*
  Code - BS
  Logic - https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
*/

/*
    class Solution {
        public List<Integer> findClosestElements(int[] arr, int k, int x) {
            int lo = 0;
            int hi = arr.length - 1;
            while (hi - lo >= k) {
                if (Math.abs(arr[lo] - x) > Math.abs(arr[hi] - x)) {
                    lo++;
                } else {
                    hi--;
                }
            }
            List<Integer> result = new ArrayList<>(k);
            for (int i = lo; i <= hi; i++) {
                result.add(arr[i]);
            }
            return result;
        }
    }
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
      int left = 0, right = A.size() - k;
      while (left < right) {
          int mid = (left + right) / 2;
          if (x - A[mid] > A[mid + k] - x)
              left = mid + 1;
          else
              right = mid;
      }
      return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};