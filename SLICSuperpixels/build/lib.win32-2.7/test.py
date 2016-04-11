import SLICSuperpixels
print dir(SLICSuperpixels)
a = SLICSuperpixels.createSuperpixels(r"C:\Users\Admin\Desktop\beauty.bmp", 'C:\\Users\\Admin\\Desktop\\', 1000, 20)
print SLICSuperpixels.cvar.g_Width, SLICSuperpixels.cvar.g_Width
SLICSuperpixels.readLabel(r"C:\Users\Admin\Desktop\beauty.dat", r"C:\Users\Admin\Desktop\beaudafty.csv", SLICSuperpixels.cvar.g_Width, SLICSuperpixels.cvar.g_Height)
