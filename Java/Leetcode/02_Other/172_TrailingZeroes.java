

class TrailingZeros {

    public static void main(String[] args) {
        int n = trailingZeroes(30);
        System.out.println(n);
    }

    public static int trailingZeroes(int n) {
        /*
            14!  2
            15!  3
            19!  3
            20!  4
            24!  4  2*4*5*6*8*10*12*15*20*22*24
            25!  6
            26!  6
            29!  6
            30!  7
        */
        
        int five=0;//five个五的倍数

        while (n != 0) {
            n /= 5;
            five += n;
        }

        int count = five;

        return count;


    }

}
