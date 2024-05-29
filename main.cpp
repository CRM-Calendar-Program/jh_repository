#include <iostream>
#include "data_handler.h"
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

int main()
{
    string filename = "test1.csv";
    DataHandler DB;

    DB.ReadCSV(filename);
    
    cout << DB.GetData(0) << endl;

    return 0;
}