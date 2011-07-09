#include "cvt_table.h"
uint32 cvt_table::getSize(){
       return num*2;
};
void cvt_table::printTable(char* path){
     ofstream file;
     file.open(path,ios::binary|ios::app);
     cout<<"good file: "<<file.good()<<endl;
     for(uint16 i=0;i<num;i++){
           file<<(char)(instr[i]>>8)<<(char)(instr[i]%256);              
     };
     file.close();
};
void gener_cvt_table(cvt_table &ft){
     ft.num=rand()%255+1;
     ft.instr=new uint16[ft.num];
     for(uint16 i=0;i<ft.num;i++) ft.instr[i]=rand()%65535;
};