#include "my_mastermind.h"

void set_opt(t_option* opt, char* name, char* val){
    for (int i = 0; name[i]; i++){
        if (name[i] == 'c')
            opt->c = val;
        if (name[i] == 'p')
            opt->p = val;
        if (name[i] == 't')
            opt->t = atoi(val);
    }
}

char* set_buff(int size){
    char* buff = (char*)malloc(size);
    for (int i = 0; i < size; i++){  
        buff[i] = 0;
    }
    return buff;
}

t_option* get_opt(int ac, char **av){
    t_option* opt = (t_option*)set_buff(sizeof(t_option));
    for (int i = 0; i < ac; i++){
        if (av[i][0] == '-'){ 
            set_opt(opt, av[i], av[i+1]);
        }
    }
    return opt;
}

char* random_code(char* p){
    char* c = (char*)malloc(sizeof(char) + 1);
    srand(time(0));
	int i = 0;
	for (i = 0; i < 4; i++){
		c[i] = p[rand() % (sizeof p - 1)];
	}
    c[4] = '\0';
    return c;
}


int main(int ac, char **av)
{
    int t;
    char* c;
    char* p;    
    t_option* opts = get_opt(ac, av);
    if (opts->t != 0){
        t = opts->t;
    }
    else {
        t = 10;
    }
    if (opts->p != NULL){
        p = opts->p;
    }
    else {
        p = "01234567";
    }
    if (opts->c != NULL){
        c = opts->c;
    }
    else {
        c  = random_code(p);
        printf("Random code: %s\n", c);
    }
    play(c, p, t);
    return 0;
}
