#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define MAX 6

void read_input(char *buf, size_t size) {
	int ret;
    ret = read(0, buf, size);
    if (ret <= 0) {
        puts("Bad input!");
        _exit(1);
    }
}

int read_int() {
	char buf[8];
	read_input(buf, sizeof(buf));
	return atoi(buf);
}

char *quotes[MAX];
unsigned int lengths[MAX];

void handler() {
	puts("Timeout!");
	exit(0);
}

void setup() {
	setvbuf(stdin, 0, 2, 0);
  	setvbuf(stdout, 0, 2, 0);
  	signal(SIGALRM, handler);
  	alarm(60);
}

void menu() {
	puts("-----------------------------");
	puts("          Quote List         ");
	puts("-----------------------------");
	puts(" 1) Create quote             ");
	puts(" 2) Edit quote               ");
	puts(" 3) Show quote               ");
	puts(" 4) Delete quote             ");
	puts(" 5) Exit                     ");
	puts("-----------------------------");
	printf("> ");
}

void create_quote() {
	size_t length = 0;
	for(int i = 0; i < MAX; i++) {
		if(!quotes[i]){
			printf("Length: ");
			length = read_int();
			lengths[i] = length;
			quotes[i] = (char *) malloc(length);
			if(!quotes[i]){
				puts("Could not allocate!");
				exit(1);
			}
			printf("Content: ");
			read_input(quotes[i], length);
			break;
		}
	}
}

void edit_quote() {
	printf("Index: ");
	int idx = read_int();
	if (idx < 0 || idx > 5) {
		puts("Invalid index!");
		_exit(1);
	}
	if (quotes[idx]) {
		printf("Content: ");
		read_input(quotes[idx], lengths[idx]+1);
		puts("Ok!");
	}else{
		puts("Invalid quote!");
	}
}

void show_quote() {
	printf("Index: ");
	int idx = read_int();
	if(idx < 0 || idx > 5){
		puts("Invalid index!");
		_exit(1);
	}
	if(quotes[idx]) {
		char buff[lengths[idx]];
		strncpy(buff, quotes[idx], lengths[idx]);
		buff[lengths[idx]] = '\0';
		printf("Quote: %s\n", buff);
	}else{
		puts("Invalid quote!");
	}
}


void delete_quote() {
	printf("Index: ");
	int idx = read_int();
	if(idx < 0 || idx > 5) {
		puts("Invalid index!");
		_exit(1);
	}
	if(quotes[idx]) {
		free(quotes[idx]);
		quotes[idx] = NULL;
		lengths[idx] = -1;
		puts("Ok!");
	}else{
		puts("Invalid quote!");
	}
}

int main(int argc, char const *argv[]) {
	setup();
    while(1) {
    	menu();
        switch(read_int()) {
        	case 1:
        		create_quote();
        		break;
        	case 2:
        		edit_quote();
        		break;
        	case 3:
        		show_quote();
        		break;
        	case 4:
        		delete_quote();
        		break;
        	case 5:
        		puts("Bye!");
        		exit(0);
        		break;
        	default :
				puts("Invalid Choice");
				break;
        }
    }
	return 0;
}
