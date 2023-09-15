import socket

from threading import Thread

host = "localhost"
port = 8080

sock = socket.socket(socket.AF_INET , socket.SOCK_STREAM)

sock.connect((host , port))


def receive_msg():
    while True:
        msg = sock.recv(1024).decode()
        print(msg)
        
def send_msg(msg):
    sock.send(bytes(msg , "utf8"))
    
        
        
        

if __name__ == "__main__":
    print(f"Connected successfully to {host}:{port}")
    t = Thread(target=receive_msg)
    t.start()
    
    while True:
        msg = input()
        send_msg(msg)
    
    