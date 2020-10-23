#include<graphics.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include"map.h"
#include"Tank.h"
#include"Bullet.h"

void Menu()
{
    //Home Screen window
    initwindow(900,600,"HOME",100,100);
    POINT CursorPosition;

    while(1)
    {
        settextstyle(9,HORIZ_DIR,5);
        setcolor(RED);
        outtextxy(200,100,"TANK GAME");
        settextstyle(9,HORIZ_DIR,1);
        setcolor(WHITE);
        outtextxy(300,200,"MENU");
        outtextxy(220,250,"1. START");
        outtextxy(220,300,"2. HOW TO PLAY");


        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&CursorPosition);
            //Mouse Click To start the game
            if((CursorPosition.x>=350 && CursorPosition.x<=430) && (CursorPosition.y>=370 && CursorPosition.y<=390))
            {
                //loading screen
                delay(500);
                outtextxy(220,450,"LOADING");
                delay(500);
                outtextxy(340,450,".");
                delay(500);
                outtextxy(360,450,".");
                delay(500);
                outtextxy(380,450,".");
                delay(500);
                outtextxy(400,450,".");
                break;
            }
            //Mouse click for Instructions
            if((CursorPosition.x>=350 && CursorPosition.x<=510) && (CursorPosition.y>=420 && CursorPosition.y<=440))
            {
                //INSTRUCTIONS Window
                initwindow(900,600,"INSTRUCTIONS",100,100,false,false);
                while(1)
                {
                    outtextxy(50,50,"PLAYER 1:");
                    outtextxy(750,470,"START >>");

                    if(GetAsyncKeyState(VK_LBUTTON))

                    {   GetCursorPos(&CursorPosition);
                        //mouse click to start the game from instructions window
                        if((CursorPosition.x>=850 && CursorPosition.x<=920) && (CursorPosition.y>=590 && CursorPosition.y<=610))
                        {
                            settextstyle(9,HORIZ_DIR,1);
                            delay(500);
                            outtextxy(220,550,"LOADING");
                            delay(500);
                            outtextxy(340,550,".");
                            delay(500);
                            outtextxy(360,550,".");
                            delay(500);
                            outtextxy(380,550,".");
                            delay(500);
                            outtextxy(400,550,".");
                            break;
                        }
                    }
                }
                break;
            }

         }

    }
}

int main()
{
    label:
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    Menu();

    initwindow(width, height, "Tank Trouble", -3, 0, false, true);
    int page=0;
    GameActive = true ;

    while(GameActive)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        T1Coordinates();
        T2Coordinates();
        DrawMap();

        if(GetAsyncKeyState(VK_UP))
        {
            MoveFront();
            T1Coordinates();
            if(ConditionCheck()==0)
            {
                MoveBack();
                T1Coordinates();
            }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            MoveBack();
            T1Coordinates();
            if(ConditionCheck()==0)
            {
                MoveFront();
                T1Coordinates();
            }
        }
       if(GetAsyncKeyState(VK_RIGHT))
        {
            angle1 -= M_PI/45.0;
            degree1 -=4;                   //4 degree
            T1Coordinates();
             if(ConditionCheck()==0)
            {
                angle1 += M_PI/45.0;
                degree1 +=4;
                T1Coordinates();
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            angle1 += M_PI/45.0;
            degree1 +=4;                  //4 degree
            T1Coordinates();
            if(ConditionCheck()==0)
            {
                angle1 -= M_PI/45.0;
                degree1 -=4;
                T1Coordinates();
            }
        }
        if(GetAsyncKeyState(VK_RCONTROL))
        {
            NewBullet1();
        }
         if(GetAsyncKeyState('W'))
        {
            MoveFront2();
            T2Coordinates();
            if(ConditionCheck2()==0)
            {
                MoveBack2();
                T2Coordinates();
            }
        }
        if(GetAsyncKeyState('S'))
        {
            MoveBack2();
            T2Coordinates();
            if(ConditionCheck2()==0)
            {
                MoveFront2();
                T2Coordinates();
            }
        }
       if(GetAsyncKeyState('D'))
        {
            angle2 -= M_PI/45.0;
            degree2 -=4;                   //4 degree
            T2Coordinates();
             if(ConditionCheck2()==0)
            {
                angle2 += M_PI/45.0;
                degree2 +=4;
                T2Coordinates();
            }
        }
        if(GetAsyncKeyState('A'))
        {
            angle2 += M_PI/45.0;
            degree2 +=4;                  //4 degree
            T2Coordinates();
            if(ConditionCheck2()==0)
            {
                angle2 -= M_PI/45.0;
                degree2 -=4;
                T2Coordinates();
            }
        }
        if(GetAsyncKeyState(VK_LCONTROL))
        {
            NewBullet2();
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            GameActive = false;
        }
        DrawTank();
        DrawTank2();
        MoveBullet1();
        MoveBullet2();
        page=1-page;
        delay(10);
     }

  //  getch();
    closegraph();
    goto label;
}
