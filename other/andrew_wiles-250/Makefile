init: clean all

all:
	g++ fermat.cpp -o fermat

permissions:
	chown ctfadmin:ctfadmin fermat
	chmod 0555 fermat

	chown ctfadmin:ctfadmin fermat.cpp
	chmod 0400 fermat.cpp

	chown ctfadmin:ctfadmin Makefile
	chmod 0400 Makefile

	chown ctfadmin:ctfadmin fermat.xinetd
	chmod 0444 fermat.xinetd

	xinetd -f fermat.xinetd -filelog log

full: all permissions

clean:
	rm -f fermat
