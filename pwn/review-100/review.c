#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	gid_t gid = getegid();
	setresgid(gid, gid, gid);

	int valid = 0;
	char buffer[32];
	int rating;

	puts("Welcome to the RottenPotatoes movie rating aggregator!\n");
	puts("What was the name of the last movie you watched?");
	gets(buffer);
	printf("You last watched:  %s\n", buffer);
	puts("What would you rate this movie (out of 10)?");
	//fflush(stdout);
	if (scanf("%d", &rating) != 1) {
		puts("Invalid rating.\n");
		exit(0);
	}
	printf("You rated %s a %d / 10.\n", buffer, rating);
	puts("\nSubmitting to central servers...");
	if (valid) {
		puts("\nThank you for using the RottenPotatoes movie rating aggregator!");
		puts("Here's a little reward for your efforts ;)\n");
		system("/bin/cat /home/ctfadmin/HSCTF-Problems/review/flag");
		puts("\nEnjoy!");
	} else {
		puts("ERROR: Review could not be submitted!");
		exit(0);
	}
}
