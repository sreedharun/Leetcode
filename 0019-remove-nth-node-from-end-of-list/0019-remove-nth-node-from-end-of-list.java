/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode t=head;
        int c=0;
        while(t!=null){
            c++;
            t=t.next;
        }
        int pos=c-n;
        System.out.print(pos);
        if(pos==0){
            head=head.next;
            return head;
        }
        t=head;
        for(int i=1;i<pos;i++){
            t=t.next;
        }
        t.next=t.next.next;
        return head;
    }
}