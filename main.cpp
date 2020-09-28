#include "Projet.h"
using namespace std;

int main()
{
restart:srand(time(0));
    monster mons[10];
    Objet objets;
    Objet P1objets;
    Room rooms[16];
    int ch;   //键盘读取
    int turn=1;   //回合数
    int monsternumber=2;   //场上怪物数量
    int monsterlevel=21;   //怪物等级初始
    Player p1;
    printmenu(p1);
        mes("您选择了职业："+p1.name);
    printmap(rooms);
    printmessage();
    printinfomation();

    InitThing(41,rooms,objets);
    InitThing(42,rooms,objets);
    InitThing(43,rooms,objets);
    InitThing(44,rooms,objets);
    InitThing(45,rooms,objets);
    InitThing(461,rooms,objets);

    for(int i=1;i<=monsternumber;i++){
        monsterlevel = judgementmonsterlevel(p1);
        InitMonster(monsterlevel,mons,rooms,i);   //生成两个怪
    }
    InitMonster(31,mons,rooms,3);  //生成boss

label:uplevel(p1);
    printhead(p1);
    printbag(P1objets);
    printequip(P1objets);


    while(1){
        p1.printplayer();
        if(kbhit())
            {
                //如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if (ch == 27){
                    mes("确定要退出？y/n");
                    while(1){
                        if(kbhit())
                        {
                            ch = _getch();
                            if(ch == 'y'){
                                for(unsigned int i=0;i<10;i++) mes("");
                                system("cls");
                                goto restart;
                            }
                            else {mes("游戏继续");goto label;}
                        }
                    }

                }//当按下ESC时循环，ESC键的键值时27.
                if (ch == 72){
                    if((p1.y-6)>3){
                        p1.cleanplayer();
                        mes("玩家向上移动");
                        int j = p1.y-6;
                        p1.y = j;
                        p1.act--;goto label;
                    }
                    else {
                        mes("不能向上移动");
                        playsound();
                    }
                }
                if (ch == 80){
                    if((p1.y+6)<24){
                        p1.cleanplayer();
                        mes("玩家向下移动");
                        int j = p1.y+6;
                        p1.y = j;
                        p1.act--;goto label;
                    }
                    else {
                        mes("不能向下移动");
                        playsound();
                    }
                }
                if (ch == 75){
                    if((p1.x-12)>24){
                        p1.cleanplayer();
                        mes("玩家向左移动");
                        int i = p1.x-12;
                        p1.x = i;
                        p1.act--;goto label;
                    }
                    else {
                        mes("不能向左移动");
                        playsound();
                    }
                }
                if (ch == 77){
                    if((p1.x+12)<72){
                        p1.cleanplayer();
                        mes("玩家向右移动");
                        int i = p1.x+12;
                        p1.x = i;
                        p1.act--;goto label;
                    }
                    else {
                        mes("不能向右移动");
                        playsound();
                    }
                }
                if (ch == 32){
                    mes("游戏暂停");
                    playsound();
                    while(1){
                        if(kbhit())
                        {
                            ch = _getch();
                            if (ch == 32){mes("游戏恢复");playsound();goto label;};
                        }
                    }
                }
                if (ch == 'c'){
                    int i=getroomnumber(p1,rooms);
                    int thing = rooms[i].thing;
                    switch(thing){
                        case 41: rooms[i].thing=0;objets.bb=0;P1objets.bb++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("捡到了血瓶");break;//血瓶
                        case 42: rooms[i].thing=0;objets.bl=0;P1objets.bl++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("捡到了蓝瓶");break;//蓝瓶
                        case 43: rooms[i].thing=0;objets.po=0;P1objets.po++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("捡到了毒瓶");break;//毒瓶
                        case 44: rooms[i].thing=0;objets.sword1=0;P1objets.sword1++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("捡到了上古神器：封魔宝剑");p1.atk+=50;break;//剑
                        case 45: rooms[i].thing=0;objets.shield1=0;P1objets.shield1++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("捡到了英灵的武器：阿古斯之盾盾");p1.def=+50;break;//盾
                        case 461: rooms[i].thing=0;objets.key=0;P1objets.key++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("捡到了钥匙");break;//钥匙
                        case 462: rooms[i].thing=0;objets.Key_BOSS=0;P1objets.Key_BOSS++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("你通关了！");break;//通关钥匙
                    }
                    goto label;
                }
                if (ch == '1'){
                    if(P1objets.bb>0){
                        if(p1.pet!=nullptr){
                            mes("治疗自己--1 治疗宠物--2");
                            int choice;
                            while(1){
                                choice = _getch();
                                if(choice == '1'){
                                    p1.health+=500;
                                    --P1objets.bb;
                                    mes("玩家使用了血瓶并加了500血");break;
                                }
                                if(choice == '2'){
                                    p1.pet->health+=100;
                                    --P1objets.bb;
                                    mes("玩家的宠物增加了100血");break;
                                }
                                mes("取消使用血瓶");
                                break;
                            }
                        }
                        else{
                            p1.health+=500;
                            --P1objets.bb;
                            mes("玩家使用了血瓶并加了500血");
                        }
                    }
                    else mes("血瓶已经没有了");
                    goto label;
                }
                if (ch == '2'){
                    if(P1objets.bl>0){
                        p1.mana+=100;
                        --P1objets.bl;
                        mes("玩家使用了蓝瓶并加了100蓝");
                    }
                else mes("蓝瓶已经没有了");
                goto label;
                }
                if (ch == '3'){
                    int n=getroomnumber(p1,rooms);
                    if(rooms[n].monster!=0){
                        int i=getmonsternumber(mons,rooms[n]);
                        if(P1objets.po>0){
                            --P1objets.po;
                            mes("玩家对怪物使用了毒药，效果显著");
                            mons[i].posion=true;
                        }
                        else mes("毒药已经一滴都没有啦");
                        goto label;
                    }
                    else mes("没有怪物，不能乱用毒药哦");
                }
                if (ch == '4'){
                    if(P1objets.key>0){
                        mes("可以朝4个方向传送2个房间的距离：");
                        mes("(w-上 s-下 a-左 d-右)");
                        int choice;
                        while(1){
                            choice=_getch();
                            if(choice == 'w'){
                                if((p1.y-12)>3){
                                    p1.cleanplayer();
                                    mes("玩家向上传送2个房间");
                                    int j = p1.y-12;
                                    p1.y = j;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("不能向上传送");
                                    playsound();
                                }
                                break;
                            }
                            if(choice == 's'){
                                if((p1.y+12)<24){
                                    p1.cleanplayer();
                                    mes("玩家向下传送2个房间");
                                    int j = p1.y+12;
                                    p1.y = j;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("不能向下传送");
                                    playsound();
                                }
                                break;
                            }
                            if(choice == 'a'){
                                if((p1.x-24)>24){
                                    p1.cleanplayer();
                                    mes("玩家向左传送2个房间");
                                    int i = p1.x-24;
                                    p1.x = i;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("不能向左传送");
                                    playsound();
                                }
                                break;
                            }
                            if(choice == 'd'){
                                if((p1.x+24)<72){
                                    p1.cleanplayer();
                                    mes("玩家向右传送2个房间");
                                    int i = p1.x+24;
                                    p1.x = i;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("不能向右传送");
                                    playsound();
                                }
                                    break;
                            }
                                ch=0;
                                mes("取消使用传送钥匙");
                                break;
                        }
                    }
                    else mes("已经没有传送钥匙了");
                }
                if (ch == 'z'){
                    int n=getroomnumber(p1,rooms);
                    int i=getmonsternumber(mons,rooms[n]);
                    if(rooms[n].monster!=0){
                        attack(p1,mons[i],rooms[n]);
                        if(p1.health<0){
                            int n = dead();
                                switch(n){
                                case 1:
                                    system("cls");
                                    goto restart;
                                    break;
                                default:
                                    locate(0,25);
                                    exit(0);
                                    break;
                            }
                        }
                        if(mons[3].health==0){
                            int n = gameclear();
                                switch(n){
                                case 1:
                                    system("cls");
                                    goto restart;
                                    break;
                                default:
                                    exit(0);
                                    break;
                            }
                        }
                        monsterlevel = judgementmonsterlevel(p1);
                        InitMonster(monsterlevel,mons,rooms,i);
                        for(unsigned int i=1;i<=3;i++){
                            printmonster(mons[i],rooms);
                        }
                        mons[i].posion=false;
                        goto label;
                    }
                    else{
                        mes("这个房间没有怪");
                    }
                }
                if (ch == 'x'){
                    int n=getroomnumber(p1,rooms);
                    int i=getmonsternumber(mons,rooms[n]);
                    if(rooms[n].monster!=0){
                        fumo(p1,mons[i],rooms[n]);
                        if(rooms[n].monster==0){
                        monsterlevel = judgementmonsterlevel(p1);
                        InitMonster(monsterlevel,mons,rooms,i);
                        goto label;
                        }
                    }
                    else{
                        mes("这个房间没有怪");
                    }
                }
            }
            if(p1.act==0){
                ++turn;
                p1.act=6;
                if(P1objets.bb<2)InitThing(41,rooms,objets);
                if(P1objets.bl<2)InitThing(42,rooms,objets);
                if(P1objets.po<2)InitThing(43,rooms,objets);
                if(P1objets.key<2)InitThing(461,rooms,objets);   //刷新药瓶

                for(int i=1;i<=monsternumber;i++){
                    move_monster(mons[i],rooms);
                    for(unsigned int i=1;i<=3;i++)printmonster(mons[i],rooms);
                    Sleep(500);
                    for(unsigned int i=1;i<=3;i++)printmonster(mons[i],rooms);
                    move_monster(mons[i],rooms);
                    Sleep(500);
                };
                move_monster(mons[3],rooms);
                Sleep(1000);
                int n=getroomnumber(p1,rooms);
                if(rooms[n].monster==31){
                    mes("Boss对你进行了攻击");
                    Sleep(1000);
                    attack(p1,mons[3],rooms[n]);
                    if(p1.health<0){
                            int n = dead();
                                switch(n){
                                case 1:
                                    system("cls");
                                    goto restart;
                                    break;
                                default:
                                    locate(0,25);
                                    exit(0);
                                    break;
                            }
                        }
                    if(mons[3].health==0){
                            int n = gameclear();
                                switch(n){
                                case 1:
                                    system("cls");
                                    goto restart;
                                    break;
                                default:
                                    exit(0);
                                    break;
                            }
                        }
                }
                for(unsigned int i=1;i<=3;i++)printmonster(mons[i],rooms);
                mes("**********回合"+tostring<int>(turn)+"**********");goto label;
            }
    }

    return 0;
}
