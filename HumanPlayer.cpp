#include <iostream>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(char symb) : Player(symb) {

}

HumanPlayer::~HumanPlayer() {

}

void HumanPlayer::get_move(OthelloBoard *b, int& col, int& row) {
    std::cout << "Enter col: ";
    //std::cin >> col;
    std::cout << "Enter row: ";
   // std::cin >> row;
	for (int i = 0; i < 4; i++){
		for (int x = 0; x < 4; x++){
			if (b->is_legal_move(i, x, 'X')){
				//printf("c:%d r:%d \n", i, x);
				col = i;
				row = x;
			}
		}
	}
}

HumanPlayer* HumanPlayer::clone() {
	HumanPlayer *result = new HumanPlayer(symbol);
	return result;
}
