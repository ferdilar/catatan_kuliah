// import java.io.*;
import java.util.*;//scanner
// import java.text.*;
// import java.math.*;
// import java.util.regex.*;
class FindBug {
    public static int solution(int[] A, int X) {
        int N = A.length;
        if (N == 0) {
            return -1;
        }
        int l = 0;
        int r = N - 1;
        while (l < r) {
            int m = ((l + r) / 2)+1;
				// System.out.println("\nm: "+m);
            if (A[m] > X) {
                r = m-1;
				// System.out.println("r: "+r);
            } else {
                l = m;
				// System.out.println("l: "+l);
            }
        }
        if (A[l] == X) {
            return l;
        }
        return -1;
    }
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		System.out.println("Hello");
		int[] A=new int[]{0,1,2,3,4,5,6,7,8,8,9};
		int X;
        X = in.nextInt();
		
		int res=solution(A,X);
		System.out.println(res);
				
        // char S = in.next().charAt(2);
		// System.out.println(S);
	}
}