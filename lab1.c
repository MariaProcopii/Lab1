#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void append(struct Node** head_r, int new_data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ref = *head_r;

    new->data = new_data;
    new->next = NULL;

    if((*head_r) == NULL){
        (*head_r) = new;
        new->prev = NULL;
        return;
    }

    while(ref->next != NULL){
        ref = ref->next;
    }
    
    ref->next = new;
    new->prev = ref;
    return;
}

void prepend(struct Node** head_r, int new_data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    new->data = new_data;
    new->prev = NULL;
    new->next = (*head_r);
    if((*head_r) != NULL){
        (*head_r)->prev = new;
    }
    else{
        append(head_r, new_data);
    }
    (*head_r) = new;
}

void reverse(struct Node** head_r){
    struct Node* prev = NULL;
    struct Node* actual = *head_r;

    if(actual == NULL){
        printf("List is empty");
        return;
    }
    while(actual != NULL){
        prev = actual->prev;
        actual->prev = actual->next;
        actual->next = prev;
        actual = actual->prev;
    }
    if(prev != NULL){
        (*head_r) = prev->prev;
    }

}
int length(struct Node* head){
    int x = 0;
    while(head != NULL){
        x++;
        head = head->next;
    }
    return x;
}

void insert(struct Node** head_r,int pos, int new_data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ref = *head_r;
    new->data = new_data;
    if((*head_r) == NULL || pos == length(*head_r) + 1){
        append(head_r, new_data);
        return;
    }

    if(pos == 1){
        prepend(head_r, new_data);
        return;
    }

    if(pos > 1 && pos <= length(*head_r)){
    for(int i = 1; i < pos; i++){
            ref = ref->next;
    }
    new->next = ref;
    new->prev = ref->prev;
    ref->prev = new;
    new->prev->next = new;
    }
    else{
        printf("Something went wrong");
        return;
    }
}
void removeAt(struct Node** head_r, int pos){
    struct Node* ref = *head_r;
    if(pos < 1 || pos > length(*head_r)){
        printf("Something went wrong");
        return;
    }
    if((*head_r) == NULL){
        printf("Nothing to delete");
        return;
    }
    if(pos == 1){
        (*head_r) = (*head_r)->next;
        free(ref);
        return;
    }
    for(int i = 1; i < pos; i++){
        ref = ref->next;
    }
    ref->prev->next = ref->next;
    if(ref->next != NULL){
        ref->next->prev = ref->prev;
    }
    ref->prev = NULL;
    ref->next = NULL;
    free(ref);
}

void search(struct Node* head, int value){
    int pos = 1;
    while(head->data != value && head->next != NULL){
        pos++;
        head = head->next;
    }
    if(head->data != value){
        printf("Value is not in the list.\n");
        return;
    }
    else{
        printf("Value is at position: %d \n", pos);
    }
}

void join(struct Node * head, struct Node* head2){
    if(head == NULL || head2 == NULL){
        printf("Nothing to join");
        return;
    }
    while(head->next != NULL){
        head = head->next;
    }
    head->next = head2;
    head2->prev = head;
}

void traverseBack(struct Node* head){
    while(head->next != NULL){
        head = head->next;
    }
    while(head != NULL){
        printf("%d  ", head->data);
        head = head->prev;
    }
    printf("\n");
}

void print(struct Node* head){
    while(head != NULL){
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    append(&head2, 4);
    append(&head2, 5);
    append(&head2, 6);    
    print(head);
    print(head2);
    join(head, head2);
    print(head);

    return 0;
}
