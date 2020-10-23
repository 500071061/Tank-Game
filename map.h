
//for moving borders
int lx=0,rx=0,k=0,s=0;

void DrawMap()
{
    setbkcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 5);

    rectangle(150, 100, 1350, 700);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(750, 400, BLACK);

    //left line
    if(lx<=600)
    {
        line(150,415,150+lx,415);
    }
    if(lx>600 && lx<=1200)
    {
        line(150,415,1350-lx,415);
    }
    if(lx>=1200)
    {
        lx=0;
    }
    lx+=3;

    //right line
    if(rx<=600)
    {
        line(1350,415,1350-rx,415);
    }
    if(rx>600 && rx<=1200)
    {
        line(1350,415,150+rx,415);
    }
    if(rx>=1200)
    {
        rx=0;
    }
    rx+=3;

    line(750,100,750,200);
    int e[]={900,190,900,320,650,320};
    drawpoly(3, e);
    int m[]={150,580,250,580,250,500};
    drawpoly(3,m);
    int w[]={750,500,750,560,650,560,650,500};
    drawpoly(4,w);
    line(540,700,540,590);
    line(540,590,420,590);
    line(750,200,650,200);
    line(540,100,540,250);
    line(920,700,920,550);
    line(920,590,1010,590);
    int t[]={1350,500,1100,500,1100,580};
    drawpoly(3,t);


if(k<=200)
{
        int r[]={250+k,200,350,200,350,300,250+k,300};
        drawpoly(4, r);
        k++;
}
if(k>=200&&k<=400)
{
    int r[]={650-k,200,350,200,350,300,650-k,300};
        drawpoly(4, r);
        k++;
}
if(k>=400&&k<=1000)
{
     int r[]={250,200,350,200,350,300,250,300};
        drawpoly(4, r);
        k++;
}
if(k>1000)
{
    k=0;
}


if(s<=200)
{
        int body_1[]={1100+s,200,1200,200,1200,300,1100+s,300};
        drawpoly(4, body_1);
        s++;
}
if(s>=200&&s<=400)
{
    int body_1[]={1500-s,200,1200,200,1200,300,1500-s,300};
        drawpoly(4, body_1);
        s++;
}
if(s>=400&&s<=1000)
{
     int body_1[]={1100,200,1200,200,1200,300,1100,300};
        drawpoly(4, body_1);
        s++;
}
if(s>1000)
{
    s=0;
}

}
