int Tank1X=300, Tank1Y=500;
int Tank2x=1200, Tank2y=340;


double angle1=M_PI_4;
double angle2=M_PI_4;
double r=30;


//coordinates of tank 1
//body
int Tank1x1, Tank1y1,
    Tank1x2, Tank1y2,
    Tank1x3, Tank1y3,
    Tank1x4, Tank1y4;

//shoot
int Shoot1x1, Shoot1y1,
    Shoot1x2, Shoot1y2,
    Shoot1x3, Shoot1y3,
    Shoot1x4, Shoot1y4;

//coordinates of tank 2
int Tank2x1, Tank2y1,
    Tank2x2, Tank2y2,
    Tank2x3, Tank2y3,
    Tank2x4, Tank2y4;

//shoot
int Shoot2x1, Shoot2y1,
    Shoot2x2, Shoot2y2,
    Shoot2x3, Shoot2y3,
    Shoot2x4, Shoot2y4;

int degree1=0;
int degree2=0;

void MoveFront()
{
    Tank1X += (int) (5.0 * cos(angle1-M_PI_4));
    Tank1Y -= (int) (5.0 * sin(angle1-M_PI_4));
}

void MoveBack()
{
    Tank1X -= (int) (5.0 * cos(angle1-M_PI_4));
    Tank1Y += (int) (5.0 * sin(angle1-M_PI_4));
}

void MoveFront2()
{
    Tank2x += (int) (5.0 * cos(angle2-M_PI_4));
    Tank2y -= (int) (5.0 * sin(angle2-M_PI_4));
}

void MoveBack2()
{
    Tank2x -= (int) (5.0 * cos(angle2-M_PI_4));
    Tank2y += (int) (5.0 * sin(angle2-M_PI_4));
}

