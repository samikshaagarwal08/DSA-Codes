#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int node_count = 0;

struct node* create_newnode() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    node_count++;
    return newnode;
}

void add_begin() {
    struct node *newnode = create_newnode();
    newnode->next = head;
    head = newnode;
}

void add_last() {
    if (!head) {
        add_begin();
        return;
    }
    struct node *newnode = create_newnode();
    struct node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void add_specific() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        add_begin();
    } else if (pos == node_count + 1) {
        add_last();
    } else if (pos > 1 && pos <= node_count) {
        struct node *newnode = create_newnode();
        struct node *temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    } else {
        printf("Invalid position!\n");
    }
}

void del_begin() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    node_count--;
}

void del_last() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    if (!head->next) {
        del_begin();
        return;
    }
    struct node *temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    node_count--;
}

void del_specific(int pos) {
    if (pos < 1 || pos > node_count) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        del_begin();
        return;
    }
    struct node *temp = head, *prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    node_count--;
}

void display() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void find_min() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    int min = head->data;
    struct node *temp = head;
    while (temp) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("Minimum value: %d\n", min);
}

void find_max() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    int max = head->data;
    struct node *temp = head;
    while (temp) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("Maximum value: %d\n", max);
}

void count_nodes() {
    printf("Total number of nodes: %d\n", node_count);
}

void sum_and_average() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    int sum = 0;
    struct node *temp = head;
    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of all nodes: %d\n", sum);
    printf("Average of all nodes: %.2f\n", (float)sum / node_count);
}

void search() {
    int key, found = 0, pos = 0;
    printf("Enter the node value to be searched: ");
    scanf("%d", &key);
    struct node *temp = head;
    while (temp) {
        pos++;
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        printf("%d found at position %d\n", key, pos);
    } else {
        printf("%d not found in the list\n", key);
    }
}

void swap_first_last() {
    if (!head || !head->next) {
        printf("List has less than two elements, cannot swap!\n");
        return;
    }
    struct node *first = head, *second_last = NULL, *last = head;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = head;
    last->next = head->next;
    head->next = NULL;
    head = last;
}



int main() {
    int ch, pos;
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add new node at beginning\n");
        printf("2. Add node at specific position\n");
        printf("3. Add node at last\n");
        printf("4. Display list\n");
        printf("5. Find minimum value\n");
        printf("6. Find maximum value\n");
        printf("7. Count nodes\n");
        printf("8. Calculate sum and average of all node values\n");
        printf("9. Search for an element\n");
        printf("10. Swap first and last node\n");
        printf("11. Delete node from beginning\n");
        printf("12. Delete node from specific position\n");
        printf("13. Delete node from last\n");
        printf("0. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: add_begin(); break;
            case 2: add_specific(); break;
            case 3: add_last(); break;
            case 4: display(); break;
            case 5: find_min(); break;
            case 6: find_max(); break;
            case 7: count_nodes(); break;
            case 8: sum_and_average(); break;
            case 9: search(); break;
            case 10: swap_first_last(); break;
            case 11: del_begin(); break;
            case 12:
                printf("Enter position: ");
                scanf("%d", &pos);
                del_specific(pos);
                break;
            case 13: del_last(); break;
            case 0: exit(0); break;
            default: printf("Invalid option!\n"); break;
        }
    }
    return 0;
}
