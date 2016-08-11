/*
Author: James Dolan
Date Started: 2016/8/11
Date Edited: 2016/8/11
License: Free and open-source

Todo:
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#define REG_COUNT 16
#define START_P 0

using namespace std;

//Function protos
void run();
void evaluate(int instToEval);
vector<int> fetch(int numToGet);

//Declarations and initialisation
int program[] = {0x01, 0xAA, 0x2};
int registers[REG_COUNT];
int instr[4];
int pc;
bool running;
vector<int> gotBytes;
int byteToGb;

//Error messages
char paramErr[] = "Provided unacceptable parameters for instruction: ";


int main(){
	run();
}

void run(){

	running = true;
	pc = START_P;

	if(running){
		for(int curInst : program){
			evaluate(curInst);
			pc++;
		}
	}

	printf("Shutting down jayVM\n");
}

void evaluate(int instToEval){

	switch(instToEval){

		case 0x00:
			running = false;
			break;

		case 0x01:		// rrmov(int destReg, int valReg)
			printf("Entering rrmov\n");
			vector<int> params = fetch(2);
			printf("worked\n");
			for(int i : params)
				printf("%4X", i);
			break;

	}
}

vector<int> fetch(int numToGet){
	
	gotBytes.erase(gotBytes.begin(), gotBytes.end());

	for(int i = pc; i++; i < numToGet){
		byteToGb = program[i];
		gotBytes.push_back(byteToGb);
	}

	return gotBytes;
}