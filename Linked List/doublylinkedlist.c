#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next, *pre;
};

struct node *head = NULL, *tail = NULL;

struct node *create_newnode() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    temp->pre = NULL;
    return temp;
}

void addbegin() {
    struct node *newnode = create_newnode();
    if (head == NULL) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
    }
}

void add_specific() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    struct node *newnode = create_newnode();
    if (pos == 1) {
        newnode->next = head;
        if (head != NULL) head->pre = newnode;
        head = newnode;
        if (tail == NULL) tail = newnode;
        return;
    }
    struct node *temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL && i < pos - 1) {
        printf("Position out of bounds\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        newnode->pre = temp;
        if (temp->next != NULL) temp->next->pre = newnode;
        temp->next = newnode;
        if (newnode->next == NULL) tail = newnode;
    }
}

void last() {
    struct node *newnode = create_newnode();
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
    }
}

void del_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL) head->pre = NULL;
    else tail = NULL;
    free(temp);
}

void del_specific() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        del_begin();
        return;
    }
    struct node *temp = head;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
    } else {
        if (temp->pre != NULL) temp->pre->next = temp->next;
        if (temp->next != NULL) temp->next->pre = temp->pre;
        if (temp == tail) tail = temp->pre;
        free(temp);
    }
}

void del_last() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = tail;
    tail = tail->pre;
    if (tail != NULL) tail->next = NULL;
    else head = NULL;
    free(temp);
}

void display() {
    struct node *t = head;
    while (t != NULL) {
        printf("\t%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nSelect an option:\n1 for add new node at beginning\n2 for add node at specific position\n3 to add node at last\n4 for display\n5 to delete node at beginning\n6 to delete node at specific position\n7 to delete node at last\n0 for exit\n");
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
                del_begin();
                break;
            case 6:
                del_specific();
                break;
            case 7:
                del_last();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
