#include<stdio.h>
#include<stdlib.h>
#include<gl\glut.h>
#include<math.h>
#include<iostream>
#include<vector>
using namespace std;
#define PI 3.1415926
int width = 800;
int height = 800;

void Render();
void Reshape(int w, int h);
void SetupViewTransform();
void SetupViewVolume();
void MouseMotion(int x, int y);
void DrawCircle(double radius, double r, double g, double b);
bool change_color1;
bool change_color2;
bool change_color3;
bool change_color4;
bool change_color5;

template<class TT>
class Point
{
public:
	TT x;
	TT y;
	Point (TT _x,TT _y)
	{
		x = _x;
		y = _y;
	}
	Point()
	{

	}
};
template<class T>
class Draw_A_Circle {
public:
	T radius, r, g, b;
	Draw_A_Circle() {}
	Draw_A_Circle(T _radius, T _r, T _g, T _b)
	{
		radius = _radius;
		r = _r;
		g = _g;
		b = _b;
	}
	void DrawCircle(/*double radius, double r, double g, double b*/)
	{
		glColor3f(r, g, b);
		glLineWidth(10);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 1000; i++)
		{
			double theta = PI*2.0*i / 100;
			double x = radius*cos(theta);
			double y = radius*sin(theta);
			glVertex3f(x, y, 0);
		}
		glEnd();
	}
};
class Draw_A_Box:public Point<double>{
public:
	double x;
	double y;
	int lengh;
	int weigh;
	double r;
	double g;
	double b;
	void(Draw_A_Box::*callback)(void) = 0;
	void exe(void(Draw_A_Box::*inputfunc)(void))
	{
		(this->*inputfunc)();
	}
	Draw_A_Box(double _x,double _y,int _lengh,int _weigh,double _r,double _g,double _b):Point<double>(x,y)
	{
		x = _x;
		y = _y;
		lengh = _lengh;
		weigh = _weigh;
		r = _r;
		g = _g;
		b = _b;

	}
	void draw_a_box()
	{
		glColor3f(r, g, b);
		glLineWidth(10);
		glBegin(GL_LINE_LOOP);
		glVertex3f(x,y,0);
		glVertex3f(x + weigh, y, 0);
		glVertex3f(x + weigh, y + lengh, 0);
		glVertex3f(x, y + lengh, 0);
		glEnd();

	}
};
Point<int>current_move;
vector<Point<int>>PTList;
void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	w = width;
	h = height;
}
void SetupViewTransform() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
}
void SetupViewVolume() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-400, 400, -400, 400, -100, 100);
}
void Render() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetupViewTransform();
	SetupViewVolume();
	glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	//glTranslatef(0, 0, 0);
	Draw_A_Box my_box1(200.0f,200.0f,200.0f,200.0f,1.0f,0.0f,0.5f);
	my_box1.callback = &Draw_A_Box::draw_a_box;
	my_box1.exe(&Draw_A_Box::draw_a_box);
	Draw_A_Box my_box2(-200.0f, -200.0f, 200.0f, 200.0f, 1.0f, 0.0f, 1.0f);
	my_box2.callback = &Draw_A_Box::draw_a_box;
	my_box2.exe(&Draw_A_Box::draw_a_box);
	//glPopMatrix();
	glPushMatrix();
	glTranslatef(-200, -200, 0);
	Draw_A_Circle<double>a(100.0f, 1.0f, 0.5f, 0.5f);
	a.DrawCircle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(220, 200, 0);
	Draw_A_Circle<double>b(100.0f, 0.3f, 1.0f, 0.3f);
	b.DrawCircle();
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(-200, 200, 0);
	Draw_A_Circle<double>c(100.0f, 1.0f, 1.0f, 0.3f);
	c.DrawCircle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(200, -200, 0);
	Draw_A_Circle<double>d(100.0f, 1.0f, 1.0f, 0.6f);
	d.DrawCircle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-200, -200, 0);
	Draw_A_Circle<double>e(100.0f, 1.0f, 0.7f, 0.8f);
	e.DrawCircle();*/
	glutSwapBuffers();
}
void MouseMotion(int x, int y)
{
	current_move.x = x;
	current_move.y = y;
	cout << current_move.x << ',' << current_move.y << endl;
	if (sqrt((current_move.x - 400)*(current_move.x - 400) + (current_move.y - 400)*(current_move.y - 400)) < 100)
	{
		change_color1 = 1;
	}
	if (sqrt((current_move.x - 600)*(current_move.x - 600) + (current_move.y - 200)*(current_move.y - 200)) < 100)
	{
		change_color2 = 1;
	}
	if (sqrt((current_move.x - 200)*(current_move.x - 200) + (current_move.y - 200)*(current_move.y - 200)) < 100)
	{
		change_color3 = 1;
	}
	if (sqrt((current_move.x - 200)*(current_move.x - 200) + (current_move.y - 600)*(current_move.y - 600)) < 100)
	{
		change_color5 = 1;
	}
	if (sqrt((current_move.x - 600)*(current_move.x - 600) + (current_move.y - 600)*(current_move.y - 600)) < 100)
	{
		change_color4 = 1;
	}
	glutPostRedisplay();
}
