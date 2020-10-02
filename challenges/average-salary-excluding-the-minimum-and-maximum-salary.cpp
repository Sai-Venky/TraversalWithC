// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salaries) {
        int max=salaries[0], min=salaries[0];
        double sum=0;
        for(auto salary: salaries) {
            if(salary >= max) {
                max = salary;
            }
            if (salary < min) {
                min = salary;
            }
            
            sum += salary;
        }
        
        return (sum - max - min)/(salaries.size()-2);
    }
};