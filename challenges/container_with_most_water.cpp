// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    
    int min(int a, int b) {
        if(a>b) {
            return b;
        } else {
            return a;
        }    
    }
    int area (vector<int>& height, int i, int j) {
        if(i>=j) {
            return 0;
        }
        return (j-i) * min(height[i], height[j]);
    }
    
    void movePointer(vector<int>& height, int *i, int *j) {
        int area1 = height[*i];
        int area2 = height[*j];
        if(area1>=area2) {
            *j = *j-1;
        } else if(area2>area1) {
            *i = *i+1;
        }
    }
    int maxArea(vector<int>& height) {
        int length = height.size();
        int i=0, j=length-1;
        int max_area=0;
        while(i<j) {
            int area_ = area(height, i, j);
            if(area_>max_area) {
                max_area = area_;
            }
            movePointer(height, &i ,&j);
        }
        
        return max_area; 
    }
};