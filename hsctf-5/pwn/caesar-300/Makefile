init: clean all

all:
	gcc -m32 -fno-stack-protector -z execstack caesar.c -o caesar

permissions:
	chown ctfadmin:ctfadmin flag
	chmod 0440 flag

	chown ctfadmin:ctfadmin caesar.c
	chmod 0400 caesar.c

	chown ctfadmin:ctfadmin Makefile
	chmod 0400 Makefile

	chown ctfadmin:ctfadmin caesar
	chmod 0555 caesar

	chown ctfadmin:ctfadmin caesar.xinetd
	chmod 0444 caesar.xinetd

	xinetd -f caesar.xinetd -filelog log

full: all permissions

clean:
	rm -f caesar