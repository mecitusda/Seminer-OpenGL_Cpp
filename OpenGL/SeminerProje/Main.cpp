#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// �rnek1:

void display() {
    // Ekran� temizler.
    glClear(GL_COLOR_BUFFER_BIT);
    // ��gen �izilmesi i�in boru hatt� ba�lat�r.
    glBegin(GL_POLYGON);
    // K��eler ve renkleri belirlenir.
    glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0.0);
    glColor3f(0, 0, 1); glVertex3f(0.0, 0.75, 0.0);
    glEnd();
    // �izim komutlar�n� �al��t�r�r.
    glFlush();
}

/*
 * OGL01Shape3D.cpp: 3D �ekiller
 */
#include <windows.h>  // MS Windows i�in
#include <GL/glut.h>  // GLUT, glu.h ve gl.h dosyalar�n� i�erir

 /* Global de�i�kenler */
char title[] = "3D �ekiller";

/* OpenGL Grafikleri Ba�lat */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Arka plan rengini siyah ve opak olarak ayarla
    glClearDepth(1.0f);                   // Arka plan derinli�ini en uza�a ayarla
    glEnable(GL_DEPTH_TEST);   // Z-culling i�in derinlik testini etkinle�tir
    glDepthFunc(GL_LEQUAL);    // Derinlik testi t�r�n� ayarla
    glShadeModel(GL_SMOOTH);   // Yumu�ak g�lgelendirmeyi etkinle�tir
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // G�zel perspektif d�zeltmeleri
}

// �rnek2

