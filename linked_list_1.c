#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdint.h>


struct node{
    char *data;         // data for node
    int index;          // index to keep track of node
    int head;           // head indicator for node
    struct node *next;  //
    struct node *prev;
};

/* List prototypes */
void addList(struct node *nodePtr,char *data);
void addHead(struct node *nodePtr,char *data);
void remove_list(struct node *nodePtr, char *key);


void addHead(struct node *nodePtr, char *data){
    (nodePtr)->head = 1;
    (nodePtr)->data = data;
    (nodePtr)->next = NULL;
}

/*
  replace_data(struct node *nodePtr, char *key, char *newVal)
  replace_data: 
    This function replaces a string from the list. 
*/

void replace_data(struct node *nodePtr, char *key, char *newVal){
    do{
        if(nodePtr->data == key){
          nodePtr->data = newVal;
        }
      
        (nodePtr) = (nodePtr)->next;
    }while(nodePtr != NULL);
    
  }
  
/*
  remove_list(struct node *nodePtr, char *key)
  remove_list: 
    This function removes a string from the list. 
*/

void remove_list(struct node *nodePtr, char *key){

  while(nodePtr->next != NULL){      
    if(nodePtr->next->data == key){
      printf("replace \n\r");
      printf("String: %s\n\r", nodePtr->data);
      nodePtr->next = nodePtr->next->next;
    }  
     (nodePtr) = (nodePtr)->next;
   } 
}

/*
addList(struct node *nodePtr, char *data)
addList:
  This function adds a string to the tail of the list.

*/

void addList(struct node *nodePtr, char *data){
    struct node *newNode = nodePtr;
    struct node *tempPtr = nodePtr;
 
    while((newNode)->next != NULL){
      /* populate previous node */
      if(newNode->head != 1){
        (newNode)->prev = tempPtr;  
         tempPtr = tempPtr->next;
      }
      (newNode) = (newNode)->next;
    }
    
    (newNode)->next = malloc(sizeof(struct node));  

    (newNode)->next-> data = data;
    (newNode)->next-> next = NULL;
   }
   
/*
printList(struct node *nodePtr)
printList:
  This function prints the list.

*/   

void printList(struct node *nodePtr){
    struct node *temp = malloc(sizeof(struct node));    
    temp = nodePtr;
    
    while((temp) != NULL){
      printf("List: %s\n\r",(temp)->data);
      (temp) = (temp)->next;
    }
    
    free(temp);
}

int main(){
    struct node *headPtr = malloc(sizeof(struct node));
     
    printf("------------------------\n\r");
    addHead(headPtr,"test0");
    printf("------------------------\n\r");
    addList(headPtr,"test2");
    printf("------------------------\n\r");
    addList(headPtr,"a");
    addList(headPtr,"b");
    addList(headPtr,"c");
    addList(headPtr,"d");
    addList(headPtr,"e");
    addList(headPtr,"f");
    addList(headPtr,"g");
    printf("------------------------\n\r");
    printList(headPtr);
    printf("------------------------\n\r");
    replace_data(headPtr, "c","xxx");
    printList(headPtr);
    printf("------------------------\n\r");
    remove_list(headPtr,"e");
    printf("------------------------\n\r");
    printList(headPtr);

 
 return 0;
}