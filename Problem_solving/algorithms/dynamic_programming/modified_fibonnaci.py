if __name__=="__main__":
    l=[]
    a = input().split(' ')
    l.append(int(a[0]))
    l.append(int(a[1]))
    n=int(a[2])
    for i in range(2,n):
        k = l[i-2]+l[i-1]*l[i-1]
        l.append(k)
    print(l[n-1])
