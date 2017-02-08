class OneSwap {
    public static boolean solution(int[] A) {
        // write your code in Java SE 8
		boolean res=false;
		if(A.length!=0){
			res=cekSort(A);
			if(res){//sudah sort
				return res;//true
			}
				for (int i = 0; i < A.length-1; i++) {
					for (int j = i + 1; j < A.length; j++){ 
						int temp = A[i];    
						A[i] = A[j];  
						A[j] = temp; 
						res=cekSort(A);
						if(res){
							return res;//return true
						}else{//balikin
							temp = A[i];    
							A[i] = A[j];  
							A[j] = temp;
						}
						// System.out.println(A[i]+" swap "+A[j]+" res: ?");
					}
					// System.out.println("break");
				}
		}
        return res;//return false
    }
    public static boolean cekSort(int[] arr){
        boolean okSort=true;
        for (int i = 0; i < arr.length - 1; i++){  
            int index = i;  
            for (int j = i + 1; j < arr.length; j++){
                if (arr[j] < arr[index]){
                    index = j;
                    okSort=false;
                }
            } 
        }  
        return okSort;  
    }
	public static void main(String[] args) {
		System.out.println("Hello");
		int[] A=new int[]{1,2,6,4,5,3,7};
		boolean res=solution(A);
		System.out.println(res);
	}
}