/*
Detect a cycle in a linked list. Note that the head pointer may be 'null' if the list is empty.

A Node is defined as: 
    class Node {
        int data;
        Node next;
    }
*/

boolean hasCycle(Node head) {
        
    if(head==null)
    {
        return false;
    }
    else
    {
        Node fast;
        Node slow;
        fast=head.next;
        slow=head;
        boolean flag=false;
        while(fast!=null && fast.next!=null)
        {
            if(fast==slow)
            {
                flag=true;
                break;
            }
            else
            {
                fast=fast.next.next;
                slow=slow.next;
            }
        }
    
    return flag;
    }
}