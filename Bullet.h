bool GameActive = true;
//Bullet for Tank
static const int Max_Bullet = 5;
static const double Bullet_Speed = 5.0;

struct BulletInfo
{
    bool IsActive = false;
    int X_Pos=0, Y_Pos=0;
    double angle=0.0;
    clock_t ReleaseTime = 0;
};

BulletInfo Bullet1[Max_Bullet];
BulletInfo Bullet2[Max_Bullet];
clock_t LastBulletFired = clock();


void NewBullet1()
{
    clock_t CurrentTime = clock();
    int TimeInterval = int ((CurrentTime - LastBulletFired)/CLOCKS_PER_SEC);
    if(TimeInterval<1)
        return;

    int i;

    for(i=0;i<Max_Bullet;i++)
    {
        if(Bullet1[i].IsActive==false)
        {
            break;
        }
    }

    if(i==Max_Bullet)
        return;

    Bullet1[i].IsActive = true;
    Bullet1[i].angle = angle1 - M_PI_4;
    Bullet1[i].X_Pos = Tank1X + (int)(40.0*cos(angle1-M_PI_4));
    Bullet1[i].Y_Pos = Tank1Y - (int)(40.0*sin(angle1-M_PI_4));
    Bullet1[i].ReleaseTime = CurrentTime;
    LastBulletFired = CurrentTime;
}

void NewBullet2()
{
    clock_t CurrentTime = clock();
    int TimeInterval = int ((CurrentTime - LastBulletFired)/CLOCKS_PER_SEC);
    if(TimeInterval<1)
        return;

    int i;

    for(i=0;i<Max_Bullet;i++)
    {
        if(Bullet2[i].IsActive==false)
        {
            break;
        }
    }

    if(i==Max_Bullet)
        return;

    Bullet2[i].IsActive = true;
    Bullet2[i].angle = angle2 - M_PI_4;
    Bullet2[i].X_Pos = Tank2x + (int)(40.0*cos(angle2-M_PI_4));
    Bullet2[i].Y_Pos = Tank2y - (int)(40.0*sin(angle2-M_PI_4));
    Bullet2[i].ReleaseTime = CurrentTime;
    LastBulletFired = CurrentTime;
}

void MoveBullet1()
{
    clock_t CurrentTime = clock();
    int BulletSurvivalTime;
    setlinestyle(SOLID_LINE, 0, 3);

    for(int i=0; i<Max_Bullet; i++)
        {
            if(Bullet1[i].IsActive)
            {
                BulletSurvivalTime = int ((CurrentTime - Bullet1[i].ReleaseTime)/CLOCKS_PER_SEC);
                if(BulletSurvivalTime > 10)
                {
                    Bullet1[i].IsActive = false;
                    Bullet1[i].angle = 0.0;
                    Bullet1[i].X_Pos = 0;
                    Bullet1[i].Y_Pos = 0;
                    Bullet1[i].ReleaseTime = 0;
                    continue;
                }


                    Bullet1[i].X_Pos += (int)(Bullet_Speed * cos(Bullet1[i].angle));
                    Bullet1[i].Y_Pos -= (int)(Bullet_Speed * sin(Bullet1[i].angle));

                    if(getpixel(Bullet1[i].X_Pos, Bullet1[i].Y_Pos) == BLACK &&
                   (getpixel(Bullet1[i].X_Pos+2, Bullet1[i].Y_Pos+2) == BLACK || getpixel(Bullet1[i].X_Pos-2, Bullet1[i].Y_Pos+2) == BLACK ||
                    getpixel(Bullet1[i].X_Pos+2, Bullet1[i].Y_Pos-2) == BLACK || getpixel(Bullet1[i].X_Pos-2, Bullet1[i].Y_Pos-2) == BLACK))
                    {
                        Bullet1[i].X_Pos -= (int)(Bullet_Speed * cos(Bullet1[i].angle));

                        if(getpixel(Bullet1[i].X_Pos, Bullet1[i].Y_Pos) == 0)
                        {
                            // DEFLECTING FROM HORIZONTAL SURFACE
                            Bullet1[i].Y_Pos += (int)(Bullet_Speed * sin(Bullet1[i].angle));
                            Bullet1[i].angle = -Bullet1[i].angle;
                        }
                        else
                        {
                            // DEFLEFCTING FROM VERTICAL SURFACE
                            Bullet1[i].Y_Pos += (int)(Bullet_Speed * sin(Bullet1[i].angle));
                            Bullet1[i].angle = M_PI - Bullet1[i].angle;
                        }

                    }
                 if(getpixel(Bullet1[i].X_Pos, Bullet1[i].Y_Pos) == GREEN &&
                   (getpixel(Bullet1[i].X_Pos+2, Bullet1[i].Y_Pos+2) == GREEN || getpixel(Bullet1[i].X_Pos-2, Bullet1[i].Y_Pos+2) == GREEN ||
                    getpixel(Bullet1[i].X_Pos+2, Bullet1[i].Y_Pos-2) == GREEN || getpixel(Bullet1[i].X_Pos-2, Bullet1[i].Y_Pos-2) == GREEN))
                {
                    GameActive = false;
                }
                if(getpixel(Bullet1[i].X_Pos, Bullet1[i].Y_Pos) == RED &&
                  (getpixel(Bullet1[i].X_Pos+2, Bullet1[i].Y_Pos+2) == RED || getpixel(Bullet1[i].X_Pos-2, Bullet1[i].Y_Pos+2) == RED ||
                   getpixel(Bullet1[i].X_Pos+2, Bullet1[i].Y_Pos-2) == RED || getpixel(Bullet1[i].X_Pos-2, Bullet1[i].Y_Pos-2) == RED))
                {
                    GameActive = false;
                }

                    circle(Bullet1[i].X_Pos, Bullet1[i].Y_Pos,2);

            }
        }

}


