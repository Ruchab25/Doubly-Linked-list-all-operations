#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node * prev;
  struct node * next;
}*head, *last;

void createList(int n);
void displayListFromFirst();
void displayListFromEnd();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);
int countNodes();
void search(); 
void displayList();

void createList(int n)
{
  int i, data;
  struct node *newNode;
  if(n >= 1)
  {
    head = (struct node *)malloc(sizeof(struct node));
    if(head != NULL)
    {
      printf("Enter data of 1 node: ");
      scanf("%d", &data);
      head->data = data;
      head->prev = NULL;
      head->next = NULL;
      last = head;

      for(i=2; i<=n; i++)
      {
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode != NULL)
        {
          printf("Enter data of %d node: ", i);
          scanf("%d", &data);
          newNode->data = data;
          newNode->prev = last; 
          newNode->next = NULL;
          last->next = newNode; 
          last = newNode;          
        }
        else
        {
          printf("Unable to allocate memory.");
          break;
        }
      }
      printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
    else
    {
      printf("Unable to allocate memory");
    }
  }
}

int countNodes() 
{  
  int counter = 0;   
  struct node *current = head;  
  while(current != NULL) 
  {   
    counter++;  
    current = current->next;  
  }  
  return counter;  
}  

void displayListFromFirst()
{
  struct node * temp;
  int n = 1;
  if(head == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    temp = head;
    printf("\n\nDATA IN THE LIST FROM START:\n");
    while(temp != NULL)
    {
      printf("%d ",  temp->data);
      n++;
      temp = temp->next;
    }
  }
}

void displayListFromEnd()
{
  struct node * temp;
  int n = 0;
  if(last == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    temp = last;
    printf("\n\nDATA IN THE LIST FROM END:\n");
    while(temp != NULL)
    {
      printf("%d ", temp->data);
      n++;            
      temp = temp->prev; 
    }
  }
}

void insertAtBeginning(int data)
{
  struct node * newNode;
  if(head == NULL)
  {
    printf("Error, List is Empty!\n");
  }
  else
  {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head; 
    newNode->prev = NULL; 
    head->prev = newNode;
    head = newNode;
    printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
  }
}

void insertAtEnd(int data)
{
  struct node * newNode;
  if(last == NULL)
  {
    printf("Error, List is empty!\n");
  }
  else
  {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
     printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
  }
}

void insertAtN(int data, int position)
{
  int i;
  struct node * newNode, *temp;
  if(head == NULL)
  {
    printf("Error, List is empty!\n");
  }
  else
  {
    temp = head;
    i=1;
    while(i<position-1 && temp!=NULL)
    {
      temp = temp->next;
      i++;
    }
    if(position == 1)
    {
      insertAtBeginning(data);
    }
    else if(temp == last)
    {
      insertAtEnd(data);
    }
    else if(temp!=NULL)
    {
      newNode = (struct node *)malloc(sizeof(struct node));
      newNode->data = data;
      newNode->next = temp->next; 
      newNode->prev = temp;          
      if(temp->next != NULL)
      {          
        temp->next->prev = newNode;
      }
      temp->next = newNode;

      printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
    }
    else
    {
      printf("Error, Invalid position\n");
    }
  }
}

void deleteFromBeginning()
{
  struct node * toDelete;
  if(head == NULL)
  {
    printf("Unable to delete. List is empty.\n");
  }
  else
  {
    toDelete = head;
    head = head->next;         
    if (head != NULL)
      head->prev = NULL; 
    free(toDelete); 
    printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
  }
}

void search()  
{  
  struct node *ptr;  
  int item,i=0,flag;  
  ptr = head;   
  if(ptr == NULL)  
  {  
    printf("\nEmpty List\n");  
  }  
  else  
  {   
    printf("\nEnter item which you want to search?\n");   
    scanf("%d",&item);  
    while (ptr!=NULL)  
    {  
      if(ptr->data == item)  
      {  
        printf("\nitem found at location %d ",i+1);  
        flag=0;  
        break;  
      }   
      else  
      {  
        flag=1;  
      }  
      i++;  
      ptr = ptr -> next;  
    }  
    if(flag==1)  
    {  
      printf("\nItem not found\n");  
    }  
  }     
}  

void deleteFromEnd()
{
  struct node * toDelete;
  if(last == NULL)
  {
    printf("Unable to delete. List is empty.\n");
  }
  else
  {
    toDelete = last;
    last = last->prev; 
    if (last != NULL)
      last->next = NULL; 
    free(toDelete);       
    printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
  }
}

void deleteFromN(int position)
{
  struct node *current;
  int i;
  current = head;
  for(i=1; i<position && current!=NULL; i++)
  {
    current = current->next;
  }
  if(position == 1)
  {
    deleteFromBeginning();
  }
  else if(current == last)
  {
    deleteFromEnd();
  }
  else if(current != NULL)
  {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current); 
    printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
  }
  else
  {
    printf("Invalid position!\n");
  }
}

void displayList()
{
  struct node * temp;
  int n = 1;
  if(head == NULL)
  {
    printf("List is empty.\n");
  }
  else
  {
    temp = head;
   
    while(temp != NULL)
    {
      printf("%d ", temp->data);
      n++;
      temp = temp->next;
    }
  }
}


int main ()  
{  
  int ch=0;  
  while(ch!=13)   
  {    
    printf("\n\nEnter the operation to be performed\n");    
    printf("\n1.Create a node list\n2.Insert in the begining\n3.Insert at the last\n4.Insert at any specified position\n5.Delete from Beginning\n6.Delete from last\n7.Delete node after specified location\n8.Count the number of node\n9.Search a node\n10.Display list from first\n11.Display list from end\n12.Display list\n13.Exit\n");              
    scanf("\n%d",&ch);  
    switch(ch)  
    {
      case 1:
          {
            int n, choice;
            head = NULL;
            last = NULL;
            printf("Enter the number of nodes you want to create: ");
            scanf("%d", &n);
            createList(n);
            break;
          }
      case 2:
          { 
            int n, data;
            printf("Enter data of first node : ");
            scanf("%d", &data);
            insertAtBeginning(data);      
            break;
          }  
      case 3:
            { 
            int n, data; 
            printf("Enter data of last node : ");
            scanf("%d", &data);
            insertAtEnd(data);      
            break;
          }    
      case 4:  
           { 
            int n, data; 
            printf("Enter the position where you want to insert new node: ");
            scanf("%d", &n);
            printf("Enter data of %d node : ", n);
            scanf("%d", &data);
            insertAtN(data, n);
            break;
          }  
      case 5:  
            {
              int n, data;
              deleteFromBeginning();
              break;
            }                   
      case 6:  
             {
              int n, data;
              deleteFromEnd();
              break;
            }   
      case 7:  
            {
              int n, data;
              printf("Enter the node position which you want to delete: ");
              scanf("%d", &n);
              deleteFromN(n);
              break;
            }
      case 8:
            printf("\nCount of nodes present in the list: %d", countNodes()); 
            break; 
      case 9:
            search(); 
            break;
      case 10:  
            displayListFromFirst();       
            break;  
      case 11:  
            displayListFromEnd();        
            break; 
      case 12:  
            displayList();       
            break; 
      case 13:  
            exit(0);  
            break;  
      default:  
            printf("Enter valid option");  
    }  
  }  
}   