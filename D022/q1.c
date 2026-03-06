#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void insertEnd(struct Node* head,int val){
    if (head==NULL){
        printf("Really???");
        return;
    }
    struct Node* temp=head;
    struct Node* newNode=NULL;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    temp->next=newNode;
    newNode->data=val;
    newNode->next=NULL;
    
}
int countList(struct Node* head){

    int count = 0;

    struct Node* temp = head->next;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}
void printList(struct Node* head){
    if (head==NULL){
        printf("Really???");
        return;
    }
    struct Node* temp=head->next;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    if(temp==head){
        printf("really?");
        return;
    }
    printf("%d",temp->data);

}
void freeList(struct Node* head){
    if (head==NULL){
        printf("Really???");
        return;
    }
    struct Node* temp=head;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);

    }
}
int main(){
    struct Node* head=NULL;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        insertEnd(head,val);
    }
    printList(head);
    printf("Count: %d",countList(head));
    freeList(head);

    return 0;


}
