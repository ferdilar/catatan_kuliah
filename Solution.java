import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {


    static int solveMeFirst(int a, int b) {
      // Hint: Type return a+b; below
      return a+b;
   }

   
 public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		String aa;
        System.out.print("String ->");
		aa = in.nextLine();
		while(aa!=null) {
			System.out.println(aa);
			if (aa.isEmpty()) {
				System.out.println("Read Enter Key.");
			}
			if (in.hasNextLine()) {
				aa = in.nextLine();
			} else {
				aa = null;
			}
		}
        // int a;
        // System.out.print("Int ->");
        // a = in.nextInt();
        // int b;
        // System.out.print("Int ->");
        // b = in.nextInt();
        // int sum;
        System.out.println("");
        // sum = solveMeFirst(a, b);
        System.out.println(aa);
        // System.out.println(sum);
   }
}
