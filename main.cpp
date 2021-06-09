#include <iostream>

struct List {
    int value;
    List *next = nullptr;
};

List *list;

void initList() {
    int n;
    std::cout << "elements count" << std::endl;
    std::cin >> n;
    int a;
    list = new List();
    List *last = list;
    for (int i = 0; i < n; ++i) {
        std::cout << "item " << i << " = ";
        std::cin >> a;
//        std::cout << std::endl;
        last->value = a;
        if (i < n - 1) {
            last->next = new List();
            last = last->next;
        }
    }
}

void printList() {
    List *last = list;
    while (last != nullptr) {
        std::cout << last->value << "  ";
        last = last->next;
    }
    std::cout << std::endl;
}

void insertIntList() {
    int e, e1;
    std::cout << "e?" << std::endl;
    std::cin >> e;

    std::cout << "e1?" << std::endl;
    std::cin >> e1;

    List *last = list;

    if (list->value == e) {
        List *next = list;
        list = new List();
        list->value = e1;
        list->next = next;
    }

    while (last != nullptr && last->next != nullptr) {
        if (last->next->value == e) {
            List *next = last->next;
            last->next = new List();
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
