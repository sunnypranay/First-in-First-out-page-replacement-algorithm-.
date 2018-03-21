#include<iostream>
using namespace std;
class page_table
{
public:
    int no_of_pages,no_of_frames,page_fault=0;
    int j=0;
    int pages[100];
    int frames[100];
    page_table(int a,int b)
    {
        no_of_pages=a;
        no_of_frames=b;
        for(int i=0;i<no_of_frames;i++)
        {
            frames[i]=0;
        }
    }
    void get_pages()
    {
        cout<<"Enter the pages one after the another\n";
        for(int i=0;i<no_of_pages;i++)
        {
            cin>>pages[i];
        }
    }
    bool check(int j1)
    {
        for(int i1=0;i1<no_of_frames;i1++)
        {
            if(frames[i1]==pages[j1])
            {
                return true;
            }
        }
        return false;
    }
    int fifo()
    {
        int i=0;
        for(j=0;j<no_of_pages;i++,j++)
        {
            if(check(j)==true)
            {
                continue;
            }
            else
            {
                frames[i]=pages[j];
                i=(i+1)%no_of_frames;
                page_fault++;
            }
            }
            return page_fault;
        }


};
int main()
{
    int a,b,c;
    cout<<"Enter the number of pages:\n";
    cin>>a;
    cout<<"Enter the number of frames:\n";
    cin>>b;
    page_table p(a,b);
    p.get_pages();
    cout<<"The no.of page fault is"<<p.fifo();

}
