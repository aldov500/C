#include <Arduino.h>

typedef struct SevenSeg{
	bool a,b,c,d,e,f,g,h;
} SevenSeg;


void SevenSeg_Init(SevenSeg* newDisplay);
void SevenSeg_SetSegments(SevenSeg *newDisplay, bool a, bool b, bool c, bool d, bool e, bool f, bool g );
void SevenSeg_SetNumber(SevenSeg *newDisplay, int num);
void SevenSeg_Display(SevenSeg newDisplay);
void SevenSeg_Clean(SevenSeg* newDisplay);


