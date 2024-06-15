#include <iostream>
#include "data_handler.h"
#include "system_menu.h"
#include "libxl.h"
using namespace std;
using namespace libxl;

void WriteExcel(string filename)
{
    Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
    if (book)
    {
        Sheet* sheet = book->addSheet(L"Sheet1");
        if (sheet)
        {
            sheet->writeStr(2, 1, L"Hello, World !");
            sheet->writeNum(3, 1, 1000);
        }
        book->save(L"exemple.xls");
        book->release();
    }
}

int GetSize(string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 0;
    }

    int size = 0;
    string line;
    while (getline(file, line))
    {
        size++;
    }

    file.close();
    return size + 10;
}

int main()
{
    string filename = "test1.csv";
    string filename_o = "test2.csv";
    int size;

    size = GetSize(filename);
    DataHandler DB(size);
    DB.ReadCSV(filename);
    Display display(DB);
    display.ShowMenu();
    //int id = DB.FindClient("020110");
    DB.WriteCSV(filename_o);

    return 0;
}