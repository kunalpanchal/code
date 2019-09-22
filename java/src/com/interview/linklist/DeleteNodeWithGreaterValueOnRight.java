package com.interview.linklist;

import sun.awt.image.ImageWatched;

/**
 * http://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
 * Test cases
 * Sorted list
 * reverse sorted list
 * 0 1 or more nodes in the list
 */
public class DeleteNodeWithGreaterValueOnRight {

    private int maxFound = Integer.MIN_VALUE;
    
    public Node deleteNodes(Node head){
        if(head == null){
            return null;
        }
        Node nextNode = deleteNodes(head.next);
        if(head.data > maxFound){
            maxFound = head.data;
        }
        if(maxFound > head.data){
            return nextNode;
        }
        head.next = nextNode;
        return head;
    }

    public Node deleteNodes1(Node head){
        Node result=head;
        head= LinkList.reverse(head);
        Node prev=head;
        head=head.next;

        while(head!=null){
            while(head.data>prev.data){
                System.out.println(prev.data);
                head=head.next;
                prev=prev.next;
            }
            head=head.next;
            prev=prev.next;
        }
//        result=head;
        return  result;
    }
    public static void main(String args[]){
        DeleteNodeWithGreaterValueOnRight dng = new DeleteNodeWithGreaterValueOnRight();
        LinkList ll = new LinkList();
        Node head = null;
        head = ll.addNode(12, head);
        head = ll.addNode(15, head);
        head = ll.addNode(10, head);
        head = ll.addNode(11, head);
        head = ll.addNode(5, head);
        head = ll.addNode(6, head);
        head = ll.addNode(2, head);
        head = ll.addNode(1, head);
        head = ll.addNode(3, head);
        head = dng.deleteNodes1(head);
        ll.printList(head);
    }
}
