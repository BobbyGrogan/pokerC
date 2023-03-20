#include <stdio.h>
#include <stdlib.h>

int main() {
	const char *cards[52][2];
	cards[0][0] = "A"; cards[0][1] = "S"; cards[1][0] = "2"; cards[1][1] = "S"; cards[2][0] = "3"; cards[2][1] = "S"; cards[3][0] = "4"; cards[3][1] = "S";
	cards[4][0] = "5"; cards[4][1] = "S"; cards[5][0] = "6"; cards[5][1] = "S"; cards[6][0] = "7"; cards[6][1] = "S"; cards[7][0] = "8"; cards[7][1] = "S";
	cards[8][0] = "9"; cards[8][1] = "S"; cards[9][0] = "10"; cards[9][1] = "S"; cards[10][0] = "J"; cards[10][1] = "S"; cards[11][0] = "Q"; cards[11][1] = "S";
        cards[12][0] = "K"; cards[12][1] = "S"; cards[13][0] = "A"; cards[13][1] = "H"; cards[14][0] = "1"; cards[14][1] = "H"; cards[15][0] = "2"; cards[15][1] = "H";
        cards[16][0] = "3"; cards[16][1] = "H"; cards[17][0] = "4"; cards[17][1] = "H"; cards[18][0] = "5"; cards[18][1] = "H";
        cards[19][0] = "6"; cards[19][1] = "H"; cards[20][0] = "7"; cards[20][1] = "H"; cards[21][0] = "8"; cards[21][1] = "H"; cards[22][0] = "9"; cards[22][1] = "H";
        cards[23][0] = "10"; cards[23][1] = "H";
        cards[24][0] = "J"; cards[24][1] = "H";
        cards[25][0] = "Q"; cards[25][1] = "H";
        cards[26][0] = "K"; cards[26][1] = "H";
        cards[27][0] = "A"; cards[27][1] = "C";


	int val = atoi(cards[1][0]) + 2;
	printf("%d\n", val);

	return 0;
}

