#include "libxl.h"
using namespace libxl;

int main()
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
        book->save(L"example.xls");
        book->release();
    }
    return 0;
}