int ConditionCheck()
{   //1/2 coordinates of body
    int Tank1Midx1x2 = (Tank1x1 + Tank1x2) / 2, Tank1Midy1y2 = (Tank1y1 + Tank1y2) / 2 ;
    int Tank1Midx2x3 = (Tank1x2 + Tank1x3) / 2, Tank1Midy2y3 = (Tank1y2 + Tank1y3) / 2 ;
    int Tank1Midx4x1 = (Tank1x4 + Tank1x1) / 2, Tank1Midy4y1 = (Tank1y4 + Tank1y1) / 2 ;
    int Tank1Midx3x4 = (Tank1x3 + Tank1x4) / 2, Tank1Midy3y4 = (Tank1y3 + Tank1y4) / 2 ;
    //1/2 coordinate of Shoot
    int Shoot1Midx3x4 = (Shoot1x3 + Shoot1x4) / 2, Shoot1Midy3y4 = (Shoot1y3 + Shoot1y4) / 2;
    //1/4 and 3/4 coordinates of body
    int Tank1Midx1_x1x2 = (Tank1x1 + Tank1Midx1x2) / 2, Tank1Midy1_y1y2 = (Tank1y1 + Tank1Midy1y2) / 2;
    int Tank1Midx1x2_x2 = (Tank1Midx1x2 + Tank1x2) / 2, Tank1Midy1y2_y2 = (Tank1Midy1y2 + Tank1y2) / 2;
    int Tank1Midx2_x2x3 = (Tank1x2 + Tank1Midx2x3) / 2, Tank1Midy2_y2y3 = (Tank1y2 + Tank1Midy2y3) / 2;
    int Tank1Midx2x3_x3 = (Tank1Midx2x3 + Tank1x3) / 2, Tank1Midy2y3_y3 = (Tank1Midy2y3 + Tank1y3) / 2;
    int Tank1Midx4_x4x1 = (Tank1x4 + Tank1Midx4x1) / 2, Tank1Midy4_y4y1 = (Tank1y4 + Tank1Midy4y1) / 2;
    int Tank1Midx4x1_x1 = (Tank1Midx4x1 + Tank1x1) / 2, Tank1Midy4y1_y1 = (Tank1Midy4y1 + Tank1y1) / 2;
    int Tank1Midx3_x3x4 = (Tank1Midx3x4 + Tank1x3) / 2, Tank1Midy3_y3y4 = (Tank1Midy3y4 + Tank1y3) / 2;
    int Tank1Midx3x4_x4 = (Tank1Midx3x4 + Tank1x4) / 2, Tank1Midy3y4_y4 = (Tank1Midy3y4 + Tank1y4) / 2;
    //1/8 coordinates of body
    int Tank1Midx1__x1_x1x2 = (Tank1x1 + Tank1Midx1_x1x2) / 2, Tank1Midy1__y1_y1y2 = (Tank1y1 + Tank1Midy1_y1y2) / 2;
    int Tank1Midx1_x1x2__x1x2 = (Tank1Midx1_x1x2 + Tank1Midx1x2) / 2, Tank1Midy1_y1y2__y1y2 = (Tank1Midy1_y1y2 + Tank1Midy1y2) / 2;
    int Tank1Midx1x2__x1x2_x2 = (Tank1Midx1x2 + Tank1Midx1x2_x2) / 2, Tank1Midy1y2__y1y2_y2 = (Tank1Midy1y2 + Tank1Midy1y2_y2) / 2;
    int Tank1Midx1x2_x2__x2 = (Tank1Midx1x2_x2 + Tank1x2) / 2, Tank1Midy1y2_y2__y2 = (Tank1Midy1y2_y2 + Tank1y2) / 2;
    int Tank1Midx2__x2_x2x3 = (Tank1x2 + Tank1Midx2_x2x3) / 2, Tank1Midy2__y2_y2y3 = (Tank1y2 + Tank1Midy2_y2y3) / 2;
    int Tank1Midx2_x2x3__x2x3 = (Tank1Midx2_x2x3 + Tank1Midx2x3) / 2, Tank1Midy2_y2y3__y2y3 = (Tank1Midy2_y2y3 + Tank1Midy2y3) / 2;
    int Tank1Midx2x3__x2x3_x3 = (Tank1Midx2x3 + Tank1Midx2x3_x3) / 2, Tank1Midy2y3__y2y3_y3 = (Tank1Midy2y3 + Tank1Midy2y3_y3) / 2;
    int Tank1Midx2x3_x3__x3 = (Tank1Midx2x3_x3 + Tank1x3) / 2, Tank1Midy2y3_y3__y3 = (Tank1Midy2y3_y3 + Tank1y3) / 2;
    int Tank1Midx4__x4_x4x1 = (Tank1x4 + Tank1Midx4_x4x1) / 2, Tank1Midy4__y4_y4y1 = (Tank1y4 + Tank1Midy4_y4y1) / 2;
    int Tank1Midx4_x4x1__x4x1 = (Tank1Midx4_x4x1 + Tank1Midx4x1) / 2, Tank1Midy4_y4y1__y4y1 = (Tank1Midy4_y4y1 + Tank1Midy4y1) / 2;
    int Tank1Midx4x1__x4x1_x1 = (Tank1Midx4x1 + Tank1Midx4x1_x1) / 2, Tank1Midy4y1__y4y1_y1 = (Tank1Midy4y1 + Tank1Midy4y1_y1) / 2;
    int Tank1Midx4x1_x1__x1 = (Tank1Midx4x1_x1 + Tank1x1) / 2, Tank1Midy4y1_y1__y1 = (Tank1Midy4y1_y1 + Tank1y1) / 2;
    int Tank1Midx3__x3_x3x4 = (Tank1x3 + Tank1Midx3_x3x4) / 2, Tank1Midy3__y3_y3y4 = (Tank1y3 + Tank1Midy3_y3y4) / 2;
    int Tank1Midx3_x3x4__x3x4 = (Tank1Midx3_x3x4 + Tank1Midx3x4) / 2, Tank1Midy3_y3y4__y3y4 = (Tank1Midy3_y3y4 + Tank1Midy3y4) / 2;
    int Tank1Midx3x4__x3x4_x4 = (Tank1Midx3x4 + Tank1Midx3x4_x4) / 2, Tank1Midy3y4__y3y4_y4 = (Tank1Midy3y4 + Tank1Midy3y4_y4) / 2;
    int Tank1Midx3x4_x4__x4 = (Tank1Midx3x4_x4 + Tank1x4) / 2, Tank1Midy3y4_y4__y4 = (Tank1Midy3y4_y4 + Tank1y4) / 2;

    //1/4 and 3/4 coordinates of shoot
    int Shoot1Midx3_x3x4 = (Shoot1x3 + Shoot1Midx3x4) / 2, Shoot1Midy3_y3y4 = (Shoot1y3 + Shoot1Midy3y4) / 2;  //1/4
    int Shoot1Midx3x4_x4 = (Shoot1Midx3x4 + Shoot1x4) / 2, Shoot1Midy3y4_y4 = (Shoot1Midy3y4 + Shoot1y4) / 2;  //3/4

    //condition to check black line
    if(getpixel(Tank1x1,Tank1y1) && getpixel(Tank1x2, Tank1y2) && getpixel(Tank1x3,Tank1y3) && getpixel(Tank1x4,Tank1y4) && getpixel(Shoot1x3,Shoot1y3) && getpixel(Shoot1x4,Shoot1y4))
    {
        if(getpixel(Tank1Midx1x2,Tank1Midy1y2) && getpixel(Tank1Midx2x3,Tank1Midy2y3) && getpixel(Tank1Midx4x1,Tank1Midy4y1) && getpixel(Shoot1Midx3x4, Shoot1Midy3y4)
           && getpixel(Tank1Midx1_x1x2, Tank1Midy1_y1y2) && getpixel(Tank1Midx1x2_x2, Tank1Midy1y2_y2)
           && getpixel(Shoot1Midx3_x3x4, Shoot1Midy3_y3y4) && getpixel(Shoot1Midx3x4_x4, Shoot1Midy3y4_y4) && getpixel(Tank1Midx2_x2x3, Tank1Midy2_y2y3)
           && getpixel(Tank1Midx2x3_x3, Tank1Midy2y3_y3 ) && getpixel(Tank1Midx4_x4x1, Tank1Midy4_y4y1 ) && getpixel(Tank1Midx4x1_x1 ,Tank1Midy4y1_y1 )
           && getpixel(Tank1Midx3x4, Tank1Midy3y4) && getpixel(Tank1Midx3_x3x4, Tank1Midy3_y3y4) && getpixel(Tank1Midx3x4_x4, Tank1Midy3y4_y4)
           && getpixel(Tank1Midx1__x1_x1x2, Tank1Midy1__y1_y1y2) && getpixel(Tank1Midx1_x1x2__x1x2, Tank1Midy1_y1y2__y1y2)
           && getpixel(Tank1Midx1x2__x1x2_x2, Tank1Midy1y2__y1y2_y2 ) && getpixel(Tank1Midx1x2_x2__x2, Tank1Midy1y2_y2__y2)
           && getpixel(Tank1Midx2__x2_x2x3, Tank1Midy2__y2_y2y3) && getpixel(Tank1Midx2_x2x3__x2x3, Tank1Midy2_y2y3__y2y3 )
           && getpixel(Tank1Midx2x3__x2x3_x3, Tank1Midy2y3__y2y3_y3 ) && getpixel(Tank1Midx2x3_x3__x3, Tank1Midy2y3_y3__y3)
           && getpixel(Tank1Midx4__x4_x4x1, Tank1Midy4__y4_y4y1 ) && getpixel(Tank1Midx4_x4x1__x4x1, Tank1Midy4_y4y1__y4y1 )
           && getpixel(Tank1Midx4x1__x4x1_x1, Tank1Midy4y1__y4y1_y1) && getpixel(Tank1Midx4x1_x1__x1, Tank1Midy4y1_y1__y1)
           && getpixel(Tank1Midx3__x3_x3x4, Tank1Midy3__y3_y3y4) && getpixel(Tank1Midx3_x3x4__x3x4, Tank1Midy3_y3y4__y3y4)
           && getpixel(Tank1Midx3x4__x3x4_x4, Tank1Midy3y4__y3y4_y4 ) && getpixel(Tank1Midx3x4_x4__x4, Tank1Midy3y4_y4__y4)
           )
          {
              return 1;
          }
    }
    return 0;

}

