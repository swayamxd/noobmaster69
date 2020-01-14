import java.util.*;
public class checkPermutation
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        
        System.out.println("enter the string");
        String st=sc.nextLine();
        int l=st.length();
        System.out.println("enter the string");
        String st1=sc.nextLine();
        int l1=st1.length();
        if(l==l1)
        {
            checkPermutation ob=new checkPermutation();
            ob.hashTable(st.toUpperCase(),l,st1.toUpperCase());
       }
       else
       System.out.println("not permutation");
        
        
    }
    //METHOD 1 USING HASHTABLE
    public void hashTable(String s,int l,String s1)
    {
        int f=1;
        char hash[]=new char[64];
        for(int i=0;i<64;i++)
            hash[i]='`';
        for(int i=0;i<l;i++)
        {
            char c=s.charAt(i);
            hash[((int)c)-32]=c;
        }
        for(int i=0;i<l;i++)
        {
            char c=s1.charAt(i);
            if(hash[((int)c)-32]=='`')
            {
                f=0;
                break;
            }
        }
         if(f==0)
         System.out.println("not permutation");
         else
         System.out.println("permutation");
    }  
    //METHOD 2 USING BIT ARRAY ASSUMING ONLY ALPHABET INPUT
    
    public void bitarray(String s,int l)
    {
            int c = 0;
            for(int i=0;i<l;i++)
            {
                 int val = s.charAt(i) - 'A';
            if ((c & (1 << val)) > 0) 
                System.out.println("not unique");
            c |= (1 << val);
            }
        System.out.println("unique");
    }
}    