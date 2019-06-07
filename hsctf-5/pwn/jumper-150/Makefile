init: clean all

all:
	gcc -m32 -fno-stack-protector -z execstack jumper.c -o jumper

permissions:
	chown ctfadmin:ctfadmin flag
	chmod 0400 flag

	chown ctfadmin:ctfadmin jumper.c
	chmod 0400 jumper.c

	chown ctfadmin:ctfadmin Makefile
	chmod 0400 Makefile

	chown ctfadmin:ctfadmin jumper
	chmod 0555 jumper

	chown ctfadmin:ctfadmin jumper.xinetd
	chmod 0444 jumper.xinetd

	xinetd -f jumper.xinetd -filelog log

full: all permissions

clean: 
	rm -f jumper