//A106 Siddhesh Ballal
/*
Assignment 4: Department IT has a student's club named 'Pinnacle Club'. The first node for president and the last node for secretary. To maintain club member’s information using a SLL. a) Add and delete b) Compute the total c) Display
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node*create();
void add(int, struct node*);
void addS(struct node*);
struct node* delete(struct node*);
struct node* deleteS(struct node*);
void display(struct node*);
void deleteM(int prn1,struct node*);
void reverse();
struct node
{
 int roll;
 int prn;
 char name[20];
 struct node*next;
};
int main()
{
 int choice,m,prn1;
 struct node*head;
 char ch;
 do{
 printf("\n Enter your choice \n 1.Create \n 2.Addmember \n 3.delete president \n 4.Add secretory \n 5.display \n 6.delete secretory \n 7.Delete member \n 8.Reverse:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 head=create();
 break;

 case 2:
 printf("enter no of members:");
 scanf("%d",&m);
 add(m,head);
 break;

 case 3:
 head=delete(head);
 display(head);
 break;

 case 4:
 addS(head);
 break;

 case 5:
 display(head);
 break;

 case 6:
 deleteS(head);
 display(head);
 break;
 case 7:
 printf("enter prn of node member to be deleted:");
 scanf("%d",&prn1);
 deleteM(prn1,head);
 display(head);
 break;
 case 8:
 reverse(head);
 break;
 default:
 printf("Thank you!!!");

 }
 printf("\ndo you want to continue(y/n):");
 scanf(" %c",&ch);
 }
 while(ch=='y');


}
struct node* create()
{
 int p,r;
 char n[20];
 struct node*head;
 head=(struct node*)malloc(sizeof(struct node));
 printf("enter prn, roll no, name of president:");
 scanf("%d%d",&r,&p);
 scanf("%s",n);
 head->prn=p;
 head->roll=r;
 strcpy(head->name,n);
 head->next=NULL;
 return head;
}
void add(int m, struct node*head)
{
 struct node*temp,*q;
 q=head;
 int p,r;
 char n[20];
 for(int i=0;i<m;i++)
 {
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter prn, roll no, name of president:");
 scanf("%d%d",&p,&r);
 scanf("%s",n);
 temp->prn=p;
 temp->roll=r;
 strcpy(temp->name,n);

 q->next=temp;
 q=temp;
 }
}
void display(struct node *head)
{
 printf("\nPRNNo\tRollNo\tName\n");
 while (head != NULL)
 {
 printf("%d\t\t%d\t\t%s", head->prn, head->roll,
head->name);
 head = head->next;
 printf("\n");
 }
}
void addS(struct node*head)
{
 char n1[20];
struct node*new;
new=(struct node*)malloc(sizeof(struct node));
printf("enter prn,roll no and name of secretory:\n");
scanf("%d",&new->prn);
scanf("%d",&new->roll);
scanf("%s",n1);
strcpy(new->name,n1);
new->next=NULL;
while(head!=NULL && head->next!=NULL)
{
 head=head->next;
}
head->next=new;
}
struct node *delete (struct node *head)
{
 struct node *p;
 p = head->next;
 free(head);
 return p;
}
struct node* deleteS(struct node *head)
{
 struct node*prv;
 while (head != NULL && head->next != NULL)
 {
 prv=head;
 head = head->next;
 }
 prv->next=NULL;
 free(head);
 return head;
}
void deleteM(int prn1,struct node*head)
{
 struct node*q;

 while(head->prn!=prn1)
 {
 q=head;
 head=head->next;
 }
 q->next=head->next;
 free(head);
}
void reverse(struct node*head)
{
 struct node *prevNode, *curNode;
 if(head != NULL)
 {
 prevNode = head;
 curNode = head->next;
 head = head->next;
 prevNode->next = NULL;
 while(head != NULL)
 {
 head = head->next;
 curNode->next = prevNode;
 prevNode = curNode;
 curNode = head;
 }
 head = prevNode;
 printf("SUCCESSFULLY REVERSED LIST\n");
 display(head);

 }
}