import java.util.*;
class Abc
{
    public static void main(String args[])
    {
        Scanner ob=new Scanner(System.in);
        int n;
        n=ob.nextInt();
        int c[]=new int[100];
        for(int i=0;i<100;i++)
        {
            c[i]=0;
        }
        int index;
        for(int i=0;i<n;i++)
        {
            index=ob.nextInt();
            c[index]++;
        }
        for(int i=0;i<100;i++)
        {
            System.out.print(c[i]+" ");
        }
    }
}
