// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/564729/Java-Simple-Code-DP
*/

public int maxProfit(int[] A) {                        
        int n = A.length, lastBuy = -A[0], lastSold = 0;
        if (n == 0) return 0;
                                
        for (int i = 1; i < n; i++) {
            int curBuy = Math.max(lastBuy, lastSold - A[i]);
            int curSold = Math.max(lastSold, lastBuy + A[i]);
            lastBuy = curBuy;
            lastSold = curSold;
        }
        
        return lastSold;
}