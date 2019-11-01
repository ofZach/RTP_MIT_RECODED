for (int i = 0; i < grabber.getWidth(); i += [[gap]])
{
    for (int j = 0; j < grabber.getHeight(); j += [[gap]])
    {
        Color color = grabber.getPixels().getColor(i, j);
        float brightness = color.getBrightness();
        
        SetColor(color);
        
        if (brightness > [[threshold]])
        {
            font.drawString("Create", i, j);
        }
    }
}
