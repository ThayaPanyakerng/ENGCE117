//Thaya Panyakerng 65543206051-6 Sec.3
//URL https://www.youtube.com/watch?v=u8ftsgq9r-0
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next; 
};

void ShowAll( struct Node *walk ){
    while (walk != NULL){
        printf("%d ", walk->data); 
        walk = walk->next; 
    } 
    printf("  ");
} 

struct Node *AddNode(struct Node **walk, int data){
    struct Node *AddNode = (struct Node*) malloc(sizeof(struct Node));
    AddNode->data = data;
    AddNode->next = NULL;

    if(*walk == NULL){
        *walk = AddNode;
    } else {
        struct Node *temp = *walk;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = AddNode;
    }
    return AddNode;
}
void UpdateNode(struct Node **head, int Value1, int Value2){
    struct Node *temp = *head;
    while (temp != NULL){
        if (temp->data == Value1){
            temp->data = Value2;
            break;
        }
        temp = temp->next;
    }
}
void Showback(struct Node **longstart) {
  	struct Node* prev = NULL;
    struct Node* current = *longstart;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *longstart = prev;
}
void SwapNode(struct Node **longstart, int data1, int data2){
    struct Node *temp = *longstart;
    struct Node *node1 = NULL;
    struct Node *node2 = NULL;
    struct Node *prev1 = NULL;
    struct Node *prev2 = NULL;

    while (temp != NULL){
        if (temp->data == data1){
            node1 = temp;
            break;
        }
        prev1 = temp;
        temp = temp->next;
    }

    temp = *longstart;
    while (temp != NULL){
        if (temp->data == data2){
            node2 = temp;
            break;
        }
        prev2 = temp;
        temp = temp->next;
    }

    if (node1 != NULL && node2 != NULL){
        if (prev1 != NULL){
            prev1->next = node2;
        } else {
            *longstart = node2;
        }
		if (prev2 != NULL){
            prev2->next = node1;
        } else {
            *longstart = node1;
        }
		temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
}

int main(){
struct Node *longstart;
	longstart = NULL;
	AddNode( &longstart, 101 );
	AddNode( &longstart, 201 );
	AddNode( &longstart, 301 );
	AddNode( &longstart, 401 );
	ShowAll(longstart);
	UpdateNode( &longstart, 101, 123);
	ShowAll(longstart);
	Showback( &longstart);
	ShowAll(longstart);
	SwapNode( &longstart, 301, 123);
	ShowAll(longstart);
return 0;
}