int ConditionCheck2()
{   //1/2 coordinates of body
    int Tank2Midx1x2 = (Tank2x1 + Tank2x2) / 2, Tank2Midy1y2 = (Tank2y1 + Tank2y2) / 2 ;
    int Tank2Midx2x3 = (Tank2x2 + Tank2x3) / 2, Tank2Midy2y3 = (Tank2y2 + Tank2y3) / 2 ;
    int Tank2Midx4x1 = (Tank2x4 + Tank2x1) / 2, Tank2Midy4y1 = (Tank2y4 + Tank2y1) / 2 ;
    int Tank2Midx3x4 = (Tank2x3 + Tank2x4) / 2, Tank2Midy3y4 = (Tank2y3 + Tank2y4) / 2 ;
    //1/2 coordinate of Shoot
    int Shoot2Midx3x4 = (Shoot2x3 + Shoot2x4) / 2, Shoot2Midy3y4 = (Shoot2y3 + Shoot2y4) / 2;
    //1/4 and 3/4 coordinates of body
    int Tank2Midx1_x1x2 = (Tank2x1 + Tank2Midx1x2) / 2, Tank2Midy1_y1y2 = (Tank2y1 + Tank2Midy1y2) / 2;
    int Tank2Midx1x2_x2 = (Tank2Midx1x2 + Tank2x2) / 2, Tank2Midy1y2_y2 = (Tank2Midy1y2 + Tank2y2) / 2;
    int Tank2Midx2_x2x3 = (Tank2x2 + Tank2Midx2x3) / 2, Tank2Midy2_y2y3 = (Tank2y2 + Tank2Midy2y3) / 2;
    int Tank2Midx2x3_x3 = (Tank2Midx2x3 + Tank2x3) / 2, Tank2Midy2y3_y3 = (Tank2Midy2y3 + Tank2y3) / 2;
    int Tank2Midx4_x4x1 = (Tank2x4 + Tank2Midx4x1) / 2, Tank2Midy4_y4y1 = (Tank2y4 + Tank2Midy4y1) / 2;
    int Tank2Midx4x1_x1 = (Tank2Midx4x1 + Tank2x1) / 2, Tank2Midy4y1_y1 = (Tank2Midy4y1 + Tank2y1) / 2;
    int Tank2Midx3_x3x4 = (Tank2Midx3x4 + Tank2x3) / 2, Tank2Midy3_y3y4 = (Tank2Midy3y4 + Tank2y3) / 2;
    int Tank2Midx3x4_x4 = (Tank2Midx3x4 + Tank2x4) / 2, Tank2Midy3y4_y4 = (Tank2Midy3y4 + Tank2y4) / 2;
    //1/8 coordinates of body
    int Tank2Midx1__x1_x1x2 = (Tank2x1 + Tank2Midx1_x1x2) / 2, Tank2Midy1__y1_y1y2 = (Tank2y1 + Tank2Midy1_y1y2) / 2;
    int Tank2Midx1_x1x2__x1x2 = (Tank2Midx1_x1x2 + Tank2Midx1x2) / 2, Tank2Midy1_y1y2__y1y2 = (Tank2Midy1_y1y2 + Tank2Midy1y2) / 2;
    int Tank2Midx1x2__x1x2_x2 = (Tank2Midx1x2 + Tank2Midx1x2_x2) / 2, Tank2Midy1y2__y1y2_y2 = (Tank2Midy1y2 + Tank2Midy1y2_y2) / 2;
    int Tank2Midx1x2_x2__x2 = (Tank2Midx1x2_x2 + Tank2x2) / 2, Tank2Midy1y2_y2__y2 = (Tank2Midy1y2_y2 + Tank2y2) / 2;
    int Tank2Midx2__x2_x2x3 = (Tank2x2 + Tank2Midx2_x2x3) / 2, Tank2Midy2__y2_y2y3 = (Tank2y2 + Tank2Midy2_y2y3) / 2;
    int Tank2Midx2_x2x3__x2x3 = (Tank2Midx2_x2x3 + Tank2Midx2x3) / 2, Tank2Midy2_y2y3__y2y3 = (Tank2Midy2_y2y3 + Tank2Midy2y3) / 2;
    int Tank2Midx2x3__x2x3_x3 = (Tank2Midx2x3 + Tank2Midx2x3_x3) / 2, Tank2Midy2y3__y2y3_y3 = (Tank2Midy2y3 + Tank2Midy2y3_y3) / 2;
    int Tank2Midx2x3_x3__x3 = (Tank2Midx2x3_x3 + Tank2x3) / 2, Tank2Midy2y3_y3__y3 = (Tank2Midy2y3_y3 + Tank2y3) / 2;
    int Tank2Midx4__x4_x4x1 = (Tank2x4 + Tank2Midx4_x4x1) / 2, Tank2Midy4__y4_y4y1 = (Tank2y4 + Tank2Midy4_y4y1) / 2;
    int Tank2Midx4_x4x1__x4x1 = (Tank2Midx4_x4x1 + Tank2Midx4x1) / 2, Tank2Midy4_y4y1__y4y1 = (Tank2Midy4_y4y1 + Tank2Midy4y1) / 2;
    int Tank2Midx4x1__x4x1_x1 = (Tank2Midx4x1 + Tank2Midx4x1_x1) / 2, Tank2Midy4y1__y4y1_y1 = (Tank2Midy4y1 + Tank2Midy4y1_y1) / 2;
    int Tank2Midx4x1_x1__x1 = (Tank2Midx4x1_x1 + Tank2x1) / 2, Tank2Midy4y1_y1__y1 = (Tank2Midy4y1_y1 + Tank2y1) / 2;
    int Tank2Midx3__x3_x3x4 = (Tank2x3 + Tank2Midx3_x3x4) / 2, Tank2Midy3__y3_y3y4 = (Tank2y3 + Tank2Midy3_y3y4) / 2;
    int Tank2Midx3_x3x4__x3x4 = (Tank2Midx3_x3x4 + Tank2Midx3x4) / 2, Tank2Midy3_y3y4__y3y4 = (Tank2Midy3_y3y4 + Tank2Midy3y4) / 2;
    int Tank2Midx3x4__x3x4_x4 = (Tank2Midx3x4 + Tank2Midx3x4_x4) / 2, Tank2Midy3y4__y3y4_y4 = (Tank2Midy3y4 + Tank2Midy3y4_y4) / 2;
    int Tank2Midx3x4_x4__x4 = (Tank2Midx3x4_x4 + Tank2x4) / 2, Tank2Midy3y4_y4__y4 = (Tank2Midy3y4_y4 + Tank2y4) / 2;

    //1/4 and 3/4 coordinates of shoot
    int Shoot2Midx3_x3x4 = (Shoot2x3 + Shoot2Midx3x4) / 2, Shoot2Midy3_y3y4 = (Shoot2y3 + Shoot2Midy3y4) / 2;  //1/4
    int Shoot2Midx3x4_x4 = (Shoot2Midx3x4 + Shoot2x4) / 2, Shoot2Midy3y4_y4 = (Shoot2Midy3y4 + Shoot2y4) / 2;  //3/4

    //condition to check black line
    if(getpixel(Tank2x1,Tank2y1) && getpixel(Tank2x2, Tank2y2) && getpixel(Tank2x3,Tank2y3) && getpixel(Tank2x4,Tank2y4) && getpixel(Shoot2x3,Shoot2y3) && getpixel(Shoot2x4,Shoot2y4))
    {
        if(getpixel(Tank2Midx1x2,Tank2Midy1y2) && getpixel(Tank2Midx2x3,Tank2Midy2y3) && getpixel(Tank2Midx4x1,Tank2Midy4y1) && getpixel(Shoot2Midx3x4, Shoot2Midy3y4)
           && getpixel(Tank2Midx1_x1x2, Tank2Midy1_y1y2) && getpixel(Tank2Midx1x2_x2, Tank2Midy1y2_y2)
           && getpixel(Shoot2Midx3_x3x4, Shoot2Midy3_y3y4) && getpixel(Shoot2Midx3x4_x4, Shoot2Midy3y4_y4)
           && getpixel(Tank2Midx1__x1_x1x2, Tank2Midy1__y1_y1y2) && getpixel(Tank2Midx1_x1x2__x1x2, Tank2Midy1_y1y2__y1y2)
           && getpixel(Tank2Midx1x2__x1x2_x2, Tank2Midy1y2__y1y2_y2 ) && getpixel(Tank2Midx1x2_x2__x2, Tank2Midy1y2_y2__y2)
           && getpixel(Tank2Midx2__x2_x2x3, Tank2Midy2__y2_y2y3) && getpixel(Tank2Midx2_x2x3__x2x3, Tank2Midy2_y2y3__y2y3 )
           && getpixel(Tank2Midx2x3__x2x3_x3, Tank2Midy2y3__y2y3_y3 ) && getpixel(Tank2Midx2x3_x3__x3, Tank2Midy2y3_y3__y3)
           && getpixel(Tank2Midx4__x4_x4x1, Tank2Midy4__y4_y4y1 ) && getpixel(Tank2Midx4_x4x1__x4x1, Tank2Midy4_y4y1__y4y1 )
           && getpixel(Tank2Midx4x1__x4x1_x1, Tank2Midy4y1__y4y1_y1) && getpixel(Tank2Midx4x1_x1__x1, Tank2Midy4y1_y1__y1)
           && getpixel(Tank2Midx3__x3_x3x4, Tank2Midy3__y3_y3y4) && getpixel(Tank2Midx3_x3x4__x3x4, Tank2Midy3_y3y4__y3y4)
           && getpixel(Tank2Midx3x4__x3x4_x4, Tank2Midy3y4__y3y4_y4 ) && getpixel(Tank2Midx3x4_x4__x4, Tank2Midy3y4_y4__y4)
           )
          {
              return 1;
          }
    }
    return 0;
}


