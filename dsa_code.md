# Data Structure &amp; Algorithms

#### Linked List
- **Reverse linked list using recursion**
    
    ```
    listnode* reverseList(listnode* A) {
        if(!A || !A->next){
            return A;
        }
    
        listnode* temp = reverseList(A->next);
    
        A->next->next = A;
    
        A->next = NULL;
    
        return temp;
    }
    ```
