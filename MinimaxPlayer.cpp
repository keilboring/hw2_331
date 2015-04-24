/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"
#include <list>
#include <unordered_map>
#include <algorithm>

using std::vector;

int MIN_VALUE(OthelloBoard *b, int& col, int& row);
int MAX_VALUE(OthelloBoard *b, int& col, int& row);

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

// I assumed that computer player is player 'O' and is trying to Maximize
//    while human player is first and is 'X' and is trying to Minimize
//    Also assumed computer player plays second.
int MiniMaxDecision(OthelloBoard *b, int& col, int&row){
	MAX_VALUE(b, col, row);
	return 0;
}


int MAX_VALUE(OthelloBoard *b, int& col, int& row){
	int cntSuccessors = 0;
	int v = -9999;
	int result_col = 0;
	int result_row = 0;

	//Generate successors
	for (int i = 0; i < 4; i++){
		for (int x = 0; x < 4; x++){
			if (b->is_legal_move(i, x, 'O')){

				OthelloBoard *c = new OthelloBoard(*b);
				c->play_move(i, x, 'O');
				cntSuccessors++;
				if (MIN_VALUE(c, col, row) > v){
					v = MIN_VALUE(c, col, row);
					result_col = i;
					result_row = x;
				}
			}
		}
	}
	//Utility function
	if (cntSuccessors == 0){
		return b->count_score('O') - b->count_score('X');
	}
	col = result_col;
	row = result_row;
	return v;
}

int MIN_VALUE(OthelloBoard *b, int& col, int& row){
	int cntSuccessors = 0;
	int v = 9999;
	int result_col = 0;
	int result_row = 0;

	//generate successors
	for (int i = 0; i < 4; i++){
		for (int x = 0; x < 4; x++){
			if (b->is_legal_move(i, x, 'X')){

				OthelloBoard *c = new OthelloBoard(*b);
				c->play_move(i, x, 'X');
				cntSuccessors++;
				if (MIN_VALUE(c, col, row) < v){
					v = MIN_VALUE(c, col, row);
					result_col = i;
					result_row = x;
				}
			}
		}
	}
	//Utility function
	if (cntSuccessors == 0){
		return b->count_score('O') - b->count_score('X');
	}

	col = result_col;
	row = result_row;
	return v;
}
void MinimaxPlayer::get_move(OthelloBoard *b, int& col, int& row) {
		MiniMaxDecision(b, col, row);
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
