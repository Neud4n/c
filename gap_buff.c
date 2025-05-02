#include <stdlib.h>
#include <stdio.h>

#define INITIAL_SIZE 15
#define GAP_SIZE 5
#define CAN_MOVE_TO_LEFT(gb) ((gb)->gap_start >0)

typedef struct GapBuffer {
    char * buffer;
    int gap_start;
    int gap_end;
    int capacity;
} GapBuffer;

GapBuffer * create_buffer();
void insert_char(GapBuffer *, char);
void move_cursor_left(GapBuffer *);

int main()
{
    return 0;
}

GapBuffer * create_buffer(){
    GapBuffer * gb = malloc(sizeof(GapBuffer));
    gb->capacity = INITIAL_SIZE;
    gb->gap_start = 0;
    gb->gap_end = GAP_SIZE;
    gb->buffer = malloc(INITIAL_SIZE * sizeof(char)); // Si bien, es redundante. Es una buena practica.
    return gb;
}

void insert_char(GapBuffer *gb, char c){
    if(gb->gap_start == gb->gap_start){
        return;
    }
    gb->buffer[gb->gap_start++] = c;
}

void move_cursor_left(GapBuffer *gb){
    if(CAN_MOVE_TO_LEFT(gb)){
        gb->gap_start--;
        gb->gap_end--;
        gb->buffer[gb->gap_end] = gb->buffer[gb->gap_start];
    }
}