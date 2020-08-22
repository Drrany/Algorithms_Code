
class CountingBits {

    public int[] countBits(int num) {
        int[] ans = new int[num + 1];

        for (int i = 0; i <= num; i++) {
            if (i % 2 == 0)
                ans[i] = ans[i / 2];
            else
                ans[i] = ans[i - 1] + 1;
        }

        return ans;
    }



}