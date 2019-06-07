#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//im noob

typedef struct alarm_t {
	unsigned int seconds;
	char name[40];
	void (* ring)();
	void (* qbe)();
} alarm_t;

typedef struct radio_t {
	unsigned int station;
	char name[52]; // 12 > 8 ;)
	void (* play)();
	void (* qbe)();
} radio_t;

alarm_t *alarm;
radio_t *radio;

void __ring() {
	puts("Brrrrring!");
}

void __play() {
	puts("Gentle music plays from the radio's speakers.");
}

void __qbe() {
	//TODO
	puts(";)");
}

void create_alarm(char *inp_name) {
	if (strstr(inp_name, "%s") || strstr(inp_name, "%x") || strstr(inp_name, "%n") || strstr(inp_name, "%p") || strstr(inp_name, "%d") || strstr(inp_name, "$s") || strstr(inp_name, "$x") || strstr(inp_name, "$n") || strstr(inp_name, "$p") || strstr(inp_name, "$d") || strstr(inp_name, "$hn") || strstr(inp_name, "$hhn") || strstr(inp_name, "%hn") || strstr(inp_name, "%hhn")) {
		printf("ERROR: Format string attack detected!\n");
		exit(1);
	} else {
		alarm = (alarm_t *)malloc(sizeof(alarm_t));
		alarm->ring = __ring;
		alarm->qbe = __qbe;
		strncpy(alarm->name, inp_name, 40);
		alarm->name[39] = '\0'; //terminate correctly
		printf("Alarm created with name %s\n", alarm->name);
	}
}

void create_radio(char *inp_name) {
	if (strstr(inp_name, "%s") || strstr(inp_name, "%x") || strstr(inp_name, "%n") || strstr(inp_name, "%p") || strstr(inp_name, "%d") || strstr(inp_name, "$s") || strstr(inp_name, "$x") || strstr(inp_name, "$n") || strstr(inp_name, "$p") || strstr(inp_name, "$d") || strstr(inp_name, "$hn") || strstr(inp_name, "$hhn") || strstr(inp_name, "%hn") || strstr(inp_name, "%hhn")) {
		printf("ERROR: Format string attack detected!\n");
		exit(1);
	} else {	
		radio = (radio_t *)malloc(sizeof(radio_t));
		radio->play = __play;
		radio->qbe = __qbe;
		strncpy(radio->name, inp_name, 52);
		radio->name[51] = '\0'; //terminate correctly
		printf("Radio created with name %s\n", radio->name);
	}
}

void alarm_name() {
	if (alarm != NULL) {
		printf("Alarm name: ");
		printf(alarm->name);
		printf("\n");
	} else {
		puts("ERROR: Can't print name of alarm that doesn't exist!");
	}
}

void radio_name() {
		if (radio != NULL) {
		printf("Radio name: ");
		printf(radio->name);
		printf("\n");
	} else {
		puts("ERROR: Can't print name of radio that doesn't exist!");
	}
}

void alarm_delete() {
	if (alarm != NULL) {
		//check if alarm exists
		//can't delete something already freed!
		memset(alarm, 0, sizeof(alarm_t)); // securely erase alarm data, including beginning ;))
		free(alarm); //delete
		puts("Alarm deleted!");
	} else {
		puts("ERROR: Can't delete alarm that doesn't exist!");
	}
}

void radio_delete() {
	if (radio != NULL) {
		memset(radio, 0, sizeof(radio_t)); // securely erase radio data, including beginning
		free(radio);
		puts("Radio deleted!");
	} else {
		puts("ERROR: Can't delete radio that doesn't exist!");
	}
}

void what() {
	gid_t gid = getegid();
	setresgid(gid,gid,gid);
	system("/bin/cat /home/ctfadmin/HSCTF-Problems/alarm/flag");
}

void alarm_ring() {
	if (alarm != NULL && alarm->ring != NULL) {
		//make sure the alarm exists and has not been "deleted"
		alarm->ring();
	} else {
		puts("ERROR: Alarm does not exist, nothing to ring!");
	}

}

void radio_play() {
	if (radio != NULL && radio->play != NULL) {
		//make sure the radio exists and has not been deleted
		radio->play();
	} else {
		puts("ERROR: Radio does not exist, nothing to play!");
	}
}

void set_alarm(char* inp) {
	if (alarm != NULL) {
		alarm->seconds = strtol(inp, NULL, 10);
		printf("Alarm initialized to %d seconds!\n", alarm->seconds);
	} else {
		puts("ERROR: Alarm does not exist, nothing to set!");
	}
}

void set_station(char* inp) {
	if (radio != NULL) {
		radio->station = strtol(inp, NULL, 10);
		printf("Radio initialized to the station %d!\n", radio->station);
	} else {
		puts("ERROR: Radio does not exist, nothing to set!");
	}
}

void help() {
	puts("----------------------------------------------");
	puts("a <char[]:name> - 	create a new [a]larm");
	puts("r <char[]:name> - 	create a new [r]adio");
	puts("h               - 	show [h]elp");
	puts("x               - 	e[x]it the program");
	puts("----------------------------------------------");
	puts("if an alarm or radio has been created:");
	puts("d               - 	[d]elete an alarm");
	puts("i               - 	r[i]ng alarm");
	puts("n               - 	show alarm [n]ame");
	puts("s <int:seconds> - 	[s]et alarm time");
	puts("----------------------------------------------");
	puts("e               - 	d[e]lete a radio");
	puts("m               - 	show radio na[m]e");
	puts("o               - 	turn [o]n radio");
	puts("t <int:station> - 	se[t] radio station");
	puts("----------------------------------------------");
}

void loop() {
	help();
	char inp[1024];
	while (1) {
		printf("\nAction: \n$ ");
		char *result = fgets(inp, 1024, stdin);
        if (!result) exit(1);
        char *type = strtok(result, " ");
        if (type == NULL) continue;
        char *arg = strtok(NULL, "\n");
        if (arg != NULL && strlen(arg) > 60) 
        	arg[60] = '\0' 	;
        switch (type[0]) {
        	case 'a':
        		if (arg != NULL) {
        			create_alarm(arg);
        		} else {
        			printf("Error: no name provided.\n");
        		}
        		break;
        	case 'd':
        		alarm_delete();
        		break;
        	case 'e':
        		radio_delete();
        		break;
        	case 'i':
        		alarm_ring();
        		break;
        	case 'm':
        		radio_name();
        		break;
        	case 'n':
        		alarm_name();
        		break;
        	case 'o':
        		radio_play();
        		break;
        	case 'r':
        		if (arg != NULL) {
        			create_radio(arg);
        		} else {
        			printf("Error: no name provided.\n");
        		}
        		break;
        	case 's':
        		if (arg != NULL) {
        			set_alarm(arg);
        		} else {
        			printf("Error: no time provided.\n");
        		}
        		break;
        	case 't':
        		if (arg != NULL) {
        			set_station(arg);
        		} else {
        			printf("Error: no station provided.\n");
        		}
        		break;
        	case 'x':
        		exit(0);
        		break;
        	default:
        		puts("Unknown command.");
        	case 'h':
        		help();
        		break;
        }
	}
}

int main(int argc, const char * argv[]) {
	setbuf(stdout, NULL);
	loop();
	return 0;
}

