#include <stdlib.h>
#include <stdio.h>

void rev_word(char *w, int len) {
	int i;
	char tmp;
	int h;

	if (w[len-1] == 0x05)
		len--;
	h = len / 2;
	for (i=0; i<h; i++) {
		tmp = w[i];
		w[i] = w[len - i - 1];
		w[len - i - 1] = tmp;	
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
		} else {
			if (inside) {
				rev_word(word, ptr);
				for (i=0; i<ptr; i++) {
					if (word[i] == 0x05) {
						putchar(' ');
					} else {
						putchar(0xd7);
						putchar(word[i]);
					}
				}
			}
			putchar(c);
			inside = 0;
			ptr = 0;
		}
	}
	if (inside) {
		rev_word(word, ptr);
		for (i=0; i<ptr; i++) {
			if (word[i] == 0x05) {
				putchar(' ');
			} else {
				putchar(0xd7);
				putchar(word[i]);
			}
		}
	}
}

