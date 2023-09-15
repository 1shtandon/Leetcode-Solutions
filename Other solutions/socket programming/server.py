import socket
import uuid
from threading import Thread

host = "localhost"
port = 8080

sock = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET , socket.SO_REUSEADDR , 1)
sock.bind((host , port))

groups = {}
users = {}


def accept_conn():
    while True:
        conn , addr = sock.accept()
        print(f"connected successfully" , addr)
        users[conn] = (uuid.uuid4() , addr)
        conn.send(bytes(f"You have been assigned with {users[conn][0]} as id\n" , "utf8"))
        t = Thread(target=join_group, args=(conn,))
        t.start()
        

# def echo_msg(conn):
#     while True:
#         msg = conn.recv(1024).decode()
#         conn.send(bytes(msg , "utf8"))

def join_group(conn):
    conn.send(bytes("Enter group id (if not exists new group will be made): \n" , "utf8"))
    grp_id = conn.recv(1024).decode()
        
    if grp_id in groups:
        groups[grp_id][1].append(conn)
    else:
        groups[grp_id] = [[] ,[conn]]
        
        
    # recover chats
    conn.send(bytes("\n".join(groups[grp_id][0]), 'utf8'))

    t = Thread(target=broadcast_msg , args=(conn , grp_id))
    t.start()
    
    
def broadcast_msg(conn , grp_id):
    while True:
        msg = conn.recv(1024).decode()
        if msg == "exit":
            groups[grp_id][1].remove(conn)
            conn.close()
            print(f"{users[conn][1]} left us")
            break
            
        elif  msg == "leave":
            groups[grp_id][1].remove(conn)
            join_group(conn)
            break
        
        msg = f"{users[conn][0]} : {msg}"
        groups[grp_id][0].append(msg)
        for client in groups[grp_id][1]:
            client.send(bytes(msg , "utf8"))
    

if __name__ == "__main__":
    sock.listen()
    print(f"Server is listening to {host}:{port}")
    
    t = Thread(target=accept_conn)
    t.start()
    t.join()
    