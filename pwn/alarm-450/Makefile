init: clean all

all:
	gcc alarm.c -o alarm -pie -fPIE -O3

permissions:
	chown ctfadmin:ctfadmin flag
	chmod 0400 flag

	chown ctfadmin:ctfadmin alarm.c
	chmod 0400 alarm.c

	chown ctfadmin:ctfadmin Makefile
	chmod 0400 Makefile

	chown ctfadmin:ctfadmin alarm
	chmod 0555 alarm

	chown ctfadmin:ctfadmin alarm.xinetd
	chmod 0444 alarm.xinetd

	xinetd -f alarm.xinetd -filelog log

full: all permissions

clean: 
	rm -f alarm
