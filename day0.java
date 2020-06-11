import java.util.*;
public class day1{
    public static Scanner scn = new Scanner(System.in);

    public static int factorial(int n){
        return n<=0?1:n*factorial(n-1);
    }

    public static int raisedPower(int n, int x){
        return x==0?1:n*raisedPower(n,x-1);
    }

    public static int betterRaisedPower(int n, int x){
        if(x == 0)  return 1;
        int ans = betterRaisedPower(n,x/2);
        ans *= ans;
        return x%2==0?ans:ans*n;
    }

    public static void display(int [] arr, int i){
        if(i == arr.length)     return;
        System.out.print(arr[i]+" ");
        display(arr,i+1);
    }


    public static int maximum(int [] arr, int n){
        if(arr.length-1 == n)   return arr[n];
        int max = arr[n];
        return Math.max(max,maximum(arr,n+1));
    }

    public static int minimum(int [] arr, int n){
        if(arr.length-1 == n )      return arr[n];
        int min = arr[n];
        return Math.min(min,minimum(arr,n+1));
    }

    public static boolean find(int [] arr, int n, int x){
        if(n == arr.length)     return false;
        if(n == x)              return true;
        return find(arr,n+1,x);
    }

    public static int firstIndex(int [] arr, int n, int x){
        if(n == arr.length)     return -1;
        if(arr[n] == x)         return n;
        return firstIndex(arr,n+1,x);
    }

    public static int lastIndex(int [] arr, int n, int x){
        if(n == arr.length){
            return -1;
        }
        int myans = lastIndex(arr, n+1, x);
        if(myans!= -1){
            return myans;
        }
        else if(arr[n] == x)    return n;
        else return -1;


    }


    public static int [] allIndex(int [] arr, int n, int x, int count){
        if(n == arr.length)     return new int [count];
        if(x == arr[n])     count++;
        int [] ans  = allIndex(arr,n+1,x,count);
        if(arr[n] == x)     ans[count-1] = n;
        return ans;
    }


    //===================================================================


    public static ArrayList<String> subSequence(String str){
        if(str.length() == 0){
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        char ch = str.charAt(0);
        ArrayList<String> recAns = subSequence(str.substring(1));
        ArrayList<String> myAns = new ArrayList<>();
        for( String s : recAns){
            myAns.add(s);
            myAns.add(ch+s);
        }
        return myAns;
    }

    //==========================================================


    public static void subSequence(String str, ArrayList<String> sa,ArrayList<ArrayList<String>> ans){
        if(str.length() == 0){
            ArrayList<String> s = new ArrayList<>(sa);
            ans.add(s);
            return;
        }
        subSequence(str.substring(1),sa,ans);
        sa.add(str.charAt(0)+"");
        subSequence(str.substring(1),sa,ans);
        sa.remove(sa.size()-1);
    }

    // subseq() is used to call subSequence
    public static void subseq(){
        ArrayList<ArrayList<String>> ans=new ArrayList<>();
        ArrayList<String> sa = new ArrayList<>();
        
        subSequence("abc",sa,ans);
        
        System.out.println(ans);
    }



public static String[] words={":;/", "abc", "def", "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz", "&*%", "#@$","+-/*"};



    public static ArrayList<String> keyPad(String str){
        if(str.length() == 0){
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        int ch = str.charAt(0);
        String word = words[ch - '0'];
        ArrayList<String> recAns = keyPad(str.substring(1));
        ArrayList<String> myAns = new ArrayList<>();
        for(String s : recAns){
            for(int i = 0; i<word.length(); i++){
                myAns.add(word.charAt(i)+s);
            }
        }
        return myAns;
    }
    

    

    public static void main(String[]args){
        // System.out.print(raisedPower(2,5));
        // int [] arr = {3,3,40,3,5};
        // System.out.print(minimum(arr,0));
        // System.out.print(lastIndex(arr,0,3));
        // System.out.print(keyPad("78"));
        subseq();

    
    }
}