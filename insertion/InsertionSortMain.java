import java.util.Arrays; 

public class InsertionSortMain {
      
    public static int[] insertionSort(int[] input){
         
        int temp;
        for (int i = 1; i < input.length; i++) {
            for(int j = i ; j > 0 ; j--){
                if(input[j] < input[j-1]){
                    temp = input[j];
                    input[j] = input[j-1];
                    input[j-1] = temp;
                }
            }
        }
        return input;
    }
	
    public static void main(String a[]){
        int[] arr = {10,34,2,56,7,67,88,42};
        System.out.println("Before Sorting : ");  
        System.out.println(Arrays.toString(arr));  
        arr = insertionSort(arr);  
        System.out.println("===================");  
        System.out.println("After Sorting : ");  
        System.out.println(Arrays.toString(arr)); 
    }
}