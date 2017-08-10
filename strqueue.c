/**
 * File: q3/strqueue.c
 * Enter a description of this file.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "strqueue.h"

struct llnode{
    char *item;
    struct llnode *next;
};

struct strqueue{
    struct llnode *front;
    struct llnode *back;
    int length;
};

StrQueue create_StrQueue(void){
    StrQueue new = malloc(sizeof(struct strqueue));
    new->front = NULL;
    new->back = NULL;
    new->length = 0;
    return new;
}

void destroy_StrQueue(StrQueue sq){
    assert(sq != NULL);
    struct llnode *current = sq->front;
    struct llnode *next;
    while (current != NULL){
        next = current->next;
        free(current->item);
        free(current);
        current=next;
    }
    free(sq);
}

void sq_add_back(StrQueue sq, const char *str){
    assert(sq != NULL);
    assert(str != NULL);
    char *mystr = malloc(sizeof(char) * (strlen(str)+1));
    mystr = strcpy(mystr,str);
    struct llnode *new = malloc(sizeof(struct llnode));
    new->item = mystr;
    new->next = NULL;
    if(sq->length == 0){
        sq->front = new;
        sq->back = new;
    }
    else{
        sq->back->next=new;
        sq->back = new;
    }
    sq->length++;
}


char *sq_remove_front(StrQueue sq){
    assert(sq != NULL);
    struct llnode *new = sq->front;
    if (new == NULL){
        return NULL;
    }
    else{
        char *reserve = new->item;
        sq->front = new->next;
        free(new);
        sq->length--;
        return reserve;
    }
}

int sq_length(StrQueue sq){
    assert(sq != NULL);
    return sq->length;
}
