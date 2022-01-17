// Siddhesh Ballal
// A106
/*
Department of Information Technology has a student's club named 'Pinnacle Club'. Students of the Second, third and final year of the department can be granted membership on request. Similarly,
one may cancel the membership of the club. The first node is reserved for the president of the club and the last node is reserved for the secretary of the club. Write C program to maintain club member’s information using a singly linked list. Store student PRN and Name. Write functions to
a) Add and delete
b) Compute the total number of members of the club
c) Display members of the club
d) Display list in reverse order using recursion
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int PRN, RollNo;
  char Name[20];
  struct node *NextAddress;
};

struct node* create()
{
  int p_prn, p_rollno;
  char p_Name[20];
  struct node *head;

  head = (struct node*) malloc (sizeof(struct node));
  printf("Enter PRN of the President:  ");
  scanf("%d", &p_prn);
  printf("Enter Roll no. of the President:  ");
  scanf("%d", &p_rollno);
  printf("Enter Name of the President:  ");
  scanf("%s", p_Name);

  head -> PRN = p_prn;
  head -> RollNo = p_rollno;
  strcpy(head -> Name, p_Name);
  head -> NextAddress = NULL;
  return head;
}

void add_members(int m, struct node* head)
{
  int m_prn, m_rollno;
  char m_Name[20];
  struct node *newnode, *prev;
  prev = head;

  for(int i=0; i<m; i++)
  {
    newnode = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter PRN of the new Member:  ");
    scanf("%d", &m_prn);
    printf("Enter Roll no. of the new Member:  ");
    scanf("%d", &m_rollno);
    printf("Enter Name of the new Member:  ");
    scanf("%s",m_Name);
    
    newnode -> PRN = m_prn;
    newnode -> RollNo = m_rollno;
    strcpy(newnode -> Name, m_Name);

    prev -> NextAddress = newnode;
    prev = newnode;
  }
}

void display(struct node* head)
{
  while(head != NULL)
  {
    printf("\nName: %s", head->Name);
    printf("\nPRN: %d", head->PRN);
    printf("\nRoll no: %d\n", head->RollNo);

    head = head -> NextAddress;
  }
}

void add_secretary(struct node* head)
{
  struct node *Secretary;
  int s_prn, s_rollno;
  char s_name[20];

  Secretary = (struct node*) malloc (sizeof(struct node));
  printf("\nEnter PRN of the Secretary:  ");
  scanf("%d", &s_prn);
  printf("Enter Roll no. of the Secretary:  ");
  scanf("%d", &s_rollno);
  printf("Enter Name of the Secretary:  ");
  scanf("%s", s_name);

  Secretary -> PRN = s_prn;
  Secretary -> RollNo = s_rollno;
  strcpy(Secretary -> Name , s_name);

  Secretary -> NextAddress = NULL;

  while(head != NULL && head -> NextAddress != NULL)
  {
    head = head -> NextAddress;
  }
  head -> NextAddress = Secretary;
}

void Deletemem(struct node* head, int prn)
{
  struct node* p;
  while(head -> PRN != prn)
  {
    p = head -> NextAddress;
    head= head->NextAddress;
  }
  p->NextAddress = head->NextAddress;
  free(head);
}

struct node* Deletesec(struct node* head)
{
  while(head != NULL && head -> NextAddress != NULL)
  {
    head = head -> NextAddress;
  }
  free(head);
  return 0;
}

int main() 
{
  int menucheck=1, menucontrol;
  
  struct node *Principal, *Secratary;
  Principal = create();

  while (menucheck == 1)
  {
    printf("\nEnter:\n1 to Add new member\n2 to add Secretary\n3 to Delete previous member\n4 to Compute total no. of members\n5 to Display members of the club\n6 to Delete secretary\n7 to Display list in reverse order using recursion\n8 to Exit:\n\n");
    scanf("%d", &menucontrol);

    switch(menucontrol)
    {
      case(1):
        printf("How many members do you want to add? :  ");
        int m;
        scanf("%d", &m);
        add_members(m, Principal);
        printf("Updated linked list:\n");
        display(Principal);
        break;

      case(2):
        add_secretary(Principal);
        printf("Updated linked list:\n");
        display(Principal);
        break;
      
      case(3):
        printf("\nEnter prn of member who is to be deleted:\n");
        int prn;
        scanf("%d",&prn);
        Deletemem(Principal,prn);
        printf("\nUpdated linked list:\n");
        display(Principal);
        break;

      case(4):
        break;
        
      case(5):
        display(Principal);
        break;

      case(6):
        Deletesec(Principal);
        printf("Updated linked list:\n");
  //      display(Principal);
        break;
      
      case(7):
        break;

      case(8):
        printf("Program Exited");
        menucheck = 0;
        break;
      
      default:
        printf("Invalid Input");
        break;
    }
  }
  return 0;
}