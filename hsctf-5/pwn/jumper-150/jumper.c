#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void lol() {
	system("/bin/cat /home/ctfadmin/HSCTF-Problems/jumper/flag" /*|        | o */);
}						  										/*|        |/|\ look it's keith! */
						  										/*|        |/ \ great jumper, he is*/
						  										/*|        | */
void jumper() {			  										/*|        | */
	char dest[32];		  										/*|        | */
	printf("Gimme some input: ");								/*|        | */
	gets(dest);			  										/*|        | */
	printf("Jumping to %s\n", dest);							/*|        | */
}						  										/*|        | */
						  										/*|        | */
int main() {													/*|        | */
	setbuf(stdout, NULL);			  							/*|        | */
	gid_t gid = getegid();										/*|        | */
	setresgid(gid,gid,gid);										/*|        | */
	jumper();			  										/*|        | */
}						  										/*|        | */
