#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Figure out why parameter is not being accepted by Add_Node() and Create_List()

unsigned short int userid = 1;

struct LL_Node {
    char fname[20], lname[20], address[60];
    unsigned short int uid;

    struct LL_Node *next;
};

struct LL_Node* Create_List(){
    struct LL_Node *head_node = NULL;
    head_node = (struct LL_Node*)malloc(sizeof(struct LL_Node));
    char fn[20], ln[20], addr[60], user_input[128];
    //Fill the head node
    printf("Enter First Name, Last Name, and Address with only spaces in between\n");
    // extra fgets to process out the LF from user input
    // in the Options selection process
    // TODO: make it less janky of a process
    fgets(user_input, 128, stdin);
    if (fgets(user_input, 128, stdin) != NULL ){
    sscanf(user_input, "%s %s %s", fn, ln, addr);
}
    strncpy(head_node->fname, fn, sizeof(fn));
    strncpy(head_node->lname, ln, sizeof(ln));
    strncpy(head_node->address, addr, sizeof(addr));
    head_node->uid = userid;
    userid++;
/*
    printf("Enter First Name\n");
    sscanf("%s", fn);
    fflush(stdin);
    printf("Enter Last Name\n");
    sscanf("%s", ln);
    fflush(stdin);
    printf("Enter Address\n");
    sscanf("%s", addr);
    fflush(stdin);
    head_node->uid = userid;
    head_node->next = NULL;
    userid++;
    return *head_node;
*/
return head_node;
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
         
    char fn[20], ln[20], addr[60], user_input[128];
    //Fill in the new node
    printf("Enter First Name, Last Name, and Address with only spaces in between\n");
    fgets(user_input, 128, stdin);
    if (fgets(user_input, 128, stdin) != NULL ){
    sscanf(user_input, "%s %s %s", fn, ln, addr);
}
    strncpy(new_node->fname, fn, sizeof(fn));
    strncpy(new_node->lname, ln, sizeof(ln));
    strncpy(new_node->address, addr, sizeof(addr));

    new_node->next = NULL;
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
    char choice[1];
    char selection = 0; 
    struct LL_Node *head;
    head = (struct LL_Node*)malloc(sizeof(struct LL_Node)); 
     

    while ( 1 ) {
    printf("=========================\n");
    printf(" 1 - Create Linked List\n");
    printf(" 2 - Add Node\n");
    printf(" 3 - Delete Node\n");
    printf(" 4 - Print Linked List\n");
    printf(" 5 - Delete Linked List\n");
    printf("=========================\n");
    choice[0] = getchar();
    sscanf(choice, "%hhd", &selection);
    //printf("%d\n", selection);

        if (selection == 1) {
            head = Create_List();
        }
        else if (selection == 2 ) {
            Add_Node(head);
        }
        else if (selection == 3) {
            printf("Not yet implemented\n");
        }
        else if (selection == 4) {
            Print_List(head);
        }
        else if (selection == 5) {
            printf("Not yet implemented\n");
        }
        else if (selection == 6) {
            printf("Exiting Program...\n");
            break;
        }
        else {
            printf("Input invalid\n\n");
            fflush(stdin);
        }
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


