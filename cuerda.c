#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 10

typedef struct RopeNode{
    char text[BLOCK_SIZE + 1]; // Incremento en + 1 para almacenar el caracter nulo '\0'
    struct RopeNode * next;
} RopeNode;

typedef RopeNode * RopePointer;

RopeNode* create_node(const char *);
RopeNode* build_rope(const char *);
void print_rope(RopeNode *);
void free_rope(RopeNode *);

int main()
{
    char *str = "Hello there! This is my first rope!";
    RopePointer rope = build_rope(str);
    print_rope(rope);
    free_rope(rope);
    return(0);
}

RopeNode* create_node(const char *str){
    RopePointer new = (RopePointer)malloc(sizeof(RopeNode));
    new->next = NULL;
    memset(new->text, 0, sizeof(new->text));
    strncpy(new->text, str, BLOCK_SIZE);
    new->text[BLOCK_SIZE] = '\0'; // Fuerzo terminación segura.
    return new;
}

RopeNode* build_rope(const char *str){
    RopePointer head = NULL;
    RopePointer tail = NULL;
    while(*str){
        RopePointer new = create_node(str);
        if(!head){
            head = new;
            tail = new;
        }else{
            tail->next = new;
            tail = new;
        }
        str+=BLOCK_SIZE;
    }
    return head;
}

void print_rope(RopeNode *head){
    RopePointer aux = head;
    while(aux){
        printf("[%s]", aux->text);
        aux = aux->next;
    }
}

void free_rope(RopeNode *head){
    while(head){
        RopePointer bor = head;
        head = head->next;
        free(bor);
    }
}