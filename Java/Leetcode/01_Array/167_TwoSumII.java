

class TwoSum2 {

    public int[] twoSum(int[] numbers, int target) {

        int[] ans = { 1, numbers.length };
        int sum = numbers[ans[0] - 1] + numbers[ans[1] - 1];
        while (sum != target) {
            if (sum < target)
                ans[0]++;
            else
                ans[1]--;
            sum = numbers[ans[0] - 1] + numbers[ans[1] - 1];
        }

        return ans;

    }
}
