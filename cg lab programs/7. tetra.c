#include<stdio.h>
#include<GL/glut.h>
typedef float point[3];
point v[]={{0,0,1},{0,1,-1},{-1,-1,-1},{1,-1,-1}};
int n;

void triangle(point a,point b,point c){
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void dividet(point a,point b,point c,int m){
	point v1,v2,v3;
	int j;
	if(m>0)
	{
		for(j=0;j<3;j++)
			v1[j]=(a[j]+b[j])/2;
		for(j=0;j<3;j++)
			v2[j]=(a[j]+c[j])/2;
		for(j=0;j<3;j++)
			v3[j]=(c[j]+b[j])/2;
		dividet(a,v1,v2,m-1);
		dividet(c,v2,v3,m-1);
		dividet(b,v3,v1,m-1);
	}
	else
		triangle(a,b,c);
}

void tetrahedron(int m){
	glColor3f(1,0,0);
	dividet(v[0],v[1],v[2],m);
	glColor3f(0,1,0);
	dividet(v[3],v[2],v[1],m);
	glColor3f(0,0,1);
	dividet(v[0],v[3],v[1],m);
	glColor3f(0.3,0.3,0.3);
	dividet(v[0],v[2],v[3],m);
	glFlush();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	tetrahedron(n);
}

void myReshape(int w, int h){
	glViewport(0,0,w,h);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	if(w<=h)
		glOrtho(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,-10,10);
	else
		glOrtho(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2,-10,10);
	glMatrixMode(GL_MODELVIEW);	
}

int main(int argc, char **argv){
	printf("Enter the number of sides : ");
	scanf("%d",&n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Tetrahedron");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1,1,1,1);
	glutMainLoop();
	return 0;
}
