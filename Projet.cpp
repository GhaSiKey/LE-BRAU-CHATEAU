#include<windows.h>
#include <iostream>
#include <sstream>
#include<string>
# include<stdio.h>
#include <conio.h>
#include <ctime>
#include "Projet.h"
void monster::cleanmonster(){
    locate(x,y);
    cout<<"  ";
}
void Player::printplayer(){
    locate(x,y);
    cout<<"��";
    Sleep(100);
    if(pet!=nullptr){
        locate(x,y+1);
        cout<<"��";
    }
}
void Player::cleanplayer(){
    locate(x,y);
    cout<<"  ";
    Sleep(100);
    if(pet!=nullptr){
        locate(x,y+1);
        cout<<" ";
    }
}
template<class T> string tostring(T i){
    stringstream f;
    f<<i;
    return f.str();
}
void printobjet(int i,int n,Room* rooms,Objet& objets){   //i����Ʒ���  n �������
    switch(i){
        case 41: if(objets.bb==0){rooms[n].thing=i;objets.bb=1;locate(rooms[n].getx()-2,rooms[n].gety()); cout<< "Ѫ"; }break;//Ѫƿ
        case 42: if(objets.bl==0){rooms[n].thing=i;objets.bl=1;locate(rooms[n].getx()-2,rooms[n].gety());cout<< "��"; }break;//��ƿ
        case 43: if(objets.po==0){rooms[n].thing=i;objets.po=1;locate(rooms[n].getx()-2,rooms[n].gety());cout<< "��"; }break;//��ƿ
        case 44: if(objets.sword1==0){rooms[n].thing=i;objets.sword1=1;locate(rooms[n].getx()-2,rooms[n].gety());cout<< "��"; }break;//��
        case 45: if(objets.shield1==0){rooms[n].thing=i;objets.shield1=1;locate(rooms[n].getx()-2,rooms[n].gety());cout<< "��"; }break;//��
        case 461: if(objets.key==0){rooms[n].thing=i;objets.key=1;locate(rooms[n].getx()-2,rooms[n].gety());cout<< "Կ";} break;//Կ��
        case 462: if(objets.Key_BOSS==0){rooms[n].thing=i;objets.Key_BOSS=1;locate(rooms[n].getx()-2,rooms[n].gety());cout<< "7";} break;//ͨ��Կ��
    }
}
void InitThing(double i,Room* rooms,Objet& objets){
    while(1){
        int n=rand()%16;
            if(rooms[n].thing==0)
            {
                printobjet(i,n,rooms,objets);
                break;
            }
    }
}
void locate(short int x,short int y){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(hOut, c);
}
void printhead(const Player& p1){
    const int head_x = 2;
    const int head_y = 1;
    const int frame_width = 20;
    const int frame_height = 10;

    locate(head_x,head_y);
    cout<<"��";
    locate(head_x+frame_width,head_y);
    cout<<"��";
    locate(head_x,head_y+frame_height);
    cout<<"��";
    locate(head_x+frame_width,head_y+frame_height);
    cout<<"��";
    locate(head_x+8,head_y+1);
    cout<<"״̬��";
    locate(head_x+4,head_y+2);
    cout<<"����: "<<"         ";
    locate(head_x+4,head_y+3);
    cout<<"�ȼ�: "<<"         ";
    locate(head_x+4,head_y+4);
    cout<<"����ֵ: "<<"         ";
    locate(head_x+4,head_y+5);
    cout<<"������: "<<"         ";
    locate(head_x+4,head_y+6);
    cout<<"������: "<<"         ";
    locate(head_x+4,head_y+7);
    cout<<"ħ��ֵ: "<<"         ";
    locate(head_x+4,head_y+8);
    cout<<"�ж���: "<<"         "<<endl;
    locate(head_x+8,head_y+1);
    cout<<"״̬��";
    locate(head_x+4,head_y+2);
    cout<<"����: "<<p1.name;
    locate(head_x+4,head_y+3);
    cout<<"�ȼ�: "<<p1.level;
    locate(head_x+4,head_y+4);
    cout<<"����ֵ: "<<p1.health;
    locate(head_x+4,head_y+5);
    cout<<"������: "<<p1.atk;
    locate(head_x+4,head_y+6);
    cout<<"������: "<<p1.def;
    locate(head_x+4,head_y+7);
    cout<<"ħ��ֵ: "<<p1.mana;
    locate(head_x+4,head_y+8);
    cout<<"�ж���: "<<p1.act<<endl;
}
void printequip(Objet& P1objets){
    const int head_x=2;
    const int head_y=19;
    const int frame_width = 20;
    const int frame_height = 6;

    locate(head_x,head_y);
    cout<<"��";
    locate(head_x+frame_width,head_y);
    cout<<"��";
    locate(head_x,head_y+frame_height);
    cout<<"��";
    locate(head_x+frame_width,head_y+frame_height);
    cout<<"��";
    locate(head_x+8,head_y+1);
    cout<<"װ����";
    locate(head_x+2,head_y+2);
    cout<<"װ��1��";
    if(P1objets.sword1==1)cout<<"��ħ����";
    locate(head_x+2,head_y+4);
    cout<<"װ��2��";
    if(P1objets.shield1==1)cout<<"����˹֮��";
}
void printroom(int x,int y){   //��ӡ����
    int i;
    for(i=-4;i<=4;i+=2)
    {
        locate(x+i,y-2);
        cout<<"��";//�Ϻ��
    }
    for(i=-4;i<=4;i+=2)
    {
        locate(x+i,y+2);
        cout<<"��";//�º��
    }
    for(i=-1;i<=1;i++)
    {
        locate(x-4,y+i);
        cout<<"��";//����
    }
    for(i=-1;i<=1;i++)
    {
        locate(x+4,y+i);
        cout<<"��";//�Һ��
    }
}

