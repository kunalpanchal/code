#include<iostream>

using namespace std;

struct node {
    int info;
    struct node *next;
} *tptr, *pptr, *head;

void create(int x) {
    if (head == NULL) {
        struct node *ptr = new struct node;
        ptr->info = x;
        ptr->next = head;
        head = ptr;
    }
    else cout << "list already exist";
}

void insb(int x) {
    if (head == NULL) {
        cout << "list does not exist";
    }
    else {
        struct node *ptr = new struct node;
        ptr->info = x;
        ptr->next = head;
        head = ptr;
    }
}

void inse(int x) {
    if (head == NULL)
        cout << "list does not exist";
    else {
        struct node *ptr = new struct node;
        tptr = head;
        while (tptr->next != NULL)
            tptr = tptr->next;
        ptr->info = x;
        tptr->next = ptr;
        ptr->next = NULL;
    }

}

void insm(int x, int y) {
    int i = 0;
    if (head == NULL)
        cout << "list does not exist";
    else {
        struct node *ptr = new struct node;
        tptr = head;

        while (i < y - 2 && tptr->next != NULL) {
            i++;
            tptr = tptr->next;
        }
        ptr->info = x;
        ptr->next = tptr->next;
        tptr->next = ptr;
    }
}

void dltb() {
    if (head == NULL) cout << "list is empty";
    else {
        tptr = head;
        head = tptr->next;
    }
}

void dlte() {
    if (head == NULL) cout << "list is empty";
    else {
        tptr = head;
        while (tptr->next != NULL) {
            pptr = tptr;
            tptr = tptr->next;
        }
        pptr->next = NULL;
    }
}

void dltm(int y) {
    int i = 0;
    if (head == NULL) cout << "list is empty";
    else {
        tptr = head;
        while (tptr->next != NULL && i < y - 1) {
            pptr = tptr;
            tptr = tptr->next;
            i++;
        }
        pptr->next = tptr->next;
    }
}

void search(int x) {
    int pos = 1;
    if (head == NULL)cout << "list is empty";
    else {
        tptr = head;
        while (tptr != NULL) {
            if (tptr->info == x) {
                cout << "the position is : " << pos;
                break;
            }
            tptr = tptr->next;
            pos++;
        }
    }
}

void trav() {
    if (head == NULL) cout << "list is empty";
    else {
        tptr = head;
        while (tptr != NULL) {
            cout << "  " << tptr->info;
            tptr = tptr->next;
        }
        cout << "\n";
    }
}

int count(struct node *p) {
    if (p != NULL) return 1 + count(p->next);
    else return 0;
}

void rev(struct node *h) {
    struct node *ptr;
    ptr = h;
    pptr = NULL;
    struct node *nptr;
    while (ptr != NULL) {
        nptr = ptr->next;
        ptr->next = pptr;
        pptr = ptr;
        ptr = nptr;
    }
    head = pptr;
}

void add() {
    struct node *ptr;
    int c, d, c2;
    c2 = count(head);
    rev(head);
    ptr = head;
    d = 0;
    while (ptr != NULL) {
        c = ptr->info;
        if (c == 9) {
            ptr->info = 0;
            d++;
        }
        else {
            c = c + 1;
            ptr->info = c;
            break;
        }
        ptr = ptr->next;
    }
    if (d == c2) inse(1);
    rev(head);
}

void kthElementLast(struct node *head, int k) {

    struct node *slow = head;
    struct node *fast = head;
    int i = 0;

    if (head != NULL) {
        while (i != (k - 1)) {
            fast = fast->next;
            i++;
        }

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        cout << "The element is -- > \n\n" << slow->info;
    }
}

main() {
    int ch, choice = 0, x, y;
    head = NULL;

    cout << "press 1 to create a list \n";
    cout << "Press 2 to insert node at beg \n";
    cout << "Press 3 to insert node at end \n";
    cout << "Press 4 to insert node at position \n";
    cout << "Press 5 to delete from beg: \n";
    cout << "Press 6 to delete node from end \n";
    cout << "Press 7 to del node from pos \n";
    cout << "press 8 to search a element \n";
    cout << "press 9 to traverse through link list\n";
    cout << "press 10 to count the no of elements\n";
    cout << "press 11 to reverese the list\n";
    cout << "press 12 to add 1 in a digit link list \n";
    cout << "press 13 to find kth element from last \n";
    while (choice == 0) {
        cout << "Enter the choice : \n";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter the data";
            cin >> x;
            create(x);
        }
        if (ch == 2) {
            cout << "Enter the data";
            cin >> x;
            insb(x);
        }
        if (ch == 3) {
            cout << "Enter the data";
            cin >> x;
            inse(x);
        }
        if (ch == 4) {
            cout << "Enter the data";
            cin >> x;
            cout << "Enter the position to insert";
            cin >> y;
            insm(x, y);
        }
        if (ch == 5)
            dltb();
        if (ch == 6)
            dlte();
        if (ch == 7) {
            cout << "Enter the position to delete";
            cin >> y;
            dltm(y);
        }

        if (ch == 8) {
            cout << "Enter the element to search";
            cin >> y;
            search(y);
        }
        if (ch == 9)
            trav();
        if (ch == 10) {
            y = count(head);
            cout << "the no of elements in node is :" << y;
        }
        if (ch == 11)
            rev(head);
        if (ch == 12)
            add();
        if (ch == 13) {
            int k;
            cout << "Enter k :";
            cin >> k;
            kthElementLast(head, k);
        }

        cout << "press 0 to continue";
        cin >> choice;
    }
}