void T1Coordinates()
{
    //body
    setcolor(BLACK);
    Tank1x1 = Tank1X - (int)r*sin(angle1), Tank1y1 = Tank1Y - (int)r*cos(angle1);
    Tank1x2 = Tank1X - (int)r*cos(angle1), Tank1y2 = Tank1Y + (int)r*sin(angle1);
    Tank1x3 = Tank1X + (int)r*sin(angle1), Tank1y3 = Tank1Y + (int)r*cos(angle1);
    Tank1x4 = Tank1X + (int)r*cos(angle1), Tank1y4 = Tank1Y - (int)r*sin(angle1);

    //shoot
    Shoot1x1= Tank1X + (int)(15.0*cos(angle1 - M_PI/12.0)),          Shoot1y1 = Tank1Y - (int)(15.0*sin(angle1 - M_PI/12.0));
    Shoot1x2= Tank1X + (int)(15.0*cos(angle1 - M_PI_4 - M_PI/6.0)),  Shoot1y2 = Tank1Y - (int)(15.0*sin(angle1 - M_PI_4 - M_PI/6.0));
    Shoot1x3= Shoot1x2 + 20.0*cos(angle1-M_PI_4),                    Shoot1y3 = Shoot1y2 - 20.0*sin(angle1-M_PI_4);
    Shoot1x4= Shoot1x1 + 20.0*cos(angle1-M_PI_4),                    Shoot1y4 = Shoot1y1 - 20.0*sin(angle1-M_PI_4);
}

