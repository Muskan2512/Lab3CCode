// Represent the polynomials P(x)=4x^3+3x^2-2x+7 ,Q(x)=-13x^3+9x^2+2x+1 as linked list 
// 1-Perform addition of the two polynomials
// 2-given a value x, evaluate the polynomial by iteration over each term and computing the sum of coefficient.
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
    float coeff;
    int power;
    struct Node* next;
};

void calculate(struct Node*head,int x){
    struct Node*temp=head;
    float sum=0;
    while(temp!=NULL){

        // printf("val is:%f %d",temp->coeff,temp->power);
        sum+=((temp->coeff)*pow(x,temp->power));
        temp=temp->next;
    }
    printf("\nThe sum of the coefficients of the obtained polynomial is:%f",sum);
}
struct Node* addition(struct Node*temp1,struct Node*temp2){
    struct Node dummyhead={0,0,NULL};
    struct Node*temp=&dummyhead;

    while(temp1 || temp2){
        struct Node* newNode=malloc(sizeof(struct Node));
        if(!temp1){temp1->coeff=0;temp1->power=0;}
        if(!temp2){temp2->coeff=0;temp2->power=0;}
        newNode->coeff=temp1->coeff+temp2->coeff;
        newNode->power=temp1->power;
        temp->next=newNode;
        temp=temp->next;
        if(temp1)temp1=temp1->next;
        if(temp2)temp2=temp2->next;
    }

temp=(&dummyhead)->next;
    struct Node*curr=temp;
    struct Node*prev=NULL;
    struct Node*forward=temp->next;
    while(curr!=NULL){
        curr->next=prev;
        prev=curr;
        curr=forward;
        if(forward)forward=forward->next;
    }
    return prev;

}

void display(struct Node*head){
    struct Node*temp=head;
        // printf("%.1f %d ",temp->coeff,temp->power);
    while(temp!=NULL){
        temp=temp->next;
    }
}

int main() {
    struct Node first={4,3,NULL};    
    struct Node second={3,2,&first};
    // printf("%f %d",second.coeff,second.power);    
    struct Node third={-2,1,&second};    
    struct Node last={7,0,&third}; 
    
    struct Node another1={-13,3,NULL};
    struct Node another2={9,2,&another1};    
    struct Node another3={2,1,&another2};    
    struct Node another4={1,0,&another3}; 

    struct Node*temp1=&last;
    // while(temp1!=NULL){
    //     printf("%f %d\n",temp1->coeff,temp1->power);
    //     temp1=temp1->next;
    // }
    struct Node*temp2=&another4;
    // while(temp2!=NULL){
    //     printf("%f %d\n",temp2->coeff,temp2->power);
    //     temp2=temp2->next;
    // }
    struct Node*head=addition(temp1,temp2);
    temp2=head;
while(temp2!=NULL){
        printf("%f %d\n",temp2->coeff,temp2->power);
        temp2=temp2->next;
    }
display(head);
    calculate(head,1);
    
       
    return 0;
}