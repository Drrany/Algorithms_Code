
class IntegertoRoman {

    public String intToRoman(int num) {

        String[] roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        StringBuilder ans = new StringBuilder();
        int[] arr = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
        int i = 12;

        while (num != 0 && i >= 0) {

            if (arr[i] <= num) {
                ans.append(roman[i]);
                num -= (int) arr[i];
            } else
                i--;
        }

        return ans.toString();

    }

}
