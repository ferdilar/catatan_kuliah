// you can also use imports, for example:
// import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(Tree T) {
        int V=0;
        int maxNow=0;
        Queue<Tree> q = new LinkedList<Tree>();
		if (T == null){
			return V;
		}
		q.add(T);
		maxNow=T.x;
		while (!q.isEmpty()) {
			Tree n = (Tree) q.remove();
			System.out.print(" " + n.x);
			if(n.x>=maxNow){
			    V++;
			    maxNow=n.x;
			}
			if (n.l != null)
				q.add(n.l);
			if (n.r != null)
				q.add(n.r);
		}
        return V;
    }
    
}