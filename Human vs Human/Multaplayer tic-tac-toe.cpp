#include<bits/stdc++.h>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;
bool ok = true;
bool available (char *spaces)
{
    for(int i=0;i<9;i++)    {
        if(spaces[i]==' ') return true;
    }
    return false;
}
void drawboard(char *spaces)
{
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
    cout<<"     |     |     "<<endl<<endl;
}
bool Xwinner (char *spaces)
{
    if(spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0]=='X')  return true;
    if(spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3]=='X')  return true;
    if(spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[7]=='X')  return true;
    if(spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[8]=='X')  return true;
    if(spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[6]=='X')  return true;

    return false;
}
bool Owinner (char *spaces)
{
    if(spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0]=='O')  return true;
    if(spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[5]=='O')  return true;
    if(spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[8]=='O')  return true;
    if(spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[8]=='O')  return true;
    if(spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[6]=='O')  return true;

    return false;
}
void moveX(char *spaces)
{
    if(!available(spaces))
    {
        ok = false;
        return;
    }
        cout<<"Turn of Player 1 (X)\n"<<endl;
        cout<<"Enter your choice: ";
        int n;cin>>n;
        while(spaces[n-'0'-1]=='X' || spaces[n-'0'-1]=='O')    {
                system("cls");
                drawboard(spaces);
            cout<<"This square is obtained by"<<(spaces[n-1]=='X'?"You.":"O.")<<". Choose another one.\n";
            cout<<"Enter your choice(1-9): ";
            cin>>n;
        }
        spaces[n-1] = 'X';
        system("cls");
        drawboard(spaces);
}
void moveY(char *spaces)
{
    if(!available(spaces))
    {
        ok = false;
        return;
    }
        cout<<"Turn of Player 1 (X)\n"<<endl;
        cout<<"Enter your choice: ";
        int n;cin>>n;
        while(spaces[n-1]=='X' || spaces[n-1]=='O')    {
                system("cls");
                drawboard(spaces);
            cout<<"This square is obtained by"<<(spaces[n-1]=='O'?"You.":"X.")<<". Choose another one.\n";
            cout<<"Enter your choice(1-9): ";
            cin>>n;
        }
        spaces[n-1] = 'O';
        system("cls");
        drawboard(spaces);
}


int main()
{

    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    drawboard(spaces);
    srand(time(0));


    while(ok)   {

        moveX(spaces);
        moveY(spaces);

        if(Xwinner(spaces)) {
            cout<<"'X' is the winner."<<endl;
            return 0;
        }
        if(Owinner(spaces)) {
            cout<<"'O' is the winner."<<endl;
            return 0;
        }


    }

    cout<<"It's a draw"<<endl;



}
