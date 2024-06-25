#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *pre;
};

struct node *head = NULL, *tail = NULL, *temp = NULL, *newnode = NULL;
int count = 0;

struct node *create_newnode() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    temp->pre = NULL;
    count++;
    return temp;
}

void last() { 
    newnode = create_newnode();
    if (head == NULL) {
        tail = head = newnode;
        head->pre = tail;
        tail->next = head;
    } else {
        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
        tail->next = head;
        head->pre = tail;
    }
}

void addbegin() {
    if (head == NULL) {
        last();
    } else {
        newnode = create_newnode();
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
        head->pre = tail;
        tail->next = head;
    }
}

void add_specific() {
    int i = 1, pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1) {
        printf("Enter correct option\n");
        add_specific();
    } else if (head == NULL) {
        last();
    } else if (pos == count + 1) {
        last();
    } else {
        newnode = create_newnode();
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->pre = temp;
        temp->next->pre = newnode;
        temp->next = newnode;
    }    
}

void delete_first() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head == tail) {
        free(head);
        head = tail = NULL;
        count--;
    } else {
        temp = head;
        head = head->next;
        head->pre = tail;
        tail->next = head;
        free(temp);
        count--;
    }
}

void delete_last() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head == tail) {
        free(head);
        head = tail = NULL;
        count--;
    } else {
        temp = tail;
        tail = tail->pre;
        tail->next = head;
        head->pre = tail;
        free(temp);
        count--;
    }
}

void delete_specific() {
    int i = 1, pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count) {
        printf("Enter correct option\n");
        delete_specific();
    } else if (pos == 1) {
        delete_first();
    } else if (pos == count) {
        delete_last();
    } else {
        temp = head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        free(temp);
        count--;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Linklist: ");
    do {
        printf("->%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("->head\n");
}

int main() {
    int ch, pos;
    while (1) {
        printf("\nSelect an option\n1 for add new node at beginning\n2 for add node at specific position\n3 to add node at last\n4 for display\n5 for delete node at first\n6 for delete node at last\n7 for delete node at specific position\n0 for exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                addbegin();
                break;
            case 2:
                add_specific();
                break;
            case 3:
                last();
                break;
            case 4:
                display();
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_last();
                break;
            case 7:
                delete_specific();
                break;
            case 0:
                exit(1);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
