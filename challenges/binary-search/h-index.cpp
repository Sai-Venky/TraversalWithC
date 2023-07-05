// https://leetcode.com/problems/h-index/

/*
  Logic - SF
  Code - BS
  Both this and h-indexii are same. This has sort and that dosent.
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end());
      int left=0, len = citations.size(), right= len-1,  mid;
      while(left<=right)
      {
          mid=left+ (right-left)/2;
          if(citations[mid] >= (len-mid)) right = mid - 1;
          else left = mid + 1;
      }
      return len - left;
  }
};