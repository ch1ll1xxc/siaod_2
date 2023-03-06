#include <iostream>
#include  <cmath>


struct Node {
    float data;
    Node* next;
};

//Func 2 make list
Node* insert_begin(Node*& head, float data) {
    Node* newNode = new Node{ data, head };
    head = newNode;
    return head;
}

Node* more_insert_begin(Node*& head) {
    int value;
    std::cout << "Enter amount of nodes: ";
    std::cin >> value;
    for (unsigned i = 0; i < value; i++) {
        float _data;
        std::cout << "Enter data: ";
        std::cin >> _data;
        insert_begin(head, _data);
    }
    return head;
}

//Func 2 output
void output(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

//Creating list w general nodes in L1 and L2
Node* L_Gen(Node* L1, Node* L2) {
    Node* L = nullptr;
    while (L1 != nullptr) {
        Node* tmp = L2;
        while (tmp != nullptr) {
            if (L1->data == tmp->data) {
                Node* check = L;
                bool flag = true;
                while (check != nullptr) {
                    if (check->data == tmp->data) {
                        flag = false;
                        break;
                    }
                    check = check->next;
                }
                if (flag) L = insert_begin(L, L1->data);
                break;
            }
            tmp = tmp->next;
        }
        L1 = L1->next;
    }
    return L;
}
// Func delete node before < 0 in L2
void deleteBeforeNegativeNode(Node*& head) {
    Node* tmp = head;
    while (tmp ->next != nullptr){
        if (tmp->next->data < 0) {
            Node* nodeToDelete = tmp->next;
            if (tmp == head) head = nodeToDelete;
            delete tmp;
            tmp = nodeToDelete;
        }
        else
            tmp = tmp->next;
    }
}

// Func to add node before %2=1 in L1
void insertBeforeOddNodes(Node*& head, float data) {
    Node* temp = head->next;
    if (fmod(head->data, 2) == 1) {
        Node* newNode = new Node{ data, head };
        head = newNode;
        temp = head->next;
    }
    else {
        temp = head;
    }
    while (temp->next != nullptr) {
        if (fmod(temp->next->data, 2) == 1) {
            Node* newNode = new Node{ data, temp->next };
            temp->next = newNode;
            temp = temp->next;
        }
        temp = temp->next;
    }
}

int main() {
    //Creating lists L1 and L2
    Node* L1 = NULL;
    Node* L2 = NULL;
    Node* L = NULL;
    std::cout << "You are making L1" << std::endl;
    more_insert_begin(L1);
    std::cout << "You are making L2" << std::endl;
    more_insert_begin(L2);

    std::cout << "This is L1: ";
    output(L1);
    std::cout << "This is L2: ";
    output(L2);

    std::cout << "This is General list: ";
    L = L_Gen(L1, L2);
    output(L);

    /*std::cout << "This is list w deleted nodes: ";
    deleteBeforeNegativeNode(L2);
    output(L2);*/

    float toAdd;
    std::cout << "Enter data that you want to add: ";
    std::cin >> toAdd;
    std::cout << "This is list w added nodes: ";
    insertBeforeOddNodes(L1, toAdd);
    output(L1);


    return 0;
}