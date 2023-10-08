#include <stdio.h>
#include <stdlib.h>
int height=20,width=40,gameover;
int x,y,fx,fy,score,flag=0;
void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;

    label1:
    fx=rand()%20;//it chooses no. from 0 to 40
     if(fx==0||fx==width-1)
     {
         goto label1;
     }
    label2:
    fy=rand()%20;//it chooses no. from 0 to 20
     if(fy==0||fy==height-1)
     {
         goto label2;
     }
     score=0;

}

void draw()
{ int i,j;
    system("cls");

    for(i=0;i<height;i++)
    {
         printf(" ");
        for(j=0;j<width;j++)
        {
            if(i==0||i==height-1||j==0||j==width-1)
            {
                printf("*");
            }
            else
            {
                if(j==x&&i==y)
                {
                    printf("O");
                }
                else if(j==fx&&i==fy)
                {
                    printf("@");
                }
                else
                {
                printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void input()//identify that any key is pressed
{
    if(kbhit())//until and unless a key from the keyboard is pressed it returns 0
    {
        switch(getch())
        {
            case 'a':flag=1;
                      break;
            case 's':flag=2;
                      break;
            case 'w':flag=3;
                      break;
            case 'z':flag=4;
                      break;
            case 'x':gameover=1;
                      break;
        }
    }
}
void logic()
{
    switch(flag)
    {
    case 1: x--;
            break;
    case 2: x++;
            break;
    case 3:y--;
            break;
    case 4:y++;
            break;
    default: break;
    }
  if(x<0||x>height||y<0||y>width)
        gameover=1;
  if(x==fx&&y==fy)
  {
      label3:
      fx=rand()%width;//it chooses no. from 0 to 20
     if(fx==0||fx==width-1)
     {
         goto label3;
     }
      label4:
      fy=rand()%height;//it chooses no. from 0 to 20
     if(fy==0||fy==height-1)
     {
         goto label4;
     }
  }
  score+=10;

}

void main()
{
    int m,n;
    setup();
    while(!gameover)
    {
      draw();
      input();
      logic();
      for(m=0;m<1000;m++)
        {
         for(n=0;n<120000;n++)
        {
        }
        }
    }
    return 0;
}
