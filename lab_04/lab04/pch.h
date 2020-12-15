#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <vector>
#include <math.h>

typedef enum { left_, right_ } move_direction;
typedef struct point_t {
	double x;
	double y;
} point;

using namespace std;
using text = vector<string>;

#endif //PCH_H
