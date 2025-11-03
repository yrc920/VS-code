from pymysql import Connection
conn = Connection(
    host='localhost',
    port=3306,
    user='root',
    password='0207',
)

print(conn.get_server_info())
conn.close()
