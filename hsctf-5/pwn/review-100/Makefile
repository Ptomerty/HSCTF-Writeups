init: clean all

all:
	gcc -fno-stack-protector -o review review.c

permissions:
	chown ctfadmin:ctfadmin flag
	chmod 0400 flag

	chown ctfadmin:ctfadmin Makefile
	chmod 0400 Makefile

	chown ctfadmin:ctfadmin review.c
	chmod 0400 review.c

	chown ctfadmin:ctfadmin review
	chmod 0555 review

	chown ctfadmin:ctfadmin review.xinetd
	chmod 0444 review.xinetd

	xinetd -f review.xinetd -filelog log

full: all permissions

clean: 
	rm -f review