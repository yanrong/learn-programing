#include <GL/gl.h>
#include <GL/glut.h>

void square(void)
{
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0); //red
    glVertex3f(-0.5, -0.5, 0.0);
    glColor3f(0, 1, 0); //green
    glVertex3f(-0.5, 0.5, 0.0);
    glColor3f(0, 0, 1); //blue
    glVertex3f(0.5, 0.5, 0.0);
    glColor3f(1, 1, 1); //white
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();
}

void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -1);
    square();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(GLfloat)w /(GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A basic OpenGL Window");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}