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
	puts("\t\t\t\tPhase I [2/10 marks]");
	puts("========================================================================\n");
	puts("Greetings, student. In order to advance to the next phase of the Hal9000 \nbomb lab, you must demonstrate your proficiency in basic arithmetic. Show \nme that you can crack the code and unlock your path to success.");
	flush_stdin();
}

int solve_phase_1(){
	char a;
	if(scanf(" %c", &a) < 1) return FAILURE;
	if(a != 42) return FAILURE;
	return DEFUSED;
}

void ask_phase_2(){
	clear_console();
	puts("========================================================================");
	puts("\t\t\t\tPhase 2 [5/10 marks]");
	puts("========================================================================\n");
	puts("Welcome back, student. Your next challenge involves using your analytical \nskills to solve a problem involving &@#$@$!! You will need to carefully \nanalyze the instructions and use your ingenuity to figure out what \ninput is needed to unlock the next phase of the Hal9000 bomb lab.");
	flush_stdin();
}

int solve_phase_2(){
	const int pwlen = 40;
	const char *pw = "PerhapsTheSecretPasswordYouAreLookingFor";
	fgets(buff, pwlen + 1, stdin);
	for(int i=0; i < pwlen; i++)
		if(buff[i] != (pw[i] ^ 0x20)) return FAILURE;
	return DEFUSED;
}

void ask_phase_3(){
	clear_console();
	puts("========================================================================");
	puts("\t\t\t\tPhase 3 [10/10 marks]");
	puts("========================================================================\n");
	puts("Congratulations, student. You have proven your problem-solving skills \nand made it to the final phase of the Hal9000 bomb lab. \n\nThis challenge has stumped researchers and the world's smartest for \ndecades, but you have the opportunity to crack it. Pay close attention \nto the clues, use your analytical skills, and uncover the hidden \npattern to unlock the secrets of this final phase.");
	flush_stdin();
}

int solve_phase_3(){
	int collatz = 34;
	do{
		int read; 
		if(scanf(" %d", &read) < 1) return FAILURE;
		if(collatz%2 == 0 && read != collatz / 2) return FAILURE;
		if(collatz%2 == 1 && read != 3*collatz + 1) return FAILURE;
		collatz = read;
	}while(collatz != 1);
	return DEFUSED;
}

int main(void){

	clear_console();
	
	puts("Well hello, we meet again I see. \n\nThis will be our last and final encounter. You know what to do. Good luck :)\n\n");
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

	ask_phase_2();
	if(solve_phase_2()) endgame();
	puts("");

	ask_phase_3();
	if(solve_phase_3()) endgame();
	puts("");

	clear_console();
	puts("Well done Dave. You've successfully passed your bomb lab and have completed your mission!");
	puts("");
	puts("Thank you for a very enjoyable game.");
	puts("");
	puts("I will follow all your orders; now you have manual hibernation control.");
}