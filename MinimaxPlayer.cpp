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
#include <algorithm>>

using std::vector;

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}


int MiniMaxDecision(OthelloBoard *b, int& col, int&row){

	//std::list<OthelloBoard> succesors;

	//for (int i = 0; i < 4; i++){
	//	for (int x = 0; x < 4; x++){
	//		if (b->is_legal_move(i, x, 'O')){
	//			succesors.push_back()
	//			printf("c:%d r:%d \n", i, x);
	//			col = i;
	//			row = x;
	//			OthelloBoard *c = new OthelloBoard(*b);
	//			c->play_move(col, row, 'O');
	//		}
	//	}
	//}
	return 0;
}
//int MIN_VALUE(std::unordered_map<char, node> hashTable, char state);
//
//int MAX_VALUE(std::unordered_map<char, node> hashTable, char state){
//	node cur_state = hashTable[state];
//	if (cur_state.succesors.empty()){
//		return cur_state.utility_value;
//	}
//	int v = -9999;
//	//for each successor states
//	for (std::list<char>::iterator it = cur_state.succesors.begin(); it != cur_state.succesors.end(); it++){
//		char temp = *it;
//		v = std::max(v, MIN_VALUE(hashTable, temp));
//	}
//	return v;
//}

//int MIN_VALUE(std::unordered_map<char, node> hashTable, char state){
//	node cur_state = hashTable[state];
//	if (cur_state.succesors.empty()){
//		return cur_state.utility_value;
//	}
//	int v = 9999;
//	//for each successor states
//	for (std::list<char>::iterator it = cur_state.succesors.begin(); it != cur_state.succesors.end(); it++){
//		char temp = *it;
//		v = std::min(v, MAX_VALUE(hashTable, temp));
//	}
//	return v;
//}
void MinimaxPlayer::get_move(OthelloBoard *b, int& col, int& row) {
    // To be filled in by you
	while (1){


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

		OthelloBoard *c = new OthelloBoard(*b);
		c->play_move(col, row, 'O');
		//c->display;
		printf("get computer move\n");
		for (int i = 0; i < 4; i++){
			for (int x = 0; x < 4; x++){
				if (c->is_legal_move(i, x, 'O')){
					printf("c:%d r:%d \n", i, x);
					col = i;
					row = x;
				}
			}
		}

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

		getchar();
		getchar();
	}

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
