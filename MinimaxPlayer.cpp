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


int MiniMaxDecision(OthelloBoard *b, int& col, int&row){
	MAX_VALUE(b, col, row);
	return 0;
}


int MAX_VALUE(OthelloBoard *b, int& col, int& row){
	int cntSuccessors = 0;
	int v = -9999;
	int result_col = 0;
	int result_row = 0;
	for (int i = 0; i < 4; i++){
		for (int x = 0; x < 4; x++){
			if (b->is_legal_move(i, x, 'O')){

				//printf("c:%d r:%d \n", i, x);
				OthelloBoard *c = new OthelloBoard(*b);
				c->play_move(i, x, 'O');
				cntSuccessors++;
				//v = std::max(v, MIN_VALUE(c, col, row));
				if (MIN_VALUE(c, col, row) > v){
					v = MIN_VALUE(c, col, row);
					result_col = i;
					result_row = x;
				}
			}
		}
	}
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
	for (int i = 0; i < 4; i++){
		for (int x = 0; x < 4; x++){
			if (b->is_legal_move(i, x, 'X')){

				//printf("c:%d r:%d \n", i, x);
				OthelloBoard *c = new OthelloBoard(*b);
				c->play_move(i, x, 'X');
				cntSuccessors++;
				//v = std::min(v, MAX_VALUE(c, col, row));
				//col = i;
				//row = x;
				if (MIN_VALUE(c, col, row) < v){
					v = MIN_VALUE(c, col, row);
					result_col = i;
					result_row = x;
				}
			}
		}
	}
	if (cntSuccessors == 0){
		return b->count_score('O') - b->count_score('X');
	}

	col = result_col;
	row = result_row;
	return v;
}
void MinimaxPlayer::get_move(OthelloBoard *b, int& col, int& row) {
    // To be filled in by you
	//while (1){


		printf("get computer move\n");
		for (int i = 0; i < 4; i++){
			for (int x = 0; x < 4; x++){
				if (b->is_legal_move(i, x, 'O')){

					printf("c:%d r:%d \n", i, x);
					col = i;
					row = x;
				}
			}
		}
		MiniMaxDecision(b, col, row);
		printf("\ncomputer picked to play c:%d r:%d \n", col, row);
		//OthelloBoard *c = new OthelloBoard(*b);
		//c->play_move(col, row, 'O');
		////c->display;
		//printf("get computer move\n");
		//for (int i = 0; i < 4; i++){
		//	for (int x = 0; x < 4; x++){
		//		if (c->is_legal_move(i, x, 'O')){
		//			printf("c:%d r:%d \n", i, x);
		//			col = i;
		//			row = x;
		//		}
		//	}
		//}

		//printf("get computer move\n");
		//for (int i = 0; i < 4; i++){
		//	for (int x = 0; x < 4; x++){
		//		if (b->is_legal_move(i, x, 'O')){
		//			printf("c:%d r:%d \n", i, x);
		//			col = i;
		//			row = x;
		//		}
		//	}
		//}

		printf("X score = %d\n", b->count_score('X'));
		printf("O score = %d\n", b->count_score('O'));
		printf("O - X = %d\n\n", b->count_score('O') - b->count_score('X'));
		//getchar();
		//getchar();
	//}

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
