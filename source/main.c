#include "Intellisense.h"

#define REG_DISPCNT *((unsigned int *)(0x04000000))
#define VIDEOMODE_3 0x0003
#define BG_ENABLE2 0x0400

#define SCREENBUFFER ((unsigned short *)(0x06000000))
#define SCREEN_W 240
#define SCREEN_H 160

unsigned short setColor(unsigned char a_red, unsigned char a_green, unsigned char a_blue)
{
	return (a_red & 0x1F) | (a_green & 0x1F) << 5 | (a_blue & 0x1F) << 10;
}

int main()
{
	//set GBA rendering context to MODE 3 Bitmap Rendering
	REG_DISPCNT = VIDEOMODE_3 | BG_ENABLE2;

	int t = 0;
	while (1)
	{
		int x, y;
		for (x = 0; x < SCREEN_W; ++x)
		{
			for (y = 0; y < SCREEN_H; ++y)
			{
				SCREENBUFFER[x + y * SCREEN_W] = setColor((x & y) + t * 5, (x & y) + t * 3, (x & y) + t);
			}
		}
		++t;
	}
	return 0;
}