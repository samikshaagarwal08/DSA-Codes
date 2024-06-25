#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *newnode;
int node_count = 0;

struct node* create_newnode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    node_count++;
    return temp;
}

void add_last() {
    newnode = create_newnode();
    if (head == NULL) {
        head = tail = newnode;
        tail->next = head;
    } else {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
}

void add_begin() {
    if (head == NULL) {
        add_last();
    } else {
        newnode = create_newnode();
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}

void add_specific() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > node_count + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        add_begin();
    } else if (pos == node_count + 1) {
        add_last();
    } else {
        newnode = create_newnode();
        struct node *temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void del_begin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    free(temp);
    node_count--;
}

void del_last() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        struct node *last = tail;
        tail = temp;
        tail->next = head;
        free(last);
    }
    node_count--;
}

void del_specific() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > node_count) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        del_begin();
    } else if (pos == node_count) {
        del_last();
    } else {
        struct node *temp = head, *prev = NULL;
        while (i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
        node_count--;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add node at last\n");
        printf("2. Display list\n");
        printf("3. Add node at beginning\n");
        printf("4. Add node at specific position\n");
        printf("5. Delete node from beginning\n");
        printf("6. Delete node from last\n");
        printf("7. Delete node from specific position\n");
        printf("0. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: add_last(); break;
            case 2: display(); break;
            case 3: add_begin(); break;
            case 4: add_specific(); break;
            case 5: del_begin(); break;
            case 6: del_last(); break;
            case 7: del_specific(); break;
            case 0: exit(0); break;
            default: printf("Invalid option!\n"); break;
        }
    }
    return 0;
}
