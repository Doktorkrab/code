import socket

sk = socket.socket()
sk.connect(('10.15.101.212', 10205))
s = sk.recv(10000)

while s == '':
    s = sk.recv(100000000000)
f = open('time1', 'wb')

f.write(s)
