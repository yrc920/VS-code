if __name__ == "__main__":    
    import socket

    socket_server = socket.socket()
    # 绑定IP地址和端口号
    socket_server.bind(('localhost', 8888))
    # 设置监听
    socket_server.listen(1)
    print("服务端启动成功, 等待客户端链接...")
    # 等待客户端链接
    conn, address = socket_server.accept()

    print(f"接收到了客户端的链接, 地址是: {address}")

    while True:
        data: str = conn.recv(1024).decode("UTF-8")
        print(f"接收到了客户端发送的数据: {data}")
        msg = input("请输入要发送给客户端的数据: ")
        if msg == "exit":
            break
        conn.send(msg.encode("UTF-8"))

    # 关闭链接    
    conn.close()
    socket_server.close()

