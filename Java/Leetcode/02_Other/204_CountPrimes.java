
class CountPrimes {

    public int countPrimes(int n) {

        boolean[] notaprime = new boolean[n];
        int count = 0;

        for (int i = 2; i * i <= n; i++) {
            if (!notaprime[i]) {
                for (int j = i * i; j < n; j += i)
                    notaprime[j] = true;
            }
        }

        for (int i = 2; i < n; i++) {
            if (!notaprime[i])
                count++;
        }

        return count;

    }

}