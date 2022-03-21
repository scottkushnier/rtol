#include <stdlib.h>
#include <stdio.h>

void rev_word(char *w, int len) {
	int i;
	char tmp;
	int h;

	while ((w[len-1] == 0x05) || (w[len-1] == 0x06)) {
		len--;
	}
	h = len / 2;
	for (i=0; i<h; i++) {
		tmp = w[i];
		w[i] = w[len - i - 1];
		w[len - i - 1] = tmp;	
	}
}

void print_word(char *word, int len) {
	int i;
	
	for (i=0; i<len; i++) {
		if (word[i] == 0x05) {
			putchar(' ');
		} else if (word[i] == 0x06) {
			putchar('-');
		} else {
			putchar(0xd7);
			putchar(word[i]);
		}
	}
}
	
void main() {
	int c;
	char word[1000];
	int inside = 0;
	int ptr = 0;
	int i;

	while ((c = getchar()) != EOF) {
		if (c == 0xd7) {
//			printf("got d7\n");
			
			c = getchar();
			word[ptr++] = c;
			inside = 1;
		}
		else if ((c == ' ') && (inside)) {
			word[ptr++] = 0x05;
		} else if ((c == '-') && (inside)) {
			word[ptr++] = 0x06;
		} else {
			if (inside) {
				rev_word(word, ptr);
				print_word(word, ptr);
			}
			putchar(c);
			inside = 0;
			ptr = 0;
		}
	}
	if (inside) {
		rev_word(word, ptr);
		print_word(word, ptr);
	}
}

