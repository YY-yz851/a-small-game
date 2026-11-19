#include"Animal.h"
Animal::Animal(Game* g,int r,int c,int maxhp):Item(g,r,c),hp(maxhp),maxHp(maxhp){}
void Animal::jump(int range){
    int nr=(int)row+randomBetween(-range,range);
    int nc=(int)col+randomBetween(-range,range);
    if(nr<0) nr=0;
    if(nr>MAXROW-1) nr=MAXROW-1;
    if(nc<0) nc=0;
    if(nc>MAXCOL-1) nc=MAXCOL-1;
    row=nr;
    col=nc;
}
void Animal::heal(int add){
    hp+=add;
    if(hp>maxHp) hp=maxHp;
}