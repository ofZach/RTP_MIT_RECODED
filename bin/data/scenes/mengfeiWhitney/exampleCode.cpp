Background(0);
SetColor(238, 168, 231);
NoFill();

float time = GetElapsedTimef();
float centerX = GetWindowWidth() * 0.5;
float centerY = GetWindowHeight() * 0.5;

for (int i = 0; i < [[number]]; i++)
{
    float x0 = centerX + [[radiusX]] * sin(time+i);
    float y0 = centerY + [[radiusY]] * cos(time+i);
    DrawTriangle(x0 - 1.732 * i*[[n]], y0 - i*[[n]],
                 x0 + 1.732*i*[[n]], y0 - i*[[n]],
                 x0, y0 + 2 * i*[[n]]);
}


SetColor(101, 25, 68);
NoFill();

for (int j = 0; j < [[number]]; j++)
{
    float x0 = centerX + radiusX * sin(time + j+180);
    float y0 = centerY + radiusY * cos(time + j+180) * (-1);
    DrawTriangle(x0 - 1.732 * j*[[n]], y0 - j * [[n]],
                 x0 + 1.732*j*[[n]],
                 y0 - j * [[n]], x0,
                 y0 + 2 * j*[[n]]);
}
