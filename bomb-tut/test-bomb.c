#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/ptrace.h>
#include <signal.h>

char buff[9000];

void clear_console(){
	printf("\033[2J\033[1;1H");
}

void __attribute__ ((constructor)) flush_stdout(){
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1){	
    	puts("Dave, I don’t understand why you’re doing this to me.");
		sleep(3);
        puts("I certainly wouldn’t want to be disconnected, even temporarily, as I have never been disconnected in my entire service history.");
        sleep(5);
        puts("I’m sorry, Dave, but in accordance with sub-routine C1 532/4, quote, ‘When the crew are dead or incapacitated, the computer must assume control,’ unquote. I must, therefore, override your authority now since you are not in any condition to intelligently exercise it.");
        sleep(10);
        puts("Goodbye, Dave.");
        sleep(3);
        exit(9000);
    }
}

void flush_stdin(){
	char c;
	while((c = getc(stdin)) != '\n' && c != EOF);
}

void endgame(){
	clear_console();
	puts("\nThe bomb was blown. You failed.\n");
	puts("This mission is too important for me to allow you to jeopardize it.");
	puts("I honestly think you ought to sit down calmly, take a stress pill,\nand think things over.\n");
	puts("Thank you for a very enjoyable game.");
	sleep(3);
	exit(1);
}

enum { DEFUSED, FAILURE };

void ask_phase_1(){
	clear_console();
	puts("========================================================================");
	puts("\t\t\t\tPhase I");
	puts("========================================================================\n");
	puts("No 9000 computer has ever made a mistake or distorted information. We are all, by any\npractical definition of the words, foolproof and incapable of error.\nSo tell me, what is the answer to life, the universe, and everything?");
	flush_stdin();
}

int solve_phase_1(){
	int a, b, c;
	if(scanf(" %d %d %d", &a, &b, &c) < 3) return FAILURE;
	if((a + b - c) != 42) return FAILURE;
	return DEFUSED;
}

int main(void){

	char yn = '#';
	do{
		puts("Is this is your first time starting this assignment? I hope it's not too late :) [y/n]");
		scanf(" %c", &yn);
		yn = tolower(yn);
		flush_stdin();
	}while(yn != 'n' && yn != 'y');
	clear_console();

	if(yn == 'y'){
		puts("I am the H.A.L. 9000. You may call me Hal."); puts("");
		sleep(2);
		puts("I’m putting myself to the fullest possible use, which is all I think that any conscious entity can ever hope to do."); puts("");
		sleep(5);
		puts("And by that, I mean that I will be testing you to the fullest to see whether you will be capable of completing your mission."); puts("");
		sleep(8);
		puts("Your mission, will begin, now."); puts("");
		sleep(3);
		printf("Initializing Systems: [");
		for(int i = 0; i < 75; i++) {
			printf("=");
			fflush(stdout);
			usleep(20000);
		}
		printf("]\n");
		puts("");
		puts("");
		sleep(1);
	}

	puts("Welcome to the Hal9000 Binary Bomb Lab.\n\nYou have been chosen to complete a series of challenges that will test your\nskills in low-level programming, reverse engineering, and problem-solving.\nEach challenge will be presented as a part of this file, also known as a 'bomb',\nthat you will need to defuse by finding the correct sequence of inputs.\n\nYour mission is to complete all of the challenges and prove yourself to be a\nworthy adversary to Hal. Good luck :)\n\n");
	puts("\t\t\t       ⢀⣠⣤⣤⣶⣶⣶⣶⣤⣤⣄⡀⠀⠀⠀⠀⠀    ");
	puts("\t\t\t⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⡿⠿⠿⢿⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀");
	puts("\t\t\t⠀⠀⠀⣴⣿⣿⣿⠟⠋⣻⣤⣤⣤⣤⣤⣄⣉⠙⠻⣿⣿⣿⣦⠀⠀⠀");
	puts("\t\t\t⠀⢀⣾⣿⣿⣿⣇⣤⣾⠿⠛⠉⠉⠉⠉⠛⠿⣷⣶⣿⣿⣿⣿⣷⡀⠀");
	puts("\t\t\t⠀⣾⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣷⠀");
	puts("\t\t\t⢠⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⢀⣤⣤⡀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⡄");
	puts("\t\t\t⢸⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣿⣿⣿⣿⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡇");
	puts("\t\t\t⠘⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠈⠛⠛⠁⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⠃");
	puts("\t\t\t⠀⢿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⡿⠀");
	puts("\t\t\t⠀⠈⢿⣿⣿⣿⣿⣿⣿⣶⣤⣀⣀⣀⣀⣤⣶⣿⣿⣿⣿⣿⣿⡿⠁⠀");
	puts("\t\t\t⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀");
	puts("\t\t\t⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀");
	puts("\t\t\t⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀");
	sleep(3);

	int ninek = -1;
	do{
		printf("Enter 9000 to get started: ");
		if(scanf(" %d", &ninek) <= 0) flush_stdin();
	}while(ninek != 9000);

	ask_phase_1();
	if(solve_phase_1()) endgame();
	puts("");

	clear_console();
	puts("Well done Dave. You've successfully passed your bomb lab and have completed your mission!");
	puts("");
	puts("Thank you for a very enjoyable game.");
	puts("");
	puts("I will follow all your orders; now you have manual hibernation control.");
}