#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int id;
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
#include <GL/glut.h>
#include "glm.h"
#include<windows.h>
float teapotX=0, teapotY=0;
GLMmodel * pmodel = NULL; ///加的程式，有顆指標，指到模型檔
GLMmodel * body = NULL;
GLMmodel * face = NULL;
GLMmodel * hair = NULL;
GLMmodel * eyes = NULL;
GLMmodel * head = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
GLMmodel * leftlower = NULL;
GLMmodel * leftupper = NULL;
GLMmodel * rightlower = NULL;
GLMmodel * rightupper = NULL;
GLMmodel * pants = NULL;
GLMmodel * rightlowerfoot = NULL;
GLMmodel * rightupperfoot = NULL;
GLMmodel * leftlowerfoot = NULL;
GLMmodel * leftupperfoot = NULL;

void drawhead(void)
{
    if(!head){
        head = glmReadOBJ("head.obj");
        if(!head) exit(0);
        glmUnitize(head);
        glmFacetNormals(head);
        glmVertexNormals(head, 90.0);
    }
    glmDraw(head, GLM_SMOOTH | GLM_MATERIAL);
}
void drawface(void)
{
    if(!face){
        face = glmReadOBJ("face.obj");
        if(!face) exit(0);
        glmUnitize(face);
        glmFacetNormals(face);
        glmVertexNormals(face, 90.0);
    }
    glmDraw(face, GLM_SMOOTH | GLM_MATERIAL);
}
void drawhair(void)
{
    if(!hair){
        hair = glmReadOBJ("hair.obj");
        if(!hair) exit(0);
        glmUnitize(hair);
        glmFacetNormals(hair);
        glmScale(hair,1.2);
        glmVertexNormals(hair, 90.0);
    }
    glmDraw(hair, GLM_SMOOTH | GLM_MATERIAL);
}
void draweyes(void)
{
    if(!eyes){
        eyes = glmReadOBJ("eyes.obj");
        if(!eyes) exit(0);
        glmUnitize(eyes);
        glmFacetNormals(eyes);
        glmVertexNormals(eyes, 90.0);
    }
    glmDraw(eyes, GLM_SMOOTH | GLM_MATERIAL);
}
void drawbody(void)
{
    if(!body){
        body = glmReadOBJ("body.obj");
        if(!body) exit(0);
        glmUnitize(body);
        glmFacetNormals(body);
        glmVertexNormals(body, 90.0);
    }
    glmDraw(body, GLM_SMOOTH | GLM_MATERIAL);
}
void drawmodel(void)
{
    if(!pmodel){
        pmodel = glmReadOBJ("1.obj");
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

void drawhand1(void)
{
    if(!hand1){
        hand1 = glmReadOBJ("hand1.obj");
        if(!hand1) exit(0);
        glmUnitize(hand1);
        glmFacetNormals(hand1);
        glmVertexNormals(hand1, 90.0);
    }
    glmDraw(hand1, GLM_SMOOTH | GLM_MATERIAL);
}

void drawhand2(void)
{
    if(!hand2){
        hand2 = glmReadOBJ("hand2.obj");
        if(!hand2) exit(0);
        glmUnitize(hand2);
        glmFacetNormals(hand2);
        glmVertexNormals(hand2, 90.0);
    }
    glmDraw(hand2, GLM_SMOOTH | GLM_MATERIAL);
}
void drawleftlower(void)
{
    if(!leftlower){
        leftlower = glmReadOBJ("leftlower.obj");
        if(!leftlower) exit(0);
        glmUnitize(leftlower);
        glmFacetNormals(leftlower);
        glmVertexNormals(leftlower, 90.0);
    }
    glmDraw(leftlower, GLM_SMOOTH | GLM_MATERIAL);
}
void drawleftupper(void)
{
    if(!leftupper){
        leftupper = glmReadOBJ("leftupper.obj");
        if(!leftupper) exit(0);
        glmUnitize(leftupper);
        glmFacetNormals(leftupper);
        glmVertexNormals(leftupper, 90.0);
    }
    glmDraw(leftupper, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrightlower(void)
{
    if(!rightlower){
        rightlower = glmReadOBJ("rightlower.obj");
        if(!rightlower) exit(0);
        glmUnitize(rightlower);
        glmFacetNormals(rightlower);
        glmVertexNormals(rightlower, 90.0);
    }
    glmDraw(rightlower, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrightupper(void)
{
    if(!rightupper){
        rightupper = glmReadOBJ("rightupper.obj");
        if(!rightupper) exit(0);
        glmUnitize(rightupper);
        glmFacetNormals(rightupper);
        glmVertexNormals(rightupper, 90.0);
    }
    glmDraw(rightupper, GLM_SMOOTH | GLM_MATERIAL);
}
void drawpants(void)
{
    if(!pants){
        pants = glmReadOBJ("pants.obj");
        if(!pants) exit(0);
        glmUnitize(pants);
        glmFacetNormals(pants);
        glmScale(pants,0.8);
        glmVertexNormals(pants, 90.0);
    }
    glmDraw(pants, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrightlowerfoot(void)
{
    if(!rightlowerfoot){
        rightlowerfoot = glmReadOBJ("rightlowerfoot.obj");
        if(!rightlowerfoot) exit(0);
        glmUnitize(rightlowerfoot);
        glmFacetNormals(rightlowerfoot);
        glmScale(rightlowerfoot,0.2);
        glmVertexNormals(rightlowerfoot, 90.0);
    }
    glmDraw(rightlowerfoot, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrightupperfoot(void)
{
    if(!rightupperfoot){
        rightupperfoot = glmReadOBJ("rightupperfoot.obj");
        if(!rightupperfoot) exit(0);
        glmUnitize(rightupperfoot);
        glmFacetNormals(rightupperfoot);
        glmScale(rightupperfoot,0.5);
        glmVertexNormals(rightupperfoot, 90.0);
    }
    glmDraw(rightupperfoot, GLM_SMOOTH | GLM_MATERIAL);
}
void drawleftlowerfoot(void)
{
    if(!leftlowerfoot){
        leftlowerfoot = glmReadOBJ("leftlowerfoot.obj");
        if(!leftlowerfoot) exit(0);
        glmUnitize(leftlowerfoot);
        glmScale(leftlowerfoot,0.2);
        glmFacetNormals(leftlowerfoot);
        glmVertexNormals(leftlowerfoot, 90.0);
    }
    glmDraw(leftlowerfoot, GLM_SMOOTH | GLM_MATERIAL);
}
void drawleftupperfoot(void)
{
    if(!leftupperfoot){
        leftupperfoot = glmReadOBJ("leftupperfoot.obj");
        if(!leftupperfoot) exit(0);
        glmUnitize(leftupperfoot);
        glmScale(leftupperfoot,0.5);
        glmFacetNormals(leftupperfoot);
        glmVertexNormals(leftupperfoot, 90.0);
    }
    glmDraw(leftupperfoot, GLM_SMOOTH | GLM_MATERIAL);
}
int angleID = 0;
float angleX[10] = { };
float angleY[10] = { };
void display()
{
    glClearColor(1,1,0,0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //glutSolidSphere( 0.02, 30, 30);///放在畫面正中心，校對用的
    ///body


    glPushMatrix();
        glTranslatef(-0.027, 0.527, 0);
        draweyes();
    glPushMatrix();
        glTranslatef(-0.000, 0.113, -0.167);
        drawhair();
    glPushMatrix();
        glTranslatef(0.000, -0.140, 0);
        drawface();
    glPushMatrix();
        glTranslatef(-0.007, -0.860, 0);
        drawpants();
        glPushMatrix();
        glTranslatef(-0.000, 0.367, 0);
    drawbody();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    ///right arm

    glPushMatrix();
        glTranslatef(0.153, 0.167, -0.160);
        glRotatef(angleX[1],1,0,0);
        glRotatef(angleY[1],0,1,0);
        glTranslatef(0.087, -0.040, 0);
        drawrightupper();
    glPushMatrix();
        glTranslatef(0.093, -0.067, 0);
        glRotatef(angleX[2],1,0,0);
        glRotatef(angleY[2],0,1,0);
        glTranslatef(0.153, -0.080, 0);
        drawrightlower();
    glPopMatrix();
    glPopMatrix();

    ///left arm
    glPushMatrix();
        glTranslatef(-0.233, 0.167, -0.187);
        glRotatef(angleX[3],1,0,0);
        glRotatef(angleY[3],0,1,0);
        glTranslatef(-0.087, -0.047, 0);
        drawleftupper();
    glPushMatrix();
        glTranslatef(-0.093, -0.073, 0);
        glRotatef(angleX[4],1,0,0);
        glRotatef(angleY[4],0,1,0);
        glTranslatef(-0.160, -0.080, 0);
        drawleftlower();
    glPopMatrix();
    glPopMatrix();

    ///right leg
    glPushMatrix();
        glTranslatef(0.133, -0.513, -0.153);
        glRotatef(angleX[5],1,0,0);
        glRotatef(angleY[5],0,1,0);
        glTranslatef(-0.007, -0.073, 0);
        drawrightupperfoot();
    glPushMatrix();
        glTranslatef(0.013, -0.093, 0);
        glRotatef(angleX[6],1,0,0);
        glRotatef(angleY[6],0,1,0);
        glTranslatef(0.007, -0.187, 0.047);
        drawrightlowerfoot();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.173, -0.500, -0.167);
        glRotatef(angleX[7],1,0,0);
        glRotatef(angleY[7],0,1,0);
        glTranslatef(-0.000, -0.073, 0);
        drawleftupperfoot();
    glPushMatrix();
        glTranslatef(-0.007, -0.093, 0);
        glRotatef(angleX[8],1,0,0);
        glRotatef(angleY[8],0,1,0);
        glTranslatef(-0.013, -0.173, 0.047);
        drawleftlowerfoot();
    glPopMatrix();
    glPopMatrix();
    ///背景
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D,id);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex3f(-4, +4,-0.9);
        glTexCoord2f(0, 1); glVertex3f(-4, -4,-0.9);
        glTexCoord2f(1, 1); glVertex3f(+4, -4,-0.9);
        glTexCoord2f(1, 0); glVertex3f(+4, +4,-0.9);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glutSwapBuffers();

}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;
void timer(int t);
void keyboard(unsigned char key, int x, int y ) {
    if(key=='p') { ///Play 播放
        glutTimerFunc(0, timer, 0);
    }
    if(key=='r') { ///Read 讀資料
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<10; i++) {
            fscanf(fin, "%f", & angleX[i] );
            fscanf(fin, "%f", & angleY[i] );
        }
        glutPostRedisplay();
    }

    if(key=='s') { ///Save 存檔
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<10; i++) {
            printf("%.1f ", angleX[i] );
            fprintf(fout, "%.1f ", angleX[i] );
            printf("%.1f ", angleY[i] );
            fprintf(fout, "%.1f ", angleY[i] );


        }
        printf("\n");
        fprintf(fout, "\n");
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
}
int oldX = 0, oldY = 0 ,oldZ= 0;
void mouse(int button, int state, int x, int y ) {
    oldX = x;
    oldY = y;

}

void motion(int x, int y ) {
    angleX[angleID] += y - oldY; ///左右兩個不一樣
    angleY[angleID] += x - oldX;

    oldX = x;
    oldY = y;
    glutPostRedisplay(); ///貼上便利貼,提醒GLUT要重畫畫面
}
float oldAngleX[10] = {}; ///另外2個
float oldAngleY[10] = {};
float newAngleX[10] = {};
float newAngleY[10] = {};
void timer(int t) { ///week14-2
    glutTimerFunc(50, timer, t+1);
    if(fin==NULL) fin = fopen("angle.txt", "r");
    if(t%20==0){ ///要讀入新的資料
        for(int i=0; i<10; i++){
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            fscanf(fin, "%f", &newAngleX[i]);
            fscanf(fin, "%f", &newAngleY[i]);
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0; i<10; i++){
        angleX[i] = alpha * newAngleX[i] + (1-alpha) * oldAngleX[i];
        angleY[i] = alpha * newAngleY[i] + (1-alpha) * oldAngleY[i];
    }
    glutPostRedisplay();
    printf("你呼叫了 timer(%d)\n", t); ///week14-2
}
void reshape(int w, int h) {
    float ar = w / (float) h; ///aspect ratio 長寬比
    glViewport(0, 0, w, h);  ///設定可以看到的範圍,全看到

    glMatrixMode(GL_PROJECTION);  ///現在要設定成Projection矩陣
    glLoadIdentity(); ///最原始的單位矩陣I
    gluPerspective(60, ar, 0.1, 100); ///透視投影的參數

    glMatrixMode(GL_MODELVIEW); ///現在要切換回 model view 矩陣(畫圖的T,R,S的那個)
    glLoadIdentity();
    gluLookAt(0, 0.3, 2,  0, 0, 0,  0, 1, 0);
}




int main(int argc, char* argv[])
{
    printf("程式開始執行\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Homework");
    glutInitWindowSize(800,600);
    glutDisplayFunc(display);
    id = myTexture("c:/2.jpg");
    glutIdleFunc(display); ///加入旋轉
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    PlaySound("C:/Y2.wav",NULL,SND_ASYNC);
    glutReshapeFunc(reshape);



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
