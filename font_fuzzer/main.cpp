#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
#include "cmap_table.h"
#include "font_directory_table.h"
#include "name_table.h"
int main(int argc, char *argv[])
{
    name_table nt=gener_name_table(4,"C:\\out.txt");
    ofstream file;
    file.open("C:\\txt.ttx",ios::binary|ios::app);
    cout<<"good file: "<<file.good()<<endl;
    //before writing each elemental strucrure divides into bytes, then writing to file
    //writing header
    file<<(char)(nt.format>>8)<<(char)(nt.format%256);
    file<<(char)(nt.count>>8)<<(char)(nt.count%256);
    file<<(char)(nt.stringOffset>>8)<<(char)(nt.stringOffset%256);
    //writing nameRecords
    for(int i=0;i<nt.count;i++){
            file<<(char)(nt.records[i].platformID>>8 )<<(char)(nt.records[i].platformID%256);
            file<<(char)(nt.records[i].platformSpecificID>>8 )<<(char)(nt.records[i].platformSpecificID%256);
            file<<(char)(nt.records[i].languageID>>8 )<<(char)(nt.records[i].languageID%256);
            file<<(char)(nt.records[i].nameID>>8 )<<(char)(nt.records[i].nameID%256);
            file<<(char)(nt.records[i].length>>8 )<<(char)(nt.records[i].length%256);
            file<<(char)(nt.records[i].offset>>8 )<<(char)(nt.records[i].offset%256);
    }
    file<<nt.name;
    file.close();
    cout<<name_table_size(nt)<<endl;
    system("PAUSE");
    
    return EXIT_SUCCESS;
}
