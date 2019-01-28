#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "vars.h"

void handler(){
	puts("Timeout!");
	exit(0);
}

void setup(){
	setvbuf(stdin, 0, 2, 0);
  	setvbuf(stdout, 0, 2, 0);
  	signal(SIGALRM, handler);
  	alarm(60);
}

void menu(){
	printf("------- BabyHeap -------\n"
		"1 - Create\n"
		"2 - Edit\n"
		"3 - Show\n"
		"4 - Delete\n"
		"5 - Exit\n");
}

void create(){
	ptr = malloc(SZ);
	printf("Done!\n");	
	created = 1;
}

void edit(){
	printf("Content? ");
	read(0, ptr, 64);
	edited = 1;
}

void show(){
	printf("Content: %s\n", ptr);
	shown = 1;
}

void delete(){
	free(ptr);
	printf("Done!\n");
	created = 0;
	deleted = 1;
}

void leet(){
	ptr = malloc(SZ);
	printf("Fill ");
	read(0, ptr, 64);
	secret++;
}

int main(){
	setup();
  	unsigned int opt;
    char buf[8];

  	while (1) {
  		menu();
  		printf("> ");
        memset(buf, 0 ,sizeof(buf));
        read(0, buf, sizeof(buf));
		opt = atoi(buf);
  		switch(opt) {
			case 1:
				if (created == 1) {
					printf("Again? Oh no, you can't\n");
					exit(0);
				}
				create();
				break;
			case 2:
				if (edited == 1) {
					printf("Again? Oh no, you can't\n");
					exit(0);
				}
				edit();
				break;
			case 3:
				if (shown == 1) {
					printf("Again? Oh no, you can't\n");
					exit(0);
				}
				show();
				break;
			case 4:
				if (deleted == 1) {
					printf("Again? Oh no, you can't\n");
					exit(0);
				}
				delete();
				break;
			case 5:
				printf("Bye!\n");
				exit(0);
				break;
			case 1337:
				if (secret == 1) {
					printf("Again? Oh no, you can't\n");
					exit(0);
				}
				leet();
				break;
			default:
				printf("Invalid option\n");
				exit(0);
  		}
  	}
	return 0;
}