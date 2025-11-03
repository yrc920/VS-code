if __name__ == "__main__":    
    import socket

    socket_client = socket.socket()
    # 连接服务端
    socket_client.connect(('localhost', 8888))
    print("成功连接到服务端")

    while True:
        msg = input("请输入要发送给服务端的数据: ")
        if msg == "exit":
            break
        socket_client.send(msg.encode("UTF-8"))
        recv_data = socket_client.recv(1024).decode("UTF-8")
        print(f"接收到了服务端发送的数据: {recv_data}")

    # 关闭链接
    socket_client.close()

