
class MaximumPointCards {

    
    public static int maxScore(int[] cardPoints, int k) {

        int len = cardPoints.length;
        int max = 0;
        int[] sum = new int[len + 1];
        sum[0] = 0;
        for (int i = 1; i <= len; i++)
            sum[i] = sum[i - 1] + cardPoints[i - 1];

        if (k >= len)
            return sum[len];

        for (int i = 0; i <= k; i++)
            max = Math.max(sum[len] - sum[len - (k - i)] + sum[i], max);

        return max;

    }
    
}