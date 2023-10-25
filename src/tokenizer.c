#include <stdio.h>
#include <stdlib.h>


int my_len(char *str){
    int i = 0;
    while (*(str + i) != '\0'){
        i++;
    }
    return i;
}




int space_char(char c){
   if ((c == ' ' || c == '\t') && c != '\0') {
       return 1;
   }
   return 0;
}



int non_space_char(char c){
   if ((c != ' ' || c != '\t') && c != '\0') {
       return 1;
   }
   return 0;
}


char *token_start(char *str){

    while (space_char(*str)){
        str++;

    }

    return str;
}



/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){

    while (space_char(*token) == 0){
        token++;
    }
    return token;


}



/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    int count = 0;
    char *t = token_start(str);

    for (int i = 0; t[i] != '\0'; i++){
        t = token_terminator(t);
        t = token_start(t);
        count++;
    }
    return count;
}


/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    char *outstring = malloc(sizeof(char) * (len +1));

    for (int i = 0; i <= len; i++) {
        *(outstring + i) = *(inStr + i);
    }
    *(outstring + len) = '\0';
    return outstring;

}




/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str){
    int num = count_tokens(str);
    char **tokens = malloc(sizeof(char*) * (num + 1));
    char *t = token_start(str);
    int i = 0;

    while (*t != '\0'){
        char *end = token_terminator(t);
        *(tokens + i) = copy_str(t,end-t);
        t = token_start(end);
        i++;
    }
    *(tokens + i) = copy_str("\0",1);
   return tokens;
}



/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    int i = 0;
    //while (**tokens != '\0'){
        //i++;
        //tokens++;
    //}
    //printf("%i\n", i);

    printf("*************************\n");
    //printf("%s\n", *tokens);
    while (**tokens != '\0'){

        printf("%s\n", *tokens);
        free(*tokens);
        tokens++;
    }

    printf("*************************\n");
    free(*tokens);
}



/* Prints all tokens. */
void print_tokens(char **tokens){
    printf("------------------------\n");
    while (**tokens != '\0'){
        printf("%s\n", *tokens);
        tokens++;
    }

    printf("------------------------\n");

}
