#include <GL/glut.h>
#include"Rubik.h"
#include "Transformaciones.h"
#include "TextureManager.h"


#include <iostream>
using namespace std;


enum DirectionOfRotation {
    rigth,
    left,
    top,
    botttom
};


void display(void);
void generateCube();
void inputManager(unsigned char key, int x, int y);
void update();

DirectionOfRotation directionOfrotation;
Rubik m_rubik;



int main(int argc, char** argv)
{
    TextureManager::getInstance()->loadTextures();
    m_rubik = Rubik(Vector3(), 1);
    glutInit(&argc, argv);                                      //inicia el glut
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE | GLUT_RGB);    //Estable ce la pantalla con doble buffer con los colores rgba
    glutInitWindowPosition(50, 50);                             //establecemos posicion de la pantalla
    glutInitWindowSize(500, 500);                               //Establecemos tamaño de la pantalla
    glutCreateWindow("Cubo Rubik");                             //Nombre de la ventana
    glEnable(GL_DEPTH_TEST);                                    //Permite 3d y rotacion
    glEnable(GL_TEXTURE_2D);                                    //Activa las texturas
    
    glutDisplayFunc(display);                                   //Se le pasa la funcion para dibujar la pantalla
    glutKeyboardFunc(inputManager);                                    //Se le pasa la funcion que se usara para la entrada del teclado
    glutIdleFunc(update);                                       //establece las funciones que se van a estar actualizando
    glutMainLoop();

    return 0;
}
void update() {    
    m_rubik.rotationManager();
    glutPostRedisplay();
}

void display(void) {
    glClearColor(0, 0, 0, 0);                               ///Color de fondo
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     //Borrando pantalla
    //glMatrixMode(GL_PROJECTION);                          //Modo de proyeccion
    glLoadIdentity();                                       //Cargando matriz de identidad
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);             //Proyeccion ortografica dentro del cubo señalado
    gluPerspective(60, 1, 1, 100);                          //Proyeccion perspectiva dentro del cubo señalado
    glTranslatef(0, 0, -2);                                 //Alejando el cuadrado del observador dos unidades en el eje z
    glMatrixMode(GL_MODELVIEW);                             //Modo de modelado
    generateCube();

    /*glFlush();*/                                          //forzando el dibujado
    glutSwapBuffers();                                      //cambiando de buffer para que se vea mas fluida(se necesita doble buffer)
}

void generateCube() {
    Vector3 color;
    Vector3 vertex;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 6; l++) {
                    color = m_rubik.m_cubeMatriz[i][j][k].m_faces[l].m_color;
                    
                    glBindTexture(GL_TEXTURE_2D ,TextureManager::getInstance()->getTextureByIndex(l));
                    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
                    glColor3f(color.x, color.y, color.z);             //color del cuadrado 
                    for (int m = 0; m < 4; m++) {
                        vertex = m_rubik.m_cubeMatriz[i][j][k].m_faces[l].m_vertex[m];
                        glVertex3f(vertex.x, vertex.y, vertex.z);   //Coordenadas de los vertices
                    }
                    glEnd();
                }  
            }
        }
    }
}

void inputManager(unsigned char key, int x, int y) {    
    if (m_rubik.m_isRotating) {
        return;
    }

    switch (key) {
        case '1':
            m_rubik.setAndStartRotationFace(Front);
            break;
        case '2':            
            m_rubik.setAndStartRotationFace(Back);
            break;
        case '3':            
            m_rubik.setAndStartRotationFace(Right);
            break;
        case '4':            
            m_rubik.setAndStartRotationFace(Left);
            break;
        case '5':            
            m_rubik.setAndStartRotationFace(Top);
            break;
        case '6':            
            m_rubik.setAndStartRotationFace(Bothom);
            break;
        case 'd': 
            m_rubik.changeRotationDirection();
            break;
        default:
            break;
    } 
}