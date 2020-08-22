class ReverseBits {

    public static void main(String[] args) {
        reverseBits(-3);
    }

    public static int reverseBits(int n) {

        int ans = 0;

        for (int i = 0; i < 32; i++) {
            // 取第i位
            int tmp = n >> i;
            tmp = tmp & 1;
            // 放在第31-i位上
            ans |= tmp << (31 - i);
        }

        return ans;

    }
}