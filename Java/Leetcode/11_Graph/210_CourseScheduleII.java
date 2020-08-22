

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

class CourseScheduleII {

    public static int[] findOrder(int numCourses, int[][] prerequisites) {
        
        int[] ans = new int[numCourses];
        int size = 0;

        Deque<Integer> s = new LinkedList<>();
        int[] indegree = new int[numCourses];
        List<List<Integer>> adj = new ArrayList<>();


        for (int i = 0; i < numCourses; i++)
            adj.add(new ArrayList<>());

        for (int[] pair : prerequisites) {
            indegree[pair[0]]++;
            adj.get(pair[1]).add(pair[0]);
        }

        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0)
                s.push(i);
        }

        while (!s.isEmpty()) {
            int i = s.pop();
            ans[size++] = i;
            List<Integer> tmp = adj.get(i);
            for (int j = 0; j < tmp.size(); j++) {
                if (--indegree[tmp.get(j)] == 0)
                    s.push(tmp.get(j));
            }
        }

        
        if (size == numCourses)
            return ans;
            

        return new int[0];

    }


}