void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlar�n� temizle
    glMatrixMode(GL_MODELVIEW);     // Model-g�r�n�m matrisi �zerinde �al��mak i�in

    // Farkl� renklere sahip 6 d�rtl�den olu�an bir renk k�p� render et
    glLoadIdentity();                 // Model-g�r�n�m matrisini s�f�rla
    glTranslatef(1.5f, 0.0f, -7.0f);  // Sa�a hareket et ve ekrana do�ru ilerle

    glBegin(GL_QUADS);                // 6 d�rtl� ile renk k�p�n� �izmeye ba�la
    // �st y�zey (y = 1.0f)
    // Normali d��a bakacak �ekilde k��eleri saat y�n�n�n tersinde (CCW) s�rayla tan�mla
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Alt y�zey (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Turuncu
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // �n y�zey (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Arka y�zey (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Sar�
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Sol y�zey (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Sa� y�zey (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Macenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // Renk k�p� �iziminin sonu

    // 4 ��genden olu�an bir piramit render et
    glLoadIdentity();                  // Model-g�r�n�m matrisini s�f�rla
    glTranslatef(-1.5f, 0.0f, -6.0f);  // Sola hareket et ve ekrana do�ru ilerle

    glBegin(GL_TRIANGLES);           // 4 ��genle piramidi �izmeye ba�la
    // �n
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Sa�
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Arka
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    glColor3f(1.0f, 0.0f, 0.0f);       // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   // Piramit �iziminin sonu

    glutSwapBuffers();  // �n ve arka �er�eve bufferlar�n� de�i�tir
}

/*pencere yediden boyutland�rma */
void reshape2(GLsizei width, GLsizei height) {  //Negatif olmayan tamsay� i�in GLsizei
    // Yeni pencerenin en boy oran�n� hesapla
    if (height == 0) height = 1;                // 0'a b�l�nmeyi �nlemek i�in
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // G�r�n�m penceresini yeni pencereyi kapsayacak �ekilde ayarlay�n
    glViewport(0, 0, width, height);

    // K�rpma hacminin en boy oran�n� g�r�n�mle e�le�ecek �ekilde ayarlay�n
    glMatrixMode(GL_PROJECTION);  // Projeksiyon matrisinde �al��mak i�in
    glLoadIdentity();             // Reset
    // Fovy, en-boy oran�, zNear ve zFar ile perspektif projeksiyonunu etkinle�tirin
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}



//�rnek3

#include <windows.h>  
#include <GL/glut.h>  

/* Global de�i�kenler */
char title3[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Piramidin d�nme a��s�
GLfloat angleCube = 0.0f;     // K�p�n d�nme a��s�
int refreshMills = 15;        // Milisaniye cinsinden yenileme aral���

/* OpenGL Grafiklerini Ba�lat */
void initGL3() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Arka plan rengini siyah ve opak olarak ayarlay�n
    glClearDepth(1.0f);                   // Arka plan derinli�ini en uza�a ayarla
    glEnable(GL_DEPTH_TEST);   // Z-ay�klama i�in derinlik testini etkinle�tir
    glDepthFunc(GL_LEQUAL);    // Derinlik testinin t�r�n� ayarlay�n
    glShadeModel(GL_SMOOTH);   // D�zg�n g�lgelendirmeyi etkinle�tir
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // G�zel perspektif d�zeltmeleri
}

/* Pencereyi yeniden boyutland�rma */
void display3() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlar�n� temizleyin
    glMatrixMode(GL_MODELVIEW);     // Model g�r�n�m� matrisinde �al��mak i�in

    // Farkl� renklere sahip 6 d�rtl�den olu�an bir renk k�p� olu�turun
    glLoadIdentity();                 // Model g�r�n�m� matrisini s�f�rlay�n
    glTranslatef(1.5f, 0.0f, -7.0f);  // Sa�a ve ekran�n i�ine do�ru hareket edin
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // (1,1,1) ekseni etraf�nda d�nd�rme

    glBegin(GL_QUADS);                // k�p� �izime ba�la
    // �st y�z (y = 1,0f)
    // K��eleri saat y�n�n�n tersine s�rayla ve normal i�aretle tan�mlay�n
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Alt Y�z (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Turuncu
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // �n Y�z  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Arka Y�z (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Sar�
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Sol Y�z (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Sa� Y�z (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Macenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // son

    // Primidi olu�turma
    glLoadIdentity();                 
    glTranslatef(-1.5f, 0.0f, -6.0f);  
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f); 

    glBegin(GL_TRIANGLES);           
    // �n
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Sa�
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Arka
    glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Sol
    glColor3f(1.0f, 0.0f, 0.0f);       // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // Ye�il
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   

    glutSwapBuffers();  

    // Her yenilemeden sonra d�nme a��s�n� g�ncelleyin 
    anglePyramid += 0.2f;
    angleCube -= 0.15f;
}


void timer(int value) {
    glutPostRedisplay();      
    glutTimerFunc(refreshMills, timer, 0); 
}


void reshape3(GLsizei width, GLsizei height) {  
    
    if (height == 0) height = 1;                
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // G�r�n�m penceresini yeni pencereyi kapsayacak �ekilde ayarlay�n
    glViewport(0, 0, width, height);

    // K�rpma hacminin en boy oran�n� g�r�n�mle e�le�ecek �ekilde ayarlay�n
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();             
    // en-boy oran�, zNear ve zFar ile perspektif projeksiyonunu etkinle�tirin
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}



//�rnek4

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

// Colors
GLfloat WHITE[] = { 1, 1, 1 };
GLfloat RED[] = { 1, 0, 0 };
GLfloat GREEN[] = { 0, 1, 0 };
GLfloat MAGENTA[] = { 1, 0, 1 };

// Bir kamera.   Merkezi merkezde olan bir daire i�inde yatay olarak hareket eder.
// yar��ap 10. Dikey olarak yukar� ve a�a�� do�ru hareket eder.
class Camera {
    double theta;      // x ve z konumlar�n� belirler
    double y;          // mevcut y konumu
    double dTheta;     // Kameray� d�nd�rmek i�in teta art���
    double dy;         // kameray� yukar�/a�a�� hareket ettirmek i�in y cinsinden art��
public:
    Camera() : theta(0), y(3), dTheta(0.04), dy(0.2) {}
    double getX() { return 10 * cos(theta); }
    double getY() { return y; }
    double getZ() { return 10 * sin(theta); }
    void moveRight() { theta += dTheta; }
    void moveLeft() { theta -= dTheta; }
    void moveUp() { y += dy; }
    void moveDown() { if (y > dy) y -= dy; }
};

//Top Tan�m�
class Ball {
    double radius;
    GLfloat* color;
    double maximumHeight;
    double x;
    double y;
    double z;
    int direction;
public:
    Ball(double r, GLfloat* c, double h, double x, double z) :
        radius(r), color(c), maximumHeight(h), direction(-1),
        y(h), x(x), z(z) {
    }
    void update() {
        y += direction * 0.05;
        if (y > maximumHeight) {
            y = maximumHeight; direction = -1;
        }
        else if (y < radius) {
            y = radius; direction = 1;
        }
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        glTranslated(x, y, z);
        glutSolidSphere(radius, 30, 30);
        glPopMatrix();
    }
};


class Checkerboard {
    int displayListId;
    int width;
    int depth;
public:
    Checkerboard(int width, int depth) : width(width), depth(depth) {}
    double centerx() { return width / 2; }
    double centerz() { return depth / 2; }
    void create() {
        displayListId = glGenLists(1);
        glNewList(displayListId, GL_COMPILE);
        GLfloat lightPosition[] = { 4, 3, 7, 1 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glBegin(GL_QUADS);
        glNormal3d(0, 1, 0);
        for (int x = 0; x < width - 1; x++) {
            for (int z = 0; z < depth - 1; z++) {
                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                    (x + z) % 2 == 0 ? RED : WHITE);
                glVertex3d(x, 0, z);
                glVertex3d(x + 1, 0, z);
                glVertex3d(x + 1, 0, z + 1);
                glVertex3d(x, 0, z + 1);
            }
        }
        glEnd();
        glEndList();
    }
    void draw() {
        glCallList(displayListId);
    }
};

// Global de�i�kenler
Checkerboard checkerboard(8, 8);
Camera camera;
Ball balls[] = {
  Ball(1, GREEN, 7, 6, 1),
  Ball(1.5, MAGENTA, 6, 3, 4),
  Ball(0.4, WHITE, 5, 1, 7)
};


// Uygulamaya �zel ba�latma: Genel ayd�nlatma parametrelerini ayarlay�n
// ve g�r�nt�leme listeleri olu�turun.
void init4() {
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    checkerboard.create();
}

// Ge�erli kameradan bir kare, �nce dama tahtas�, ard�ndan toplar �izer
void display4() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera.getX(), camera.getY(), camera.getZ() - 4,
        checkerboard.centerx(), 0.0, checkerboard.centerz(),
        0.0, 1.0, 0.0);
    checkerboard.draw();
    for (int i = 0; i < sizeof balls / sizeof(Ball); i++) {
        balls[i].update();
    }
    glFlush();
    glutSwapBuffers();
}

// Yeniden �ekillendirirken pencereye m�kemmel �ekilde uyan bir kamera olu�turur.
void reshape4(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
}

// Bir sonraki kareyi �izme iste�i.
void timer4(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, v);
}

