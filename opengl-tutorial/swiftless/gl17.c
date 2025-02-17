#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

GLuint texture;
GLfloat angle = 0.0;

GLuint LoadTexture(const char * filename, int width, int height)
{
	GLuint texture;
	unsigned char * data;
	FILE *file;
	//The following code will read in our RAW file
	file = fopen(filename, "rb");
	if(file == NULL) return 0;
	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	glGenTextures(1, &texture); //generate the texture
	glBindTexture(GL_TEXTURE_2D, texture);// bind the texture to it's array
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //set texture enviroment parameters
	
	//here we are setting what textures to use and when. The MIN filter is which quality to show
	//when the texture is near the view, and the MAG filter is which quality to show when the texture
	//is far from the view.
	//The qualities are (in order from worst to best)
	//GL_NEAREST
	//GL_LINEAR
	//GL_LINEAR_MIPMAP_NEAREST
	//GL_LINEAR_MIPMAP_LINEAR
	
	//And if you go and use extensions, you can use Anisotropicfiltering textures which are of an
	//even better quality, but this will do for now.
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	//Here we are setting the parameter to repeat the texture instead of clamping the texture
	//to the edge of our shape.
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	//Generate the texture with mipmaps
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data); //free the texture
	return texture; //return whether it was successfull
}

void FreeTexture(GLuint texture)
{
	glDeleteTextures(1, &texture);
}

void cube (void) 
{
	glBindTexture(GL_TEXTURE_2D, texture); //bind the texture
	glRotatef(angle, 1.0f, 1.0f, 1.0f);
	glutSolidCube(2);
}

void display (void) 
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	texture = LoadTexture("texture.raw", 256, 256); //loadthe texture
	glEnable(GL_TEXTURE_2D); //enable 2D texturing
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	cube();
	FreeTexture(texture);
	glutSwapBuffers();
	angle++;
}

void reshape (int w, int h) 
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("A basic OpenGL Window");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}