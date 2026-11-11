//Nama: Salman Santika Abdullah
// NIM: 13224084
// Modul: 2
// Hari, Tanggal: Rabu, 11 November 2026
// Deskripsi: membuat sistem untuk mencari posisi di antara
#include <stdio.h>
#include <stdlib.h>

// defining a Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new Node with given value as data
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}



void addLast(struct Node **head, int val)
{
    //create a new Node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next     = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last Node and add the newNode
    else
    {
        struct Node *lastNode = *head;

        //last Node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}


// Fungsi untuk mencari posisi Node yang nilainya di antara Node prev dan next
void cariNodeDiantara(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("List terlalu pendek\n");
        return;
    }

    Node* current = head->next; 
    int posisi = 1;             
    int ditemukan = 0;

    while (current != NULL && current->prev != NULL && current->next != NULL) {
        int valPrev = current->prev->data;
        int valCurr = current->data;
        int valNext = current->next->data;
        if ((valCurr > valPrev && valCurr < valNext) || (valCurr < valPrev && valCurr > valNext)) {
            printf("%d", posisi);
            ditemukan = 1;
        }

        current = current->next;
        posisi++;
    }

    if (ditemukan == 0) {
        printf("NONE");
    }
}

void printListForward(Node* head)
{
    Node* temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    int tinggi;
    while(scanf("%d", &tinggi) == 1){
        addLast(&head, tinggi);
        int kar = getchar();
        if (kar == '\n'){
            break;
        }
    }
    // printListForward(head);
    cariNodeDiantara(head);
    return 0;
}
