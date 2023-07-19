#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
GLint xi,yi,xk,yk;

void plot_point(GLint x,GLint y){
	glColor3f(1,0,0);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void bresenhamsLineDraw(){
	GLint pk;
	GLint dy = yk-yi;
	GLint dx = xk-xi;
	plot_point(xi,yi);
	float m;
	if(xi!=xk && yi!=yk)
	{
		printf("next pk  next xi  next yi \n");
		m = (float) dy/(float) dx;
		if(m>0)
		{
			if(abs(m)<=1)
			{
				pk = 2*dy-dx;
				while(xi<xk)
				{
					if(pk<=0)
					{
						pk = pk+2*dy;
						xi++;
						printf("%2d \t %2d \t %2d \n",pk,xi,yi);
						plot_point(xi,yi);
					}
					if(pk>0)
					{
						pk = pk+2*(dy-dx);
						xi++;
						yi++;
						printf("%2d \t %2d \t %2d \n",pk,xi,yi);
						plot_point(xi,yi);
					}
				}
			}
			if(abs(m)>1)
			{
				pk = dy-2*dx;
				while(yi<yk)
				{
					if(pk<=0)
					{
						pk = pk+2*(dy-dx);
						xi++;
						yi++;
						printf("%3d \t %3d \t %3d \n",pk,xi,yi);
						plot_point(xi,yi);
					}
					if(pk>0)
					{
						pk = pk-2*dx;
						yi++;
						printf("%3d \t %3d \t %3d \n",pk,xi,yi);
						plot_point(xi,yi);
					}
				}
			}
		}
		else
		{
			if(abs(m)<=1)
			{	
				pk = -2*dy-dx;
				while(xi<xk)
				{
					if(pk<=0)
					{
						pk = pk-2*dy;
						xk--;
						printf("%2d \t %2d \t %2d \n",pk,xk,yk);
						plot_point(xk,yk);
					}
					if(pk>0)
					{
						pk = pk-2*(dy+dx);
						xk--;
						yk++;
						printf("%2d \t %2d \t %2d \n",pk,xk,yk);
						plot_point(xk,yk);
					}
				}
			}
			if(abs(m)>1)
			{	
				pk = -dy-2*dx;
				while(yk<yi)
				{
					if(pk<=0)
					{
						pk = pk-2*dx;
						yk++;
						printf("%3d \t %3d \t %3d \n",pk,xk,yk);
						plot_point(xk,yk);
					}
					if(pk>0)
					{
						pk = pk-2*(dy+dx);
						xk--;
						yk++;
						printf("%3d \t %3d \t %3d \n",pk,xk,yk);
						plot_point(xk,yk);
					}
				}
			}
		}
	}
	else if(xi==xk)
	{
        printf("next xi \t next yi \n");		
        while(yi<yk)
		{
			yi++;
			printf("%3d \t %3d \n",xi,yi);
			plot_point(xi,yi);
		}
	}
	else if(yi==yk)
	{
		printf("next xi \t next yi \n");
		while(xi<xk)
		{
			xi++;
			printf("%3d \t %3d \n",xi,yi);
			plot_point(xi,yi);
		}
	}
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	bresenhamsLineDraw();
	glFlush();
}

void myinit(){
    glClearColor(1,1,1,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500,500,-500,500);
}

int main(int argc,char **argv){
	printf("Enter the value of (x0,y0) & (x1,y1) \n");
	scanf("%d %d %d %d",&xi,&yi,&xk,&yk);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(1920,1080);
	glutCreateWindow("Bresenhams Line Drawing Algorithm - Khushi");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}



