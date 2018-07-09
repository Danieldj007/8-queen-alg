#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class chess
{public:
int  n,x,c,z,pos1,pos2,i,j,a[8][8],b[8][8],t1,t2;
public:
chess()
{
for(i=0;i<8;i++)
{for(j=0;j<8;j++)
{a[i][j]=0;
b[i][j]=0;
}
}
i=0;
}
void draw();
void getdata();
void check();
void set();
void output();
};
void chess::draw()
{
clrscr();
cout<<"\t\t\t\t queen challenge"<<endl;
for(i=0;i<8;i++)
{
for(j=0;j<8;j++)
{
if(a[i][j]==2)
cout<<"Q"<<"\t";
else if(a[i][j]==9)
cout<<"x"<<"\t";
else
cout<<a[i][j]<<"\t";
}
cout<<endl;
}
getch();
}
void chess::getdata()
{

cout<<endl<<"Enter your queens position (row,coloum)"<<endl;
cin>>pos1>>pos2;
check();
}

void chess::check()
{pos1=pos1-1;
pos2=pos2-1;
if(b[pos1][pos2]==1)
{
if(a[pos1][pos2]==2)
{draw();
cout<<endl<<"you have already place a queen at ("<<pos1+1<<","<<pos2+1<<")"<<endl ;
}
else
{a[pos1][pos2]=9;
draw();
a[pos1][pos2]=0;
cout<<endl<<"queen position ("<<pos1+1<<","<<pos2+1<<")"<<"is under attack zone"<<endl;
}
}
else
{
cout<<"data acepted"<<endl;
set();
}
}
void chess::set()
{
a[pos1][pos2]=2;
draw();
b[pos1][pos2]=1;
t1=pos1;
t2=pos2;
for(i=0;i<8;i++) //up to down
{
b[i][pos2]=1;
}
for(i=0;i<8;i++) //left to right
{
b[pos1][i]=1;
}
i=pos1;
j=pos2;
while (i>0 || j>0)
{
b[i][j]=1 ;
i--;
j--;
} //left to right  corner

i=pos1;
j=pos2;
while (i<9 || j<9)
{
b[i][j]=1 ;
i++;
j++;
}


}

void main()
{
int opt=1;
clrscr();
chess c;
do
{
c.draw();
c.getdata();
cout<<"Press 1 to cont and 0 to exist : \t";
cin>>opt;
}while (opt==1);

cout<<"\n\n\t\t\t\tcoded by BHARATH";
getch();
}
