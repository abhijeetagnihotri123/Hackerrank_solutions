    static int B,H;
    static boolean flag;
    static
    {
        Scanner ob=new Scanner (System.in);
        //boolean flag=true;
        B=ob.nextInt();
        H=ob.nextInt();
       
        if(B<=0 || H<=0)
        {
            flag=false;
            System.out.println("java.lang.Exception: Breadth and height must be positive");
        }
        else
        {
            flag=true;
        }
    }
