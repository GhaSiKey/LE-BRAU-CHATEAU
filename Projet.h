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
class monster{// 怪兽
public:
    monster(){}
    string name;
    int monsterlevel;
    int num_room;//哪个房间
    int x;
    int y;//坐标
    int exp; //经验
    double health,atk,def,mana ;//血量 攻击 防御 法力值
    int Aggressiveness;//攻击性,1代表低侵略性（不会主动攻击你）2代表中侵略性（只有在随机移动遇到的时候才会攻击你）3代表高侵略性（一旦你与他出现在同一地图中就会攻击你）
    bool t;//是否被附魔。
    bool posion=false;//是否中毒
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
    int room;//哪个房间
    int x=30;
    int y=4;//坐标
    int health=0,atk=0,def=0,mana=0;//血量 攻击 防御 法力值
    int exp=0;//经验值
    int exp_limit=200; //经验上限
    int level=1;//等级
    int act=6;//行动力
    bool posion;//是否中毒
    monster* pet=nullptr;//附魔的宠物

    void setinfo(int h,int a,int d,int m){
        health=h;atk=a;def=d;mana=m;
    }
    void poison();//释放毒药
    double moinsbloodtout();//返回扣血总量
    void uplevel();//升级函数
    void upgrade();//加点函数
    void Attack();  //攻击函数
    void printplayer();
    void cleanplayer();
};
class Objet{
public:
    int bb=0;//血瓶  41
    int bl=0;//蓝瓶  42
    int po=0;//毒药  43
    int sword1=0;//宝剑1  44
    int sword2=0;//宝剑2
    int shield1=0;//盾牌1  45
    int shield2=0;//盾牌2
    int key=0; //传送钥匙   461
    int Key_BOSS=0; //通关钥匙   462
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

