#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

return head_node;

}

void Add_Node(struct LL_Node *head){
    int iterator = 1;
    while (iterator == 1) {
        if (head->next == NULL) {
            iterator = 0;
        }
        else {
        head = head->next;
        }
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

//Implement search_by for lname, addr, and uid
void Print_Node(struct LL_Node *head) {
    char choice[1], user_input[60], search_by[60];
    char selection = 0;

    while (1) {
        fgets(user_input, 60, stdin);
        printf("Search by\n 1 - First Name \n 2 - Last Name\n 3 - Address\n");
        choice[0] = getchar();
        sscanf(choice, "%hhd", &selection);

        if (selection == 1) {
            printf("Please enter First Name\n");
            fgets(user_input, 60, stdin);
            if (fgets(user_input, 60, stdin) != NULL ) {
                sscanf(user_input, "%s", search_by);
                while (1) {
                    if(strcmp(head->fname,search_by) == 0) {
                        printf("%s\t", head->fname);
                        printf("%s\t", head->lname);
                        printf("%s\t", head->address);
                        printf("%hu\n", head->uid);
                        
                    }
                    if(head->next != NULL) {
                        head = head->next;
                    }
                    else {
                        break;
                    }
                }
            break;
            }
        }
        else {
                printf("Please enter a choice\n");
        }
    }
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
    printf(" 4 - Print Node\n");
    printf(" 5 - Print Linked List\n");
    printf(" 6 - Delete Linked List\n");
    printf(" 7 - Quit Program\n");
    printf("=========================\n");
    choice[0] = getchar();
    sscanf(choice, "%hhd", &selection);

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
            Print_Node(head);
        }
        else if (selection == 5) {
            Print_List(head);
        }
        else if (selection == 6) {
            printf("Not yet implemented\n");
        }
        else if (selection == 7) {
            printf("Exiting Program...\n");
            break;
        }
        else {
            printf("Input invalid\n\n");
            fflush(stdin);
        }
    }
}


