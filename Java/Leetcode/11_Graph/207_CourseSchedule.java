
import java.util.ArrayList;
import java.util.List;
import java.util.Deque;
import java.util.LinkedList;

class CourseSchedule {

    public static boolean canFinish(int numCourses, int[][] prerequisites) {


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
            if (indegree[i] == 0) {
                s.push(i);
                numCourses--;
            }
        }

        while (!s.isEmpty()) {
            int i = s.pop();
            List<Integer> tmp = adj.get(i);
            for (int j = 0; j < tmp.size(); j++) {
                if (--indegree[tmp.get(j)]==0) {
                    s.push(tmp.get(j));
                    numCourses--;
                }
            }
        }

        if (numCourses == 0)
            return true;

        return false;

    }

}