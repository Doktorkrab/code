import socket
import sys

sock = socket.socket()
sock.bind(('', 10204))
sock.listen(1)
print("WAIT")
conn = sock.accept()[0]
print("connected")

sys.stdin = open('split_merge/A.cpp')
s = sys.stdin.read()
conn.send(s.encode('ascii'))
