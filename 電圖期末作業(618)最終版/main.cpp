#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

GLUquadric*quad=NULL;
int id1;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

///上週有做過, 請用剪貼的
#include <GL/glut.h>
#include "glm.h"
///GLMmodel * pmodel = NULL;
///GLMmodel * hand1 = NULL;
///GLMmodel * hand2 = NULL;
GLMmodel * left = NULL;
GLMmodel * right = NULL;
GLMmodel * hand = NULL;
GLMmodel * body  = NULL;
GLMmodel * head  = NULL;
GLMmodel * foot = NULL;
void drawBody(void)
{
    if (!body) {
        body = glmReadOBJ("body.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!body) exit(0);
        glmUnitize(body);
        glmFacetNormals(body);
        glmVertexNormals(body, 90.0);
    }
    glmDraw(body, GLM_SMOOTH);
}
void drawHead(void)
{
    if (!head) {
        head = glmReadOBJ("head.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!head) exit(0);
        glmUnitize(head);
        glmFacetNormals(head);
        glmVertexNormals(head, 90.0);
    }
    glmDraw(head, GLM_SMOOTH);
}
void drawUpperleft(void)
{
    if (!left) {
        left = glmReadOBJ("upperleft.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!left) exit(0);
        glmUnitize(left);
        glmFacetNormals(left);
        glmVertexNormals(left, 90.0);
    }
    glmDraw(left, GLM_SMOOTH);
}
void drawUpperright(void)
{
    if (!right) {
        right = glmReadOBJ("upperright.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!right) exit(0);
        glmUnitize(right);
        glmFacetNormals(right);
        glmVertexNormals(right, 90.0);
    }
    glmDraw(right, GLM_SMOOTH);
}
void drawHand(void)
{
    if (!hand) {
        hand = glmReadOBJ("hand.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!hand) exit(0);
        glmUnitize(hand);
        glmFacetNormals(hand);
        glmVertexNormals(hand, 90.0);
    }
    glmDraw(hand, GLM_SMOOTH);
}
void drawfoot(void)
{
    if (!foot) {
        foot = glmReadOBJ("foot.obj");
        ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
        ///本週,要換更好的地方
        if (!foot) exit(0);
        glmUnitize(foot);
        glmFacetNormals(foot);
        glmVertexNormals(foot, 90.0);
    }
    glmDraw(foot, GLM_SMOOTH);
}


int angleID=0;
float angle[20] = {};///float angle=0,da=-1;
void display()
{
    glClearColor(1.0, 1.0, 0.6, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D,id1);

    glPushMatrix();///加入旋轉
        glRotatef(180,0,1,0);
        drawBody();
        glPushMatrix();
            glScalef(1.5,1.5,1.5);
            glTranslatef(0,0.38,0);
            glRotatef(angle[6],1,0,0);
            glRotatef(angle[7],0,1,0);
            glRotatef(angle[8],0,0,1);
            glTranslatef(0,0.1,0);
            drawHead();
        glPopMatrix();

                glPushMatrix();
                    glScalef(5,5,5);
                    glTranslatef(-0.045,0.06,0);
                    glRotatef(angle[0],1,0,0);
                    glRotatef(angle[1],0,1,0);
                    glRotatef(angle[2],0,0,1);
                    glTranslatef(-0.021,-0.04,0.009);
                    drawUpperleft();
                    glPushMatrix();
                        glScalef(0.9,0.9,0.9);
                        glRotatef(-20,0,1,1);
                        glTranslatef(-0.008,0.12,0.06);
                        //glRotatef(angle[3],1,0,0);
                        glTranslatef(0,-0.2,0);
                        drawHand();
                    glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    //glutSwapBuffers();

    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glutWireCube(0.6);
    //glutSolidSphere(0.1,30,30);
    //glPushMatrix();///加入旋轉
        //glRotatef(180,0,1,0);
        //drawBody();
        glPushMatrix();

            glScalef(4.3,4.3,4.3);
            glRotatef(180,0,1,0);///轉動
            glTranslatef(0.055,0.06,0);
            glRotatef(angle[3],1,0,0);
            glRotatef(angle[4],0,1,0);
            glRotatef(angle[5],0,0,1);
            glTranslatef(0.03,-0.04,0);
            drawUpperright();
            glPushMatrix();
                glTranslatef(0.04,0.12,0.06);
                //glRotatef(angle[3],1,0,0);
                //glRotatef(angle[4],0,1,0);
                //glRotatef(angle[5],0,0,1);
                glTranslatef(0,-0.2,0);
                drawHand();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
                glScalef(5,5,5);
                glRotatef(180,0,1,0);
                glTranslatef(0.04,-0.08,0.1);
                glRotatef(angle[9],1,0,0);
                glRotatef(angle[10],0,1,0);
                glRotatef(angle[11],0,0,1);
                glTranslatef(0,-0.05,0);
                drawfoot();
        glPopMatrix();
        glPushMatrix();
               glScalef(5,5,5);
                glRotatef(180,0,1,0);
                glTranslatef(-0.04,-0.08,0.07);
                glRotatef(angle[12],1,0,0);
                glRotatef(angle[13],0,1,0);
                glRotatef(angle[14],0,0,1);
                glTranslatef(0,-0.05,0);
                drawfoot();
        glPopMatrix();
    //glPopMatrix();
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;
int oldX = 0,oldY = 0;
void motion (int x,int y){
    angle[angleID] +=y-oldY;
    oldX= x;
    oldY=y;
    glutPostRedisplay(); ///貼上便利貼，提醒glut要重畫畫面
    if(fout==NULL) fout= fopen("angle.txt","w+");
        for(int i=0;i<20;i++){
            printf("%.1f ",angle[i]);
            fprintf(fout,"%.1f ",angle[i]);
        }
        printf("\n");
        fprintf(fout,"\n");
}
void mouse(int button,int state,int x,int y){
    oldX= x;
    oldY= y;
}

float oldAngle[20]={},newAngle[20]={};
void timer(int t){ ///week12
    glutTimerFunc(50,timer,t+1);
    if(t%20==0){
        if(fin==NULL) fin= fopen("angle.txt","r");
        for(int i=0;i<20;i++){
            oldAngle[i] = newAngle[i];
            fscanf(fin,"%f", &newAngle[i]);
        }
    }
    float alpha=(t%20)/20.0;
    for(int i=0;i<20;i++){
        angle[i]=newAngle[i]*alpha+oldAngle[i]*(1-alpha);
    }
    glutPostRedisplay();
}






void keyboard(unsigned char key,int x,int y){

    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
    if(key=='a') angleID = 10;
    if(key=='b') angleID = 11;
    if(key=='c') angleID = 12;
    if(key=='d') angleID = 13;
    if(key=='e') angleID = 14;
    //if(key=='f') angleID = 15;

    if(key=='p'){
        glutTimerFunc(0,timer,0);
    }
    else if(key=='s'){
        if(fout==NULL) fout = fopen("angle.txt","w+");
        for(int i=0;i<20;i++){
            printf("%.1f ",angle[i]);
            fprintf(fout,"%.1f ",angle[i]);
        }
        printf("\n");
        fprintf(fout,"\n");
        }
}






int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13-1_keyboard_angleID_mouse_motion_angle");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    id1=myTexture("C:/lego.jpg");
    glutMotionFunc(motion);
    ///myTexture("Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