void T2Coordinates()
{
    setcolor(BLACK);

    //body

    Tank2x1 = Tank2x - (int)r*sin(angle2), Tank2y1 = Tank2y - (int)r*cos(angle2);
    Tank2x2 = Tank2x - (int)r*cos(angle2), Tank2y2 = Tank2y + (int)r*sin(angle2);
    Tank2x3 = Tank2x + (int)r*sin(angle2), Tank2y3 = Tank2y + (int)r*cos(angle2);
    Tank2x4 = Tank2x + (int)r*cos(angle2), Tank2y4 = Tank2y - (int)r*sin(angle2);

    //shoot
    Shoot2x1 = Tank2x + (int)15*cos(angle2-M_PI/12), Shoot2y1 = Tank2y - (int)15*sin(angle2-M_PI/12);
    Shoot2x2 = Tank2x + (int)15*cos(angle2-M_PI_4-M_PI/6), Shoot2y2 = Tank2y - (int)15*sin(angle2-M_PI_4-M_PI/6);
    Shoot2x3 = Shoot2x2 + (int)20*cos(angle2-M_PI_4),Shoot2y3 = Shoot2y2 - (int)20*sin(angle2-M_PI_4);
    Shoot2x4 = Shoot2x1 + (int)20*cos(angle2-M_PI_4),Shoot2y4 = Shoot2y1 - (int)20*sin(angle2-M_PI_4);
}

