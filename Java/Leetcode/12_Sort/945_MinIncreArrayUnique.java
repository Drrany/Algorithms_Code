
import java.util.Arrays;

class MinIncreArrayUnique {

        // 方法一：排序 O(nlogn)O(nlogn)
        public int minIncrementForUnique(int[] A) {

            Arrays.sort(A);
            int len = A.length;
    
            int count = 0;
            for (int i = 1; i < len; i++) {
                while (A[i] <= A[i - 1]) {
                    int next = A[i - 1] + 1;
                    count += next - A[i];
                    A[i] = next;
                }
            }
    
            return count;
        }
    
        // 方法二：计数排序 O(N)O(N)
    
        public static void main(String[] args) {
            int[] A = { 3, 2, 1, 2, 1, 7 };
            int c = minIncrementForUnique2(A);
            System.out.println(c);
        }
    
        public static int minIncrementForUnique2(int[] A) {
    
            if (A == null || A.length < 2)
                return 0;
    
            int count = 0;
            int[] times = new int[40001];
            int max = -1;
            for (int i : A) {
                times[i]++;
                max = Math.max(max, i);
            }
    
            for (int i = 0; i < max; i++) {
                if (times[i] > 1) {
                    int d = times[i] - 1;
                    times[i + 1] += d;
                    count += d;
                }
            }
    
            if (times[max] > 1) {
                int d = times[max] - 1;
                count += (1 + d) * d / 2;
            }
    
            return count;
        }

}