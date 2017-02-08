class FindIndex {
    public static int solution(int[] A, int[] B) {
        // write your code in Java SE 8
        int res=-1;
		if(A.length!=0 && B.length!=0){
			A=insertionSort(A);
			int i=0;
			while(i<A.length && res==-1){
				for(int j=0;j<B.length;j++){
					if(A[i]==B[j]){
						res=A[i];
						break;
					}
				}
				i++;
			}
        }
        return res;
    }
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
	public static void main(String[] args) {
		System.out.println("Hello");
		int[] A=new int[]{2,4,3,7,9,6,2};
		int[] B=new int[]{12,23,14,2,45,3};
		int res=solution(A,B);
		System.out.println(res);
	}
}