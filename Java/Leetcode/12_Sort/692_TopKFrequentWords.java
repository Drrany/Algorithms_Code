
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

class TopKFrequentWords {

    public List<String> topKFrequent(String[] words, int k) {

        List<String> ans = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();
        for (String s : words) {
            m.put(s, m.getOrDefault(s, 0) + 1);
        }

        PriorityQueue<String> pQ=new PriorityQueue<>(new Comparator<String>() {
        
            @Override
            public int compare(String o1, String o2) {

                if(m.get(o1)==m.get(o2))
                    return o1.compareTo(o2);
                
                return m.get(o2).compareTo(m.get(o1));
            }
        
        });

        for (String s : m.keySet())
            pQ.add(s);
        
        for (int i = 0; i < k; i++)
            ans.add(pQ.poll());

        return ans;

    }



}