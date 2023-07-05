// https://leetcode.com/problems/asteroid-collision

/*
  Logic - Note the flow of values
  Code - Stack
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack
        for (int i : a) {
            if(i > 0) s.push_back(i);
            else{
                while(!s.empty() && s.back() > 0 && s.back() < abs(i)) s.pop_back();
                if(s.empty() || s.back() < 0) s.push_back(i);
                else if(s.back() == -i) s.pop_back();
            }
        }
        return s;
    }
};

/*

My Implementation - 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> output;
        
        for(int asteroid:asteroids) {
            
            if(output.empty() || asteroid > 0) {
                output.push_back(asteroid);
            } else if (asteroid < 0) {
                bool broken = false;
                while(!output.empty() && output.back() > 0 ) {
                     if(output.back() < abs(asteroid)) {
                        output.pop_back();
                    } else {
                        if(output.back() == abs(asteroid)) {
                            output.pop_back();
                        }
                        broken = true;
                        break;
                    }
                }
                        
                if(!broken) {
                    output.push_back(asteroid);
                }
                
            }

        }

        return output;
    }
};

*/