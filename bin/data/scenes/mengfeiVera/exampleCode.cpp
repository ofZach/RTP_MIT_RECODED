Background(0);
SetColor([[color]]);

Polyline pl;
pl.addVertex(100, 150);
SeedRandom([[seed]]);

int i = 0;

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < [[vertexnumber]]; k++)
        {
            if (i % 2 == 0)
            {
                int rx = (int)ofRandom(3.9);
                int ry = (int)ofRandom(3.9);
                pl.addVertex(50 + j * 200 + (double)rx * 50,
                             50 + i * 200 + (double)ry * 50);
            }
            else
            {
                int rm = (int)ofRandom(3.9);
                int rn = (int)ofRandom(3.9);
                pl.addVertex(1000 - j * 200 - (double)rm * 50,
                             50 + i * 200 + (double)rn * 50);
            }
        }
    }
}
