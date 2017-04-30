#ifndef FONCTION
#define FONCTION

#include <QtWidgets>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace cv;
using namespace std;


class Fenetre : public QWidget
{
    Q_OBJECT


public:
    Fenetre();
    static void mouseEvent(int evt, int x, int y, int flags, void* param);
    static void fonctionNicolas();
    static void fonctionNicolasArmand();
    static void fonctionCarron();

public slots:
    void ouvrirDialogueChoisir();
    void fonctionPrincipale();
    void selectionPixel();
    void selectionMarqueur();
//    void seuillage(bool cocher);
    void seuillage(int seuil);

private:
    QPushButton *choixFichier;
    QPushButton *go;

    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
    QPushButton *bouton5;
    QPushButton *bouton6;
    QLCDNumber  *lcd;
    QLCDNumber  *lcd1;
    QLCDNumber  *lcd2;
    QLCDNumber  *lcd3;
    QLCDNumber  *lcd4;
    QLCDNumber  *lcd5;
    QLCDNumber  *lcd6;
    QSlider     *slider;
    QLabel      *texte;
    QLabel      *texte1;
    QLabel      *texte2;
    QLabel      *texte3;
    QLabel      *texte4;
    QLabel      *texte5;
    QLabel      *texte6;
    QCheckBox   *cocheseuil;
    QTabWidget  *onglets;
    QLabel      *page1;
    QLabel      *page2;
    QLabel      *page3;
    QLabel      *page4;
    QLabel      *page5;

    QString nomFichier;
    QString marqueur;


};

#endif // FONCTION
