#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// Örnek1:

void display() {
    // Ekraný temizler.
    glClear(GL_COLOR_BUFFER_BIT);
    // Üçgen çizilmesi için boru hattý baþlatýr.
    glBegin(GL_POLYGON);
    // Köþeler ve renkleri belirlenir.
    glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0.0);
    glColor3f(0, 0, 1); glVertex3f(0.0, 0.75, 0.0);
    glEnd();
    // Çizim komutlarýný çalýþtýrýr.
    glFlush();
}

/*
 * OGL01Shape3D.cpp: 3D Þekiller
 */
#include <windows.h>  // MS Windows için
#include <GL/glut.h>  // GLUT, glu.h ve gl.h dosyalarýný içerir

 /* Global deðiþkenler */
char title[] = "3D Þekiller";

/* OpenGL Grafikleri Baþlat */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Arka plan rengini siyah ve opak olarak ayarla
    glClearDepth(1.0f);                   // Arka plan derinliðini en uzaða ayarla
    glEnable(GL_DEPTH_TEST);   // Z-culling için derinlik testini etkinleþtir
    glDepthFunc(GL_LEQUAL);    // Derinlik testi türünü ayarla
    glShadeModel(GL_SMOOTH);   // Yumuþak gölgelendirmeyi etkinleþtir
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Güzel perspektif düzeltmeleri
}

// Örnek2

