

class SumTwoInt {

    public int getSum(int a, int b) {

        int sum = a;
        int count = b;

        while (count != 0) {
            int tmp = sum;
            sum ^= count;
            count &= tmp;
            count <<= 1;
        }

        return sum;

    }

}