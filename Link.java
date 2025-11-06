class Node{
    int data;
    Node next;

    public Node(int data){
        this.data=data;
        this.next=null;
    }
}

public class Link{
    
    //travasal
    public static void printList(Node head){
        Node current =head;
        while(current!=null){
            System.out.print(current.data+"->");
            current=current.next;
        }
    }

    //insertion begin
    public static Node insertB(Node head,int ne){
        Node newNode=new Node(ne);
        newNode.next=head;
        return newNode;
    }

    //insertion end
    public static Node insertE(Node head,int ne){
        Node newNode=new Node(ne);
             newNode.next=null;
        if(head==null){
            return newNode;
        }     
        Node current=head;
        while(current.next != null){
            current=current.next;
        }
        current.next=newNode;
        return head;
    }

    //insertion anywhere
    public static Node insertA(Node head,int ne,int data){
        Node newNode=new Node(ne);
        Node current =head;
        Node insert=null;
        while(current!=null && current.data != data){
            if(current.data==data){
                insert=current;

            }
            current=current.next;
        }
        newNode.next=insert.next;
        insert.next=newNode;
        return head;

        
    }

    
    // Merge two unsorted lists (append list2 to list1)
    public static Node mergeLists(Node head1, Node head2) {
        if (head1 == null) return head2;
        if (head2 == null) return head1;

        Node current = head1;
        while (current.next != null) {
            current = current.next;
        }
        current.next = head2; // attach list2 to the end of list1
        return head1;
    }


    //deletion
    public static Node delete(Node head, int key) {
    if (head == null) return null;

    // If the node to delete is the head
    if (head.data == key) {
        return head.next;
    }

    Node current = head;
    while (current.next != null && current.next.data != key) {
        current = current.next;
    }

    if (current.next == null) {
        System.out.println("Node with value " + key + " not found!");
        return head;
    }

    // Skip the node to delete
    current.next = current.next.next;

    return head;
}

    public static void main(String[] args) {
        Node head= new Node(10);
        Node second= new Node(20);
        Node third=new Node(30);
        Node fourth=new Node(40);
        head.next=second;
        head.next.next=third;
        head.next.next.next=fourth;

        printList(head);
      System.out.println();
       head= insertB(head, 5);
        printList(head);
        System.out.println();
       head= insertE(head, 50);
        printList(head);
        System.out.println();
       head=insertA(head, 25, 20); 
       printList(head);
    }
}