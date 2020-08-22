

class BullsAndCows {

    public String getHint(String secret, String guess) {

        int[] sp = new int[10];
        int[] gp = new int[10];
        int len = secret.length();
        int bulls = 0;
        for (int i = 0; i < len; i++) {
            int cs = secret.charAt(i);
            int cg = guess.charAt(i);
            if (cs == cg)
                bulls++;
            sp[cs - 48]++;
            gp[cg - 48]++;
        }
        
        int cows = 0;
        for (int i = 0; i < 10; i++)
            cows += Math.min(sp[i], gp[i]);
        cows -= bulls;

        return bulls + "A" + cows + "B";
    }
}