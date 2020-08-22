

class ArithmeticSlices {

    public static int numberOfArithmeticSlices(int[] A) {

        int len = A.length;
        int ans = 0;
        int count = 1;
        if (len < 3)
            return ans;

        int[] dis = new int[len - 1];
        for (int i = 0; i < len - 1; i++)
            dis[i] = A[i + 1] - A[i];

        for (int i = 1; i < len - 1; i++) {

            if (dis[i] == dis[i - 1])
                count++;
            else if (count >= 2) {
                while (2 <= count)
                    ans += --count;
            } else
                count = 1;
        }

        if (count >= 2) {
            while (2 <= count)
                ans += --count;
        }

        return ans;
    }


}