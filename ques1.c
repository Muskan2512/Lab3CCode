// create an inventory with product id,product name and price as a linked list with 10 products
// create Node:Creates a new node with the given items
// insert node:inserts a new node a the end of a transaction liked list 
// delete node:removes a node from a transaction linked list 
// search node:searches for a node with a given item in a transaction linked list
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct Product{
    int productId;
    char product_name[50];
    float price;
    struct Product*next;
};

// this function will create a node for u.
struct Product* createProduct(int id,char *name,float price){
    // syntax  int* newNode=(int*)malloc(sizeof(int))
    struct Product* newProduct=(struct Product*)malloc(sizeof(struct Product));
    newProduct->productId=id;
    strcpy(newProduct->product_name,name);
    newProduct->price=price;
    newProduct->next=NULL;
    return newProduct;
}

void insertNode(struct Product* head,int id,char* name,float price){
    struct Product* createdNode=createProduct(id,name,price);
    struct Product*temp=head;
    while(temp!=NULL && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->next==NULL){
        temp->next=createdNode;
    }
}

void deleteProduct(struct Product* head,int id){
    if(head==NULL){
        printf("Linked list is empty");
        return;
    }
    struct Product* temp=head;
    if(head->productId==id){
        head=head->next;
        free(temp);
        return;
    }
    while(temp->next!=NULL && temp->next->productId!=id){
        temp=temp->next;
    }
    if(temp->next->productId==id){
        temp->next=temp->next->next;
        return;
    }
    if(temp->next==NULL){
        // there is no such node with the given id to delete
        return;
    }
}

void search(struct Product* head,int id){
    struct Product* temp=head;
    while(temp!=NULL && temp->productId!=id)temp=temp->next;
    if(temp==NULL){
        printf("Product Not found");
        return;
    }
    if(temp->productId==id){
        printf("Product found\n");
        printf("%d %s %.1f",temp->productId,temp->product_name,temp->price);
    }
}

void print(struct Product*head){
    // printf("Inside print function");
    if(head==NULL){
        printf("Linked list is empty");
        return;
    }
    struct Product *temp=head;
    while(temp!=NULL){
        printf("%d %s %.1f\n",temp->productId,temp->product_name,temp->price);
        // printf("Inside print");
        temp=temp->next;
    }
}


int main() {

    // make a head pointer
    struct Product*head=NULL;
    head=(struct Product*)malloc(sizeof(struct Product));
    head->productId=1;
    strcpy(head->product_name,"Paste");
    head->price=10;
    head->next=NULL;

    struct Product* newPro=createProduct(12,"Book",90);
    head->next=newPro;
    insertNode(head,10,"Biscuits",990);
    insertNode(head,17,"statinory",50);
    insertNode(head,15,"Lights",100);
    deleteProduct(head,1);
    print(head);
    printf("\n");
    search(head,1);

    // printf("%d %s %f",newPro->productId,newPro->product_name,newPro->price);
    return 0;
}
