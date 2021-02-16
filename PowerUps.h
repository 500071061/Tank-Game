int Random(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

struct HealthInfo
{
    int EllipseX = 0,EllipseY = 0;
    int Bar1X =0 ,Bar1Y = 0;
    int Bar2X =0 ,Bar2Y = 0;
    bool Active = false;
    clock_t SpawnTime = 0;
};
HealthInfo Health ;

void HealthUp()
{
    clock_t CurrentTime = clock();

      if(Health.Active == false)
      {
        srand(time(0));
        Health.Active = true;
        Health.EllipseX = Random(150,1350);
        Health.EllipseY = Random(100,700);
        Health.Bar1X = Health.EllipseX - 2;
        Health.Bar1Y = Health.EllipseY - 8;
        Health.Bar2X = Health.EllipseX - 8;
        Health.Bar2Y = Health.EllipseY - 2;
        Health.SpawnTime = CurrentTime ;
      }

            if(int((CurrentTime - Health.SpawnTime) / CLOCKS_PER_SEC)-15 > 6) //Time duration for 1 health pack
            {
                    Health.Active = false;
            }

            if(Health.Active == true)
            {
                if(getpixel(Health.EllipseX + 10, Health.EllipseY + 10) == RED || getpixel(Health.EllipseX - 10, Health.EllipseY + 10) == RED ||
                   getpixel(Health.EllipseX + 10, Health.EllipseY - 10) == RED || getpixel(Health.EllipseX - 10, Health.EllipseY - 10) == RED )
                {
                    Life1 = Life1 + 1 ;

                    if(Life1>3)
                        Life1 = Life1 - 1;

                    Health.Active = false;
                }

                if(getpixel(Health.EllipseX + 10, Health.EllipseY + 10) == GREEN || getpixel(Health.EllipseX - 10, Health.EllipseY + 10) == GREEN ||
                   getpixel(Health.EllipseX + 10, Health.EllipseY - 10) == GREEN || getpixel(Health.EllipseX - 10, Health.EllipseY - 10) == GREEN )
                {
                    Life2 = Life2 + 1 ;

                    if(Life2>3)
                        Life2 = Life2 - 1;

                    Health.Active = false;
                }

                if(int((CurrentTime - Health.SpawnTime) / CLOCKS_PER_SEC) < 15 ) //Time Interval between 2 health packs
                    return ;

                    setcolor(WHITE);
                    setlinestyle(SOLID_LINE, 0, 1);
                    setfillstyle(SOLID_FILL, WHITE);

                    fillellipse(Health.EllipseX, Health.EllipseY,10,10);

                    setfillstyle(SOLID_FILL, BLUE);

                    bar(Health.Bar1X, Health.Bar1Y, Health.Bar1X+4, Health.Bar1Y+16);
                    bar(Health.Bar2X, Health.Bar2Y, Health.Bar2X+16, Health.Bar2Y+4);

                    settextstyle(6,HORIZ_DIR,2);
                    setcolor(BLUE);
                    if(int((CurrentTime - Health.SpawnTime) / CLOCKS_PER_SEC)-15 < 3)
                    outtextxy(500,30,"HEALTH PACK AVAILABLE");
            }

}

