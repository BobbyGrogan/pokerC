#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rank_to_num(const char *rank);

int main() {
	// create deck of cards in order
	const char *cards[52][2];
	const char *ranks[13]; ranks[0] = "A"; ranks[1] = "2"; ranks[2] = "3"; ranks[3] = "4"; ranks[4] = "5"; ranks[5] = "6"; ranks[6] = "7"; ranks[7] = "8"; ranks[8] = "9"; ranks[9] = "10"; ranks[10] = "J"; ranks[11] = "Q"; ranks[12] = "K";
	const char *suits[4]; suits[0] = "S"; suits[1] = "H"; suits[2] = "C"; suits[3] = "D";
	int i = 0; int c; int a = 0;
	while(i++ < 4) { c = -1; while(c++ < 12) { cards[a][0] = ranks[c]; cards[a][1] = suits[i]; a = a + 1; } }

	printf("%s\n", cards[12][1]);
	char j = rank_to_num(cards[12][0]);
	printf("%i\n", j);

	return 0;
}

int rank_to_num(const char *rank) {
	int num;
	if(strcmp(rank, "A") == 0) { num = 14; return num; }
        if(strcmp(rank, "K") == 0) { num = 13; return num; }
        if(strcmp(rank, "Q") == 0) { num = 12; return num; }
        if(strcmp(rank, "J") == 0) { num = 11; return num; }
	num = atoi(rank);
	return num;
}