// Bas�lan tu�a g�re kameray� hareket ettirir, ard�ndan ekran�n yenilenmesini ister.
void special(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT: camera.moveRight(); break;
    case GLUT_KEY_RIGHT: camera.moveLeft(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
    }
    glutPostRedisplay();
}


//�rnek5




#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

// Bir bal�k bit haritas�, boyutu 27x11'dir, ancak t�m sat�rlar�n 8 bitin kat� olmas� gerekir,
// yani 32x11 gibi tan�ml�yoruz.
GLubyte fish[] = {
  0x00, 0x60, 0x01, 0x00,
  0x00, 0x90, 0x01, 0x00,
  0x03, 0xf8, 0x02, 0x80,
  0x1c, 0x37, 0xe4, 0x40,
  0x20, 0x40, 0x90, 0x40,
  0xc0, 0x40, 0x78, 0x80,
  0x41, 0x37, 0x84, 0x80,
  0x1c, 0x1a, 0x04, 0x80,
  0x03, 0xe2, 0x02, 0x40,
  0x00, 0x11, 0x01, 0x40,
  0x00, 0x0f, 0x00, 0xe0,
};

// 0,0 ila 1,0 aral���nda rastgele bir kayan nokta d�nd�r�n.
GLfloat randomFloat() {
    return (GLfloat)rand() / RAND_MAX;
}

