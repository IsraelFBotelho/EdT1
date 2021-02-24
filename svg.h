#ifndef __SVG__
#define __SVG__

#include <stdio.h>
#include "rectangle.h"

void createSvg(FILE* svg, char* path, char* name);

void endSvg(FILE* svg, char* path, char* name);

void drawRectangle(FILE *svg, char* path, char* name, Rectangle rectangle);

#endif