void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlarýný temizle
    glMatrixMode(GL_MODELVIEW);     // Model-görünüm matrisi üzerinde çalýþmak için

    // Farklý renklere sahip 6 dörtlüden oluþan bir renk küpü render et
    glLoadIdentity();                 // Model-görünüm matrisini sýfýrla
    glTranslatef(1.5f, 0.0f, -7.0f);  // Saða hareket et ve ekrana doðru ilerle

    glBegin(GL_QUADS);                // 6 dörtlü ile renk küpünü çizmeye baþla
    // Üst yüzey (y = 1.0f)
    // Normali dýþa bakacak þekilde köþeleri saat yönünün tersinde (CCW) sýrayla tanýmla
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Alt yüzey (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Turuncu
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Ön yüzey (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Arka yüzey (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Sarý
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Sol yüzey (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Sað yüzey (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Macenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // Renk küpü çiziminin sonu

    // 4 üçgenden oluþan bir piramit render et
    glLoadIdentity();                  // Model-görünüm matrisini sýfýrla
    glTranslatef(-1.5f, 0.0f, -6.0f);  // Sola hareket et ve ekrana doðru ilerle

    glBegin(GL_TRIANGLES);           // 4 üçgenle piramidi çizmeye baþla
    // Ön
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Sað
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Arka
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
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
    glEnd();   // Piramit çiziminin sonu

    glutSwapBuffers();  // Ön ve arka çerçeve bufferlarýný deðiþtir
}

/*pencere yediden boyutlandýrma */
void reshape2(GLsizei width, GLsizei height) {  //Negatif olmayan tamsayý için GLsizei
    // Yeni pencerenin en boy oranýný hesapla
    if (height == 0) height = 1;                // 0'a bölünmeyi önlemek için
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Görünüm penceresini yeni pencereyi kapsayacak þekilde ayarlayýn
    glViewport(0, 0, width, height);

    // Kýrpma hacminin en boy oranýný görünümle eþleþecek þekilde ayarlayýn
    glMatrixMode(GL_PROJECTION);  // Projeksiyon matrisinde çalýþmak için
    glLoadIdentity();             // Reset
    // Fovy, en-boy oraný, zNear ve zFar ile perspektif projeksiyonunu etkinleþtirin
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}



//Örnek3

#include <windows.h>  
#include <GL/glut.h>  

/* Global deðiþkenler */
char title3[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Piramidin dönme açýsý
GLfloat angleCube = 0.0f;     // Küpün dönme açýsý
int refreshMills = 15;        // Milisaniye cinsinden yenileme aralýðý

/* OpenGL Grafiklerini Baþlat */
void initGL3() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Arka plan rengini siyah ve opak olarak ayarlayýn
    glClearDepth(1.0f);                   // Arka plan derinliðini en uzaða ayarla
    glEnable(GL_DEPTH_TEST);   // Z-ayýklama için derinlik testini etkinleþtir
    glDepthFunc(GL_LEQUAL);    // Derinlik testinin türünü ayarlayýn
    glShadeModel(GL_SMOOTH);   // Düzgün gölgelendirmeyi etkinleþtir
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Güzel perspektif düzeltmeleri
}

/* Pencereyi yeniden boyutlandýrma */
void display3() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlarýný temizleyin
    glMatrixMode(GL_MODELVIEW);     // Model görünümü matrisinde çalýþmak için

    // Farklý renklere sahip 6 dörtlüden oluþan bir renk küpü oluþturun
    glLoadIdentity();                 // Model görünümü matrisini sýfýrlayýn
    glTranslatef(1.5f, 0.0f, -7.0f);  // Saða ve ekranýn içine doðru hareket edin
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // (1,1,1) ekseni etrafýnda döndürme

    glBegin(GL_QUADS);                // küpü çizime baþla
    // Üst yüz (y = 1,0f)
    // Köþeleri saat yönünün tersine sýrayla ve normal iþaretle tanýmlayýn
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Alt Yüz (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Turuncu
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Ön Yüz  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Arka Yüz (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Sarý
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Sol Yüz (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Sað Yüz (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Macenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // son

    // Primidi oluþturma
    glLoadIdentity();                 
    glTranslatef(-1.5f, 0.0f, -6.0f);  
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f); 

    glBegin(GL_TRIANGLES);           
    // Ön
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Sað
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Arka
    glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Sol
    glColor3f(1.0f, 0.0f, 0.0f);       // Kýrmýzý
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Mavi
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // Yeþil
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   

    glutSwapBuffers();  

    // Her yenilemeden sonra dönme açýsýný güncelleyin 
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

    // Görünüm penceresini yeni pencereyi kapsayacak þekilde ayarlayýn
    glViewport(0, 0, width, height);

    // Kýrpma hacminin en boy oranýný görünümle eþleþecek þekilde ayarlayýn
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();             
    // en-boy oraný, zNear ve zFar ile perspektif projeksiyonunu etkinleþtirin
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}



//Örnek4

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

// Bir kamera.   Merkezi merkezde olan bir daire içinde yatay olarak hareket eder.
// yarýçap 10. Dikey olarak yukarý ve aþaðý doðru hareket eder.
class Camera {
    double theta;      // x ve z konumlarýný belirler
    double y;          // mevcut y konumu
    double dTheta;     // Kamerayý döndürmek için teta artýþý
    double dy;         // kamerayý yukarý/aþaðý hareket ettirmek için y cinsinden artýþ
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

//Top Tanýmý
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

// Global deðiþkenler
Checkerboard checkerboard(8, 8);
Camera camera;
Ball balls[] = {
  Ball(1, GREEN, 7, 6, 1),
  Ball(1.5, MAGENTA, 6, 3, 4),
  Ball(0.4, WHITE, 5, 1, 7)
};


// Uygulamaya özel baþlatma: Genel aydýnlatma parametrelerini ayarlayýn
// ve görüntüleme listeleri oluþturun.
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

// Geçerli kameradan bir kare, önce dama tahtasý, ardýndan toplar çizer
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

// Yeniden þekillendirirken pencereye mükemmel þekilde uyan bir kamera oluþturur.
void reshape4(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
}

// Bir sonraki kareyi çizme isteði.
void timer4(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, v);
}

// Basýlan tuþa göre kamerayý hareket ettirir, ardýndan ekranýn yenilenmesini ister.
void special(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT: camera.moveRight(); break;
    case GLUT_KEY_RIGHT: camera.moveLeft(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
    }
    glutPostRedisplay();
}


//Örnek5




#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

// Bir balýk bit haritasý, boyutu 27x11'dir, ancak tüm satýrlarýn 8 bitin katý olmasý gerekir,
// yani 32x11 gibi tanýmlýyoruz.
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

// 0,0 ila 1,0 aralýðýnda rastgele bir kayan nokta döndürün.
GLfloat randomFloat() {
    return (GLfloat)rand() / RAND_MAX;
}

// Yeniden þekillendirirken, dünya koordinatlarý arasýnda deðiþen ortografik bir projeksiyon kullanýr
// x ve y yönlerinde 0'dan 1'e ve z'de -1'den 1'e.
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
    glutInit(&argc, argv);//glut baþlatýr.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Tek arabellekli ve RGB modunda pencere oluþturulur.

    glutInitWindowPosition(80, 80); //Pernecere pozisyonu ve boyutu belirlenir
    glutInitWindowSize(400, 300);  //
    glutCreateWindow("A Simple Triangle");//pencere oluþturulur.

    glutDisplayFunc(display);//Yeniden çizim gerektiðinde çaðrýlýcak fonksiyon(pencerenin boyutunu deðiþtirme)
    glutMainLoop();//Olay döngüsü baþlatýr.

}


void example2(int argc, char** argv) {
    glutInit(&argc, argv);            // GLUT'u baþlat
    glutInitDisplayMode(GLUT_DOUBLE); // Çift tamponlu modu etkinleþtir
    glutInitWindowSize(640, 480);   // Pencerenin baþlangýç geniþlik ve yüksekliðini ayarla
    glutInitWindowPosition(50, 50); // Pencerenin baþlangýç sol üst köþe konumunu ayarla
    glutCreateWindow(title);          // Belirtilen baþlýkla pencere oluþtur
    glutDisplayFunc(display2);       // Pencere yeniden boyandýðýnda çaðrýlacak geri çaðýrma iþlevini kaydet
    glutReshapeFunc(reshape2);       // Pencere yeniden boyutlandýrýldýðýnda çaðrýlacak geri çaðýrma iþlevini kaydet
    initGL();                       // OpenGL baþlatma iþlemlerimiz
    glutMainLoop();                 // Sonsuz olay iþleme döngüsüne gir
}


void example3(int argc, char** argv) {
    glutInit(&argc, argv);            // GLUT'u baþlat
    glutInitDisplayMode(GLUT_DOUBLE); // Çift tamponlu modu etkinleþtir
    glutInitWindowSize(640, 480);   // Pencerenin baþlangýç geniþlik ve yüksekliðini ayarla
    glutInitWindowPosition(50, 50); // Pencerenin baþlangýç sol üst köþe konumunu ayarla
    glutCreateWindow(title3);          // Belirtilen baþlýkla pencere oluþtur
    glutDisplayFunc(display3);       // Pencere yeniden boyandýðýnda çaðrýlacak geri çaðýrma iþlevini kaydet
    glutReshapeFunc(reshape3);       // Pencere yeniden boyutlandýrýldýðýnda çaðrýlacak geri çaðýrma iþlevini kaydet
    initGL3();                       // OpenGL baþlatma iþlemlerimiz
    glutTimerFunc(0, timer, 0);     // Ýlk zamanlayýcý çaðrýsý hemen yapýlýr [YENÝ]
    glutMainLoop();                 // Sonsuz olay iþleme döngüsüne gir
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