void printmap(Room* rooms){        //��ӡ��Ϸ��ͼ
    const int head_x=24;
    const int head_y=1;
    const int frame_width = 46;
    const int frame_height = 23;

    locate(head_x,head_y);
    cout<<"��";
    locate(head_x+2+frame_width,head_y);
    cout<<"��";
    locate(head_x,head_y+frame_height+1);
    cout<<"��";
    locate(head_x+2+frame_width,head_y+frame_height+1);
    cout<<"��";

    int i=head_x+6;
    int j;
    int t=0;
    while(i<head_x+2+frame_width){
        j=head_y+3;
        while(j<head_y+frame_height){
            printroom(i,j);
            rooms[t].setxy(i,j);
            t++;
            j+=6;
        };
        i+=12;
}
}
void printmessage(){  //��ӡ�Ҳ���Ϣ���߿�
    const int head_x=80;
    const int head_y=1;
    const int frame_width = 35;
    const int frame_height = 12;

    locate(head_x,head_y);
    cout<<"��";
    locate(head_x+frame_width,head_y);
    cout<<"��";
    locate(head_x,head_y+frame_height);
    cout<<"��";
    locate(head_x+frame_width,head_y+frame_height);
    cout<<"��";
    locate(head_x+2,head_y+1);
    cout<<"��Ϣ����";
};
int getmonstersroomnumber(monster& mons,Room* rooms){
    for(unsigned int i=0;i<16;i++){
        if((rooms[i].getx()==mons.x)&&(mons.y==rooms[i].gety()-1)){
             return i;
        }
    }
};
int getmonsternumber(monster* mons,Room& rooms){
    for(unsigned int i=1;i<=3;i++){
        if((mons[i].x==rooms.getx())&&(rooms.gety()==mons[i].y+1))
            return i;
    }
}
void creer_monster(int monsterlevel,Room* rooms,int n){   //monsterlevel��������  n �������
    switch(monsterlevel){
        case 21: rooms[n].monster=21;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "M1"; break;//MONTER 21
        case 22: rooms[n].monster=22;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "M2"; break;//MONTER 22
        case 23: rooms[n].monster=23;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "M3"; break;//MONTER 23
        case 24: rooms[n].monster=24;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "M4"; break;//MONTER 24
        case 25: rooms[n].monster=25;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "M5"; break;//MONTER 25
        case 26: rooms[n].monster=26;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "M6"; break;//MONTER 26
        case 31: rooms[n].monster=31;locate(rooms[n].getx(),rooms[n].gety()-1); cout<< "MM"; break;//MONTER 31
    }
}
void InitMonster(int monsterlevel,monster* mons,Room* rooms, int i){//����ȼ�
    while(1){
        int n=rand()%16;
        if(rooms[n].monster==0)
        {
            mons[i].monsterlevel=monsterlevel;
            mons[i].num_room=n;     //��¼���ɹֵķ����
            mons[i].x=rooms[n].getx();
            mons[i].y=rooms[n].gety()-1;
            mons[i].setting();
            creer_monster(monsterlevel,rooms,n);
            break;
        }
    }
}
void printmonster(monster& mons,Room* rooms){
    int n = getmonstersroomnumber(mons,rooms);
    rooms[n].monster=mons.monsterlevel;
    mons.num_room=n;
    locate(mons.x,mons.y);
    switch(mons.monsterlevel){   //i��֮ǰ�Ѿ��ó��Ĺ�����
        case 21: cout<< "M1"; break;//MONTER 21
        case 22: cout<< "M2"; break;//MONTER 22
        case 23: cout<< "M3"; break;//MONTER 23
        case 24: cout<< "M4"; break;//MONTER 24
        case 25: cout<< "M5"; break;//MONTER 25
        case 26: cout<< "M6"; break;//MONTER 26
        case 31: cout<< "MM"; break;//MONTER 31
    }
}
int judgementmonsterlevel(Player& p1){
    int niveau;
    niveau=rand()%2;
    if(p1.level<5){
        if(niveau==1) return 21;
        else          return 22;
    }
    else if(p1.level<15&&p1.level>=5){
        if(niveau==1)  return 23;
        else           return 24;
    }
    else
        if(niveau==1)  return 25;
        else           return 26;
}
void printbag(Objet& P1objets){
    const int head_x=2;
    const int head_y=12;
    const int frame_width = 20;
    const int frame_height = 6;

    locate(head_x,head_y);
    cout<<"��";
    locate(head_x+frame_width,head_y);
    cout<<"��";
    locate(head_x,head_y+frame_height);
    cout<<"��";
    locate(head_x+frame_width,head_y+frame_height);
    cout<<"��";
    locate(head_x+8,head_y+1);
    cout<<"��Ʒ��";
    locate(head_x+4,head_y+2);
    cout<<"Ѫƿ������X"<<P1objets.bb;
    locate(head_x+4,head_y+3);
    cout<<"��ƿ������X"<<P1objets.bl;
    locate(head_x+4,head_y+4);
    cout<<"��ƿ������X"<<P1objets.po;
    locate(head_x+4,head_y+5);
    cout<<"Կ��������X"<<P1objets.key;
}
int getroomnumber(Player& p1,Room* rooms){
    for(unsigned int i=0;i<16;i++){
        if((rooms[i].getx()==p1.x)&&(rooms[i].gety()==p1.y)){
             return i;
        }
    }
}
string* infos[10];
void mes(string info){ //��Ϣ���� ������ӡ��Ϣ
    static string message[10]={"","","","","","","","","",""};
    for(int i=0;i<10;i++){
        locate(82,3+i);
        cout<<"                                  ";
    };
    for(int i=9;i>0;i--){
        message[i]=message[i-1];
    };
    for(int i=0;i<10;i++){
        infos[i] = &message[i];
    };
    infos[0]=&info;
    for(int i=0;i<10;i++){
        message[i] = *infos[i];
    };
    for(int i=0;i<10;i++){
        locate(82,3+i);
        cout<<message[i];
    };
};
void playsound(){
    cout<<"\a";
}
void printmenu(Player& p1){
    const int head_x=24;
    const int head_y=1;
    const int frame_width = 46;
    const int frame_height = 23;
    for(unsigned int i=head_x;i<=head_x+2+frame_width;i+=2)
    {
        locate(i,head_y);
        cout<<"��";
    }
    for(unsigned int i=head_x;i<=head_x+2+frame_width;i+=2)
    {
        locate(i,head_y+frame_height+1);
        cout<<"��";
    }
    for(unsigned int i=head_y;i<=head_y+1+frame_height;i++)
    {
        locate(head_x,i);
        cout<<"��";
    }
    for(unsigned int i=head_y;i<=head_y+1+frame_height;i++)
    {
        locate(head_x+2+frame_width,i);
        cout<<"��";
    }
    locate(head_x+frame_width/2-5,head_y+2);
    cout<<"LE BEAU CHATEAU";
    locate(head_x+frame_width/2-12,head_y+5);
    cout<<"ѡ���ɫ:   Hp  Atk  Def  Mana";
    locate(head_x+frame_width/2-12,head_y+6);
    cout<<"1:սʿ     500   20   20   100";
    locate(head_x+frame_width/2-12,head_y+7);
    cout<<"2:ħ��ʦ   300   15   10   600";
    locate(head_x+frame_width/2-12,head_y+8);
    cout<<"3:��ʦ     200   20   10   800";
    locate(head_x+frame_width/2-12,head_y+9);
    cout<<"4:����     150   50   15    50";
    locate(head_x+frame_width/2-12,head_y+10);
    cout<<"5:����ѷ   500   10   30     0";
    locate(head_x+frame_width/2-12,head_y+11);
    cout<<"6:cheater 9999 9999 9999  9999";
    locate(head_x+frame_width/2-3,head_y+13);
    cout<<"0:�˳���Ϸ";
    locate(head_x+frame_width/2-12,head_y+17);
    cout<<"��ѡ��[1��2��3��4��5��6]��[ ]\b\b";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
            p1.name = "սʿ";
            p1.setinfo(500,20,20,10);
            break;
        case 2:
            p1.name = "ħ��ʦ";
            p1.setinfo(300,15,10,600);
            break;
        case 3:
            p1.name = "��ʦ";
            p1.setinfo(200,20,10,800);
            break;
        case 4:
            p1.name = "����";
            p1.setinfo(150,50,15,50);
            break;
        case 5:
            p1.name = "����ѷ";
            p1.setinfo(500,10,30,0);
            break;
        case 6:
            p1.name = "cheater";
            p1.setinfo(9999,9999,9999,9999);
            break;
        case 0:
            locate(0,25);
            exit(0);
            break;
        default:
            locate(head_x+frame_width/2-8,head_y+18);
            cout<<"(please choose from 0~6)";
            printmenu(p1);
    }
    system("cls");//c++����Ļ����
}
void printinfomation(){
    const int head_x=80;
    const int head_y=14;
    const int frame_width = 35;
    const int frame_height = 12;

    locate(head_x,head_y);
    cout<<"��";
    locate(head_x+frame_width,head_y);
    cout<<"��";
    locate(head_x,head_y+frame_height);
    cout<<"��";
    locate(head_x+frame_width,head_y+frame_height);
    cout<<"��";
    locate(head_x+2,head_y+1);
    cout<<"��Ϣ����";
    locate(head_x+2,head_y+2);
    cout<<"�����������������";
    locate(head_x+2,head_y+3);
    cout<<"z��       ����";
    locate(head_x+2,head_y+4);
    cout<<"x��       ��ħ����";
    locate(head_x+2,head_y+5);
    cout<<"c��       ����";
    locate(head_x+2,head_y+6);
    cout<<"M1~M6��   ����";
    locate(head_x+2,head_y+7);
    cout<<"��Ѫ����    Ѫƿ ";
    locate(head_x+2,head_y+8);
    cout<<"��������    ��ƿ";
    locate(head_x+2,head_y+9);
    cout<<"��Կ��������Կ��";
    locate(head_x+2,head_y+10);
    cout<<"MM: ����boss ��������������";
    locate(head_x+2,head_y+11);
    cout<<"  ��˵����������õ�����";

}
void move_monster(monster& mons,Room* rooms){
    //int up=1,down=1,left=1,right=1; //�ж�������Ƿ����
    int v;
    int n=mons.num_room;
    if(n==5||n==6||n==9||n==10){
        v=rand()%4;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x+12;printmonster(mons,rooms);break;  //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x-12;printmonster(mons,rooms);break;   //����
            case 2: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y+6;printmonster(mons,rooms);break;   //����
            case 3: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y-6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==0){
        v=rand()%2;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x+12;printmonster(mons,rooms);break;  //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y+6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==3){
        v=rand()%2;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x+12;printmonster(mons,rooms);break;  //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y-6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==12){
        v=rand()%2;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x-12;printmonster(mons,rooms);break;   //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y+6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==15){
        v=rand()%2;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x-12;printmonster(mons,rooms);break;   //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y-6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==1||n==2){
        v=rand()%3;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x+12;printmonster(mons,rooms);break;  //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y+6;printmonster(mons,rooms);break;   //����
            case 2: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y-6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==4||n==8){
        v=rand()%3;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x+12;printmonster(mons,rooms);break;  //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x-12;printmonster(mons,rooms);break;   //����
            case 2: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y+6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==13||n==14){
        v=rand()%3;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x-12;printmonster(mons,rooms);break;   //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y+6;printmonster(mons,rooms);break;   //����
            case 2: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y-6;printmonster(mons,rooms);break;   //����
        }
    }
    else if(n==7||n==11){
        v=rand()%3;
        switch(v){
            case 0: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x+12;printmonster(mons,rooms);break;  //����
            case 1: rooms[n].monster=0;mons.cleanmonster(); mons.x=mons.x-12;printmonster(mons,rooms);break;   //����
            case 2: rooms[n].monster=0;mons.cleanmonster(); mons.y=mons.y-6;printmonster(mons,rooms);break;   //����
        }
    }
}
void uplevel(Player& p1){//����
    if(p1.exp>=p1.exp_limit){
        ++p1.level;
        p1.exp=0;
        p1.exp_limit+=100;
        p1.atk+=10;
        p1.def+=5;
        mes("�������������ˡ�����");
        mes("++Hp:"+tostring<int>(p1.health)+"  ++Atc:"+tostring<int>(p1.atk)+"  ++Def:"+tostring<int>(p1.def));
    }
}
double moinsbloodtout(Player& p1,monster& monster){//���ؿ�Ѫ����
    double moins1=0;//�ҶԹ�һ��
    double moins2=0;//�ֶ���һ��
    double moins3=0;//����Թ�һ��
    double moins4=0;//�ֶԳ���һ��
    int fois1=0;   //�Ҵ�ִ���
    int fois2=0;  //�ִ�������
    int fois3=0;  //�����ִ���
    double a=0;
    double b=0;
    double n = monster.health;
    if(p1.pet==nullptr){
        //û����
        if(monster.posion==true){
        moins1=p1.atk/(monster.def*0.8);
        }
        else{
            moins1=p1.atk/monster.def;
        }
        if(p1.posion==true){
            moins2=monster.atk/(p1.def*0.8);
        }
        else{
            moins2=monster.atk/p1.def;
        }
        while(n>0)
        {
            n-= moins1;
            fois1++;
        }
        return fois1*moins2;
    }
    //�г���
    else{
        if(monster.posion==true){
            moins1=p1.atk/(monster.def*0.8);
            moins3=(p1.pet->atk)/(monster.def*0.8);
        }
        else{
            moins1=p1.atk/monster.def;
            moins3=(p1.pet->atk)/monster.def;
        }
        moins2=monster.atk/(p1.def);
        if(p1.pet->posion){
            moins4=monster.atk/(p1.pet->def*0.8);
        }
        else{
            moins4=monster.atk/(p1.pet->def);
        }
        a=monster.health;
        b=(p1.pet->health);

        while(b>0)
        {
            b-=moins4;
            fois2++;      //�ִ����Ĵ���
        }
        while(a>0)
        {
            a-= moins3;
            fois3++;      //�����ֵĴ���
        }
        //����û��
        if(fois3<=fois2){
            return fois3*moins4;  //���س����Ѫ
        }
        //��������
        else{
            a-=fois2*moins3;
            while(a>0)
            {
                a-= moins1;
                fois1++;
            }
            return ((p1.pet->health)+fois1*moins2);
        }
    }
}
void attack(Player& p1,monster& monster,Room& rooms){
    double moins;
    moins=moinsbloodtout(p1,monster);
    if(p1.pet!=nullptr){
        if(moins >= (p1.pet->health))  //��������
        {
            moins -= (p1.pet->health);
            mes("��ĳ���������@~@");
            locate(p1.x,p1.y+1);cout<<" ";
            p1.pet=nullptr;
            if(p1.health<moins)
            {
                mes("������!!!");
                p1.health-=moins;
            }
            else{
                mes("������˹��� : HP-"+tostring<double>(moins));
                p1.health-=moins;
                monster.health=0;rooms.monster=0;monster.cleanmonster();
                p1.exp+=monster.exp;
            }
        }
        //����û��
        else{
            p1.pet->health-=moins;
            mes("��������˹���!Pet's Hp:"+tostring<double>(p1.pet->health));
            monster.health=0;rooms.monster=0;monster.cleanmonster();
            p1.exp+=monster.exp;
        }
    }
    else{
        if(p1.health<moins)
        {
            mes("������!!!!!!!!!");
            p1.health-=moins;
        }
        else{
            mes("������˹��� : HP-"+tostring<double>(moins));
            p1.health-=moins;
            monster.health=0;rooms.monster=0;monster.cleanmonster();
            p1.exp+=monster.exp;
        }
    }
    if(p1.exp<p1.exp_limit)mes("��þ���ֵ��"+tostring<int>(monster.exp)+"  ������һ�ȼ���"+tostring<int>(p1.exp_limit-p1.exp));
}
void fumo(Player& p1,monster& monster,Room& rooms){  //��ħ
    double moins;
    moins=moinsbloodtout(p1,monster);
    if(p1.mana<moins/2)
    {
        mes("û���㹻��ħ��ֵ");
    }
    else{
        p1.mana -= moins/2;
        p1.pet=&monster;
        rooms.monster=0;monster.cleanmonster();
        mes("�ɹ���ħ mana-"+tostring<double>(moins/2));
        mes("Pet's Hp:"+tostring<double>(p1.pet->health)+"  Atc:"+tostring<double>(p1.pet->atk)+"  Def:"+tostring<double>(p1.pet->def));
    }

}
int dead(){
    system("cls");
    const int head_x=24;
    const int head_y=1;
    const int frame_width = 46;
    const int frame_height = 23;
    for(unsigned int i=head_x;i<=head_x+2+frame_width;i+=2)
    {
        locate(i,head_y);
        cout<<"��";
    }
    for(unsigned int i=head_x;i<=head_x+2+frame_width;i+=2)
    {
        locate(i,head_y+frame_height+1);
        cout<<"��";
    }
    for(unsigned int i=head_y;i<=head_y+1+frame_height;i++)
    {
        locate(head_x,i);
        cout<<"��";
    }
    for(unsigned int i=head_y;i<=head_y+1+frame_height;i++)
    {
        locate(head_x+2+frame_width,i);
        cout<<"��";
    }
    for(unsigned int i=0;i<3;i++){
        locate(43,10);
        cout<<"            ";
        Sleep(100);
        locate(43,10);
        cout<<"YOU   DIED";
        Sleep(900);
    }
    locate(40,12);
    cout<<"����һ��----------1";
    locate(40,13);
    cout<<"�����²�----------2\n";
    int n;
    locate(45,14);
    cout<<"ѡ��1/2����";
    cin>>n;
    return n;
}
int gameclear(){
    system("cls");
//    const int head_x=24;
//    const int head_y=1;
//    const int frame_width = 46;
//    const int frame_height = 23;
//    for(unsigned int i=head_x;i<=head_x+2+frame_width;i+=2)
//    {
//        locate(i,head_y);
//        cout<<"��";
//    }
//    for(unsigned int i=head_x;i<=head_x+2+frame_width;i+=2)
//    {
//        locate(i,head_y+frame_height+1);
//        cout<<"��";
//    }
//    for(unsigned int i=head_y;i<=head_y+1+frame_height;i++)
//    {
//        locate(head_x,i);
//        cout<<"��";
//    }
//    for(unsigned int i=head_y;i<=head_y+1+frame_height;i++)
//    {
//        locate(head_x+2+frame_width,i);
//        cout<<"��";
//    }
        for(unsigned int i=0;i<120;i+=2){
            for(unsigned int j=0;j<25;j++){
                locate(i,j);cout<<"��";
            }
            Sleep(1);
        }
        for(unsigned int i=0;i<120;i++){
            for(unsigned int j=0;j<25;j+=2){
                locate(i,j);cout<<" ";Sleep(0.5);
            }

        }
        for(unsigned int i=0;i<120;i++){
            for(unsigned int j=1;j<25;j+=2){
                locate(i,j);cout<<" ";Sleep(0.5);
            }

        }
        system("cls");
        locate(5,3);
        cout<<"Wow~ You have finally killed the Boss....\n";
        Sleep(2000);
        locate(18,5);
        cout<<"Suddenly! A key floated down from the sky.....\n";
        Sleep(2000);
        locate(14,7);
        cout<<"That key doesn't look like the others.......Wait!!....\n";
        Sleep(2000);
        locate(24,9);
        cout<<"That's THE KEY will help you get out of the CASTLE!!!\n";
        Sleep(2000);
        locate(30,11);
        cout<<"Congratulation!! Game Clear!!!";
        Sleep(2000);
    locate(30,15);
    cout<<"����һ��------------------1";
    locate(30,16);
    cout<<"�����²�------------------2\n";
    int n;
    locate(45,17);
    cout<<"ѡ��1/2����";
    cin>>n;
    return n;
}

