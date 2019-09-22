package com.interview.linklist;

/**
 * Created by Kunal on 14-11-2016.
 1->9->9->9 is added to 1 and we get
 2->0->0->0
 */
public class Add1ToLinkedList {

    private static Node addNumber(Node head,int number){

        // res is head node of the resultant list
        Node res = head;
        Node temp=null;
        int carry = 1, sum;

        while (head != null)
        {
            // Calculate value of next digit in resultant list.
            // The next digit is sum of following things
            // (i) Carry
            // (ii) Next digit of head list (if there is a
            //     next digit)
            sum = carry + (head!=null? head.data: 0);

            // update carry for next calulation
            carry = (sum >= 10)? 1 : 0;

            // update sum if it is greater than 10
            sum = sum % 10;

            // Create a new node with sum as data
            head.data = sum;

            // Move head and second pointers to next nodes
            temp = head;
            head = head.next;
        }

        // if some carry is still there, add a new node to result list.
        if (carry > 0)
            temp.next = Node.newNode(carry);

         return res;
    }

    public static void main(String args[]){
        LinkList ll=new LinkList();
        Node head=null;
        head=ll.addNode(1,head);
        ll.addNode(9,head);
        ll.addNode(9,head);
        ll.addNode(9,head);
        System.out.println("Entered Number = ");
        ll.printList(head);

        head=ll.reverse(head);
        head=Add1ToLinkedList.addNumber(head,1);
        head=ll.reverse(head);

        System.out.println("\nAfter adding one = ");
        ll.printList(head);

    }
}
