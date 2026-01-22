from http.server import BaseHTTPRequestHandler,HTTPServer
import json
from Tablecreator import TableCreator

class APIHandler(BaseHTTPRequestHandler):
    db = None
    def do_GET(self):

        if self.path.startswith("/read"):
            table_name = self.path.split("/read/")[1]
            self.read_data(table_name)
        else:
            self.send_error(404,"Not Found")

    def do_POST(self):
        if self.path.startswith("/insert/"):
            table_name = self.path.split("/insert/")[1]
            self.insert_data(table_name)
        else:
            self.send_error(404,"Not Found")
        
    def do_DELETE(self):
        
        if self.path.startswith("/delete/"):
            parts = self.path.split("/")
            if len(parts) == 4:
                table_name = parts[2]
                content = parts[3]
                self.delete_data(table_name,content)
            else:
                self.send_error(400, "Bad Request")
        else:
            self.send_error(404,"Not Found")
    
    #helper functions to read , insert and delete contents
    def read_data(self,table_name):
        self.send_response(200)
        self.send_headers("Content-type", "application/json")
        self.end_headers()
        self.db.cursor.execute(f"SELECT * FROM {table_name}")
        rows = self.db.cursor.fetchall()
        self.wfile.write(json.dumps(rows).encode())
    
    def insert_data(self,table_name):
        pass
    def delete_data(self,table_name, info):
        pass

    