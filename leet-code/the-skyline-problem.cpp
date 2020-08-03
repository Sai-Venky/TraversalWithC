// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		multimap<int, int> coords;
		for (auto building : buildings) {
			coords.emplace(building[0], building[2]);
			coords.emplace(building[1], -building[2]);
		}

		vector<vector<int>> results;
		multiset<int> heights = { 0 };
		map<int, int> corners;
		for (auto p : coords) {
			if (p.second > 0) {
				heights.insert(p.second);
			}
			else {
				heights.erase(heights.find(-p.second));
			}
			int cur_y = *heights.rbegin();
			corners[p.first] = cur_y;
		}

        int current;
        for(auto corner: corners) {
            if(corner.second == current) continue;
            results.push_back({corner.first ,corner.second});
            current = corner.second;
        }
        return results;
    }
};