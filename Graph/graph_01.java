
    public static int encoding(String str,String ans){
        if(str.length()==0) {
            System.out.println(ans);
            return 1;
        }

        char ch=str.charAt(0);
        String nstr=str.substring(1);
        int count=0;
        
        count+=encoding(nstr,ans+(char)('a'+ (ch-'0')));    
        if(str.length() > 1){
            char ch2=str.charAt(1);
            int num = (ch-'0')*10 + (ch2-'0');
            if(num >= 10 && num <= 25){
                count+=encoding(str.substring(2),ans+ (char)('a'+ num));
            }
        }
       
        return count;
    }