#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
  char text[50];
  struct node *add;
  struct node *preadd;
};

struct node *head = NULL;
struct node *tail = NULL;

typedef struct done
{
  char text2[50];
  struct done *next;
}DONE;

struct done *head1 = NULL;
struct done *tail1 = NULL;

void displayaccomplishment();
int n = 0;


void add()
{
  struct node *temp,*newnode;//*newnode1;
  int num;
  if(head != NULL)
  {
    temp = tail;
  }
  //int x,pos,k=1;
  printf("Enter the number of tasks: ");
  scanf("%d",&num);
  n += num;
  for(int i=1;i<=num;i++)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the task: ");
    scanf("\n");
    scanf("%[^\n]%*c",newnode->text);
    newnode->add=NULL;
    newnode->preadd=NULL;

    if (head==NULL)
    {
      head=temp=newnode;
    }
    else
    {
      temp->add=newnode;
      newnode->preadd=temp;
      temp=newnode;
    }
    tail=temp;
  }
  printf("\nThe first task is: %s",head->text);
  printf("\nThe last task is: %s",tail->text);
  printf("\n\n");
  int count = 0;
  temp = head;
  while(temp!=NULL)
  {
    printf("Task %d: %s\n",++count,temp->text);
    temp=temp->add;
  }
}
  /*char choice;
  printf("Want to add more tasks?[Y/N]");
  scanf("%c",&choice);
  if(choice == 'Y' || choice == 'y')
  {
    if(n==0)
    {
      printf("Currently you have no tasks.\n");
      newnode1=(struct node*)malloc(sizeof(struct node));
      printf("Enter the task: ");
      scanf("\n");
      scanf("%[^\n]%*c",newnode1->text);
      newnode1->add=NULL;
      newnode1->preadd=NULL;
      head=temp=newnode1;
    }
    else
    {
      //printf("\nTo enter the task at any position\n\n");
      printf("\n\nEnter the position to which task to be added: ");
      scanf("\n%d",&pos);
      while(pos>n+1 || pos<1)
      {
        printf("\nInvalid position!!");
        printf("\nEnter the position:\n");
        scanf("%d",&pos);
      }
        newnode1=(struct node*)malloc(sizeof(struct node));
        newnode1->add=NULL;
        newnode1->preadd=NULL;
        printf("\nEnter the task: ");
        scanf("\n");
        scanf("%[^\n]%*c",newnode1->text);
      if(pos==1)
      {
        newnode1->add=head;
        newnode1->preadd = NULL;
        head = newnode1;
      }
      if(pos==n+1)
      {
          tail->add = newnode1;
          newnode1->preadd = tail;
          tail = newnode1;
      }
      else
      {
          temp = head;
          for(int i=1;i<pos-1;i++)
            temp = temp->add;
        newnode1->add = temp->add;
        temp->add->preadd = newnode1;
        temp->add = newnode1;
        newnode1->preadd = temp;
      }
      n++;
      printf("\nThe first task is:%s\n",head->text);
      printf("The last task is: %s\n",tail->text);
    }
  }
}*/


void display()
{
  struct node *temp = head;
  //temp = head;
  int p = 1;
  int copy_num = n;
  if(temp == NULL)
  {
    printf("ToDo List is empty!!\n\n");
  }
  while(copy_num)
  {
    printf("Task %d is: %s\n",p,temp->text);
    temp = temp->add;
    p++;
    copy_num--;
  }
}


void addatend(char *data)
{
    struct done *newdone = (struct done*)malloc(sizeof(struct done));
    strcpy(newdone->text2,data);
    newdone->next = NULL;

    if(head1 == NULL)
    {
      head1 = newdone;
      tail1 = newdone;
    }
    else
    {
      tail1->next = newdone;
      tail1 = newdone;
    }
}


