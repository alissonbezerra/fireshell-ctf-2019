#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <openssl/md5.h>

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

void welcome() {
    puts("");
}

char *str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

void* check1(void* arg){
	char *p = (char *) arg;
	int c = (char) p[0];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check2(void* arg){
	char *p = (char *) arg;
	int c = (char) p[1];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check3(void* arg){
	char *p = (char *) arg;
	int c = (char) p[2];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check4(void* arg){
	char *p = (char *) arg;
	int c = (char) p[3];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check5(void* arg){
	char *p = (char *) arg;
	int c = (char) p[4];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check6(void* arg){
	char *p = (char *) arg;
	int c = (char) p[5];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check7(void* arg){
	char *p = (char *) arg;
	int c = (char) p[6];
	int d;
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check8(void* arg){
	char *p = (char *) arg;
	int c = (char) p[7];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check9(void* arg){
	char *p = (char *) arg;
	int c = (char) p[8];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check10(void* arg){
	char *p = (char *) arg;
	int c = (char) p[9];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check11(void* arg){
	char *p = (char *) arg;
	int c = (char) p[10];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check12(void* arg){
	char *p = (char *) arg;
	int c = (char) p[11];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check13(void* arg){
	char *p = (char *) arg;
	int c = (char) p[12];
	int d;
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check14(void* arg){
	char *p = (char *) arg;
	int c = (char) p[13];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check15(void* arg){
	char *p = (char *) arg;
	int c = (char) p[14];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '2';
	if (c == d) { pthread_exit((void *) 50); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

void* check16(void* arg){
	char *p = (char *) arg;
	int c = (char) p[15];
	int d;
	d = (int) '0';
	if (c == d) { pthread_exit((void *) 48); }
	d = (int) '1';
	if (c == d) { pthread_exit((void *) 49); }
	d = (int) '3';
	if (c == d) { pthread_exit((void *) 51); }
	d = (int) '4';
	if (c == d) { pthread_exit((void *) 52); }
	d = (int) '5';
	if (c == d) { pthread_exit((void *) 53); }
	d = (int) '6';
	if (c == d) { pthread_exit((void *) 54); }
	d = (int) '7';
	if (c == d) { pthread_exit((void *) 55); }
	d = (int) '8';
	if (c == d) { pthread_exit((void *) 56); }
	d = (int) '9';
	if (c == d) { pthread_exit((void *) 57); }
	d = (int) 'A';
	if (c == d) { pthread_exit((void *) 65); }
	d = (int) 'B';
	if (c == d) { pthread_exit((void *) 66); }
	d = (int) 'C';
	if (c == d) { pthread_exit((void *) 67); }
	d = (int) 'D';
	if (c == d) { pthread_exit((void *) 68); }
	d = (int) 'E';
	if (c == d) { pthread_exit((void *) 69); }
	d = (int) 'F';
	if (c == d) { pthread_exit((void *) 70); }
	d = (int) 'a';
	if (c == d) { pthread_exit((void *) 97); }
	d = (int) 'b';
	if (c == d) { pthread_exit((void *) 98); }
	d = (int) 'c';
	if (c == d) { pthread_exit((void *) 99); }
	d = (int) 'd';
	if (c == d) { pthread_exit((void *) 100); }
	d = (int) 'e';
	if (c == d) { pthread_exit((void *) 101); }
	d = (int) 'f';
	if (c == d) { pthread_exit((void *) 102); }
	pthread_exit((void*) 0);
}

int main(){
    setup();
    welcome();

    char k[16], kk[16];
    printf("Give me your flag: ");
    read(0, k, 16);

    int c = 0;
    for(int i = 0; i < 16; i++) {
        kk[i] = k[i];
        c++;
    }

    for(int i = 0; i < 16; i++) {
        int c = kk[i];
        if (c < 48 || c > 102) {
            puts("Wrong flag!\n");
            exit(0);
        }
    }

    int soma = 0;
    int rs[16];
    pthread_t tid[16];

    pthread_create(&tid[0], NULL, check1, kk);
    pthread_create(&tid[1], NULL, check2, kk);
    pthread_create(&tid[2], NULL, check3, kk);
    pthread_create(&tid[3], NULL, check4, kk);
    pthread_create(&tid[4], NULL, check5, kk);
    pthread_create(&tid[5], NULL, check6, kk);
    pthread_create(&tid[6], NULL, check7, kk);
    pthread_create(&tid[7], NULL, check8, kk);
    pthread_create(&tid[8], NULL, check9, kk);
    pthread_create(&tid[9], NULL, check10, kk);
    pthread_create(&tid[10], NULL, check11, kk);
    pthread_create(&tid[11], NULL, check12, kk);
    pthread_create(&tid[12], NULL, check13, kk);
    pthread_create(&tid[13], NULL, check14, kk);
    pthread_create(&tid[14], NULL, check15, kk);
    pthread_create(&tid[15], NULL, check16, kk);

    pthread_join(tid[0], (void**) &rs[0]);
    pthread_join(tid[1], (void**) &rs[1]);
    pthread_join(tid[2], (void**) &rs[2]);
    pthread_join(tid[3], (void**) &rs[3]);
    pthread_join(tid[4], (void**) &rs[4]);
    pthread_join(tid[5], (void**) &rs[5]);
    pthread_join(tid[6], (void**) &rs[6]);
    pthread_join(tid[7], (void**) &rs[7]);
    pthread_join(tid[8], (void**) &rs[8]);
    pthread_join(tid[9], (void**) &rs[9]);
    pthread_join(tid[10], (void**) &rs[10]);
    pthread_join(tid[11], (void**) &rs[11]);
    pthread_join(tid[12], (void**) &rs[12]);
    pthread_join(tid[13], (void**) &rs[13]);
    pthread_join(tid[14], (void**) &rs[14]);
    pthread_join(tid[15], (void**) &rs[15]);

    for(int i = 0; i < 16; i++) {
        soma += rs[i];
    }

    if (soma == 0) {
        char *s1 = str2md5(kk, 16);
        char *s2 = "32f4f18bfd639f8df791ad6d8263d3d3";
        for(int i = 0; i < strlen(s1); i++) {
            if (s1[i] != s2[i]) {
                puts("Wrong flag!");
                exit(1);
            }
        }
        puts("Correct flag!");
    } else {
        puts("Wrong flag!");
    }

    return 0;
}
