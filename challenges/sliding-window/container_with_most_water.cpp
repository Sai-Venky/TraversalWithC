// https://leetcode.com/problems/container-with-most-water/

/*
  Logic -
Consider a simpler problem. Let's say there's a table with a bunch of closed boxes. You're told there's a number in each box and you're asked to find the largest number. So you open some first box, remember its number, and then throw that box away. Then you open some other box. If its number is larger than the one before, you remember this new number instead. And then you throw that box away. And so on. Until you went through all boxes. In code, that might look like this:

max = 0
i = 0
while i < number_of_boxes:
    if number_in_box[i] > max:
        max = number_in_box[i]
    i = i + 1
print(max)
Are you here also wondering whether the optimal solution might be missed? If yes, then why? If no, then what's the difference to the water problem? The box problem is simpler, but the process is the same as the water one. You consider a new option, you update your current "best", you remove something that can't give you something better anymore, and you move on. If you have seen the overall optimum already, then you have seen it already and remember it until the end. And if not, it's still in the game. So it will be found at some point. Really the only thing you need to show is that you don't make a mistake when you reduce the problem, which is what I did in my post.
 it does not matter whether you perform i++ or j--, because if h[i] == h[j], neither (i+1, j) or (i, j-1) can be potential solutions because the area obtained is necessarily smaller than (i, j).

  Code - Using 2 pointers
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
      
      int l=0, h=height.size()-1;
      int marea=0;
      
      while(l<h) {
        marea = max(marea, (h-l) * min(height[l], height[h]));
        
        if(height[l] > height[h]) h--;
        else l++;
      }
      
      return marea;
    }
};