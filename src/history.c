#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"



typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;


/* Initialize the linked list to keep the history. */
List* init_history(){
    List *list = malloc(sizeof(List));
    list->root = 0;
    return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/


int len(char *str){
    int i = 0;
    while (*(str + i) != '\0'){
        i++;
    }
    return i;
}


void add_history(List *list, char *str){
    Item *item = malloc(sizeof(Item));

    item->str = copy_str(str, len(str));

    if (list->root == 0){
        item->id = 1;
        list->root = item;
    }

    else{
        Item *last = list->root;
        while(list->root !=0){
            last = last->next;
        }
        last->next = item;
        item->id = last->id+1;
    }

}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *last = list->root;
    while (last != 0){
        if (last->id == id){
            return last->str;
        }
        last = last->next;
    }


    return 0;
}

/*Print the entire contents of the list. */
void print_history(List *list){
    Item *last = list->root;
    while (last != 0){
        printf("%s\n", last->str);
        last = last->next;
    }


}

/*Free the history list and the strings it references. */
void free_history(List *list){

    Item *last = list->root;
    while (last != 0){
        Item *temp = last->next;
        free(last->str);
        free(last);
        last = temp;
    }
    free(list);


}
