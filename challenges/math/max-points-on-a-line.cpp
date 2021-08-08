// https://leetcode.com/problems/max-points-on-a-line

// This is an O(n^2) solution given the nested for loops. All operations of unordered_map take O(1) time on average.


class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        int res = 0;
        //vertical line, pair is x, y, (0, 1), otherwise calculate gcd
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> m;
            vector<int> a = points[i];
            int dup = 1;
            for (int j = i + 1; j < points.size(); j++) {
                vector<int> b = points[j];
                int diff[] = {b[0]-a[0], b[1]-a[1]};
                if (diff[0]==0 && diff[1]==0) {//duplicate point, do not add to map
                    dup++;
                } else {
                    int factor = gcd(diff[0], diff[1]);
                    diff[0] /= factor;
                    diff[1] /= factor;
                    if (diff[0] == 0) {//vertical slope
                        diff[1] = 1;
                    } else if (diff[0] < 0) {//normalize run to positive int
                        diff[0] *= -1;
                        diff[1] *= -1;
                    }
                    m[make_pair(diff[0], diff[1])]++;
                }
            }
            res = max(res, dup);
            for (auto p : m) {
                res = max(res, p.second+dup);
            }
        }
        return res;
    }
};