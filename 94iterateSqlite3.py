# SQL injection safe
# import sqlite3
# database = 'testcsv.db'
# usrinput = input("Search name: ")
# connectdb = sqlite3.connect(database)
# cursor = connectdb.cursor()
# cursor.execute("SELECT * FROM testcsv WHERE name = ?", (usrinput,))
# rows = cursor.fetchall()
# for row in rows:
#     print(row)
# cursor.close()
# connectdb.close()

# # Search sqlite3 without user input
# import sqlite3
# database = 'testcsv.db'
# connectdb = sqlite3.connect(database)
# cursor = connectdb.cursor()
# cursor.execute("SELECT * FROM testcsv WHERE name = 'Davor'")
# rows = cursor.fetchall()
# for row in rows:
#     print(row)
# cursor.close()
# connectdb.close()

# SQL injection vunerability: if user input is example Davor'-- 
# then all Py code after -- is by SQL ignored
import sqlite3
database = 'testcsv.db'
usrinput = input("Search name (SQL injection vunerable if possible): ")
connectdb = sqlite3.connect(database)
cursor = connectdb.cursor()
cursor.execute(f"SELECT * FROM testcsv WHERE name = '{usrinput}' AND password = 'Somepassword'")
rows = cursor.fetchall()
for row in rows:
    print(row)
cursor.close()
connectdb.close()