#include"Header.h"
using namespace std;
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Color Change");
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutPassiveMotionFunc(MouseMotion);
	glutMainLoop();
	return 0;
}