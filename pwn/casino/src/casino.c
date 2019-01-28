#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
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

int main(){
	setup();

	char name[16];

	unsigned int seed = (unsigned int) time(NULL);
	seed = seed / 10;

	printf("What is your name? ");
	read(0, name, 16);
	printf("Welcome ");
	printf(name);
	printf("\n");

	seed += bet;
	srand(seed);

	int number = 0;
	int money = 0;
	for(int i = 1; i < 100; i++){
		int secret = rand();
		printf("[%d/100] Guess my number: ", i);
		scanf("%d", &number);
		if (number != secret) {
			printf("Sorry! It was not my number\n");
			exit(0);
		}
		printf("Correct!\n");
		money += bet;
	}

	if (money > 100) {
		printf("Cool! Here's another prize\n");
		char flag[30];
		FILE* f = fopen("flag.txt", "r");
		fread(&flag, sizeof(flag), 1, f);
		fclose(f);
		printf("%s", flag);
	}

	return 0;
}