void deleteone()
{
  struct node *temp=head;
  int pos,k=1;
  char copy[50];
  if(n == 0)
  {
      if((temp == head && temp == tail )&&(head=NULL))
      {
          printf("After deletion\n");
          head=NULL;
          strcpy(copy,temp->text);
          addatend(copy);
          free(temp);
          n--;
          printf("The ToDo List is empty now.");
      }
    else
    {
      printf("\nToDo List is empty. There are no tasks to delete.\n");
    }
  }
  else
  {
    printf("\nTo delete a task enter the position: ");
    scanf("%d",&pos);
    while(pos<1 || pos>n)
    {
      printf("\nInvalid position....\n");
      printf("Enter the position: ");
      scanf("%d",&pos);
    }
    temp=head;
    if (pos==1)
    {
      head=temp->add;
      head->preadd=NULL;

      strcpy(copy,temp->text);
      addatend(copy);
      n--;
      free(temp);
    }
    else if(pos==n)
    {
      temp=tail;
      if(temp->preadd == NULL)
      {
        printf("preadd is NULL");
      }
      tail=temp->preadd;
      tail->add=NULL;

      n--;
      free(temp);
    }
    else
    {
      while(k<pos-1)
      {
        temp=temp->add;
        k++;
      }
      strcpy(copy,temp->add->text);
      addatend(copy);
      free(temp->add);
      temp->add=temp->add->add;
      temp->add->preadd=temp;
      printf("%s %s",temp->text, temp->add->text);

      n--;
    }
    printf("\n");
    printf("The list after deleting task is:\n");
    int p =1;
    temp=head;
    while(temp!=NULL)
    {
      printf("Task %d : %s\n",p,temp->text);
      temp=temp->add;
      p++;
    }
  }
}


void update()
{
  struct node *temp = head,*tail;
  int pos,k=1;
  temp = head;
  if(head == temp && temp == tail)
  {
    if(n == 0 || head==NULL)
    {
      printf("Currently no task...\n\n");
    }
    else
    {
      printf("Enter the new task: ");
      scanf("\n");
      scanf("%[^\n]%*c",temp->text);

      printf("\n");
      printf("The list after updating node is:\n");
      int p = 1;
      temp=head;
      while(temp!=NULL)
      {
        printf("The task at %d is: %s\n",p,temp->text);
        temp=temp->add;
        p++;
      }
    }
  }
  else
  {
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    while(pos < 1 || pos > n)
    {
      printf("\nInvalid position.\n");
      printf("Enter the position: ");
      scanf("%d",&pos);
    }
      temp = head;
      if (pos == 1)
      {
        printf("Enter the new task: ");
        scanf("\n");
        scanf("%[^\n]%*c",temp->text);
      }

      else if(pos == n)
      {
        printf("Enter the new task: ");
        scanf("\n");
        scanf("%[^\n]%*c",tail->text);
      }
      else
      {
        while(k < pos)
        {
          temp=temp->add;
          k++;
        }
        printf("Enter the new task: ");
        scanf("\n");
        scanf("%[^\n]%*c",temp->text);
      }
    printf("\n");
    printf("The list after updating task is:\n");
    int p = 1;
    temp = head;
    while(temp != NULL)
    {
      printf("Task %d : %s\n",p,temp->text);
      temp = temp->add;
      p++;
    }
  }
}


void displayaccomplishment()
{
  struct done *temp1 = head1;
  int c = 0;
  if(head1 != NULL)
  {
    printf("\nYour accomplishments are:\n");
    while(temp1 != NULL)
    {
      printf("%d. %s\n",c+1,temp1->text2);
      temp1 = temp1->next;
      c += 1;
    }
    printf("Delete accomplishments?[Y/N]: ");
    char ch;
    scanf("\n%c",&ch);
    if(ch == 'y' || ch == 'Y')
    {
        temp1 = head1;
        while(head1 != NULL)
        {
          temp1 = head1;
          head1 = temp1->next;
          free(temp1);
        }
        printf("Deleted accomplishment list.\n");
        head1 = NULL;
    }
  }
  else
  {
    printf("\nNo accomplished tasks\n");
  }
}


