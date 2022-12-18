#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <stdbool.h>
#define DEGER 100000

int main(int argc, char const *argv[]) {

  FILE *f;
  int N;
  double points[DEGER][2]; //x, y
  int i, j;


  if((f = fopen("noktalar.txt","r")) == NULL){
    printf("Error opening the file");
    exit(1);
  }

  fscanf(f, "%d", &N);

  for(i=0;i<N;i++){
    fscanf(f, "%lf %lf", &points[i][0], &points[i][1]);
  }
double R;
  double mesafe;
  double m,n,r;
  //double enbuyuk_mesafe;
if(N==0){
    m=0;
    n=0;
    r=0;
}
 if(N==1){
    m=points[0][0];
    n=points[0][1];
    r=0;
 }
 if(N==2){
    m=(points[0][0]+points[1][0])/2;
    n=(points[0][1]+points[1][1])/2;
    r=sqrt(pow(points[0][0]-points[1][0], 2) + pow(points[0][1] -points[1][1], 2))/2;
 }
if(N>=3){



int a=0,b=0,c=0,d=0;


int xenkucuk=points[0][0];
int xenbuyuk=points[0][0];
int yenkucuk=points[0][1];
int yenbuyuk=points[0][1];

// en kucuk x, en buyuk x ,en kucuk y,en buyuk y
for(i=1;i<N;i++){
    if(points[i][0]<xenkucuk){
        a=i;
        xenkucuk=points[i][0];
    }
    if(points[i][0]>xenbuyuk){
        b=i;
        xenbuyuk=points[i][0];

    }
     if(points[i][0]<yenkucuk){
        c=i;
        yenkucuk=points[i][1];

    }
     if(points[i][1]>yenbuyuk){
        d=i;
        yenbuyuk=points[i][1];

    }
}
// 4 noktadan mutlak degeri en büyük olan 3 noktayi secme




double x1,y1,x2,y2,x3,y3;

int enkucuk_x=abs(points[a][0]);
int enbuyuk_x=abs(points[b][0]);
int enkucuk_y=abs(points[c][1]);
int enbuyuk_y=abs(points[d][1]);

if( enkucuk_x<enbuyuk_x){
    x1=points[b][0];
    y1=points[b][1];
}else{
    x1=points[a][0];
    y1=points[a][1];

}if( enkucuk_x<enkucuk_y){
    y2=points[c][1];
    x2=points[c][0];
}else{
    x2=points[a][0];
    y2=points[a][1];

}if( enkucuk_x<enbuyuk_y){
    y3=points[d][1];
    x3=points[d][0];
}else{
    x3=points[a][0];
    y3=points[a][1];
}



    double x12 = x1 - x2;
    double x13 = x1 - x3;
    double y12 = y1 - y2;
    double y13 = y1 - y3;
    double y31 = y3 - y1;
    double y21 = y2 - y1;
    double x31 = x3 - x1;
    double x21 = x2 - x1;



    double sx13 = pow(x1, 2) - pow(x3, 2);
    double sy13 = pow(y1, 2) - pow(y3, 2);
    double sx21 = pow(x2, 2) - pow(x1, 2);
    double sy21 = pow(y2, 2) - pow(y1, 2);

    double f = ((sx13) * (x12)+ (sy13) * (x12)+ (sx21) * (x13)+ (sy21) * (x13))/ (2 * ((y31) * (x12) - (y21) * (x13)));

    double g = ((sx13) * (y12)+ (sy13) * (y12)+ (sx21) * (y13)+ (sy21) * (y13))/ (2 * ((x31) * (y12) - (x21) * (y13)));

    double q = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;
    m = -g;//x
    n = -f;//y
    double rkare = m * m + n * n - q;

    double r = sqrt(rkare);

     R=r;
}



    printf(" merkez -> (%.2lf, %.2lf), yaricap -> %.2lf\n", m, n, R);



//arayüz
initwindow(700,600);
line(0,300,600,300);
line(300,0,300,600);
setcolor(WHITE);
int x=25;
for(int i=0;i<23;i++){
    line(x,297,x,303);
    x=x+25;
}
int y=25;
for(int i=0;i<23;i++){
    line(297,y,303,y);
    y=y+25;
}
//  kordinat düzlemine rakamlari yazdirma
  char rakam[11];
        int sayi;
        int xnegatif=18;
        int xpozitif=320;
        int ypozitif=18;
        int ynegatif=320;

    for(int i=0;i<11;i++){
        rakam[i]=i-11;
        sayi=rakam[i];
        sprintf(rakam,"%d",sayi);
        outtextxy(xnegatif,310,rakam);
        xnegatif=xnegatif+25;
    }
    for(int i=0;i<11;i++){
        rakam[i]=i+1;
        sayi=rakam[i];
         sprintf(rakam,"%d",sayi);
        outtextxy(xpozitif,310,rakam);
        xpozitif=xpozitif+25;

    }
    for(int i=0;i<11;i++){
        rakam[i]=11-i;
        sayi=rakam[i];
        sprintf(rakam,"%d",sayi);
        outtextxy(310,ypozitif,rakam);
        ypozitif=ypozitif+25;
    }
 for(int i=0;i<11;i++){
        rakam[i]=-i-1;
        sayi=rakam[i];
        sprintf(rakam,"%d",sayi);
        outtextxy(310,ynegatif,rakam);
        ynegatif=ynegatif+25;
    }

float xson,yson,rson;
xson=m*25+300;
yson=300-n*25;
rson=R*25;
setcolor(LIGHTCYAN);
    circle(xson,yson,rson);
    setcolor(LIGHTMAGENTA);

    circle(xson,yson,3);
    line(xson,yson,xson+rson,yson);

setcolor(YELLOW);

  for(i=0;i<N;i++){
    fscanf(f, "%lf %lf", &points[i][0], &points[i][1]);
    if(points[i][0]!=0 && points[i][1]!=0){
        points[i][0]=300+points[i][0]*25;
        points[i][1]=300-points[i][1]*25;

        circle(points[i][0],points[i][1],3);
    }

    else  if(points[i][0]==0){

        points[i][1]=300-points[i][1]*25;

        circle(300,points[i][1],3);
    }
    else  if(points[i][1]==0){

        points[i][0]=300+points[i][0]*25;

        circle(points[i][0],300,3);
    }
    else  if(points[i][0]==0 && points[i][1]==0){


        circle(300,300,3);
    }
  }




    getch();
    closegraph();

    return 0;
}
