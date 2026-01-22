import sqlite3
class TableCreator:
    def __init__(self, db_name):
        self.connect = sqlite3.connect(db_name)
        self.cursor = self.connect.cursor()
    def create_table(self, table_name):
        command = f"DROP TABLE IF EXISTS {table_name}"
        self.cursor.execute(command)

        query = f"""CREATE TABLE {table_name}
                    (ID INT PRIMARY KEY,
                     First_name VARCHAR(25) NOT NULL,
                     Last_name VARCHAR(25),
                     Email VARCHAR(50) NOT NULL )"""
        
        self.cursor.execute(query)
        self.connect.commit()
        print("Created table successfully")

    def insert_table_content(self, table_name, id_data, first, email, last=None):
        command = f"""INSERT INTO {table_name}
                    VALUES (?,?,?,?)"""
        self.cursor.execute(command,(id_data, first, last, email))
        self.connect.commit()
        print("Data inserted successfully")

    def delete_table_content(self, table_name, first):
        command = f"""DELETE FROM {table_name} 
                    WHERE First_name = ?"""
        self.cursor.execute(command,(first,))
        self.connect.commit()
        print("Data deleted from table content successfully")

        
    def delete_table(self, table_name):
        command = f"""DROP TABLE IF EXISTS {table_name}"""
        self.cursor.execute(command)
        self.connect.commit()
        print("Table deleted successfully")
        
    def read_table(self, table_name):
        command = f"""SELECT * FROM {table_name}"""
        self.cursor.execute(command)
        output = self.cursor.fetchall()
        for data in output:
            print(data)
        self.connect.commit()
        print("Read all data in the table")

    def close(self):
        self.cursor.close()
        self.connect.close()
        print("Closed connection successfully")

