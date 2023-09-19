/*
Brute Force Approach
The simple idea is to store all the data values of the linked list nodes in an ArrayList and then directly access the middle element by index. 

Initialize an empty ArrayList al to store the data values of the linked list nodes.
Initialize a curr pointer to the head of the linked list.
Traverse the linked list using a loop:
 In each iteration, add the data value of the current node (pointed to by curr) to the ArrayList al.
Move the curr pointer to the next node.
Repeat until curr becomes null, i.e., you have traversed the entire linked list.
Return the value stored at the index al.size()/2 in the ArrayList. This value represents the middle element of the linked list.
Code
Time Complexity: The time complexity of this approach is directly proportional to the number of nodes in the linked list. You need to traverse the entire linked list to populate the ArrayList, which takes O(n) time.

Space Complexity: The space complexity is also relatively high. You are using additional space to store all the data values of the linked list in an ArrayList, which takes O(n) space, where 'n' is the number of nodes in the linked list.


The intuition behind finding the middle of a linked list using two-pointers is based on the concept of moving one pointer at half the speed of the other. This technique is commonly referred to as the "tortoise and hare" or "slow and fast" pointers approach.
Time Complexity:  O(n), where 'n' is the number of nodes in the linked list.

Space Complexity: O(1), constant space usage.

Alternate Approach

We can first counts the number of nodes in the linked list using one pass, and then calculate the index of the middle node based on whether the number of nodes is even or odd. After determining the index, traverse the linked list again to reach the middle node and returns its data value.
class Solution
{
    int getMiddle(Node head)
    {
      Node list = head;
        int counter =0;
        //count no. of nodes
        while (list!=null){
            counter++;
            list=list.next;
        }
        //Decide mid node
         int mid = (counter%2 == 0)? (counter+1)/2 : (counter/2);
        
        list = head;
        counter=0;
		
        //return from mid node
        while (counter!=mid){
            list=list.next;
            counter++;
        }
return list.data;
    }}

*/








//two pointer techniiique
here we take two pontiners slow and fast
as fast moves double times by te time it will be at end slow will in the midddle


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if(head->next==NULL || head->next==NULL)
            return head->data;
        if(head->next->next==NULL)
        {
            return head->next->data;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
    
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends
