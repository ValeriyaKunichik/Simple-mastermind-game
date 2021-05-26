#include "my_mastermind.h"
int well_placed_number(char* c, char* input){
    int well_placed = 0;
    for (int i = 0; c[i]; i++){
        if (c[i] == input[i])
            well_placed++;
    }
    return (well_placed);
}


int find_piece(char* p, char c){
    for (int i = 0; p[i]; i++){
        if (p[i] == c){
            return (i);
        }    
    }
    return 0;
}

int* count_correct_pieces(char* p, char* c){
    int* pieces_number = (int*)malloc(sizeof(int) * 9);
    int piece;
    for (int i = 0; c[i]; i++){
        piece = find_piece(p, c[i]);
        pieces_number[piece]++;
    }
    return (pieces_number);
}

int misplaced_number(char* c, char* input, char* p){
                                                            
    int* code_pieces_number = count_correct_pieces(p, c); 
    int* input_pieces_number = count_correct_pieces(p, input);     
    int correct_pieces = 0;
    for (int i = 0; i < 8; i++){
        int code_pieces = code_pieces_number[i];
        int input_pieces = input_pieces_number[i];
        if (code_pieces < input_pieces){
            correct_pieces += code_pieces;
        }
        else {
            correct_pieces += input_pieces;
        }
    }      
    return (correct_pieces - (well_placed_number(c, input)));
}

void play(char* c, char* p, int t){
    if ((strlen(c) == 4) && (strlen(p) == 8)){
        char *input = (char*)malloc(sizeof(char) * 5);
        int attempt = 0;      
        while (attempt < t){
            printf("Round %d. Enter 4 symbols among %s: \n", attempt + 1, p);
            read(0, input, 5);           
            input[4] = '\0';
            if (strcmp(input, c) == 0){
                printf("Congratz! You did it!\n");
                break;
            } 
            else {
                printf("Well placed pieces: %d\n", well_placed_number(c, input));
                printf("Misplaced pieces: %d\n", misplaced_number(c, input, p));
            }            
            attempt++;
            if (attempt == t){
                printf("Game over\n");
            }
        }
    }
    else if ((strlen(c) != 4) && (strlen(p) == 8)){
        printf("A secret code should be composed of 4 pieces\n");
    }
    else if ((strlen(c) == 4) && (strlen(p) != 8)){
        printf("Number of pieces should be 8\n");
    }
    else {
        printf("Invalid input\n");
    }
}
