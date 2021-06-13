typedef enum
{
	VGA_Black = 0,
	VGA_Blue = 1,
	VGA_Green = 2,
	VGA_Cyan = 3,
	VGA_Red = 4,
	VGA_Magenta = 5,
	VGA_Brown = 6,
	VGA_LightGrey = 7,
	VGA_DarkGrey = 8,
	VGA_LightBlue = 9,
	VGA_LightGreen = 10,
	VGA_LightCyan = 11,
	VGA_LightRed = 12,
	VGA_LightMagenta = 13,
	VGA_LightBrown = 14,
	VGA_White = 15,
} VgaColor;

typedef enum
{
	false,
	true,
} bool;

void Main(int magic)
{
	unsigned char *vgaBuff = (unsigned char *)0xA0000;
	vgaBuff[0] = VGA_Green;
	vgaBuff[1] = VGA_Green;
}