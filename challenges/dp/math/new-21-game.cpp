// https://leetcode.com/problems/new-21-game

// https://leetcode.com/problems/new-21-game/discuss/1253071/Easy-to-understand-Java-solution-with-probability-calculation-examples
// Highly Logical and Intuitive

class Solution {
public:
    double new21Game(int N, int K, int W) {
      
      if (N >= K + W - 1)
            return 1.0;

        double p[N + 1];

        p[0] = 1.0;

        double prev = 0.0;
        for (int i = 1; i <= K; i++) {

            prev += p[i - 1] - ((i - W - 1) >= 0 ? p[i - 1 - W]: 0);
            p[i] = prev * 1 / (W * 1.0);
        }

        double res = p[K];

        for (int i = K + 1; i < N + 1; i++) {

            prev -= (i - 1 - W >= 0 ? p[i - 1 - W] : 0);
            p[i] = prev * 1 / (W * 1.0);
            res += p[i];
        }

		return res;
    }
};