#include "System.h"
#include "Screen.h"
#include "Font.h"

ulong System::randSeed;

ulong System::Hash(ulong n)
{
	n ^= 2747636419;
	n *= 2654435769;

	n ^= n >> 16;
	n *= 2654435769;

	n ^= n >> 16;
	n *= 2654435769;
	return n;
}

void System::Panic(const char *err)
{
	Screen::Clear(0x37);
	Font::DrawStr(err, 5, 5, 0x0F);
	Screen::SwapBuffers();
	while (true);
}

#define RAND(ty) template<> ty System::Random() { return (ty)Hash(randSeed++); }
#define RAND_MAX(ty) template<> ty System::Random(ty max) { return (ty)Hash(randSeed++) % max; }
#define RAND_RANGE(ty) template<> ty System::Random(ty min, ty max) { return min + ((ty)Hash(randSeed++) % (max - min)); }

template<>
float System::Random()
{ return (float)Hash(randSeed++) / (float)0xFFFFFFFFFFFFFFFF; }

template<>
bool System::Random()
{ return Hash(randSeed++) & 1; }

RAND(ulong)
RAND(uint)
RAND(word)
RAND(byte)


template<>
float System::Random(float max)
{ return ((float)Hash(randSeed++) * max / (float)0xFFFFFFFFFFFFFFFF); }


// RAND_MAX(ulong)
RAND_MAX(uint)
RAND_MAX(word)
RAND_MAX(byte)



template<>
float System::Random(float min, float max)
{ return ((float)Hash(randSeed++) / (float)0xFFFFFFFFFFFFFFFF) * (max - min) + min; }


// RAND_RANGE(ulong)
RAND_RANGE(uint)
RAND_RANGE(word)
RAND_RANGE(byte)