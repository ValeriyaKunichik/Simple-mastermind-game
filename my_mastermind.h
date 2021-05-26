#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
typedef struct t_option{
    char* c;
    char* p;
    int t;
} t_option;

t_option* get_opt(int ac, char **av);
char* set_buff(int size);
void set_opt(t_option* option, char* name, char* value);
void play(char* c, char* p, int t);
char* random_code(char* p);
int* count_correct_pieces(char* p, char* c);
int well_placed_number(char* c, char* input);
int misplaced_number(char* c, char* input, char* p);
int find_piece(char* p, char c);
