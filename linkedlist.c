#include <stdio.h>
#include <stdlib.h>

// TODO: Figure out why parameter is not being accepted by Add_Node() and Create_List()

unsigned short int userid = 1;

struct LL_Node {
    char fname[10], lname[10], address[20];
    unsigned short int uid;

    struct LL_Node *next;
};

struct LL_Node Create_List(){
    struct LL_Node *head_node = NULL;
    head_node = (struct LL_Node*)malloc(sizeof(struct LL_Node));
    char fn[10], ln[10], addr[20];
    //Fill the head node
    printf("Enter First Name\n");
    scanf("%s", fn);
    fflush(stdin);
    printf("Enter Last Name\n");
    scanf("%s", ln);
    fflush(stdin);
    printf("Enter Address\n");
    scanf("%s", addr);
    fflush(stdin);
    head_node->uid = userid;
    head_node->next = NULL;
    userid++;
    return *head_node;
}

void Add_Node(struct LL_Node *head){
    int iterator;
    while (iterator == 1) {
        if (head->next == NULL) {
            iterator = 0;
        }
        head = head->next;
    }
    //Create the newest node in the list
    struct LL_Node* new_node = NULL;
    new_node = (struct LL_Node*)malloc(sizeof(struct LL_Node)); 
         
    char fn[10], ln[10], addr[20];
    //Fill in the new node
    printf("Enter First Name\n");
    scanf("%s", fn);
    fflush(stdin);
    printf("Enter Last Name\n");
    scanf("%s", ln);
    fflush(stdin);
    printf("Enter Address\n");
    fflush(stdin);
    scanf("%s", addr);
    new_node->uid = userid;
    head->next = new_node;
    userid++;

    printf("New node contains the following information:\nFirst Name: %s\nLast Name: %s\nAddress: %s\nNodeId: %hu\n", new_node->fname, new_node->lname, new_node->address, new_node->uid);
}


void Print_List(struct LL_Node *head) {
    int check;
    check = 1;
    while (check == 1) {
        printf("%s\t", head->fname);
        printf("%s\t", head->lname);
        printf("%s\t", head->address);
        printf("%hu\n", head->uid);
       
        if (head->next == NULL) {
            check = 0;
        }
        head = head->next;
    }
}
main() {
    int selection = 0; 
    struct LL_Node *head;
     
    while ( selection == 0 ) {
    printf(" 1 - Create Linked List\n");
    printf(" 2 - Add Node\n");
    printf(" 3 - Delete Node\n");
    printf(" 4 - Print Linked List\n");
    printf(" 5 - Delete Linked List\n");
    scanf("%d", &selection);
        if (selection == 1) {
            *head = Create_List();
            selection = 0;
        }
        else if (selection ==2 ) {
            Add_Node(head);
            selection = 0;
        }
        else if (selection == 3) {
            printf("Not yet implemented\n");
            selection = 0;
        }
        else if (selection == 4) {
            Print_List(head);
            selection = 0;
        }
        else {
            break;
        }
        fflush(stdin);
    }
}
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
    first->uid = 1;
    first->next = second;
    second->fname = "John";
    second->lname = "Holloway";
    second->address = "258 Chocolate Drive";
    second->uid = 2;
    second->next = third;
    third->fname = "Jacob";
    third->lname = "Lackman";
    third->address = "369 Butts";
    third->uid = 3;
    third->next = NULL;
    
    Print_List(first);
*/


