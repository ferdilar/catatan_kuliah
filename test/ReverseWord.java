import java.util.*;//scanner
class ReverseWord {
    public static String solution(String S) {
        // write your code in Java SE 8
        S=S.toLowerCase();
        int numOfSpace=0;
        for(int i=0;i<S.length();i++){
            if(S.charAt(i)==' '){
                numOfSpace++;
            }
        }
        char[] charArray = S.toCharArray();
        int index=0;
        int indexStart=index;
        int indexEnd=0;
            while(index<S.length()){
                if(S.charAt(index)==' '){
                    indexEnd=index-1;
                    //swap
                    for(int k=indexStart;k<=indexEnd;k++){
                        charArray[k]=S.charAt(indexEnd-k+indexStart);
                        //System.out.println(k+" swap "+(indexEnd-k+indexStart));
                    }
                    indexStart=index+1;
                }else if(index+1==S.length()){
                    indexEnd=index;
                    //swap
                    for(int k=indexStart;k<=indexEnd;k++){
                        charArray[k]=S.charAt(indexEnd-k+indexStart);
                        //System.out.println(k+" swap "+(indexEnd-k+indexStart));
                    }
                    indexStart=index+1;
                }
                index++;
            }
        return String.valueOf(charArray);
    }
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Hello");
		String S;
        S = in.nextLine();
		S=solution(S);
		System.out.println(S);
	}
}

