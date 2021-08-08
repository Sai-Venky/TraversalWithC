// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/


/*
    class Solution {
        public:
            int chalkReplacer(vector<int>& chalk, int k) {
            
                size_t sum=0;
                for(auto &x: chalk)
                    sum+=x;    // getting sum of all chalk values
                
                k = k%sum;   // modifyig k so that we dont have to do that much iterations
                
                for(int i=0;i<chalk.size();i++)  
                {  if( k-chalk[i] < 0) return i;
                    else
                        k-=chalk[i];
                }
            return chalk.size()-1;
            }
        };
*/
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
      int n=chalk.size();
      vector<long> sums(n, 0);
      sums[0]=chalk[0];
      for(int i=1;i<n;i++) sums[i]=sums[i-1]+chalk[i];
      
      k=k%sums[n-1];
      int l=0, h=n-1;
      
      while(l<h) {
        int m=l+(h-l)/2;
        if(sums[m]>k) {
          h=m;
        } else {
          l=m+1;
        }
      }
      return l;
    }
};