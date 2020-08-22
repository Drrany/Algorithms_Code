package Leetcode;

import java.util.HashMap;
import java.util.Map;

class RomanInte {

    public int romanToInt(String s) {

        int len = s.length();
        int sum = 0;

        //map的执行时间较长，用switch-case比较快，但后面判断的原理一样
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        for (int i = 0; i < len; i++) {
            if (i < len - 1 && map.get(s.charAt(i)) < map.get(s.charAt(i+1)))
                sum -= 2 * map.get(s.charAt(i));
            sum += map.get(s.charAt(i));
        }

        return sum;

    }

}
