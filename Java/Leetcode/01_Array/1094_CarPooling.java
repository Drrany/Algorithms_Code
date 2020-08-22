

class CarPooling {

    public static boolean carPooling(int[][] trips, int capacity) {

        int[] pt = new int[1001];
        for (int[] n : trips) {
            pt[n[1]] += n[0];
            pt[n[2]] -= n[0];
        }

        if (pt[0] > capacity)
            return false;
        for (int i = 1; i < 1001; i++) {
            pt[i] += pt[i - 1];
            if (pt[i] > capacity)
                return false;
        }
        
        return true;

    }
    
}