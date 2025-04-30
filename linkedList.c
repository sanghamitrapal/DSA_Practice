#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
  int data;
  struct node *next; 
};
typedef struct node node;
node *head=NULL, *ptr;

void insert(value){
  if(head==NULL){
    head = malloc(sizeof(node));
    head -> next = NULL;
    head->data = value;
  }else{
    ptr = head;
    while((ptr->next)!= NULL){
      ptr = ptr->next;
    }
    ptr->next = malloc(sizeof(node));
    ptr = ptr->next;
    ptr -> next = NULL;
    ptr->data = value;
  }
}

void insertAfter(pos){
	char input[15];
	int value;
	node *temp;
	if(head==NULL){
		printf("The list is empty!");
		return;
	} else{
		ptr=head;
		while(ptr->data!=pos){
			ptr= ptr->next;
			if(ptr->next==NULL){
				printf("%d is not in the list!",pos);
				return;
			}
		}
		printf("Enter the value you wanna insert: ");
	    fgets(input,sizeof(input),stdin);
	    value=atoi(input);
		temp = ptr->next;
		ptr->next = malloc(sizeof(node));
		ptr = ptr->next;
		ptr->data = value;
		ptr->next = temp;
	}
}

void viewList(){
  if(head == NULL){
    printf("The list is Empty!");
  }else{
    ptr = head;
    printf("%d",ptr->data);
    ptr = ptr->next;
    while((ptr)!=NULL){
      printf(" -> %d",ptr->data);
      ptr = ptr->next;
    }
  }
}


void main(){
  bool choice=true;
  char input[50];
  char *command, *command2;
  int value,pos;
  printf("Use following commands to interact with the linked list! Replace <value> with the value of the node you want to insert or delete \n To view the list: view\n To insert at the end: insert <value> \n To insert after a existing value: insert after <Existing Value> \n To delete a node: delete <value>");
  
  
  //command parsing
  while(choice==true){
    printf("\n>>>");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input, "\n")] = '\0'; //Removes the newline character fgets( ) adds by default.
    command = strtok(input," ");
    if(strcmp(command,"view")==0){
      viewList();
    }
	else if(strcmp(command,"insert")==0){
    	command2=strtok(NULL, " ");
      	if(strcmp(command2,"after")==0){
      		pos=atoi(strtok(NULL," "));	
	    	insertAfter(pos);
		  } else{
		  	value=atoi(command2);
		  	insert(value);
		  }
    } 
	else if(strcmp(command,"exit")==0){
      printf("Goodbye!");
      choice = !choice;
    }
  }
}

