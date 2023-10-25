#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int str_check(char str[], char check[]){
    for (int i = 0; str[i] != '\n' || check[i] != '\n'; i++){

        //printf("%c\n",str[i]); checks on chars
        //printf("%c\n",check[i]);

        if (str[i] != check[i]){
            return 0;
        }
    }
    return 1;
}

int main_len(char *str){
    int i = 0;
    while (*(str + i) != '\0'){
        i++;
    }
    return i;
}

void clr_str(char *str){
    int i = 0;
    while (*(str + i) != '\0'){
        str[i] = '\n';
        i++;
    }
}


int main(void){
  puts("Welcome!");

  char q[2] = "q\n";
  int MAX_LIMIT = 20;
  char t[MAX_LIMIT];
  t[0] = '\n';

  while (t[0] == '\n'){
      printf("Please type the word/words you would like to tokenize! To quit please type q.\n");
      fgets(t, MAX_LIMIT, stdin);
      //fflush(stdin); Q: why doesnt this work?



      //printf("%s\n",t);  //checks on the chars
      //printf("%s\n",q);
      //printf("%i",str_check(t,q));

      if (str_check(t,q)){ //early quit option
          printf("Goodbye!\n");
          exit(0);

      }
      //catch for no word imput
      /*
      if (t == '\n'){
          while (t == '\n'){
              printf("please enter a word\n");
              t = getchar();
          }
      }
      */

      char s = '\n';  //switch control variable
                      //
      do{

          //while (s != 0){ //runs while the switch doesnt equal 0
          printf("\nEnter 0 to quit.\nEnter 1 to print tokens.\nEnter 2 to count tokens.\nEnter 3 to free tokens.\nEnter 4 to select another token.\n\n"); //Q: Why does this print twice when staying in the loop


          s = getchar();
          fflush(stdin);

          char **token = tokenize(t);



          if (s == '0'){
              printf("Goodbye!\n\n");
              exit(0);
          }

          if (s == '1'){
              printf("Printing tokens!\n\n");
              print_tokens(token);

          }


          if (s == '2'){
              printf("Here are the number of tokens.\n\n");
          }

          if (s == '3'){
              printf("Printing tokens!\n\n");
          }
          if (s == '4'){
              printf("Returning\n\n");
              break;
          }

          s = '\n';




      }while(s != '4');


     fflush(stdin);
     clr_str(t);
     //printf("%s", t);
     //fflush(stdin);



  }
}