void search()
{
  struct node *temp;//*newnode,*newnode1;//*tail;
  int loc,l=1;
  //int k = 1,pos,x;
  char f;
  if(n == 0)
  {
    printf("NO task found...\n");
  }
  else if(n == 1)
  {
    temp=head;
    printf("The only task is: %s\n",temp->text);
  }
  else
  {
    printf("\nEnter the location of the task to be found:");
    scanf("%d",&loc);
    while(loc<1||loc>n)
    {
      printf("\nInvalid postion....\n");
      printf("\nEnter the location of the task to be found:\n");
      scanf("%d",&loc);
    }
    temp=head;
    //printf("%s",head->text);
    while(l<loc)
    {
      temp=temp->add;
      l++;
    }
    printf("\nTask at position %d is: %s\n",loc,temp->text);

    printf("\nTo print the previous task press 'b' and to print next task press 'a': \n");
    scanf("\n%c",&f);
    if(f=='a')
    {
      if(temp->add==NULL)
      {
        printf("This is the last Task...\n");
      }
      else
      {
         printf("\nThe next task is %s\n",temp->add->text);
      }
    }
    else
    {
      if(temp->preadd==NULL)
      {
        printf("This is the first Task...\n");
      }
      else
      {
        printf("\nThe previous task is %s\n",temp->preadd->text);
      }
    }
  }
}

void searchkey()
{
  struct node *temp;
  int count = 0;
  char key[50],text2[50],key2[50];
  if(n == 0)
  {
    printf("No task found...\n");
  }
  else if(n == 1)
  {
    temp = head;
    printf("The only task is: %s\n",temp->text);
  }
  else
  {
    temp = head;
    printf("\nEnter keyword: ");
    scanf("\n%s",key);
    printf("\n");
    int len = sizeof(key)/sizeof(key[0]);
    for(int i=0;i<len;i++)
    {
      if(isupper(key[i]))
      {
        key2[i] = tolower(key[i]);
      }
      else
      {
        key2[i] = key[i];
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    int len = sizeof(temp->text)/sizeof(temp->text[0]);
    for(int i=0;i<len;i++)
    {
      if(isupper(temp->text[i]))
      {
        text2[i] = tolower(temp->text[i]);
      }
      else
      {
        text2[i] = temp->text[i];
      }
    }
    if(strstr(text2,key2) != NULL)
    {
      if(count == 0)
        printf("Tasks with keyword '%s' are:\n",key);
      printf("%d.%s \n",count+1,temp->text);
      count++;
    }
    temp = temp->add;
  }

  if(count == 0)
  {
    printf("\nNo tasks found with keyword: %s\n",key);
  }
}


int deleteall()
{
  char copy[50];
  struct node *tempo = head;
  while(head != NULL)
  {
    tempo = head;
    head = tempo->add;
    printf("Deleting task : %s\n",tempo->text);
    strcpy(copy,tempo->text);
    addatend(copy);
    free(tempo);
  }
  printf("SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
  n = 0;
  return 0;
}

int main()
{
  int choice;
  //struct node *temp;//*newnode;
  while(1)
  {
    printf("\n1.Add a new task to ToDo List");
    printf("\n2.Display the ToDo List");
    printf("\n3.Delete a task from ToDo List");
    printf("\n4.Rename a task");
    printf("\n5.Search task with serial number");
    printf("\n6.Find all pending tasks with a keyword");
    printf("\n7.All tasks are completed. Delete all");
    printf("\n8.View accomplishments");
    printf("\n9.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      add();
      break;

      case 2:
      display();
      break;

      case 3:
      deleteone();
      break;

      case 4:
      update();
      break;

      case 5:
      search();
      break;

      case 6:
      searchkey();
      break;

      case 7:
      deleteall();
      break;

      case 8:
      displayaccomplishment();
      break;

      case 9:
      exit(0);
      break;
    }
  }
return 0;
}