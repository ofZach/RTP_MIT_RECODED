SeedRandom([[seedrandom]]);

for (int i = 0; i < GetWidth(); i += [[gap]])
{
    for (int j = 0; j < GetHeight(); j += [[gap]])
    {
        if (Random(10)*sin(5*i) + 5*cos(10*j) <= [[noise1]])
        {
            SetColor(0);
            DrawRectangle(i, j, 10, 10);
        }
        else if (28*sin(20 * i) + 6 * cos(50 * j) > [[noise2]])
        {
            SetColor(255);
            DrawRectangle(i, j, 30, 30);
        }
        else
        {
            SetColor(127);
            DrawRectangle(i, j, 10, 10);
        }
    }
}
