#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
#include<windows.h>
#include <iostream>
#include <sstream>
#include<string>
# include<stdio.h>
#include <conio.h>
#include <ctime>
using namespace  std;
class Room{
    int x;
    int y;
public:
    double thing=0;
    double mthing=0;
    double monster=0;
    inline int getx()const {return x;};
    inline int gety()const {return y;};
    void setxy(int i,int j){ x=i;y=j;};
};
class monster{// ����
public:
    monster(){}
    string name;
    int monsterlevel;
    int num_room;//�ĸ�����
    int x;
    int y;//����
    int exp; //����
    double health,atk,def,mana ;//Ѫ�� ���� ���� ����ֵ
    int Aggressiveness;//������,1����������ԣ��������������㣩2�����������ԣ�ֻ��������ƶ�������ʱ��Żṥ���㣩3����������ԣ�һ��������������ͬһ��ͼ�оͻṥ���㣩
    bool t;//�Ƿ񱻸�ħ��
    bool posion=false;//�Ƿ��ж�
    void cleanmonster();
    void setting(){
        switch(monsterlevel){
            case 21:  exp=50;health=50;atk=32;def=8;Aggressiveness=1;break;//MONTER 21
            case 22:  exp=100;health=150;atk=35;def=15;Aggressiveness=1;break;//MONTER 22
            case 23:  exp=200;health=350;atk=50;def=25;Aggressiveness=2;break;//MONTER 23
            case 24:  exp=500;health=500;atk=70;def=30;Aggressiveness=2;break;//MONTER 24
            case 25:  exp=700;health=800;atk=90;def=35;Aggressiveness=3;break;//MONTER 25
            case 26:  exp=1000;health=1000;atk=150;def=50;Aggressiveness=3;break;//MONTER 26
            case 31:  exp=0;health=2000;atk=200;def=50;Aggressiveness=1;break;//MONTER 31
        }
    }
};
class Player{
public:
    string name;
    int room;//�ĸ�����
    int x=30;
    int y=4;//����
    int health=0,atk=0,def=0,mana=0;//Ѫ�� ���� ���� ����ֵ
    int exp=0;//����ֵ
    int exp_limit=200; //��������
    int level=1;//�ȼ�
    int act=6;//�ж���
    bool posion;//�Ƿ��ж�
    monster* pet=nullptr;//��ħ�ĳ���

    void setinfo(int h,int a,int d,int m){
        health=h;atk=a;def=d;mana=m;
    }
    void poison();//�ͷŶ�ҩ
    double moinsbloodtout();//���ؿ�Ѫ����
    void uplevel();//��������
    void upgrade();//�ӵ㺯��
    void Attack();  //��������
    void printplayer();
    void cleanplayer();
};
class Objet{
public:
    int bb=0;//Ѫƿ  41
    int bl=0;//��ƿ  42
    int po=0;//��ҩ  43
    int sword1=0;//����1  44
    int sword2=0;//����2
    int shield1=0;//����1  45
    int shield2=0;//����2
    int key=0; //����Կ��   461
    int Key_BOSS=0; //ͨ��Կ��   462
};

void locate(short int x,short int y);
template<class T> string tostring(T i);
void printobjet(int i,int n,Room* rooms,Objet& objets);
void InitThing(double i,Room* rooms,Objet& objets);
void locate(short int x,short int y);
void printhead(const Player& p1);
void printequip(Objet& P1objets);
void printroom(int x,int y);
void printmap(Room* rooms);
void printmessage();
int getmonstersroomnumber(monster& mons,Room* rooms);
int getmonsternumber(monster* mons,Room& rooms);
void creer_monster(int monsterlevel,Room* rooms,int n);
void InitMonster(int monsterlevel,monster* mons,Room* rooms, int i);
void printmonster(monster& mons,Room* rooms);
int judgementmonsterlevel(Player& p1);
void printbag(Objet& P1objets);
int getroomnumber(Player& p1,Room* rooms);
void mes(string info);
void playsound();
void printmenu(Player& p1);
void printinfomation();
void move_monster(monster& mons,Room* rooms);
void uplevel(Player& p1);
double moinsbloodtout(Player& p1,monster& monster);
void attack(Player& p1,monster& monster,Room& rooms);
void fumo(Player& p1,monster& monster,Room& rooms);
int dead();
int gameclear();
#endif // PROJET_H_INCLUDED

