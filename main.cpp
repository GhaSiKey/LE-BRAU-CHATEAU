#include "Projet.h"
using namespace std;

int main()
{
restart:srand(time(0));
    monster mons[10];
    Objet objets;
    Objet P1objets;
    Room rooms[16];
    int ch;   //���̶�ȡ
    int turn=1;   //�غ���
    int monsternumber=2;   //���Ϲ�������
    int monsterlevel=21;   //����ȼ���ʼ
    Player p1;
    printmenu(p1);
        mes("��ѡ����ְҵ��"+p1.name);
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
        InitMonster(monsterlevel,mons,rooms,i);   //����������
    }
    InitMonster(31,mons,rooms,3);  //����boss

label:uplevel(p1);
    printhead(p1);
    printbag(P1objets);
    printequip(P1objets);


    while(1){
        p1.printplayer();
        if(kbhit())
            {
                //����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if (ch == 27){
                    mes("ȷ��Ҫ�˳���y/n");
                    while(1){
                        if(kbhit())
                        {
                            ch = _getch();
                            if(ch == 'y'){
                                for(unsigned int i=0;i<10;i++) mes("");
                                system("cls");
                                goto restart;
                            }
                            else {mes("��Ϸ����");goto label;}
                        }
                    }

                }//������ESCʱѭ����ESC���ļ�ֵʱ27.
                if (ch == 72){
                    if((p1.y-6)>3){
                        p1.cleanplayer();
                        mes("��������ƶ�");
                        int j = p1.y-6;
                        p1.y = j;
                        p1.act--;goto label;
                    }
                    else {
                        mes("���������ƶ�");
                        playsound();
                    }
                }
                if (ch == 80){
                    if((p1.y+6)<24){
                        p1.cleanplayer();
                        mes("��������ƶ�");
                        int j = p1.y+6;
                        p1.y = j;
                        p1.act--;goto label;
                    }
                    else {
                        mes("���������ƶ�");
                        playsound();
                    }
                }
                if (ch == 75){
                    if((p1.x-12)>24){
                        p1.cleanplayer();
                        mes("��������ƶ�");
                        int i = p1.x-12;
                        p1.x = i;
                        p1.act--;goto label;
                    }
                    else {
                        mes("���������ƶ�");
                        playsound();
                    }
                }
                if (ch == 77){
                    if((p1.x+12)<72){
                        p1.cleanplayer();
                        mes("��������ƶ�");
                        int i = p1.x+12;
                        p1.x = i;
                        p1.act--;goto label;
                    }
                    else {
                        mes("���������ƶ�");
                        playsound();
                    }
                }
                if (ch == 32){
                    mes("��Ϸ��ͣ");
                    playsound();
                    while(1){
                        if(kbhit())
                        {
                            ch = _getch();
                            if (ch == 32){mes("��Ϸ�ָ�");playsound();goto label;};
                        }
                    }
                }
                if (ch == 'c'){
                    int i=getroomnumber(p1,rooms);
                    int thing = rooms[i].thing;
                    switch(thing){
                        case 41: rooms[i].thing=0;objets.bb=0;P1objets.bb++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("����Ѫƿ");break;//Ѫƿ
                        case 42: rooms[i].thing=0;objets.bl=0;P1objets.bl++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("������ƿ");break;//��ƿ
                        case 43: rooms[i].thing=0;objets.po=0;P1objets.po++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("���˶�ƿ");break;//��ƿ
                        case 44: rooms[i].thing=0;objets.sword1=0;P1objets.sword1++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("�����Ϲ���������ħ����");p1.atk+=50;break;//��
                        case 45: rooms[i].thing=0;objets.shield1=0;P1objets.shield1++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("����Ӣ�������������˹֮�ܶ�");p1.def=+50;break;//��
                        case 461: rooms[i].thing=0;objets.key=0;P1objets.key++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("����Կ��");break;//Կ��
                        case 462: rooms[i].thing=0;objets.Key_BOSS=0;P1objets.Key_BOSS++;locate(rooms[i].getx()-2,rooms[i].gety()); cout<< "  ";mes("��ͨ���ˣ�");break;//ͨ��Կ��
                    }
                    goto label;
                }
                if (ch == '1'){
                    if(P1objets.bb>0){
                        if(p1.pet!=nullptr){
                            mes("�����Լ�--1 ���Ƴ���--2");
                            int choice;
                            while(1){
                                choice = _getch();
                                if(choice == '1'){
                                    p1.health+=500;
                                    --P1objets.bb;
                                    mes("���ʹ����Ѫƿ������500Ѫ");break;
                                }
                                if(choice == '2'){
                                    p1.pet->health+=100;
                                    --P1objets.bb;
                                    mes("��ҵĳ���������100Ѫ");break;
                                }
                                mes("ȡ��ʹ��Ѫƿ");
                                break;
                            }
                        }
                        else{
                            p1.health+=500;
                            --P1objets.bb;
                            mes("���ʹ����Ѫƿ������500Ѫ");
                        }
                    }
                    else mes("Ѫƿ�Ѿ�û����");
                    goto label;
                }
                if (ch == '2'){
                    if(P1objets.bl>0){
                        p1.mana+=100;
                        --P1objets.bl;
                        mes("���ʹ������ƿ������100��");
                    }
                else mes("��ƿ�Ѿ�û����");
                goto label;
                }
                if (ch == '3'){
                    int n=getroomnumber(p1,rooms);
                    if(rooms[n].monster!=0){
                        int i=getmonsternumber(mons,rooms[n]);
                        if(P1objets.po>0){
                            --P1objets.po;
                            mes("��ҶԹ���ʹ���˶�ҩ��Ч������");
                            mons[i].posion=true;
                        }
                        else mes("��ҩ�Ѿ�һ�ζ�û����");
                        goto label;
                    }
                    else mes("û�й���������ö�ҩŶ");
                }
                if (ch == '4'){
                    if(P1objets.key>0){
                        mes("���Գ�4��������2������ľ��룺");
                        mes("(w-�� s-�� a-�� d-��)");
                        int choice;
                        while(1){
                            choice=_getch();
                            if(choice == 'w'){
                                if((p1.y-12)>3){
                                    p1.cleanplayer();
                                    mes("������ϴ���2������");
                                    int j = p1.y-12;
                                    p1.y = j;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("�������ϴ���");
                                    playsound();
                                }
                                break;
                            }
                            if(choice == 's'){
                                if((p1.y+12)<24){
                                    p1.cleanplayer();
                                    mes("������´���2������");
                                    int j = p1.y+12;
                                    p1.y = j;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("�������´���");
                                    playsound();
                                }
                                break;
                            }
                            if(choice == 'a'){
                                if((p1.x-24)>24){
                                    p1.cleanplayer();
                                    mes("���������2������");
                                    int i = p1.x-24;
                                    p1.x = i;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("����������");
                                    playsound();
                                }
                                break;
                            }
                            if(choice == 'd'){
                                if((p1.x+24)<72){
                                    p1.cleanplayer();
                                    mes("������Ҵ���2������");
                                    int i = p1.x+24;
                                    p1.x = i;
                                    --P1objets.key;goto label;
                                }
                                else {
                                    mes("�������Ҵ���");
                                    playsound();
                                }
                                    break;
                            }
                                ch=0;
                                mes("ȡ��ʹ�ô���Կ��");
                                break;
                        }
                    }
                    else mes("�Ѿ�û�д���Կ����");
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
                        mes("�������û�й�");
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
                        mes("�������û�й�");
                    }
                }
            }
            if(p1.act==0){
                ++turn;
                p1.act=6;
                if(P1objets.bb<2)InitThing(41,rooms,objets);
                if(P1objets.bl<2)InitThing(42,rooms,objets);
                if(P1objets.po<2)InitThing(43,rooms,objets);
                if(P1objets.key<2)InitThing(461,rooms,objets);   //ˢ��ҩƿ

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
                    mes("Boss��������˹���");
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
                mes("**********�غ�"+tostring<int>(turn)+"**********");goto label;
            }
    }

    return 0;
}
