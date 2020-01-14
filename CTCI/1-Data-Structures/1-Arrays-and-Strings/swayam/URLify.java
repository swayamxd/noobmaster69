import java.util.*;
public class URLify{  
    
        public static void main(String args[]){  
            Scanner sc=new Scanner(System.in);
            System.out.println("enter the string");
            String s1=sc.nextLine();  
            char arr[];
            //METHOD 1 USING .replace() FUNCTION
            String replaceString=s1.replace(" ","%20"); 
            System.out.println(replaceString);
            //METHOD 2 IN PLACE REPLACEMENT USING CHARACTER ARRAY 
            int l=s1.length(),sp=0;
            
            for(int i=0;i<l;i++)
            {
                char c=s1.charAt(i);
                if(c==' ')
                sp++;
            } 
            arr=new char[l+(3*sp)-sp];
            int j=-1;
            for(int i=0;i<l;i++)
            {
                char c=s1.charAt(i);
                if(c==' ')
                {
                    arr[++j]='%';
                    arr[++j]='2';
                    arr[++j]='0';
                }
                else
                 arr[++j]=c;
                }
            for(int i=0;i<arr.length;i++)
                System.out.print(arr[i]);
                
            
            
     }
}  