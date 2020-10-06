#include <stdio.h>
#include <stdlib.h>

// TODO: Create incrementing ID system. 
// TODO: Figure out why parameter is not being accepted by Add_Node() and Create_List()

struct LL_Node {
    char *fname, *lname, *address;
    int id;

    struct LL_Node* next;
};

void Create_List(){
    struct LL_Node* head_node = NULL;
    head_node = (struct LL_Node*)malloc(sizeof(struct LL_Node));
    int fn, ln, addr;
    //Fill the head node
    printf("Enter First Name\n");
    while ((fn = getchar()) != "\n") {
        head_node->fname += fn;
    }
    printf("Enter Last Name\n");
    while ((ln = getchar()) != "\n") {
        head_node->lname += ln;
    }
    printf("Enter Address\n");
    while ((addr = getchar()) != "\n") {
        head_node->address += addr;
    }
    head_node->id = 1;
    head_node->next = NULL;
}

void Add_Node(struct LL_Node* head){
    int iterator;
    while (iterator == 1) {
        if (head->next == NULL) {
            iterator = 0;
        }
        head = head->next;
    }
    char fn, ln, addr;
    //Create the newest node in the list
    struct LL_Node* new_node = NULL;
    new_node = (struct LL_Node*)malloc(sizeof(struct LL_Node)); 
         
    //Fill in the new node
    printf("Enter First Name\n");
    while ((fn = getchar()) != "\n") {
        new_node->fname += fn;
    }
    printf("Enter Last Name\n");
    while ((ln = getchar()) != "\n") {
       new_node->lname += fn;
    }   
    printf("Enter Address\n");
    while ((addr = getchar()) != "\n") {
       new_node->address += addr;
    }
    new_node->id = head->id + 1;
    head->next = new_node;

    printf("New node contains the following information:\nFirst Name: %s\nLast Name: %s\nAddress: %s\nNodeId: %d\n", new_node->fname, new_node->lname, new_node->address, new_node->id);
}


void Print_List(struct LL_Node* head) {
    int check;
    check = 1;
    while (check == 1) {
        printf("%s\t", head->fname);
        printf("%s\t", head->lname);
        printf("%s\t", head->address);
        printf("%d\n", head->id);
       
        if (head->next == NULL) {
            check = 0;
        }
        head = head->next;
    }
}
main() {
    printf(" 1 - Create Linked List\n");
    printf(" 2 - Add Node\n");
    printf(" 3 - Delete Node\n");
    printf(" 4 - Print Linked List\n");
    printf(" 5 - Delete Linked List\n");
    int selection; 
    while ((selection = getchar()) != "\n") {
        if (selection == 1) {
            Create_List();
        }
        else if (selection == 2) {
            Add_node(head);
        }
        else if (selection == 3) {
            printf("Not yet implemented\n");
        }
        else if (selection == 4) {
            Print_List(head);
   /* 
    struct LL_Node* first = NULL;
    struct LL_Node* second = NULL;
    struct LL_Node* third = NULL;
    first = (struct LL_Node*)malloc(sizeof(struct LL_Node));
    second = (struct LL_Node*)malloc(sizeof(struct LL_Node));
    third = (struct LL_Node*)malloc(sizeof(struct LL_Node));
    first->fname = "Jenny";
    first->lname = "Graves";
    first->address = "147 Bob Street";
    first->id = 1;
    first->next = second;
    second->fname = "John";
    second->lname = "Holloway";
    second->address = "258 Chocolate Drive";
    second->id = 2;
    second->next = third;
    third->fname = "Jacob";
    third->lname = "Lackman";
    third->address = "369 Butts";
    third->id = 3;
    third->next = NULL;
    
    Print_List(first);
*/
}
