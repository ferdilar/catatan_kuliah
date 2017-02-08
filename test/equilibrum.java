// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int res=-1;
        if(A.length!=0){
            int N=A.length;
            for(int i=0;i<N;i++){
                int tempBefore=0;
                int tempAfter=0;
                for(int j=0;j<i;j++){
                    tempBefore=tempBefore+A[j];
                }
                for(int k=i+1;k<N;k++){
                    tempAfter=tempAfter+A[k];
                }
                //System.out.println(i+" : "+tempBefore+" "+tempAfter);
                if(tempBefore == tempAfter){
                    return i;
                }
            }
        }
        return res;
    }
}