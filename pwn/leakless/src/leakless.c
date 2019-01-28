/*
* This challenge should not be leakable, but due to a copy and paste,
* challenge didn't work this way in the end.
*/

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(){
	// The line below caused the issue that I introduced before.
	puts("Timeout!");
	exit(0);
}

void setup(){
	  setvbuf(stdin, 0, 2, 0);
  	setvbuf(stdout, 0, 2, 0);
  	signal(SIGALRM, handler);
  	alarm(120);
}

void feedme() {
    char buff[64];
    read(0, buff, 256);
}

int main() {
	setup();
  feedme();
  return 0;
}