void MoveBullet2()
{
    clock_t CurrentTime = clock();
    int BulletSurvivalTime;

    for(int i=0; i<Max_Bullet; i++)
        {
            if(Bullet2[i].IsActive)
            {
                BulletSurvivalTime = int ((CurrentTime - Bullet2[i].ReleaseTime)/CLOCKS_PER_SEC);
                if(BulletSurvivalTime > 10)
                {
                    Bullet2[i].IsActive = false;
                    Bullet2[i].angle = 0.0;
                    Bullet2[i].X_Pos = 0;
                    Bullet2[i].Y_Pos = 0;
                    Bullet2[i].ReleaseTime = 0;
                    continue;
                }


                    Bullet2[i].X_Pos += (int)(Bullet_Speed * cos(Bullet2[i].angle));
                    Bullet2[i].Y_Pos -= (int)(Bullet_Speed * sin(Bullet2[i].angle));

                  if(getpixel(Bullet2[i].X_Pos, Bullet2[i].Y_Pos) == BLACK &&
                   (getpixel(Bullet2[i].X_Pos+2, Bullet2[i].Y_Pos+2) == BLACK || getpixel(Bullet2[i].X_Pos-2, Bullet2[i].Y_Pos+2) == BLACK ||
                    getpixel(Bullet2[i].X_Pos+2, Bullet2[i].Y_Pos-2) == BLACK || getpixel(Bullet2[i].X_Pos-2, Bullet2[i].Y_Pos-2) == BLACK))
                    {
                        Bullet2[i].X_Pos -= (int)(Bullet_Speed * cos(Bullet2[i].angle));

                        if(getpixel(Bullet2[i].X_Pos, Bullet2[i].Y_Pos) == 0)
                        {
                            // DEFLECTING FROM HORIZONTAL SURFACE
                            Bullet2[i].Y_Pos += (int)(Bullet_Speed * sin(Bullet2[i].angle));
                            Bullet2[i].angle = -Bullet2[i].angle;
                        }
                        else
                        {
                            // DEFLEFCTING FROM VERTICAL SURFACE
                            Bullet2[i].Y_Pos += (int)(Bullet_Speed * sin(Bullet2[i].angle));
                            Bullet2[i].angle = M_PI - Bullet2[i].angle;
                        }

                    }
                 if(getpixel(Bullet2[i].X_Pos, Bullet2[i].Y_Pos) == GREEN &&
                   (getpixel(Bullet2[i].X_Pos+2, Bullet2[i].Y_Pos+2) == GREEN || getpixel(Bullet2[i].X_Pos-2, Bullet2[i].Y_Pos+2) == GREEN ||
                    getpixel(Bullet2[i].X_Pos+2, Bullet2[i].Y_Pos-2) == GREEN || getpixel(Bullet2[i].X_Pos-2, Bullet2[i].Y_Pos-2) == GREEN))
                {
                    GameActive = false;
                }
                if(getpixel(Bullet2[i].X_Pos, Bullet2[i].Y_Pos) == RED &&
                  (getpixel(Bullet2[i].X_Pos+2, Bullet2[i].Y_Pos+2) == RED || getpixel(Bullet2[i].X_Pos-2, Bullet2[i].Y_Pos+2) == RED ||
                   getpixel(Bullet2[i].X_Pos+2, Bullet2[i].Y_Pos-2) == RED || getpixel(Bullet2[i].X_Pos-2, Bullet2[i].Y_Pos-2) == RED))
                {
                    GameActive = false;
                }

                    circle(Bullet2[i].X_Pos, Bullet2[i].Y_Pos,2);

            }
        }

}
