class Solution {

    static public boolean isPal(String s, int j){


        int i=0;

        while(i<j){
            if(s.charAt(i)!=s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
    
    public String shortestPalindrome(String s) {
        int n=s.length()-1;
        if(isPal(s,n)) return s;

        int end=n-1;

        while(end>0){
            if(isPal(s,end)){
                break;
            }
            else{
                end--;
            }
        }

        
        StringBuilder lf= new StringBuilder(s.substring(end+1));
        lf.reverse();
        return lf.toString()+s;
    }
}