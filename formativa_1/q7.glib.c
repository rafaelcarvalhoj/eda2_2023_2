//compile
// gcc -o q7 q7.c `pkg-config --cflags --libs glib-2.0`

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

int main(){
    GQueue *stack = g_queue_new();

    char op[10];

    while(scanf("%s", op) != EOF){
        if(!strcmp(op, "inserir")){
            char str[100];
            fgets(str, 100, stdin);

            size_t len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }

            g_queue_push_head(stack, strdup(str));
        }
        else{
            if(g_queue_is_empty(stack))
                printf("NULL\n");
            else{
                char *rm = g_queue_pop_head(stack);
                printf("%s\n",g_strchug(rm));
                free(rm);
            }
        }
    }

    return 0;

}
