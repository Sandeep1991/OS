#include<stdio.h>
#include<stdlib.h>
 
/* structure for a node */
struct node
{
  int data;
  struct node *next;
};
 
/* function to insert a new_node in a list in sorted way.
   Note that this function expects a pointer to head node
   as this can modify the head of the input linked list */
void sortedInsert(struct node** head_ref, struct node* new_node)
{
  struct node* current = *head_ref;
 
  // Case 1 of the above algo
  if (current == NULL)
  {
     new_node->next = new_node;
     *head_ref = new_node;
  }
 
  // Case 2 of the above algo
  else if (current->data >= new_node->data)
  {
    /* If value is smaller than head's value then
      we need to change next of last node */
    while(current->next != *head_ref)
        current = current->next;
    current->next = new_node;
    new_node->next = *head_ref;
    *head_ref = new_node;
  }
 
  // Case 3 of the above algo
  else
  {
    /* Locate the node before the point of insertion */
    while (current->next!= *head_ref && 
           current->next->data < new_node->data)
      current = current->next;
 
    new_node->next = current->next;
    current->next = new_node;
  }
}
 
int Length(struct node **head_ref)
{
	struct node* t1 = (struct node*) malloc(sizeof(struct node));
	t1 = *head_ref; //Temp variable t1 to initially point to head_ref
	if(t1==NULL) return 0;
	int cnt=0; //count for the length
	while(t1->next!=*head_ref)
	{
		cnt++;
		t1 = t1->next;
	}
	return cnt+1;
}
int Empty(struct node **head_ref)
{
	struct node* t1 = (struct node*) malloc(sizeof(struct node));
	t1 = *head_ref; //Temp variable t1 to initially point to head_ref
	if(t1==NULL) return 1;//return true that it is empty
	else return 0;//return false meaning is not empty
	
}
/* Function to print nodes in a given linked list */
int append(struct node** head, void *obj)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp = *head;
	obj= temp;
	while(temp->next!=*head)
	{
		temp = temp -> next;
	}
	temp->next = obj;
	return 1;
}


void printList(struct node *start)
{
  struct node *temp;
 
  if(start != NULL)
  {
    temp = start;
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
  }
}
 
/* Driver program to test above functions */
int main()
{
  int arr[]= {12, 56, 2, 11, 1};//, 90};
  int i;
 
  /* start with empty linked list */
  struct node *start = NULL;
  struct node *temp;
 
  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for (i = 0; i< 5; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = arr[i];
    sortedInsert(&start, temp);
  }
  int a = Length(&start);
  int b = Empty(&start);
  printf("%d\n",a);
  printf("%d\n",b);
  printList(start);
  struct node * p = (struct node *)malloc(sizeof(struct node));
  p->data=7;
 append(&start,p);
 printList(start);
  return 0;
}