// Yeniden �ekillendirirken, d�nya koordinatlar� aras�nda de�i�en ortografik bir projeksiyon kullan�r
// x ve y y�nlerinde 0'dan 1'e ve z'de -1'den 1'e.
void reshape5(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
}


void display5() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < 20; i++) {
        glColor3f(randomFloat(), randomFloat(), randomFloat());
        glRasterPos3f(randomFloat(), randomFloat(), 0.0);
        glBitmap(27, 11, 0, 0, 0, 0, fish);
    }
    glFlush();
}




// ---------------------------------------------------------------------/




void example1(int argc, char** argv) {
    glutInit(&argc, argv);//glut ba�lat�r.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Tek arabellekli ve RGB modunda pencere olu�turulur.

    glutInitWindowPosition(80, 80); //Pernecere pozisyonu ve boyutu belirlenir
    glutInitWindowSize(400, 300);  //
    glutCreateWindow("A Simple Triangle");//pencere olu�turulur.

    glutDisplayFunc(display);//Yeniden �izim gerekti�inde �a�r�l�cak fonksiyon(pencerenin boyutunu de�i�tirme)
    glutMainLoop();//Olay d�ng�s� ba�lat�r.

}


void example2(int argc, char** argv) {
    glutInit(&argc, argv);            // GLUT'u ba�lat
    glutInitDisplayMode(GLUT_DOUBLE); // �ift tamponlu modu etkinle�tir
    glutInitWindowSize(640, 480);   // Pencerenin ba�lang�� geni�lik ve y�ksekli�ini ayarla
    glutInitWindowPosition(50, 50); // Pencerenin ba�lang�� sol �st k��e konumunu ayarla
    glutCreateWindow(title);          // Belirtilen ba�l�kla pencere olu�tur
    glutDisplayFunc(display2);       // Pencere yeniden boyand���nda �a�r�lacak geri �a��rma i�levini kaydet
    glutReshapeFunc(reshape2);       // Pencere yeniden boyutland�r�ld���nda �a�r�lacak geri �a��rma i�levini kaydet
    initGL();                       // OpenGL ba�latma i�lemlerimiz
    glutMainLoop();                 // Sonsuz olay i�leme d�ng�s�ne gir
}


void example3(int argc, char** argv) {
    glutInit(&argc, argv);            // GLUT'u ba�lat
    glutInitDisplayMode(GLUT_DOUBLE); // �ift tamponlu modu etkinle�tir
    glutInitWindowSize(640, 480);   // Pencerenin ba�lang�� geni�lik ve y�ksekli�ini ayarla
    glutInitWindowPosition(50, 50); // Pencerenin ba�lang�� sol �st k��e konumunu ayarla
    glutCreateWindow(title3);          // Belirtilen ba�l�kla pencere olu�tur
    glutDisplayFunc(display3);       // Pencere yeniden boyand���nda �a�r�lacak geri �a��rma i�levini kaydet
    glutReshapeFunc(reshape3);       // Pencere yeniden boyutland�r�ld���nda �a�r�lacak geri �a��rma i�levini kaydet
    initGL3();                       // OpenGL ba�latma i�lemlerimiz
    glutTimerFunc(0, timer, 0);     // �lk zamanlay�c� �a�r�s� hemen yap�l�r [YEN�]
    glutMainLoop();                 // Sonsuz olay i�leme d�ng�s�ne gir
}

void example4(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bouncing Balls");
    glutDisplayFunc(display4);
    glutReshapeFunc(reshape4);
    glutSpecialFunc(special);
    glutTimerFunc(100, timer, 0);
    init4();
    glutMainLoop();
}


void example5(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Fishies");
    glutReshapeFunc(reshape5);
    glutDisplayFunc(display5);
    glutMainLoop();
}
int main(int argc, char** argv) {
    example1(argc, argv);
    //example2(argc, argv);
    //example3(argc, argv);
    //example4(argc, argv);
    //example5(argc, argv);
   
    return 0;


}