void DrawTank()
{
    setfillstyle(SOLID_FILL, RED);
    setlinestyle(SOLID_LINE, 0, 1);

    int body[] = {Tank1x1, Tank1y1, Tank1x2, Tank1y2, Tank1x3, Tank1y3, Tank1x4, Tank1y4, Tank1x1,Tank1y1};
    fillpoly(5, body);
    int Shoot[] = {Shoot1x1, Shoot1y1, Shoot1x2, Shoot1y2, Shoot1x3, Shoot1y3, Shoot1x4, Shoot1y4, Shoot1x1, Shoot1y1};
    fillpoly(5, Shoot);
    arc(Tank1X, Tank1Y, degree1+30, 330+degree1, 15);
}

void DrawTank2()
{
    setfillstyle(SOLID_FILL, GREEN);
    setlinestyle(SOLID_LINE, 0, 1);

    int body[]={Tank2x1, Tank2y1, Tank2x2, Tank2y2, Tank2x3, Tank2y3, Tank2x4, Tank2y4, Tank2x1, Tank2y1};
    fillpoly(5, body);

    int shoot[]={Shoot2x1, Shoot2y1,
    Shoot2x2, Shoot2y2,
    Shoot2x3, Shoot2y3,
    Shoot2x4, Shoot2y4,Shoot2x1, Shoot2y1};
    fillpoly(5, shoot );

    arc(Tank2x, Tank2y, degree2+30, degree2+330, 15);

}
