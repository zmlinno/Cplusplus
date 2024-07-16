#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
static inline size_t _RoundUp(size_t bytes,size_t alignNum)
{
    return((bytes+alignNum-1)& ~(alignNum-1));
}


//演示对齐分配
void demonsTrateAlignment(size_t size,size_t alignNum)
{
    size_t alignSize = _RoundUp(size,alignNum);
    cout<<"Original size:" << size << "bytes" <<endl;
    cout<<"Alignen to" << alignNum << "bytes" <<alignSize<<"bytes"<<endl;
}
int main()
{
    //原始内存块大小
    size_t size1 = 13;
    size_t size2 = 512;

    //对齐大小
    size_t align2 = 2;
    size_t align8 = 8;
    size_t align16 = 16;


    //演示不同对齐方式
    cout<<"Alignment to 2 bytes:"<<endl;
    demonsTrateAlignment(size1,align2);
    demonsTrateAlignment(size2,align2);

    cout<<"\nAlignment to 8 bytes:"<<endl;
    demonsTrateAlignment(size1,align8);
    demonsTrateAlignment(size2,align8);

    cout<<"\nAlignment to 16 bytes:"<<endl;
    demonsTrateAlignment(size1,align16);
    demonsTrateAlignment(size2,align16);
    return 0;
}