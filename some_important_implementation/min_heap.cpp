#include <iostream>
using namespace std;
#define capacity 16

int *harr;
int heap_size = 0;
void swap(int &a,int &b)
{
    int t = a ^ b;
    a = t ^ a;
    b = t ^ b;
}
int getMin(void)
{
    return harr[0];
}
int parent(int i)
{
    int j = i-1;
    j = (j>>1);
    return j;
}
int left(int i)
{
    int j = (i<<1);
    return (j+1);
}
int right(int i)
{
    int j = (i<<1);
    return (j+2);
}
void Minheapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(harr[l] < harr[i] && l<heap_size)
    {
        smallest = l;
    }
    if(harr[r] < harr[smallest] && r<heap_size)
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(harr[smallest],harr[i]);
        Minheapify(smallest);
    }
}
void insert_key(int k)
{
    heap_size++;
    int i = heap_size-1;
    harr[i] = k;
    while(harr[parent(i)] > harr[i] && i>0)
    {
        int l = parent(i);
        swap(harr[i],harr[l]);
        i = l;
    }
}
int extractMin(void)
{   
    if(heap_size <= 0)
    {
        return -1;
    }
    if(heap_size == 1)
    {   
        heap_size = 0;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size = heap_size-1;
    Minheapify(0);
    return root;
}
void decrease_key(int i,int value)
{
    harr[i] = value;
    while(i > 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[parent(i)],harr[i]);
        i = parent(i);
    }
}
void deleteKey(int i)
{
    decrease_key(i,-2147483648);
    extractMin();
}
void display_heap(void)
{
    for(int i=0;i<heap_size;i++)
    {
        cout<<harr[i]<<" ";
    }
    cout<<endl;
}
int main()
{   
    harr = new int[capacity];
    for(int i=0;i<capacity;i++)
    {
        harr[i]=0;
    }
    char ch = 'y';
    do
    {
        int q;
        cout<<"Enter 1 for insertion of element in heap.\nEnter 2 for deletion of root from the heap.\nEnter 3 for deletion from a specific location.\nEnter 4 for displaying heap.\nEnter choice\n";
        cin>>q;
        switch(q)
        {
            case 1:
                cout<<"Insertion\n";
                int k;
                cin>>k;
                insert_key(k);
                break;
            case 2:
                cout<<"Deletion from the root.\nThe element from the root is:"<<extractMin()<<endl;
                break;
            case 3:
                int i;
                cout<<"Enter index from which element is to be deleted"<<endl;
                cin>>i;
                deleteKey(i);
                break;
            case 4:
                cout<<"Displaying the heap"<<endl;
                display_heap();
                break;
            default:
                break;
        }
        cout<<"Want to enter more queries press y or Y to do so\n";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    
    return 0;
}