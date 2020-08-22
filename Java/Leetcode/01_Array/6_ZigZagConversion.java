package Leetcode;

import java.util.ArrayList;

class Solution {
    public String convert(String s, int numRows) {

        int len = s.length();
        if (len <= numRows||numRows<2)
            return s;

        ArrayList<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < numRows; i++)
            rows.add(new StringBuilder());

        int flag = -1;
        int rownum = 0;
        for (int i = 0; i < len; i++) {
            rows.get(rownum).append(s.charAt(i));
            if (rownum == 0 || rownum == numRows - 1)
                flag = -flag;
            rownum += flag;
        }
        
        for (int i = 1; i < numRows; i++) 
            rows.get(0).append(rows.get(i));
        
        return rows.get(0).toString();

    }
}