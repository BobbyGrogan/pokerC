#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rank_to_num(const char *rank);
char *to_word(char *letter);
char high_card(const char *two[2]);
char ***give_cards(int how_many, const char *cards[52][2]);
int to_pass_out();

int main() {
	// create deck of cards in order
	const char *cards[52][2];
	const char *ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	const char *suits[4] = {"S", "H", "C", "D"};
	int numofcards = -1; int i; int c;
	for(i = 0; i < 4; i++) {
		for(c = 0; c < 13; c++) {
			numofcards++; cards[numofcards][0] = suits[i]; cards[numofcards][1] = ranks[c];
		}
	};

	int num_of_cards = 9;
//to_pass_out();
	char ***distributed = give_cards(num_of_cards, cards);
	char *community[5][2] = { distributed[0][0], distributed[0][1], distributed[1][0], distributed[1][1], distributed[2][0], distributed[2][1],
					distributed[3][0], distributed[3][1], distributed[4][0], distributed[4][1] };
	int num_of_players = (num_of_cards - 5) / 2;
	char *player_hands[num_of_players][2];
	for(i = 5; i < num_of_players * 2 + 5; i++) {
		char *your_suit = distributed[i][0];
                char *your_rank = distributed[i][1];
		printf("%d ", i);
		player_hands[i][0] = your_suit;
		player_hands[i][1] = your_rank;
	}

//	printf("\nTest 0: %s %s\n", player_hands[0][0], player_hands[0][1]);
//      printf("\nTest 5: %s %s\n", player_hands[5][0], player_hands[5][1]);


	printf("\nThe community cards are: \n\n");
	for(i = 0; i < 5; i++) {
		char *your_suit = to_word(community[i][0]);
		char *your_rank = to_word(community[i][1]);
	//	printf("%s of %s\n", your_rank, your_suit);



	}
}


// functions

int rank_to_num(const char *rank) {
	int num;
	if(strcmp(rank, "A") == 0) { num = 14; return num; }
        if(strcmp(rank, "K") == 0) { num = 13; return num; }
        if(strcmp(rank, "Q") == 0) { num = 12; return num; }
        if(strcmp(rank, "J") == 0) { num = 11; return num; }
	num = atoi(rank);
	return num;
}

char *to_word(char *letter) {
	char *word;
	if(strcmp(letter, "D") == 0) { word = "Diamonds"; return word; }
        if(strcmp(letter, "H") == 0) { word = "Hearts"; return word; }
        if(strcmp(letter, "S") == 0) { word = "Spades"; return word; }
        if(strcmp(letter, "C") == 0) { word = "Clubs"; return word; }

	if(strcmp(letter, "A") == 0) { word = "Ace"; return word; }
	if(strcmp(letter, "1") == 0) { word = "One"; return word; }
	if(strcmp(letter, "2") == 0) { word = "Two"; return word; }
	if(strcmp(letter, "3") == 0) { word = "Three"; return word; }
	if(strcmp(letter, "4") == 0) { word = "Four"; return word; }
        if(strcmp(letter, "5") == 0) { word = "Five"; return word; }
        if(strcmp(letter, "6") == 0) { word = "Six"; return word; }
        if(strcmp(letter, "7") == 0) { word = "Seven"; return word; }
	if(strcmp(letter, "8") == 0) { word = "Eight"; return word; }
        if(strcmp(letter, "9") == 0) { word = "Nine"; return word; }
        if(strcmp(letter, "10") == 0) { word = "Ten"; return word; }
        if(strcmp(letter, "J") == 0) { word = "Jack"; return word; }
	if(strcmp(letter, "Q") == 0) { word = "Queen"; return word; }
        if(strcmp(letter, "K") == 0) { word = "King"; return word; }

	return letter;
}

char high_card(const char *two[2]) {
	printf("%s\n", two[0]);
	int first = rank_to_num(two[0]);
	int second = rank_to_num(two[1]);
	if(first < second) { return *two[0]; }
	return *two[1];
}

char ***give_cards(int how_many, const char *cards[52][2]) {
    char ***yours = malloc(how_many * sizeof(char *));
    int selected[52] = {0};
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < how_many; i++) {
        int random;
        do {
            random = rand() % 52;
        } while (selected[random]);
        selected[random] = 1;
        char *suit = malloc(sizeof(char));
        char *rank = malloc(sizeof(char));
        *suit = cards[random][0][0];
        *rank = cards[random][1][0];
        char **card = malloc(2 * sizeof(char *));
        card[0] = suit;
        card[1] = rank;
        yours[i] = card;
    }
    return yours;
}

int to_pass_out() {

	int number_of_players;
	int community = 5;
	printf("How many players: ");
	scanf("%d", &number_of_players);
	printf("\n");
	int number_of_cards = 2 * number_of_players + community;
//	printf("%d cards will be distributed \n", number_of_cards);
	return number_of_cards;

}

int is_pair(char *first[2], char *second[2]) {
        if (strcmp(first[0], second[0]) == 0) {
                        if (strcmp(first[1], second[1]) == 0) {
                                printf("yes!\n");
                return 1;
                        }
        }
        return 0;
} 

int is_triple(char *first[2], char *second[2], char *third[2]) {
        if (strcmp(first[0], second[0]) == 0) {
                        if (strcmp(first[1], second[1]) == 0) {
                                printf("yes!\n");
                return 1;
                        }
        }
        return 0;
} 

