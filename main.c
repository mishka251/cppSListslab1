#include <stdio.h>
#include <malloc.h>

struct Node {
    int value;
    struct Node *next;
};
typedef struct Node *PNode;

PNode list = NULL;

void initList() {
    int n;
    printf("elements count\n");
    scanf("%d", &n);
    int a;
    list = (PNode) malloc(sizeof(struct Node));
    list->next = NULL;
    PNode last = list;
    for (int i = 0; i < n; ++i) {
        printf("item %d = ", i);
        scanf("%d", &a);
        last->value = a;
        if (i < n - 1) {
            last->next = (PNode) malloc(sizeof(struct Node));
            last = last->next;
            last->next = NULL;
        }
    }
}

void printList() {
    PNode last = list;
    while (last != NULL) {
        printf("%d  ", last->value);
        last = last->next;
    }
    printf("\n");
}

void insertIntList() {
    int e, e1;
    printf("e?\n");
    scanf("%d", &e);

    printf("e1?\n");
    scanf("%d", &e1);

    PNode last = list;

    if (list->value == e) {
        PNode next = list;
        list = (PNode) malloc(sizeof(struct Node));
        list->value = e1;
        list->next = next;
    }

    while (last != NULL && last->next != NULL) {
        if (last->next->value == e) {
            PNode next = last->next;
            last->next = (PNode) malloc(sizeof(struct Node));
            last->next->value = e1;
            last->next->next = next;
            last = next;
        } else {
            last = last->next;
        }
    }

}

int main() {
    initList();
    printList();
    insertIntList();
    printList();
    return 0;
}
