from Tablecreator import TableCreator
def main():
    obj = TableCreator("datatable.db")
    obj.create_table("information")
    obj.insert_table_content("information" , 1,"shiva", "abc@gmail.com","chinduja")
    obj.read_table("information")
    obj.insert_table_content("information",2,"abc", "ghj@gmail.com","ghj")
    obj.read_table("information")
    obj.delete_table_content("information","abc")
    obj.read_table("information")
    obj.delete_table("information")
    obj.close()
if __name__ == "__main__":
    main()