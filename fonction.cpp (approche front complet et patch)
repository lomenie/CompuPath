#include "fonction.h"
#include <QTextStream>
double Teinte = 0;double Luminance = 0;double Saturation = 0;double Rouge = 0;double Vert = 0;double Bleu = 0;
Mat image,imageC1,imageC2,imageC3,imageInt, imageExt,imageZone;
string fichierstd;
bool traitement = false;
int nbCourbe = 0;
double DiametreCellule = 15.;
double diametrePixel = 0.2325;
vector<vector<int> > TabCourbeMoy;
vector<vector<int> > contour;
//int contourMinx,contourMiny,contourMaxx,contourMaxy;
int distanceExtFront=10;//distance pixels minimum entre le front et le bord de l'image
int bandelette = 5;//taille bandelettes de 5 micro
int nb=0;

Fenetre::Fenetre() : QWidget()

{
    setFixedSize(1000, 700);

    /////////////////////////////////////////////////////////////////////////
    //bouton1
    bouton1 = new QPushButton("Vue",this);
    bouton1->setGeometry(735, 650, 70, 30);
    bouton1->setToolTip("Texte d'aide");
    bouton1->setFont(QFont("Comic Sans MS", 10, QFont::Bold, true));
    bouton1->setCursor(Qt::PointingHandCursor);
    //bouton2
    bouton2 = new QPushButton("Valider", this);
    bouton2->setGeometry(820,650, 70, 30);
    bouton2->setToolTip("Texte d'aide");
    bouton2->setFont(QFont("Comic Sans MS", 10, QFont::Bold, true));
    bouton2->setCursor(Qt::PointingHandCursor);
    //bouton3
    bouton3 = new QPushButton("Quitter", this);
    bouton3->setGeometry(905, 650, 70, 30);
    bouton3->setToolTip("Texte d'aide");
    bouton3->setFont(QFont("Comic Sans MS", 10, QFont::Bold, true));
    bouton3->setCursor(Qt::PointingHandCursor);
    //bouton4
    bouton4 = new QPushButton("Image", this);
    bouton4->setGeometry(670, 225, 70, 30);
    bouton4->setToolTip("Texte d'aide");
    bouton4->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton4->setCursor(Qt::PointingHandCursor);
    //bouton5
    bouton5 = new QPushButton("Sélection Pixel", this);
    bouton5->setGeometry(750, 225, 110, 30);
    bouton5->setToolTip("Texte d'aide");
    bouton5->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton5->setCursor(Qt::PointingHandCursor);
    //bouton6
    bouton6 = new QPushButton("Sélection Marqueur", this);
    bouton6->setGeometry(870, 225, 125, 30);
    bouton6->setToolTip("Texte d'aide");
    bouton6->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton6->setCursor(Qt::PointingHandCursor);
    //bouton7
    bouton7 = new QPushButton("Cytomine Patchs", this);
    bouton7->setGeometry(100, 660, 120, 30);
    bouton7->setToolTip("Texte d'aide");
    bouton7->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton7->setCursor(Qt::PointingHandCursor);
    //bouton8
    bouton8 = new QPushButton("Cytomine Front", this);
    bouton8->setGeometry(250, 660, 120, 30);
    bouton8->setToolTip("Texte d'aide");
    bouton8->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton8->setCursor(Qt::PointingHandCursor);
    //bouton9
    bouton9 = new QPushButton("Analyse Image", this);
    bouton9->setGeometry(400, 660, 120, 30);
    bouton9->setToolTip("Texte d'aide");
    bouton9->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton9->setCursor(Qt::PointingHandCursor);
    //bouton10
    bouton10 = new QPushButton("AnnotationFront", this);
    bouton10->setGeometry(670, 260, 110, 30);
    bouton10->setToolTip("Texte d'aide");
    bouton10->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton10->setCursor(Qt::PointingHandCursor);

    lcd = new QLCDNumber(this);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->move(765, 190);
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(0, 255);
    slider->setGeometry(720, 170, 150, 20);
    texte = new QLabel("Seuil",this);
    texte->setFont(QFont("Comic Sans MS", 13, QFont::Bold, true));
    texte->move(780, 150);
    cocheseuil = new QCheckBox(this);
    cocheseuil->move(760, 150);

    //Rouge
    texte1 = new QLabel("Rouge",this);
    texte1->setFont(QFont("Comic Sans MS", 12, QFont::Bold, true));
    texte1->move(680, 30);
    lcd1 = new QLCDNumber(this);
    lcd1->setSegmentStyle(QLCDNumber::Flat);
    lcd1->move(675, 50);

    //Vert
    texte2 = new QLabel("Vert",this);
    texte2->setFont(QFont("Comic Sans MS", 12, QFont::Bold, true));
    texte2->move(780, 30);
    lcd2 = new QLCDNumber(this);
    lcd2->setSegmentStyle(QLCDNumber::Flat);
    lcd2->move(770, 50);

    //Bleu
    texte3 = new QLabel("Bleu",this);
    texte3->setFont(QFont("Comic Sans MS", 12, QFont::Bold, true));
    texte3->move(870, 30);
    lcd3 = new QLCDNumber(this);
    lcd3->setSegmentStyle(QLCDNumber::Flat);
    lcd3->move(860, 50);

    //Teinte
    texte4 = new QLabel("Teinte",this);
    texte4->setFont(QFont("Comic Sans MS", 12, QFont::Bold, true));
    texte4->move(680, 90);
    lcd4 = new QLCDNumber(this);
    lcd4->setSegmentStyle(QLCDNumber::Flat);
    lcd4->move(675, 110);

    //Saturation
    texte5 = new QLabel("Saturation",this);
    texte5->setFont(QFont("Comic Sans MS", 12, QFont::Bold, true));
    texte5->move(755, 90);
    lcd5 = new QLCDNumber(this);
    lcd5->setSegmentStyle(QLCDNumber::Flat);
    lcd5->move(770, 110);

    //Luminance
    texte6 = new QLabel("Luninance",this);
    texte6->setFont(QFont("Comic Sans MS", 12, QFont::Bold, true));
    texte6->move(860, 90);

    lcd6 = new QLCDNumber(this);
    lcd6->setSegmentStyle(QLCDNumber::Flat);
    lcd6->move(860, 110);

    onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 630, 630);
    page1 = new QLabel;//onglet 1
    page2 = new QLabel;//onglet 2
    page3 = new QLabel;//onglet 3
    page4 = new QLabel;//onglet 4
    page6 = new QLabel;//onglet 5
      //  page4->setPixmap(QPixmap("icone.png"));
      //  page4->setAlignment(Qt::AlignCenter);
    page5 = new QLabel(this);//pour afficher l'image HSV
          page5 ->setGeometry(675,300,10,10);
          page5->setPixmap(QPixmap("/home/djiro/annotations/color3d.jpg"));
          page5->setScaledContents(true);
          page5->adjustSize();
    onglets->addTab(page1, "Image Originale");
    onglets->addTab(page2, "Transformation Couleur");
    onglets->addTab(page3, "Objets Biologiques");
    onglets->addTab(page4, "Image Bandelettes");
    onglets->addTab(page6, "Courbe");
    /////////////////////////////////////////////////////////////////////////

    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(bouton4, SIGNAL(clicked()), this, SLOT(ouvrirDialogueChoisir()));
    QObject::connect(bouton5, SIGNAL(clicked()), this, SLOT(selectionPixel()));
    QObject::connect(bouton10, SIGNAL(clicked()), this, SLOT(Annotation()));
    QObject::connect(bouton6, SIGNAL(clicked()), this, SLOT(selectionMarqueur()));
    QObject::connect(bouton7, SIGNAL(clicked()), this, SLOT(imageCytomineA1()));
    QObject::connect(bouton8, SIGNAL(clicked()), this, SLOT(imageCytomineA2()));
    QObject::connect(bouton9, SIGNAL(clicked()), this, SLOT(imageCytomineA3()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), lcd,SLOT(display(int)));
    QObject::connect(bouton2, SIGNAL(clicked()), this,SLOT(courbes()));
    QObject::connect(bouton1, SIGNAL(clicked()), this,SLOT(seuillage()));
  //  QObject::connect(slider, SIGNAL(valueChanged(int)), this,SLOT(seuillage(int))) ;
//    QObject::connect(cocheseuil, SIGNAL(toggled(bool)), this,SLOT(seuillage(bool))) ;
}
//////////////////////////////////////////
//////////////////////////////////////////

void Fenetre::imageCytomineA1()
{
    string ligne,mot;
    double coord;//recupère les coordonnées annotation
    int taille,i,j,term; int premier = 0;
    bool ok;
    double demipatch;// = 3040/2; //longueur patch 1mm = 3040 pixels
    int TermFront = 4903197;//2 recherche par Term
    int TermZone = 3478753;
   // vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image
   // vector<vector<double> > TabZone;// tableau des coordonnées de la Zone à analyser

  int idImage = QInputDialog::getInt(this,tr("Integer"),tr("Entrer Id Image :"),3452832,0,100000000,1,&ok );
  string idimage = "python /home/djiro/spyder/djiro/client/examples/get_Front_Cord.py "+to_string(idImage);
  system(idimage.c_str()); int MinX,MaxX,MinY,MaxY;

  ifstream fichier("/home/djiro/annotations/fichier.txt");//où le fichier texte est enregistré

       if(fichier)
       {
            while(getline(fichier, ligne))
            { //traiter le texte; supprimer ,()[]
                ofstream fichier1("/home/djiro/annotations/fichier1.txt");
                for ( i = 0; i<ligne.size();i++)
                {
                    if(ligne[i] ==','||ligne[i]=='('||ligne[i]==')'||ligne[i]=='['||ligne[i]==']')
                        ligne[i]=' ';
                }
                //cout << ligne << endl;
                fichier1 <<ligne;
                fichier1.close();

                //retrouver les coordonnées du polygone image selectionné dans le texte
                ifstream fichier2("/home/djiro/annotations/fichier1.txt");
                fichier2 >> mot;//1,2
                fichier2 >> term;//2

               // if (fichierstd=="/home/djiro/annotations/3478753/"+mot+".png")//1 Recherche par Nom
                  if (TermFront == term)//2 Recherche par Term
                {
                    //fichier2 >> mot;//1
                    fichier2 >> mot;//recupère le mot polygon
                    //remplir tableau des coordonnées image
                    taille=0;

                    vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image
                    while(fichier2 >> coord)
                      {

                        TabImage.push_back(vector<double>(2));
                        TabImage[taille][0]=coord;

                        fichier2 >> coord;
                        TabImage[taille][1]=coord;

                        taille+=1;
                      }
                    fichier2.close();

                    /////////////////////////
                    idimage = "python /home/djiro/spyder/djiro/client/examples/get_Zone_Cord.py "+to_string(idImage);
                    system(idimage.c_str());
                    ifstream fich("/home/djiro/annotations/fich.txt");
                    while(getline(fich, ligne))
                    {
                        ofstream fich1("/home/djiro/annotations/fichier1.txt");
                        for ( i = 0; i<ligne.size();i++)
                        {
                            if(ligne[i] ==','||ligne[i]=='('||ligne[i]==')'||ligne[i]=='['||ligne[i]==']')
                                ligne[i]=' ';
                        }
                        //cout << ligne << endl;
                        fich1 <<ligne;
                        fich1.close();
                        //retrouver les coordonnées du polygone image selectionné dans le texte
                        ifstream fich2("/home/djiro/annotations/fichier1.txt");
                        fich2 >> mot;//1,2
                        fich2 >> term;//2
                        if (term == TermZone)//2 Recherche par Term
                        {
                            //fichier2 >> mot;//1
                            fich2 >> mot;//recupère le mot polygon
                            //remplir tableau des coordonnées image
                            taille=0;

                            vector<vector<double> > TabZone;// tableau des coordonnées de la Zone à analyser
                            while(fich2 >> coord)
                              {

                                TabZone.push_back(vector<double>(2));
                                TabZone[taille][0]=coord;

                                fich2 >> coord;
                                TabZone[taille][1]=coord;

                                taille+=1;
                              }
                            fich2.close();

                            //rechercher les 4 points min et max de la Zone d'interet pour determiner sa boite englobante
                            MinX = TabZone[TabZone.size()-1][0];
                            MaxX = TabZone[TabZone.size()-1][0];
                            MinY = TabZone[TabZone.size()-1][1];
                            MaxY = TabZone[TabZone.size()-1][1];

                            for (i=0;i<TabZone.size(); i++)
                            {
                                if (TabZone[i][0]<MinX)
                                {
                                    MinX = TabZone[i][0];
                                }
                                if (TabZone[i][0]>MaxX)
                                {
                                    MaxX = TabZone[i][0];
                                }
                                if (TabZone[i][1]<MinY)
                                {
                                    MinY = TabZone[i][1];
                                }
                                if (TabZone[i][1]>MaxY)
                                {
                                    MaxY = TabZone[i][1];
                                }
                            }

                            int nbcolonne = MaxX - MinX;
                            int nbligne = MaxY - MinY;

                            // Creer le boite englobante de l'annotation front tumorale
                            cout << "création image boite englobante " <<endl;
                            Mat imageboiteRGB(nbligne, nbcolonne, CV_8UC3);

                            int X1,Y1,X2,Y2,X3,Y3,X4,Y4;
                            Mat images;

                            for (i=0;i<nbligne; i+=3040)
                            {
                                for (j=0;j<nbcolonne; j+=3040)
                                {
                                    /*
                                    idimage = "python /home/djiro/spyder/djiro/client/examples/delete_annotations.py "+to_string(idImage);
                                    system(idimage.c_str());*/


                                    X1 = j+MinX;X4 = X1; X2 = X1+3040;
                                    if (X2>MaxX)
                                    {
                                        X2 = MaxX;
                                    }
                                    X3 = X2;

                                    Y1 = MaxY-i; Y2=Y1; Y4=Y1-3040;
                                    if (Y4<MinY)
                                    {
                                        Y4 = MinY;
                                    }
                                    Y3 = Y4;
                                    string commande = "python /home/djiro/spyder/djiro/client/examples/create_annotation.py "+to_string(idImage)+" "+to_string(X1)+" "+to_string(Y1)+" "+to_string(X2)+" "+to_string(Y2)+" "+to_string(X3)+" "+to_string(Y3)+" "+to_string(X4)+" "+to_string(Y4);
                                    system(commande.c_str());

                                    idimage = "python /home/djiro/spyder/djiro/client/examples/get_annotations.py "+to_string(idImage);
                                    system(idimage.c_str());

                                    //lire l'image

                                    ifstream fichiers("/home/djiro/annotations/fichier.txt");
                                    fichiers >> mot;
                                    fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";//1 Recherche par Nom
                                    images = imread(fichierstd);

                                    for (int n=0;n<images.rows; n++)
                                    {
                                        for (int m=0;m<images.cols;m++)
                                        {
                                            ////////////////////////////////////
                                            Vec3b rgb=images.at<Vec3b>(n,m);
                                            imageboiteRGB.at<Vec3b>(n+i,m+j)=rgb;
                                            ////////////////////////////////////////
                                        }
                                    }


                                }

                            }

                            idimage = "rm -r /home/djiro/annotations/3478753";
                            system(idimage.c_str());
                            images.release();

                            imwrite("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp",imageboiteRGB);
                            imageboiteRGB.release();

                        //nouveaux coordonnées sur petite image des points du polygone

                             for (i=0;i<TabImage.size(); i++)
                             {
                                 TabImage[i][0] = TabImage[i][0]-MinX;
                                 TabImage[i][1] = MaxY-TabImage[i][1];
                             }
                       //nouveaux coordonnées sur petite image des points de la Zone d'interet

                             for (i=0;i<TabZone.size(); i++)
                             {
                                 TabZone[i][0] = TabZone[i][0]-MinX;
                                 TabZone[i][1] = MaxY-TabZone[i][1];
                             }

                             /////////////////////////////////////
                             /////////////////////////////////////

                             fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
                             nomFichier = QString::fromStdString(fichierstd);

                             image = imread(fichierstd);

                                 page1->setPixmap(QPixmap(fichierstd.c_str()));
                                // page1->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig.bmp"));
                                 page1->setScaledContents(true);
                                 page1->adjustSize();

                                 page2->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page2->setScaledContents(true);
                                 page2->adjustSize();

                                 page3->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page3->setScaledContents(true);
                                 page3->adjustSize();

                                 page4->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page4->setScaledContents(true);
                                 page4->adjustSize();

                                 page6->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page6->setScaledContents(true);
                                 page6->adjustSize();


                                 if (premier == 0)
                                 {
                                     QStringList items;
                                     items << "Rouge" << "Jaune" << "Vert" << "Cyan"<< "Bleu"<< "Magenta";
                                     marqueur = QInputDialog::getItem(this, "Seletion de Marqueur","Marqueurs:", items, 0, false, &ok);

                                     premier = 1;
                                 }

                                 cout << " ---> Traitement image déconvolution " <<endl;

                              //   selectionMarqueur();
                                 Traitement();

                                 ///////////////////////////////
                                 //////////////////////////////

                                 cout << " ---> Traitement: Transformée de distance " <<endl;
                                 //Distances
                                 if (traitement == true)
                                 {
                                     //calcule des distances
                                 //    fichierstd= "/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig1.bmp";
                                 //    nomFichier = QString::fromStdString(fichierstd);
                                         image = imread(fichierstd);
                                         CvScalar pixel; pixel.val[0]=0;pixel.val[1]=255;pixel.val[2]=0;

                                     //tranformé de distance
                                     seuillage();
                                     nbCourbe += 1;
                                     vector<vector<int> > TabCourbe1;TabCourbe1.push_back(vector<int>(4));TabCourbe1[0][0]=0;TabCourbe1[0][1]=0;TabCourbe1[0][2]=0;TabCourbe1[0][3]=0;
                                     int nbPixelMax = 0;
                                     //recuperer le nombre de pixels du marqueur par bandelette de 5um(15pixels)car 1mm = 3040pixels
                             //        int TabTaille = floor(demipatch*2/15.197)+1;
                                     int Xcourbe = -floor(demipatch/15.197)*5;//première valeur x de la courbe
                                    // int TabCourbe [TabTaille][3];
                                     //initialisation
/*
                                     for (int i=0; i<TabTaille; i++)
                                     {
                                         TabCourbe[i][0]=Xcourbe;
                                         TabCourbe[i][1]=0;
                                         TabCourbe[i][2]=0;
                                         Xcourbe += 5;
                                     }*/

                                     for (int i=0; i<imageInt.rows; i++)
                                     {
                                          for (int j=0; j<imageInt.cols; j++)
                                          {
                                          int intersect = 0;
                                          for (int k=0; k<TabImage.size()-1;k++)
                                          {
                                              double ordonn;
                                              double coefdir;
                                              if ((TabImage[k][0]-TabImage[k+1][0]) == 0)
                                              {
                                                  if(i< max(TabImage[k][1],TabImage[k+1][1]) && i>=min(TabImage[k][1],TabImage[k+1][1]) && j<=TabImage[k][0])
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                             else if(i< max(TabImage[k][1],TabImage[k+1][1]) && i>=min(TabImage[k][1],TabImage[k+1][1]))
                                              {
                                                  coefdir = (TabImage[k][1]-TabImage[k+1][1])/(TabImage[k][0]-TabImage[k+1][0]);
                                                  ordonn = TabImage[k][1]-(coefdir*TabImage[k][0]);
                                                  double x = (i-ordonn)/coefdir;

                                                  if (x>=j)
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                          }

                                          if ((intersect % 2) == 1)
                                          {
                                              imageInt.at<uchar>(i,j)=255;
                                              imageExt.at<uchar>(i,j)= 0;
                                          }

                                          if ((intersect % 2) == 0)
                                        //  else
                                          {
                                              imageInt.at<uchar>(i,j)=0;
                                              imageExt.at<uchar>(i,j)=255;
                                          }

                                          intersect = 0;
                                          for (int k=0; k<TabZone.size()-1;k++)
                                          {
                                              double ordonn;
                                              double coefdir;
                                              if ((TabZone[k][0]-TabZone[k+1][0]) == 0)
                                              {
                                                  if(i< max(TabZone[k][1],TabZone[k+1][1]) && i>=min(TabZone[k][1],TabZone[k+1][1]) && j<=TabZone[k][0])
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                             else if(i< max(TabZone[k][1],TabZone[k+1][1]) && i>=min(TabZone[k][1],TabZone[k+1][1]))
                                              {
                                                  coefdir = (TabZone[k][1]-TabZone[k+1][1])/(TabZone[k][0]-TabZone[k+1][0]);
                                                  ordonn = TabZone[k][1]-(coefdir*TabZone[k][0]);
                                                  double x = (i-ordonn)/coefdir;

                                                  if (x>=j)
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                          }

                                          if ((intersect % 2) == 1)
                                          {
                                              imageZone.at<uchar>(i,j)=255;
                                          }
                                          if ((intersect % 2) == 0)
                                          {
                                              imageZone.at<uchar>(i,j)=0;
                                          }


                                      }
                                    }

                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Interieur.bmp", imageInt );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Exterieur.bmp", imageExt );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Zone.bmp", imageZone );
                               //   imwrite( "imageBandelette.bmp", image );


                                  distanceTransform(imageInt, imageInt, CV_DIST_L2, 3);
                                //  normalize(imageInt, imageInt, 0, 255, NORM_MINMAX);
                               //   imshow("Distance Transform ImageInt", imageInt);
                               //   imwrite( "Interieur.bmp", imageInt );

                                  distanceTransform(imageExt, imageExt, CV_DIST_L2, 3);
                               //   normalize(imageExt, imageExt, 0, 255, NORM_MINMAX);
                               //   imshow("Distance Transform ImageExt", imageExt);
                               //   imwrite( "Exterieur.bmp", imageExt );

                                  cout << " ---> Création Image bandelette et Création courbe " <<endl;

                                  for ( i=0; i<image.rows; i++)
                                  {
                                       for ( j=0; j<image.cols; j++)
                                       {
                                           if (imageZone.at<uchar>(i,j)==255)
                                           {
                                               ///////////////////////
                                               //////////////////////
                                               //lignes de niveau

                                               if (imageInt.at<float>(i,j)!=0.)
                                               {
                                                   int valeur = ceil(imageInt.at<float>(i,j));
                                                   if ((valeur%(3*bandelette))<=2)
                                                   {
                                                        Vec3b rgb; rgb.val[0]=0; rgb.val[1]=0;rgb.val[2]=255;
                                                        image.at<Vec3b>(i,j)=rgb;
                                                   }
                                               }

                                               if (imageExt.at<float>(i,j)!=0.)
                                               {
                                                   int valeur = ceil(imageExt.at<float>(i,j));
                                                   if ((valeur%(3*bandelette))<=2)
                                                   {
                                                        Vec3b rgb; rgb.val[0]=0; rgb.val[1]=255;rgb.val[2]=0;
                                                        image.at<Vec3b>(i,j)=rgb;
                                                   }
                                               }

                                               if (imageInt.at<float>(i,j) <= 2.&& imageExt.at<float>(i,j) <= 2.)
                                               {

                                                   Vec3b rgb; rgb.val[0]=255; rgb.val[1]=0;rgb.val[2]=0;
                                                   image.at<Vec3b>(i,j)=rgb;
                                               }

                                               ///////////////////////
                                               //////////////////////

                                               if(imageC3.at<uchar>(i,j)==0)
                                               {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][1] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                                       }

                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][1] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                                       }

                                                   }
                                               }
                                               //////////////
                                               else
                                               {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][2] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                       }


                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][2] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if(trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                       }

                                                   }
                                               }

                                               //////////////////////
                                               //////////////////////

                                           }
                                       }
                                  }

                             //     cvSaveImage("imageBandelette.bmp",imag);
                             //     imwrite( "imageBandelette.bmp", image );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp", image );
                              //    imageInt.release();imageExt.release();imageZone.release();imageC3.release();
                                  image.release();

                                  //ranger les Zones pixels par distances et supprimer celles n'ayant pas une surface représentative
                                  for (int i=0; i<TabCourbe1.size(); i++)
                                  {
                                      if (nbPixelMax<(TabCourbe1[i][1]+TabCourbe1[i][2]))
                                      {
                                          nbPixelMax = (TabCourbe1[i][1]+TabCourbe1[i][2]);
                                      }
                                  }

                                  int tampon0,tampon1,tampon2;
                                  for (i=0; i<TabCourbe1.size(); i++)
                                  {
                                      for ( j=i; j<TabCourbe1.size(); j++)
                                      {
                                          if (TabCourbe1[j][0]<TabCourbe1[i][0])
                                          {
                                              tampon0 = TabCourbe1[j][0]; tampon1 = TabCourbe1[j][1]; tampon2 = TabCourbe1[j][2];
                                              TabCourbe1[j][0] = TabCourbe1[i][0]; TabCourbe1[j][1] = TabCourbe1[i][1];TabCourbe1[j][2] = TabCourbe1[i][2];
                                              TabCourbe1[i][0] = tampon0; TabCourbe1[i][1] = tampon1; TabCourbe1[i][2] = tampon2;
                                          }

                                      }
                                     // cout<< TabCourbe1[i][0] <<endl;
                                  }

                                  ////////////////////////////////////////////////////////////////////////////////////////////////////
                                  ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
                                  ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
                                  ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

                                  //Nombre de pixels objets
                                 /*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1] << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1] << endl;
                                      }
                                  }*/
                                  /////////////////////////
                                  //Nombre de Lymphocytes
                                  /*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]/315 << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]/315 << endl;
                                      }
                                  }*/


                                  //Nombre de Lymphocytes par 5000 micromètre carré
                                  int x = 1;
                                 // int densiteMax = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
                                 // int densiteMin = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
                                  int densiteMax = 0;
                                  int densiteMin = 0;

                                  for ( i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/5)))
                                      {
                                          fichier1 << x; fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                                          TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                                          TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                                          TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                                          TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];


                                          if (densiteMax<TabCourbe1[i][3])
                                          {
                                              densiteMax = TabCourbe1[i][3];
                                          }
                                          if (densiteMin>TabCourbe1[i][3])
                                          {
                                              densiteMin = TabCourbe1[i][3];
                                          }
                                          x += 1;
                                      }
                                         //pour TabCourbe1[i][0] == 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                        //  TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                        //  TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                                          TabCourbe1[i][1] = TabCourbe1[i+1][1];
                                          TabCourbe1[i][2] = TabCourbe1[i+1][2];

                                          fichier1 << x;fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << (TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << (TabCourbe1[i][1]/315.0)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                                          TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                                          TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                                          TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                                          TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];

                                          if (densiteMax<TabCourbe1[i][3])
                                          {
                                              densiteMax = TabCourbe1[i][3];
                                          }
                                          if (densiteMin>TabCourbe1[i][3])
                                          {
                                              densiteMin = TabCourbe1[i][3];
                                          }
                                          x += 1;
                                      }

                                  }

                                  cout << " ---> Création Image Carte de chaleur " <<endl;
                                  //////////////////////////////////////////
                                  /////////////////////////////////////////
                                  for ( i=0; i<imageC3.rows; i++)
                                  {
                                       for ( j=0; j<imageC3.cols; j++)
                                       {
                                           if (imageZone.at<uchar>(i,j)==255)
                                           {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                                                           }

                                                       }
                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                                                           }

                                                       }
                                                   }
                                           }
                                           else
                                           {
                                               imageC3.at<uchar>(i,j)=0;
                                           }
                                       }
                                  }

                                  applyColorMap(imageC3, imageC3, COLORMAP_JET);
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleur.bmp", imageC3);

                                  imageInt.release();imageExt.release();imageZone.release();

                               //   fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
                               //   nomFichier = QString::fromStdString(fichierstd);
                                  Mat image;
                                  image = imread(fichierstd);

                                  addWeighted(image,0.3,imageC3,0.7,0.,imageC3);
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleurImage.bmp", imageC3);

                                  imageC3.release();image.release();

                                  ////////////////////////////////////////
                                  ////////////////////////////////////////




                                  //Nombre de pixels par Zone
/*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                      }
                                  }*/




                                  /////////////////////////

                                  fichier1.close();fichier2.close();fichier3.close();
                                  system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
                                  page4->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp"));
                                  page4->setScaledContents(true);
                                  page4->adjustSize();

                                  page6->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
                                  page6->setScaledContents(true);
                                  page6->adjustSize();

                                  /////////////////////////////////////////////////////////////////////////////////////////////////////

                          }

                                 for (i=0;i<TabImage.size(); i++)
                                 {
                                     TabImage[i][0] = TabImage[i][0]+MinX;
                                     TabImage[i][1] = MaxY-TabImage[i][1];

                                 }



                            }

                        }

                fich.close();
            }


   }
         fichier.close();
         /////////////////////////////////////////////////
         //courbe moyenne
         if (nbCourbe>1)
         {
         vector<vector<int> > TabCourbe;
         for (int i=0; i<TabCourbeMoy.size()-1;i++)
         {
             int nbSomme = 0;
             for (int j=i+1; j<TabCourbeMoy.size();j++)
             {
                 if (TabCourbeMoy[i][0]==TabCourbeMoy[j][0])
                 {
                     TabCourbeMoy[i][1] += TabCourbeMoy[j][1];
                     nbSomme += 1;
                 }
             }
             if (nbSomme == (nbCourbe-1))
             {
                 TabCourbe.push_back(vector<int>(2));
                 TabCourbe[TabCourbe.size()-1][0]=TabCourbeMoy[i][0];
                 TabCourbe[TabCourbe.size()-1][1]=TabCourbeMoy[i][1]/nbSomme;
             }

         }

         for (int i=0; i<TabCourbe.size()-1; i++)//pour ordonner le tableau
         {
             for (int j=i+1; j<TabCourbe.size();j++)
             {
                 if (TabCourbe[i][0] > TabCourbe[j][0])
                 {
                     int tampX, tampY;
                     tampX = TabCourbe[i][0];
                     tampY = TabCourbe[i][1];
                     TabCourbe[i][0] = TabCourbe[j][0];
                     TabCourbe[i][1] = TabCourbe[j][1];
                     TabCourbe[j][0] = tampX;
                     TabCourbe[j][1] = tampY;
                 }
             }
         }

         ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
         ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
         ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

         for (int i=0;i<TabCourbe.size();i++)
         {
           //  fichier1 << TabCourbe[i][0]; fichier1 << " "; fichier1 << (TabCourbe[i][1]/315) << endl;
             fichier2 << TabCourbe[i][0] << endl;
             fichier3 << TabCourbe[i][1] << endl;
         }
         fichier1.close();fichier2.close();fichier3.close();
         system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
         page4->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
         page4->setScaledContents(true);
         page4->adjustSize();

         }
       }

       else
       {
       cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
       }
}

///////////////////////////////////////////////////////////////////////////////////////////

void Fenetre::imageCytomineA2()
{
    string ligne,mot;
    double coord;//recupère les coordonnées annotation
    int taille,i,j,term; int premier = 0;
    bool ok;
    double demipatch;// = 3040/2; //longueur patch 1mm = 3040 pixels
    int TermFront = 4903197;//2 recherche par Term
  //  int TermZone = 3478753;
   // vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image
   // vector<vector<double> > TabZone;// tableau des coordonnées de la Zone à analyser

  int idImage = QInputDialog::getInt(this,tr("Integer"),tr("Entrer Id Image :"),3452832,0,100000000,1,&ok );
  string idimage = "python /home/djiro/spyder/djiro/client/examples/get_Front_Cord.py "+to_string(idImage);
  system(idimage.c_str()); int MinX,MaxX,MinY,MaxY;

  ifstream fichier("/home/djiro/annotations/fichier.txt");//où le fichier texte est enregistré

       if(fichier)
       {
            while(getline(fichier, ligne))
            { //traiter le texte; supprimer ,()[]
                ofstream fichier1("/home/djiro/annotations/fichier1.txt");
                for ( i = 0; i<ligne.size();i++)
                {
                    if(ligne[i] ==','||ligne[i]=='('||ligne[i]==')'||ligne[i]=='['||ligne[i]==']')
                        ligne[i]=' ';
                }
                //cout << ligne << endl;
                fichier1 <<ligne;
                fichier1.close();

                //retrouver les coordonnées du polygone image selectionné dans le texte
                ifstream fichier2("/home/djiro/annotations/fichier1.txt");
                fichier2 >> mot;//1,2
                fichier2 >> term;//2

               // if (fichierstd=="/home/djiro/annotations/3478753/"+mot+".png")//1 Recherche par Nom
                  if (TermFront == term)//2 Recherche par Term
                {
                    //fichier2 >> mot;//1
                    fichier2 >> mot;//recupère le mot polygon
                    //remplir tableau des coordonnées image
                    taille=0;

                    vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image
                    while(fichier2 >> coord)
                      {

                        TabImage.push_back(vector<double>(2));
                        TabImage[taille][0]=coord;

                        fichier2 >> coord;
                        TabImage[taille][1]=coord;

                        taille+=1;
                      }
                    fichier2.close();

                    /////////////////////////

                            //rechercher les 4 points min et max de la Zone d'interet pour determiner sa boite englobante
                            MinX = TabImage[TabImage.size()-1][0];
                            MaxX = TabImage[TabImage.size()-1][0];
                            MinY = TabImage[TabImage.size()-1][1];
                            MaxY = TabImage[TabImage.size()-1][1];

                            for (i=0;i<TabImage.size(); i++)
                            {
                                if (TabImage[i][0]<MinX)
                                {
                                    MinX = TabImage[i][0];
                                }
                                if (TabImage[i][0]>MaxX)
                                {
                                    MaxX = TabImage[i][0];
                                }
                                if (TabImage[i][1]<MinY)
                                {
                                    MinY = TabImage[i][1];
                                }
                                if (TabImage[i][1]>MaxY)
                                {
                                    MaxY = TabImage[i][1];
                                }
                            }
                            MinX=MinX-distanceExtFront;
                            MinY=MinY-distanceExtFront;
                            MaxX=MaxX+distanceExtFront;
                            MaxY=MaxY+distanceExtFront;

                            int nbcolonne = MaxX - MinX;
                            int nbligne = MaxY - MinY;

                            // Creer le boite englobante de l'annotation front tumorale
                            cout << "création image boite englobante " <<endl;
                            Mat imageboiteRGB(nbligne, nbcolonne, CV_8UC3);

                            int X1,Y1,X2,Y2,X3,Y3,X4,Y4;
                            Mat images;

                            for (i=0;i<nbligne; i+=3040)
                            {
                                for (j=0;j<nbcolonne; j+=3040)
                                {
                                    /*
                                    idimage = "python /home/djiro/spyder/djiro/client/examples/delete_annotations.py "+to_string(idImage);
                                    system(idimage.c_str());*/


                                    X1 = j+MinX;X4 = X1; X2 = X1+3040;
                                    if (X2>MaxX)
                                    {
                                        X2 = MaxX;
                                    }
                                    X3 = X2;

                                    Y1 = MaxY-i; Y2=Y1; Y4=Y1-3040;
                                    if (Y4<MinY)
                                    {
                                        Y4 = MinY;
                                    }
                                    Y3 = Y4;
                                    string commande = "python /home/djiro/spyder/djiro/client/examples/create_annotation.py "+to_string(idImage)+" "+to_string(X1)+" "+to_string(Y1)+" "+to_string(X2)+" "+to_string(Y2)+" "+to_string(X3)+" "+to_string(Y3)+" "+to_string(X4)+" "+to_string(Y4);
                                    system(commande.c_str());

                                    idimage = "python /home/djiro/spyder/djiro/client/examples/get_annotations.py "+to_string(idImage);
                                    system(idimage.c_str());

                                    //lire l'image

                                    ifstream fichiers("/home/djiro/annotations/fichier.txt");
                                    fichiers >> mot;
                                    fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";//1 Recherche par Nom
                                    images = imread(fichierstd);

                                    for (int n=0;n<images.rows; n++)
                                    {
                                        for (int m=0;m<images.cols;m++)
                                        {
                                            ////////////////////////////////////
                                            Vec3b rgb=images.at<Vec3b>(n,m);
                                            imageboiteRGB.at<Vec3b>(n+i,m+j)=rgb;
                                            ////////////////////////////////////////
                                        }
                                    }


                                }

                            }

                            idimage = "rm -r /home/djiro/annotations/3478753";
                            system(idimage.c_str());
                            images.release();

                            imwrite("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp",imageboiteRGB);
                            imageboiteRGB.release();

                            //nouveaux coordonnées sur petite image des points du polygone

                                 for (i=0;i<TabImage.size(); i++)
                                 {
                                     TabImage[i][0] = TabImage[i][0]-MinX;
                                     TabImage[i][1] = MaxY-TabImage[i][1];
                                 }

                             /////////////////////////////////////
                             /////////////////////////////////////

                             fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
                             nomFichier = QString::fromStdString(fichierstd);
                             image = imread(fichierstd);

                                 page1->setPixmap(QPixmap(fichierstd.c_str()));
                                // page1->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig.bmp"));
                                 page1->setScaledContents(true);
                                 page1->adjustSize();

                                 page2->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page2->setScaledContents(true);
                                 page2->adjustSize();

                                 page3->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page3->setScaledContents(true);
                                 page3->adjustSize();

                                 page4->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page4->setScaledContents(true);
                                 page4->adjustSize();

                                 page6->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page6->setScaledContents(true);
                                 page6->adjustSize();


                                 if (premier == 0)
                                 {
                                     QStringList items;
                                     items << "Rouge" << "Jaune" << "Vert" << "Cyan"<< "Bleu"<< "Magenta";
                                     marqueur = QInputDialog::getItem(this, "Seletion de Marqueur","Marqueurs:", items, 0, false, &ok);

                                     premier = 1;
                                 }

                                 cout << " ---> Traitement image déconvolution " <<endl;

                              //   selectionMarqueur();
                                 Traitement();

                                 ///////////////////////////////
                                 //////////////////////////////

                                 cout << " ---> Traitement: Transformée de distance " <<endl;
                                 //Distances
                                 if (traitement == true)
                                 {
                                     //calcule des distances
                                 //    fichierstd= "/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig1.bmp";
                                 //    nomFichier = QString::fromStdString(fichierstd);
                                         image = imread(fichierstd);
                                         CvScalar pixel; pixel.val[0]=0;pixel.val[1]=255;pixel.val[2]=0;

                                     //tranformé de distance
                                     seuillage();
                                     nbCourbe += 1;
                                     vector<vector<int> > TabCourbe1;TabCourbe1.push_back(vector<int>(4));TabCourbe1[0][0]=0;TabCourbe1[0][1]=0;TabCourbe1[0][2]=0;TabCourbe1[0][3]=0;
                                     int nbPixelMax = 0;
                                     //recuperer le nombre de pixels du marqueur par bandelette de 5um(15pixels)car 1mm = 3040pixels
                             //        int TabTaille = floor(demipatch*2/15.197)+1;
                                     int Xcourbe = -floor(demipatch/15.197)*5;//première valeur x de la courbe
                                    // int TabCourbe [TabTaille][3];
                                     //initialisation
/*
                                     for (int i=0; i<TabTaille; i++)
                                     {
                                         TabCourbe[i][0]=Xcourbe;
                                         TabCourbe[i][1]=0;
                                         TabCourbe[i][2]=0;
                                         Xcourbe += 5;
                                     }*/

                                     for (int i=0; i<imageInt.rows; i++)
                                     {
                                          for (int j=0; j<imageInt.cols; j++)
                                          {
                                          int intersect = 0;
                                          for (int k=0; k<TabImage.size()-1;k++)
                                          {
                                              double ordonn;
                                              double coefdir;
                                              if ((TabImage[k][0]-TabImage[k+1][0]) == 0)
                                              {
                                                  if(i< max(TabImage[k][1],TabImage[k+1][1]) && i>=min(TabImage[k][1],TabImage[k+1][1]) && j<=TabImage[k][0])
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                             else if(i< max(TabImage[k][1],TabImage[k+1][1]) && i>=min(TabImage[k][1],TabImage[k+1][1]))
                                              {
                                                  coefdir = (TabImage[k][1]-TabImage[k+1][1])/(TabImage[k][0]-TabImage[k+1][0]);
                                                  ordonn = TabImage[k][1]-(coefdir*TabImage[k][0]);
                                                  double x = (i-ordonn)/coefdir;

                                                  if (x>=j)
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                          }

                                          if ((intersect % 2) == 1)
                                          {
                                              imageInt.at<uchar>(i,j)=255;
                                              imageExt.at<uchar>(i,j)= 0;
                                          }

                                          if ((intersect % 2) == 0)
                                        //  else
                                          {
                                              imageInt.at<uchar>(i,j)=0;
                                              imageExt.at<uchar>(i,j)=255;
                                          }

                                      }
                                    }

                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Interieur.bmp", imageInt );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Exterieur.bmp", imageExt );
                               //   imwrite( "imageBandelette.bmp", image );


                                  distanceTransform(imageInt, imageInt, CV_DIST_L2, 3);
                                //  normalize(imageInt, imageInt, 0, 255, NORM_MINMAX);
                               //   imshow("Distance Transform ImageInt", imageInt);
                               //   imwrite( "Interieur.bmp", imageInt );

                                  distanceTransform(imageExt, imageExt, CV_DIST_L2, 3);
                               //   normalize(imageExt, imageExt, 0, 255, NORM_MINMAX);
                               //   imshow("Distance Transform ImageExt", imageExt);
                               //   imwrite( "Exterieur.bmp", imageExt );

                                  cout << " ---> Création Image bandelette et Création courbe " <<endl;

                                  for ( i=0; i<image.rows; i++)
                                  {
                                       for ( j=0; j<image.cols; j++)
                                       {
                                           {
                                               ///////////////////////
                                               //////////////////////
                                               //lignes de niveau

                                               if (imageInt.at<float>(i,j)!=0.)
                                               {
                                                   int valeur = ceil(imageInt.at<float>(i,j));
                                                   if ((valeur%(3*bandelette))<=2)
                                                   {
                                                        Vec3b rgb; rgb.val[0]=0; rgb.val[1]=0;rgb.val[2]=255;
                                                        image.at<Vec3b>(i,j)=rgb;
                                                   }
                                               }

                                               if (imageExt.at<float>(i,j)!=0.&& imageExt.at<float>(i,j)<distanceExtFront)
                                               {
                                                   int valeur = ceil(imageExt.at<float>(i,j));
                                                   if ((valeur%(3*bandelette))<=2)
                                                   {
                                                        Vec3b rgb; rgb.val[0]=0; rgb.val[1]=255;rgb.val[2]=0;
                                                        image.at<Vec3b>(i,j)=rgb;
                                                   }
                                               }

                                               if (imageInt.at<float>(i,j) <= 2.&& imageExt.at<float>(i,j) <= 2.)
                                               {

                                                   Vec3b rgb; rgb.val[0]=255; rgb.val[1]=0;rgb.val[2]=0;
                                                   image.at<Vec3b>(i,j)=rgb;
                                               }

                                               ///////////////////////
                                               //////////////////////

                                               if(imageC3.at<uchar>(i,j)==0)
                                               {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][1] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                                       }

                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0. && imageExt.at<float>(i,j)<distanceExtFront)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][1] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                                       }

                                                   }
                                               }
                                               //////////////
                                               else
                                               {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][2] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                       }


                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0. && imageExt.at<float>(i,j)<distanceExtFront)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][2] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if(trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                       }

                                                   }
                                               }

                                               //////////////////////
                                               //////////////////////

                                           }
                                       }
                                  }

                             //     cvSaveImage("imageBandelette.bmp",imag);
                             //     imwrite( "imageBandelette.bmp", image );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp", image );
                              //    imageInt.release();imageExt.release();imageZone.release();imageC3.release();
                                  image.release();

                                  //ranger les Zones pixels par distances et supprimer celles n'ayant pas une surface représentative
                                  for (int i=0; i<TabCourbe1.size(); i++)
                                  {
                                      if (nbPixelMax<(TabCourbe1[i][1]+TabCourbe1[i][2]))
                                      {
                                          nbPixelMax = (TabCourbe1[i][1]+TabCourbe1[i][2]);
                                      }
                                  }

                                  int tampon0,tampon1,tampon2;
                                  for (i=0; i<TabCourbe1.size(); i++)
                                  {
                                      for ( j=i; j<TabCourbe1.size(); j++)
                                      {
                                          if (TabCourbe1[j][0]<TabCourbe1[i][0])
                                          {
                                              tampon0 = TabCourbe1[j][0]; tampon1 = TabCourbe1[j][1]; tampon2 = TabCourbe1[j][2];
                                              TabCourbe1[j][0] = TabCourbe1[i][0]; TabCourbe1[j][1] = TabCourbe1[i][1];TabCourbe1[j][2] = TabCourbe1[i][2];
                                              TabCourbe1[i][0] = tampon0; TabCourbe1[i][1] = tampon1; TabCourbe1[i][2] = tampon2;
                                          }

                                      }
                                     // cout<< TabCourbe1[i][0] <<endl;
                                  }

                                  ////////////////////////////////////////////////////////////////////////////////////////////////////
                                  ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
                                  ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
                                  ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

                                  //Nombre de pixels objets
                                 /*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1] << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1] << endl;
                                      }
                                  }*/
                                  /////////////////////////
                                  //Nombre de Lymphocytes
                                  /*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]/315 << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]/315 << endl;
                                      }
                                  }*/


                                  //Nombre de Lymphocytes par 5000 micromètre carré
                                  int x = 1;
                                 // int densiteMax = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
                                 // int densiteMin = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
                                  int densiteMax = 0;
                                  int densiteMin = 0;

                                  for ( i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/5)))
                                      {
                                          fichier1 << x; fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                                          TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                                          TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                                          TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                                          TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];


                                          if (densiteMax<TabCourbe1[i][3])
                                          {
                                              densiteMax = TabCourbe1[i][3];
                                          }
                                          if (densiteMin>TabCourbe1[i][3])
                                          {
                                              densiteMin = TabCourbe1[i][3];
                                          }
                                          x += 1;
                                      }
                                         //pour TabCourbe1[i][0] == 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                        //  TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                        //  TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                                          TabCourbe1[i][1] = TabCourbe1[i+1][1];
                                          TabCourbe1[i][2] = TabCourbe1[i+1][2];

                                          fichier1 << x;fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << (TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << (TabCourbe1[i][1]/315.0)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                                          TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                                          TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                                          TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                                          TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];

                                          if (densiteMax<TabCourbe1[i][3])
                                          {
                                              densiteMax = TabCourbe1[i][3];
                                          }
                                          if (densiteMin>TabCourbe1[i][3])
                                          {
                                              densiteMin = TabCourbe1[i][3];
                                          }
                                          x += 1;
                                      }

                                  }

                                  cout << " ---> Création Image Carte de chaleur " <<endl;
                                  //////////////////////////////////////////
                                  /////////////////////////////////////////
                                  for ( i=0; i<imageC3.rows; i++)
                                  {
                                       for ( j=0; j<imageC3.cols; j++)
                                       {
                                           if (imageZone.at<uchar>(i,j)==255)
                                           {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                                                           }

                                                       }
                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                                                           }

                                                       }
                                                   }
                                           }
                                           else
                                           {
                                               imageC3.at<uchar>(i,j)=0;
                                           }
                                       }
                                  }

                                  applyColorMap(imageC3, imageC3, COLORMAP_JET);
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleur.bmp", imageC3);

                                  imageInt.release();imageExt.release();imageZone.release();

                               //   fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
                               //   nomFichier = QString::fromStdString(fichierstd);
                                  Mat image;
                                  image = imread(fichierstd);

                                  addWeighted(image,0.3,imageC3,0.7,0.,imageC3);
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleurImage.bmp", imageC3);

                                  imageC3.release();image.release();

                                  ////////////////////////////////////////
                                  ////////////////////////////////////////

                                  //Nombre de pixels par Zone
/*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                      }
                                  }*/

                                  /////////////////////////

                                  fichier1.close();fichier2.close();fichier3.close();
                                  system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
                                  page4->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp"));
                                  page4->setScaledContents(true);
                                  page4->adjustSize();

                                  page6->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
                                  page6->setScaledContents(true);
                                  page6->adjustSize();

                                  /////////////////////////////////////////////////////////////////////////////////////////////////////

                          }

                                 for (i=0;i<TabImage.size(); i++)
                                 {
                                     TabImage[i][0] = TabImage[i][0]+MinX;
                                     TabImage[i][1] = MaxY-TabImage[i][1];

                                 }
            }


   }
         fichier.close();
         /////////////////////////////////////////////////
         //courbe moyenne
         if (nbCourbe>1)
         {
         vector<vector<int> > TabCourbe;
         for (int i=0; i<TabCourbeMoy.size()-1;i++)
         {
             int nbSomme = 0;
             for (int j=i+1; j<TabCourbeMoy.size();j++)
             {
                 if (TabCourbeMoy[i][0]==TabCourbeMoy[j][0])
                 {
                     TabCourbeMoy[i][1] += TabCourbeMoy[j][1];
                     nbSomme += 1;
                 }
             }
             if (nbSomme == (nbCourbe-1))
             {
                 TabCourbe.push_back(vector<int>(2));
                 TabCourbe[TabCourbe.size()-1][0]=TabCourbeMoy[i][0];
                 TabCourbe[TabCourbe.size()-1][1]=TabCourbeMoy[i][1]/nbSomme;
             }

         }

         for (int i=0; i<TabCourbe.size()-1; i++)//pour ordonner le tableau
         {
             for (int j=i+1; j<TabCourbe.size();j++)
             {
                 if (TabCourbe[i][0] > TabCourbe[j][0])
                 {
                     int tampX, tampY;
                     tampX = TabCourbe[i][0];
                     tampY = TabCourbe[i][1];
                     TabCourbe[i][0] = TabCourbe[j][0];
                     TabCourbe[i][1] = TabCourbe[j][1];
                     TabCourbe[j][0] = tampX;
                     TabCourbe[j][1] = tampY;
                 }
             }
         }

         ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
         ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
         ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

         for (int i=0;i<TabCourbe.size();i++)
         {
           //  fichier1 << TabCourbe[i][0]; fichier1 << " "; fichier1 << (TabCourbe[i][1]/315) << endl;
             fichier2 << TabCourbe[i][0] << endl;
             fichier3 << TabCourbe[i][1] << endl;
         }
         fichier1.close();fichier2.close();fichier3.close();
         system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
         page4->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
         page4->setScaledContents(true);
         page4->adjustSize();

         }
         //////////////////////////////////////////////////////////
       }

       else
       {
       cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
       }
}

void Fenetre::imageCytomineA3()
{
    /////////////////////////////////////////////////////
/*
    QString path = QFileDialog::getExistingDirectory(this, "Choisissez un dossier");
    QDir dir(path);

    QString nomDuDossier = dir.dirName();
    dir.cdUp();

    QString cheminDuDossier = dir.path();
    QStringList filters;
    filters << "*.tif" << "*.bmp"<< "*.png"<< "*.gif"<< "*.jpg"<< "*.jpeg";
    QStringList files = QDir( cheminDuDossier ).entryList( filters );*/
    int premier = 0;

  //  foreach (QString file, files)
  //  foreach (nomFichier, files)
  //  for (int k=0; k<files.size(); k++)
    {

        nomFichier = "";
        nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",QString(), "Images (*.tif *.bmp *.png *.gif *.jpg *.jpeg)");

     //   nomFichier = files.at(k);
        // nomFichier = file;
         ///////////////////////////////////////////
         int i,j;
         bool ok;

         fichierstd = nomFichier.toStdString();
         cout << fichierstd << endl;

         image = imread(fichierstd);
         imwrite("imageOrig.bmp",image);

             //page1->setPixmap(QPixmap(fichierstd.c_str()));
             page1->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig.bmp"));
             page1->setScaledContents(true);
             page1->adjustSize();

             page2->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
             page2->setScaledContents(true);
             page2->adjustSize();

             page3->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
             page3->setScaledContents(true);
             page3->adjustSize();

             page4->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
             page4->setScaledContents(true);
             page4->adjustSize();

             page6->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
             page6->setScaledContents(true);
             page6->adjustSize();


             if (premier == 0)
             {
                 QStringList items;
                 items << "Rouge" << "Jaune" << "Vert" << "Cyan"<< "Bleu"<< "Magenta";
                 marqueur = QInputDialog::getItem(this, "Seletion de Marqueur","Marqueurs:", items, 0, false, &ok);

                 premier = 1;
             }

             cout << " ---> Traitement image déconvolution " <<endl;

          //   selectionMarqueur();
             Traitement();

             cout << " ---> Traitement: Transformée de distance " <<endl;
             if (traitement == true)
             {
                 vector<vector<int> > TabCourbe1;TabCourbe1.push_back(vector<int>(4));TabCourbe1[0][0]=0;TabCourbe1[0][1]=0;TabCourbe1[0][2]=0;TabCourbe1[0][3]=0;
                 vector<vector<int> > TabCourbe2;TabCourbe2.push_back(vector<int>(4));TabCourbe2[0][0]=0;TabCourbe2[0][1]=0;TabCourbe2[0][2]=0;TabCourbe2[0][3]=0;
                 int nbPixelMax = 0;
                 int Xcourbe;//première valeur x de la courbe

                 for (int i=0; i<image.rows; i++)
                 {
                     for (int j=0; j<image.cols; j++)
                     {
                        Vec3b rgb=image.at<Vec3b>(i,j);
                        if((rgb.val[0]==255 && rgb.val[1]==255 && rgb.val[2]==255) || (i==0 || i==image.rows || j==0 || j==image.cols))
                        {
                            imageInt.at<uchar>(i,j)=0;
                        }
                        else
                            imageInt.at<uchar>(i,j)=255;

                     }

                 }

                 medianBlur(imageInt,imageInt,9);
                 imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Interieur.bmp", imageInt );
                 distanceTransform(imageInt, imageInt, CV_DIST_L2, 3);
            //  normalize(imageInt, imageInt, 0, 255, NORM_MINMAX);
           //   imshow("Distance Transform ImageInt", imageInt);
           //   imwrite( "Interieur.bmp", imageInt );
                 cout << " ---> Création Image bandelette et Création courbe " <<endl;

                 for ( i=0; i<image.rows; i++)
                 {
                    for ( j=0; j<image.cols; j++)
                    {
                           ///////////////////////
                           //////////////////////
                           //lignes de niveau

                           if (imageInt.at<float>(i,j)!=0.)
                           {
                               int valeur = ceil(imageInt.at<float>(i,j));
                               if ((valeur%(3*bandelette))<=2)
                               {
                                    Vec3b rgb; rgb.val[0]=0; rgb.val[1]=0;rgb.val[2]=255;
                                    image.at<Vec3b>(i,j)=rgb;
                               }
                           }
/*
                           if (imageInt.at<float>(i,j) <= 2.)
                           {

                               Vec3b rgb; rgb.val[0]=255; rgb.val[1]=0;rgb.val[2]=0;
                               image.at<Vec3b>(i,j)=rgb;
                           } */

                           ///////////////////////
                           //////////////////////

                           if(imageC3.at<uchar>(i,j)==0)
                           {
                               if (imageInt.at<float>(i,j)!=0.)
                               {
                                   Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                   int trouve = 0;
                                   for (int n=0; n<TabCourbe1.size(); n++)
                                   {
                                       if (TabCourbe1[n][0] == Xcourbe)
                                       {
                                           TabCourbe1[n][1] += 1;
                                           trouve = 1;
                                       }

                                   }
                                   if (trouve == 0)
                                   {
                                       TabCourbe1.push_back(vector<int>(4));
                                       TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                       TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                       TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                       TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                   }

                               }
                           }
                           //////////////
                           else
                           {
                               if (imageInt.at<float>(i,j)!=0.)
                               {
                                   Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                   int trouve = 0;
                                   for (int n=0; n<TabCourbe1.size(); n++)
                                   {
                                       if (TabCourbe1[n][0] == Xcourbe)
                                       {
                                           TabCourbe1[n][2] += 1;
                                           trouve = 1;
                                       }

                                   }
                                   if (trouve == 0)
                                   {
                                       TabCourbe1.push_back(vector<int>(4));
                                       TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                       TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                       TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                       TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                   }


                               }
                           }

                           //////////////////////
                           //////////////////////
                   }
              }

         //     cvSaveImage("imageBandelette.bmp",imag);
         //     imwrite( "imageBandelette.bmp", image );
              imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp", image );
          //    imageInt.release();imageExt.release();imageZone.release();imageC3.release();
              image.release();

              //ranger les Zones pixels par distances et supprimer celles n'ayant pas une surface représentative
              for (int i=0; i<TabCourbe1.size(); i++)
              {
                  if (nbPixelMax<(TabCourbe1[i][1]+TabCourbe1[i][2]))
                  {
                      nbPixelMax = (TabCourbe1[i][1]+TabCourbe1[i][2]);
                  }
              }

              int tampon0,tampon1,tampon2;
              for (i=0; i<TabCourbe1.size(); i++)
              {
                  for ( j=i; j<TabCourbe1.size(); j++)
                  {
                      if (TabCourbe1[j][0]<TabCourbe1[i][0])
                      {
                          tampon0 = TabCourbe1[j][0]; tampon1 = TabCourbe1[j][1]; tampon2 = TabCourbe1[j][2];
                          TabCourbe1[j][0] = TabCourbe1[i][0]; TabCourbe1[j][1] = TabCourbe1[i][1];TabCourbe1[j][2] = TabCourbe1[i][2];
                          TabCourbe1[i][0] = tampon0; TabCourbe1[i][1] = tampon1; TabCourbe1[i][2] = tampon2;
                      }

                  }
                 // cout<< TabCourbe1[i][0] <<endl;
              }

              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
              ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
              ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

              //Nombre de pixels objets
             /*
              for (int i=0;i<TabCourbe1.size();i++)
              {
                  if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                  {
                      fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << TabCourbe1[i][1] << endl;
                  }
                     //pour x = 0 utiliser la moyenne des voisin
                  if (TabCourbe1[i][0] == 0)
                  {
                      TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                      fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << TabCourbe1[i][1] << endl;
                  }
              }*/
              /////////////////////////
              //Nombre de Lymphocytes
              /*
              for (int i=0;i<TabCourbe1.size();i++)
              {
                  if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                  {
                      fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << TabCourbe1[i][1]/315 << endl;
                  }
                     //pour x = 0 utiliser la moyenne des voisin
                  if (TabCourbe1[i][0] == 0)
                  {
                      TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                      fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << TabCourbe1[i][1]/315 << endl;
                  }
              }*/


              //Nombre de Lymphocytes par 5000 micromètre carré
              int x = 1;
             // int densiteMax = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
             // int densiteMin = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
              int densiteMax = 0;
              int densiteMin = 0;

              for ( i=0;i<TabCourbe1.size();i++)
              {
                  if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/5)))
                  {
                      fichier1 << x; fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                      TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                      TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                      TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                      TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];


                      if (densiteMax<TabCourbe1[i][3])
                      {
                          densiteMax = TabCourbe1[i][3];
                      }
                      if (densiteMin>TabCourbe1[i][3])
                      {
                          densiteMin = TabCourbe1[i][3];
                      }
                      x += 1;
                  }
                     //pour TabCourbe1[i][0] == 0 utiliser la moyenne des voisin
                  if (TabCourbe1[i][0] == 0)
                  {
                    //  TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                    //  TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                      TabCourbe1[i][1] = TabCourbe1[i+1][1];
                      TabCourbe1[i][2] = TabCourbe1[i+1][2];

                      fichier1 << x;fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << (TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << (TabCourbe1[i][1]/315.0)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                      TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                      TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                      TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                      TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];

                      if (densiteMax<TabCourbe1[i][3])
                      {
                          densiteMax = TabCourbe1[i][3];
                      }
                      if (densiteMin>TabCourbe1[i][3])
                      {
                          densiteMin = TabCourbe1[i][3];
                      }
                      x += 1;
                  }

              }

              cout << " ---> Création Image Carte de chaleur " <<endl;
              //////////////////////////////////////////
              /////////////////////////////////////////
              for ( i=0; i<imageC3.rows; i++)
              {
                   for ( j=0; j<imageC3.cols; j++)
                   {
                       if (imageInt.at<float>(i,j)!=0.)
                       {
                           Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                           for (int n=0; n<TabCourbe1.size(); n++)
                           {
                               if (TabCourbe1[n][0] == Xcourbe)
                               {
                                   imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                               }

                           }

                       }
                       else
                       {
                           imageC3.at<uchar>(i,j)=0;
                       }
                   }
              }

              applyColorMap(imageC3, imageC3, COLORMAP_JET);
              imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleur.bmp", imageC3);

              //imageInt.release();
              imageExt.release();imageZone.release();

           //   fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
           //   nomFichier = QString::fromStdString(fichierstd);
              Mat image;
              image = imread(fichierstd);

              addWeighted(image,0.3,imageC3,0.7,0.,imageC3);
              imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleurImage.bmp", imageC3);

              imageC3.release();
              //image.release();
              fichier1.close();fichier2.close();fichier3.close();
              system("python /home/djiro/spyder/djiro/client/examples/courbe.py");

              ////////////////////////////////////////
              ////////////////////////////////////////

              for ( i=0; i<image.rows; i++)
              {
                 for ( j=0; j<image.cols; j++)
                 {

                        if(imageC2.at<uchar>(i,j)==0)
                        {
                            if (imageInt.at<float>(i,j)!=0.)
                            {
                                Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                int trouve = 0;
                                for (int n=0; n<TabCourbe2.size(); n++)
                                {
                                    if (TabCourbe2[n][0] == Xcourbe)
                                    {
                                        TabCourbe2[n][1] += 1;
                                        trouve = 1;
                                    }

                                }
                                if (trouve == 0)
                                {
                                    TabCourbe2.push_back(vector<int>(4));
                                    TabCourbe2[TabCourbe2.size()-1][0] = Xcourbe;
                                    TabCourbe2[TabCourbe2.size()-1][1] = 1;
                                    TabCourbe2[TabCourbe2.size()-1][2] = 0;
                                    TabCourbe2[TabCourbe2.size()-1][3] = 0;
                                }

                            }
                        }
                        //////////////
                        else
                        {
                            if (imageInt.at<float>(i,j)!=0.)
                            {
                                Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                int trouve = 0;
                                for (int n=0; n<TabCourbe2.size(); n++)
                                {
                                    if (TabCourbe2[n][0] == Xcourbe)
                                    {
                                        TabCourbe2[n][2] += 1;
                                        trouve = 1;
                                    }

                                }
                                if (trouve == 0)
                                {
                                    TabCourbe2.push_back(vector<int>(4));
                                    TabCourbe2[TabCourbe2.size()-1][0] = Xcourbe;
                                    TabCourbe2[TabCourbe2.size()-1][1] = 0;
                                    TabCourbe2[TabCourbe2.size()-1][2] = 1;
                                    TabCourbe2[TabCourbe2.size()-1][2] = 0;
                                }


                            }
                        }

                        //////////////////////
                        //////////////////////
                }
           }

       //    imageInt.release();imageExt.release();imageZone.release();imageC3.release();
           image.release();

           //ranger les Zones pixels par distances et supprimer celles n'ayant pas une surface représentative
           for (int i=0; i<TabCourbe2.size(); i++)
           {
               if (nbPixelMax<(TabCourbe2[i][1]+TabCourbe2[i][2]))
               {
                   nbPixelMax = (TabCourbe2[i][1]+TabCourbe2[i][2]);
               }
           }

           for (i=0; i<TabCourbe2.size(); i++)
           {
               for ( j=i; j<TabCourbe2.size(); j++)
               {
                   if (TabCourbe2[j][0]<TabCourbe2[i][0])
                   {
                       tampon0 = TabCourbe2[j][0]; tampon1 = TabCourbe2[j][1]; tampon2 = TabCourbe2[j][2];
                       TabCourbe2[j][0] = TabCourbe2[i][0]; TabCourbe2[j][1] = TabCourbe2[i][1];TabCourbe2[j][2] = TabCourbe2[i][2];
                       TabCourbe2[i][0] = tampon0; TabCourbe2[i][1] = tampon1; TabCourbe2[i][2] = tampon2;
                   }

               }
              // cout<< TabCourbe1[i][0] <<endl;
           }

           ////////////////////////////////////////////////////////////////////////////////////////////////////
           ofstream fichier4("/home/djiro/annotations/fichierCourbe.txt");
           ofstream fichier5("/home/djiro/annotations/fichierCourbeX.txt");
           ofstream fichier6("/home/djiro/annotations/fichierCourbeY.txt");

           //Nombre de pixels objets
          /*
           for (int i=0;i<TabCourbe1.size();i++)
           {
               if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
               {
                   fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                   fichier2 << TabCourbe1[i][0] << endl;
                   fichier3 << TabCourbe1[i][1] << endl;
               }
                  //pour x = 0 utiliser la moyenne des voisin
               if (TabCourbe1[i][0] == 0)
               {
                   TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                   fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                   fichier2 << TabCourbe1[i][0] << endl;
                   fichier3 << TabCourbe1[i][1] << endl;
               }
           }*/
           /////////////////////////
           //Nombre de Lymphocytes
           /*
           for (int i=0;i<TabCourbe1.size();i++)
           {
               if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
               {
                   fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                   fichier2 << TabCourbe1[i][0] << endl;
                   fichier3 << TabCourbe1[i][1]/315 << endl;
               }
                  //pour x = 0 utiliser la moyenne des voisin
               if (TabCourbe1[i][0] == 0)
               {
                   TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                   fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                   fichier2 << TabCourbe1[i][0] << endl;
                   fichier3 << TabCourbe1[i][1]/315 << endl;
               }
           }*/


           //Nombre de Lymphocytes par 5000 micromètre carré
           x = 1;
          // int densiteMax = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
          // int densiteMin = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
           densiteMax = 0;
           densiteMin = 0;

           for ( i=0;i<TabCourbe2.size();i++)
           {
               if ((TabCourbe2[i][0] != 0)&&((TabCourbe2[i][1]+TabCourbe2[i][2])>(nbPixelMax/5)))
               {
                   fichier4 << x; fichier4 << " ";fichier4 << TabCourbe2[i][0]; fichier4 << " "; fichier4 << ((TabCourbe2[i][1]/pow(DiametreCellule/diametrePixel,2))/((TabCourbe2[i][1]+TabCourbe2[i][2])/46193.2167)) << endl;
                   fichier5 << TabCourbe2[i][0] << endl;
                   fichier6 << ((TabCourbe2[i][1]/pow(DiametreCellule/diametrePixel,2))/((TabCourbe2[i][1]+TabCourbe2[i][2])/46193.2167)) << endl;
                   TabCourbe2[i][3] = ((TabCourbe2[i][1]/pow(DiametreCellule/diametrePixel,2))/((TabCourbe2[i][1]+TabCourbe2[i][2])/46193.2167));

                   if (densiteMax<TabCourbe2[i][3])
                   {
                       densiteMax = TabCourbe2[i][3];
                   }
                   if (densiteMin>TabCourbe2[i][3])
                   {
                       densiteMin = TabCourbe2[i][3];
                   }
                   x += 1;
               }
                  //pour TabCourbe1[i][0] == 0 utiliser la moyenne des voisin
               if (TabCourbe2[i][0] == 0)
               {
                 //  TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                 //  TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                   TabCourbe2[i][1] = TabCourbe2[i+1][1];
                   TabCourbe2[i][2] = TabCourbe2[i+1][2];

                   fichier4 << x;fichier4 << " ";fichier4 << TabCourbe2[i][0]; fichier4 << " "; fichier4 << (TabCourbe2[i][1]/pow(DiametreCellule/diametrePixel,2))/((TabCourbe2[i][1]+TabCourbe2[i][2])/46193.2167) << endl;
                   fichier5 << TabCourbe2[i][0] << endl;
                   fichier6 << (TabCourbe2[i][1]/pow(DiametreCellule/diametrePixel,2))/((TabCourbe2[i][1]+TabCourbe2[i][2])/46193.2167) << endl;
                   TabCourbe2[i][3] = ((TabCourbe2[i][1]/pow(DiametreCellule/diametrePixel,2))/((TabCourbe2[i][1]+TabCourbe2[i][2])/46193.2167));

                   if (densiteMax<TabCourbe2[i][3])
                   {
                       densiteMax = TabCourbe2[i][3];
                   }
                   if (densiteMin>TabCourbe2[i][3])
                   {
                       densiteMin = TabCourbe2[i][3];
                   }
                   x += 1;
               }

           }

           cout << " ---> Création Image Carte de chaleur " <<endl;

           for ( i=0; i<imageC2.rows; i++)
           {
                for ( j=0; j<imageC2.cols; j++)
                {
                    if (imageInt.at<float>(i,j)!=0.)
                    {
                        Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                        for (int n=0; n<TabCourbe2.size(); n++)
                        {
                            if (TabCourbe2[n][0] == Xcourbe)
                            {
                                imageC2.at<uchar>(i,j)= (TabCourbe2[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                            }

                        }

                    }
                    else
                    {
                        imageC2.at<uchar>(i,j)=0;
                    }
                }
           }

           applyColorMap(imageC2, imageC2, COLORMAP_JET);
           imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleur.bmp", imageC2);

           imageInt.release();

        //   fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
        //   nomFichier = QString::fromStdString(fichierstd);

           image = imread(fichierstd);

           addWeighted(image,0.3,imageC2,0.7,0.,imageC2);
           imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleurImage.bmp", imageC2);

           imageC2.release();image.release();





              ////////////////////////////////////////
              ///////////////////////////////////////
              //Nombre de pixels par Zone
/*
              for (int i=0;i<TabCourbe1.size();i++)
              {
                  if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                  {
                      fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                  }
                     //pour x = 0 utiliser la moyenne des voisin
                  if (TabCourbe1[i][0] == 0)
                  {
                      TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                      TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                      fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                      fichier2 << TabCourbe1[i][0] << endl;
                      fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                  }
              }*/

              /////////////////////////

              fichier4.close();fichier5.close();fichier6.close();
              //system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
              system("python /home/djiro/spyder/djiro/client/examples/courbe2.py");

              page4->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp"));
              page4->setScaledContents(true);
              page4->adjustSize();

              page6->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
              page6->setScaledContents(true);
              page6->adjustSize();

              /////////////////////////////////////////////////////////////////////////////////////////////////////

      }
//////////////////////////////////////////////////////////
}

}

void Fenetre::imageCytomineA4()
{
    string ligne;
    int i,j; int premier = 0; int taille = 0;
    bool ok;
    double demipatch;// = 3040/2; //longueur patch 1mm = 3040 pixels

    nomFichier = "";
    nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",QString(), "Images (*.tif *.bmp *.png *.gif *.jpg *.jpeg)");


        fichierstd = nomFichier.toStdString();
        vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image

  ifstream fichier(fichierstd +".txt");//où le fichier texte est enregistré
 // ofstream fichier1(fichierstd +".txt");

    if(fichier)
        {
                while(getline(fichier, ligne))
                {


                ofstream fichier1("/home/djiro/annotations/fichier1.txt");
                fichier1 <<ligne;
                fichier1.close();
                TabImage.push_back(vector<double>(2));
                //retrouver les coordonnées du polygone image selectionné dans le texte
                ifstream fichier2("/home/djiro/annotations/fichier1.txt");
                fichier2 >> TabImage[taille][0];
                fichier2 >> TabImage[taille][1];
                fichier1.close();
                taille+=1;
                }

                             /////////////////////////////////////
                             /////////////////////////////////////

                           //  fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
                           //  nomFichier = QString::fromStdString(fichierstd);
                             image = imread(fichierstd);

                                 page1->setPixmap(QPixmap(fichierstd.c_str()));
                                // page1->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig.bmp"));
                                 page1->setScaledContents(true);
                                 page1->adjustSize();

                                 page2->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page2->setScaledContents(true);
                                 page2->adjustSize();

                                 page3->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page3->setScaledContents(true);
                                 page3->adjustSize();

                                 page4->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page4->setScaledContents(true);
                                 page4->adjustSize();

                                 page6->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
                                 page6->setScaledContents(true);
                                 page6->adjustSize();


                                 if (premier == 0)
                                 {
                                     QStringList items;
                                     items << "Rouge" << "Jaune" << "Vert" << "Cyan"<< "Bleu"<< "Magenta";
                                     marqueur = QInputDialog::getItem(this, "Seletion de Marqueur","Marqueurs:", items, 0, false, &ok);

                                     premier = 1;
                                 }

                                 cout << " ---> Traitement image déconvolution " <<endl;

                              //   selectionMarqueur();
                                 Traitement();

                                 ///////////////////////////////
                                 //////////////////////////////

                                 cout << " ---> Traitement: Transformée de distance " <<endl;
                                 //Distances
                                 if (traitement == true)
                                 {
                                     //calcule des distances
                                 //    fichierstd= "/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig1.bmp";
                                 //    nomFichier = QString::fromStdString(fichierstd);
                                         image = imread(fichierstd);
                                         CvScalar pixel; pixel.val[0]=0;pixel.val[1]=255;pixel.val[2]=0;

                                     //tranformé de distance
                                     seuillage();
                                     nbCourbe += 1;
                                     vector<vector<int> > TabCourbe1;TabCourbe1.push_back(vector<int>(4));TabCourbe1[0][0]=0;TabCourbe1[0][1]=0;TabCourbe1[0][2]=0;TabCourbe1[0][3]=0;
                                     int nbPixelMax = 0;
                                     //recuperer le nombre de pixels du marqueur par bandelette de 5um(15pixels)car 1mm = 3040pixels
                             //        int TabTaille = floor(demipatch*2/15.197)+1;
                                     int Xcourbe = -floor(demipatch/15.197)*5;//première valeur x de la courbe
                                    // int TabCourbe [TabTaille][3];
                                     //initialisation
/*
                                     for (int i=0; i<TabTaille; i++)
                                     {
                                         TabCourbe[i][0]=Xcourbe;
                                         TabCourbe[i][1]=0;
                                         TabCourbe[i][2]=0;
                                         Xcourbe += 5;
                                     }*/

                                     for (int i=0; i<imageInt.rows; i++)
                                     {
                                          for (int j=0; j<imageInt.cols; j++)
                                          {
                                          int intersect = 0;
                                          for (int k=0; k<TabImage.size()-1;k++)
                                          {
                                              double ordonn;
                                              double coefdir;
                                              if ((TabImage[k][0]-TabImage[k+1][0]) == 0)
                                              {
                                                  if(i< max(TabImage[k][1],TabImage[k+1][1]) && i>=min(TabImage[k][1],TabImage[k+1][1]) && j<=TabImage[k][0])
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                             else if(i< max(TabImage[k][1],TabImage[k+1][1]) && i>=min(TabImage[k][1],TabImage[k+1][1]))
                                              {
                                                  coefdir = (TabImage[k][1]-TabImage[k+1][1])/(TabImage[k][0]-TabImage[k+1][0]);
                                                  ordonn = TabImage[k][1]-(coefdir*TabImage[k][0]);
                                                  double x = (i-ordonn)/coefdir;

                                                  if (x>=j)
                                                  {
                                                      intersect += 1;
                                                  }
                                              }
                                          }

                                          if ((intersect % 2) == 1)
                                          {
                                              imageInt.at<uchar>(i,j)=255;
                                              imageExt.at<uchar>(i,j)= 0;
                                          }

                                          if ((intersect % 2) == 0)
                                        //  else
                                          {
                                              imageInt.at<uchar>(i,j)=0;
                                              imageExt.at<uchar>(i,j)=255;
                                          }

                                      }
                                    }

                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Interieur.bmp", imageInt );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Exterieur.bmp", imageExt );
                               //   imwrite( "imageBandelette.bmp", image );


                                  distanceTransform(imageInt, imageInt, CV_DIST_L2, 3);
                                //  normalize(imageInt, imageInt, 0, 255, NORM_MINMAX);
                               //   imshow("Distance Transform ImageInt", imageInt);
                               //   imwrite( "Interieur.bmp", imageInt );

                                  distanceTransform(imageExt, imageExt, CV_DIST_L2, 3);
                               //   normalize(imageExt, imageExt, 0, 255, NORM_MINMAX);
                               //   imshow("Distance Transform ImageExt", imageExt);
                               //   imwrite( "Exterieur.bmp", imageExt );

                                  cout << " ---> Création Image bandelette et Création courbe " <<endl;

                                  for ( i=0; i<image.rows; i++)
                                  {
                                       for ( j=0; j<image.cols; j++)
                                       {
                                           {
                                               ///////////////////////
                                               //////////////////////
                                               //lignes de niveau

                                               if (imageInt.at<float>(i,j)!=0.)
                                               {
                                                   int valeur = ceil(imageInt.at<float>(i,j));
                                                   if ((valeur%(3*bandelette))<=2)
                                                   {
                                                        Vec3b rgb; rgb.val[0]=0; rgb.val[1]=0;rgb.val[2]=255;
                                                        image.at<Vec3b>(i,j)=rgb;
                                                   }
                                               }

                                               if (imageExt.at<float>(i,j)!=0.&& imageExt.at<float>(i,j)<distanceExtFront)
                                               {
                                                   int valeur = ceil(imageExt.at<float>(i,j));
                                                   if ((valeur%(3*bandelette))<=2)
                                                   {
                                                        Vec3b rgb; rgb.val[0]=0; rgb.val[1]=255;rgb.val[2]=0;
                                                        image.at<Vec3b>(i,j)=rgb;
                                                   }
                                               }

                                               if (imageInt.at<float>(i,j) <= 2.&& imageExt.at<float>(i,j) <= 2.)
                                               {

                                                   Vec3b rgb; rgb.val[0]=255; rgb.val[1]=0;rgb.val[2]=0;
                                                   image.at<Vec3b>(i,j)=rgb;
                                               }

                                               ///////////////////////
                                               //////////////////////

                                               if(imageC3.at<uchar>(i,j)==0)
                                               {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][1] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                                       }

                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0. && imageExt.at<float>(i,j)<distanceExtFront)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][1] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][3] = 0;
                                                       }

                                                   }
                                               }
                                               //////////////
                                               else
                                               {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][2] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if (trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                       }


                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0. && imageExt.at<float>(i,j)<distanceExtFront)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       int trouve = 0;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               TabCourbe1[n][2] += 1;
                                                               trouve = 1;
                                                           }

                                                       }
                                                       if(trouve == 0)
                                                       {
                                                           TabCourbe1.push_back(vector<int>(4));
                                                           TabCourbe1[TabCourbe1.size()-1][0] = Xcourbe;
                                                           TabCourbe1[TabCourbe1.size()-1][1] = 0;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 1;
                                                           TabCourbe1[TabCourbe1.size()-1][2] = 0;
                                                       }

                                                   }
                                               }

                                               //////////////////////
                                               //////////////////////

                                           }
                                       }
                                  }

                             //     cvSaveImage("imageBandelette.bmp",imag);
                             //     imwrite( "imageBandelette.bmp", image );
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp", image );
                              //    imageInt.release();imageExt.release();imageZone.release();imageC3.release();
                                  image.release();

                                  //ranger les Zones pixels par distances et supprimer celles n'ayant pas une surface représentative
                                  for (int i=0; i<TabCourbe1.size(); i++)
                                  {
                                      if (nbPixelMax<(TabCourbe1[i][1]+TabCourbe1[i][2]))
                                      {
                                          nbPixelMax = (TabCourbe1[i][1]+TabCourbe1[i][2]);
                                      }
                                  }

                                  int tampon0,tampon1,tampon2;
                                  for (i=0; i<TabCourbe1.size(); i++)
                                  {
                                      for ( j=i; j<TabCourbe1.size(); j++)
                                      {
                                          if (TabCourbe1[j][0]<TabCourbe1[i][0])
                                          {
                                              tampon0 = TabCourbe1[j][0]; tampon1 = TabCourbe1[j][1]; tampon2 = TabCourbe1[j][2];
                                              TabCourbe1[j][0] = TabCourbe1[i][0]; TabCourbe1[j][1] = TabCourbe1[i][1];TabCourbe1[j][2] = TabCourbe1[i][2];
                                              TabCourbe1[i][0] = tampon0; TabCourbe1[i][1] = tampon1; TabCourbe1[i][2] = tampon2;
                                          }

                                      }
                                     // cout<< TabCourbe1[i][0] <<endl;
                                  }

                                  ////////////////////////////////////////////////////////////////////////////////////////////////////
                                  ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
                                  ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
                                  ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

                                  //Nombre de pixels objets
                                 /*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1] << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1] << endl;
                                      }
                                  }*/
                                  /////////////////////////
                                  //Nombre de Lymphocytes
                                  /*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]/315 << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]/315 << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]/315 << endl;
                                      }
                                  }*/


                                  //Nombre de Lymphocytes par 5000 micromètre carré
                                  int x = 1;
                                 // int densiteMax = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
                                 // int densiteMin = ((TabCourbe1[0][1]/315)/((TabCourbe1[0][1]+TabCourbe1[0][2])/46193.2167));
                                  int densiteMax = 0;
                                  int densiteMin = 0;

                                  for ( i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/5)))
                                      {
                                          fichier1 << x; fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167)) << endl;
                                          TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                                          TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                                          TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                                          TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];


                                          if (densiteMax<TabCourbe1[i][3])
                                          {
                                              densiteMax = TabCourbe1[i][3];
                                          }
                                          if (densiteMin>TabCourbe1[i][3])
                                          {
                                              densiteMin = TabCourbe1[i][3];
                                          }
                                          x += 1;
                                      }
                                         //pour TabCourbe1[i][0] == 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                        //  TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                        //  TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                                          TabCourbe1[i][1] = TabCourbe1[i+1][1];
                                          TabCourbe1[i][2] = TabCourbe1[i+1][2];

                                          fichier1 << x;fichier1 << " ";fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << (TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << (TabCourbe1[i][1]/315.0)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167) << endl;
                                          TabCourbe1[i][3] = ((TabCourbe1[i][1]/315)/((TabCourbe1[i][1]+TabCourbe1[i][2])/46193.2167));

                                          TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
                                          TabCourbeMoy[TabCourbeMoy.size()-1][0]=TabCourbe1[i][0];
                                          TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe1[i][3];

                                          if (densiteMax<TabCourbe1[i][3])
                                          {
                                              densiteMax = TabCourbe1[i][3];
                                          }
                                          if (densiteMin>TabCourbe1[i][3])
                                          {
                                              densiteMin = TabCourbe1[i][3];
                                          }
                                          x += 1;
                                      }

                                  }

                                  cout << " ---> Création Image Carte de chaleur " <<endl;
                                  //////////////////////////////////////////
                                  /////////////////////////////////////////
                                  for ( i=0; i<imageC3.rows; i++)
                                  {
                                       for ( j=0; j<imageC3.cols; j++)
                                       {
                                           if (imageZone.at<uchar>(i,j)==255)
                                           {
                                                   if (imageInt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = ceil(imageInt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                                                           }

                                                       }
                                                   }
                                                   else if (imageExt.at<float>(i,j)!=0.)
                                                   {
                                                       Xcourbe = -ceil(imageExt.at<float>(i,j)/(3.0394*bandelette))*bandelette;
                                                       for (int n=0; n<TabCourbe1.size(); n++)
                                                       {
                                                           if (TabCourbe1[n][0] == Xcourbe)
                                                           {
                                                               imageC3.at<uchar>(i,j)= (TabCourbe1[n][3]-densiteMin)*(255/(densiteMax-densiteMin));
                                                           }

                                                       }
                                                   }
                                           }
                                           else
                                           {
                                               imageC3.at<uchar>(i,j)=0;
                                           }
                                       }
                                  }

                                  applyColorMap(imageC3, imageC3, COLORMAP_JET);
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleur.bmp", imageC3);

                                  imageInt.release();imageExt.release();imageZone.release();

                               //   fichierstd= "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageOrig1.bmp";
                               //   nomFichier = QString::fromStdString(fichierstd);
                                  Mat image;
                                  image = imread(fichierstd);

                                  addWeighted(image,0.3,imageC3,0.7,0.,imageC3);
                                  imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/CarteDeChaleurImage.bmp", imageC3);

                                  imageC3.release();image.release();

                                  ////////////////////////////////////////
                                  ////////////////////////////////////////

                                  //Nombre de pixels par Zone
/*
                                  for (int i=0;i<TabCourbe1.size();i++)
                                  {
                                      if ((TabCourbe1[i][0] != 0)&&((TabCourbe1[i][1]+TabCourbe1[i][2])>(nbPixelMax/2)))
                                      {
                                          fichier1 << TabCourbe1[i][0]/5; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                      }
                                         //pour x = 0 utiliser la moyenne des voisin
                                      if (TabCourbe1[i][0] == 0)
                                      {
                                          TabCourbe1[i][1] = (TabCourbe1[i-1][1]+TabCourbe1[i+1][1])/2;
                                          TabCourbe1[i][2] = (TabCourbe1[i-1][2]+TabCourbe1[i+1][2])/2;
                                          fichier1 << TabCourbe1[i][0]; fichier1 << " "; fichier1 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                          fichier2 << TabCourbe1[i][0] << endl;
                                          fichier3 << TabCourbe1[i][1]+TabCourbe1[i][2] << endl;
                                      }
                                  }*/

                                  /////////////////////////

                                  fichier1.close();fichier2.close();fichier3.close();
                                  system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
                                  page4->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageBandelette.bmp"));
                                  page4->setScaledContents(true);
                                  page4->adjustSize();

                                  page6->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
                                  page6->setScaledContents(true);
                                  page6->adjustSize();

                                  /////////////////////////////////////////////////////////////////////////////////////////////////////

                          }
/*
                                 for (i=0;i<TabImage.size(); i++)
                                 {
                                     TabImage[i][0] = TabImage[i][0]+MinX;
                                     TabImage[i][1] = MaxY-TabImage[i][1];

                                 }*/
         fichier.close();
         /////////////////////////////////////////////////
         //courbe moyenne
         if (nbCourbe>1)
         {
         vector<vector<int> > TabCourbe;
         for (int i=0; i<TabCourbeMoy.size()-1;i++)
         {
             int nbSomme = 0;
             for (int j=i+1; j<TabCourbeMoy.size();j++)
             {
                 if (TabCourbeMoy[i][0]==TabCourbeMoy[j][0])
                 {
                     TabCourbeMoy[i][1] += TabCourbeMoy[j][1];
                     nbSomme += 1;
                 }
             }
             if (nbSomme == (nbCourbe-1))
             {
                 TabCourbe.push_back(vector<int>(2));
                 TabCourbe[TabCourbe.size()-1][0]=TabCourbeMoy[i][0];
                 TabCourbe[TabCourbe.size()-1][1]=TabCourbeMoy[i][1]/nbSomme;
             }

         }

         for (int i=0; i<TabCourbe.size()-1; i++)//pour ordonner le tableau
         {
             for (int j=i+1; j<TabCourbe.size();j++)
             {
                 if (TabCourbe[i][0] > TabCourbe[j][0])
                 {
                     int tampX, tampY;
                     tampX = TabCourbe[i][0];
                     tampY = TabCourbe[i][1];
                     TabCourbe[i][0] = TabCourbe[j][0];
                     TabCourbe[i][1] = TabCourbe[j][1];
                     TabCourbe[j][0] = tampX;
                     TabCourbe[j][1] = tampY;
                 }
             }
         }

         ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
         ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
         ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

         for (int i=0;i<TabCourbe.size();i++)
         {
           //  fichier1 << TabCourbe[i][0]; fichier1 << " "; fichier1 << (TabCourbe[i][1]/315) << endl;
             fichier2 << TabCourbe[i][0] << endl;
             fichier3 << TabCourbe[i][1] << endl;
         }
         fichier1.close();fichier2.close();fichier3.close();
         system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
         page4->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
         page4->setScaledContents(true);
         page4->adjustSize();

         }
         //////////////////////////////////////////////////////////
       }

       else
       {
       cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
       }
}
//////////////////////////////////////////////////////////////////////////////////////////

void Fenetre::ouvrirDialogueChoisir()
{
   nomFichier = "";
   nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",QString(), "Images (*.tif *.bmp *.png *.gif *.jpg *.jpeg)");

   if(!nomFichier.isNull())
   { 
       fichierstd = nomFichier.toStdString();
       IplImage *imag = cvLoadImage(fichierstd.c_str());

       cvSaveImage("imageOrig.bmp",imag);

    // page1->setPixmap(QPixmap(nomFichier));//n'affiche pas les fichiers .tif
       page1->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig.bmp"));
       page1->setScaledContents(true);
       page1->adjustSize();

       page2->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
       page2->setScaledContents(true);
       page2->adjustSize();

       page3->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
       page3->setScaledContents(true);
       page3->adjustSize();

       page4->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
       page4->setScaledContents(true);
       page4->adjustSize();

       page6->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
       page6->setScaledContents(true);
       page6->adjustSize();

       traitement = false;
   }

   else
   {
     QMessageBox::critical(this, "Information"," Pas d'image sélectionnée ");
   }
}


void Fenetre::Annotation()
{
    if(!nomFichier.isNull())
    {
        string fichierstd = nomFichier.toStdString();
        Mat img = imread(fichierstd);
     //   int tailleContour = Mat(contour).rows;
        int i,j, MinX, MaxX, MinY, MaxY;
        nb=0;

        vector<Point> contoure;
        namedWindow("Choix Pixel", 1);
        setMouseCallback("Choix Pixel", mouseAnnotation, &img);
        imshow("Choix Pixel", img);
        waitKey(0);
        //traitement image puis affichage dans page2
     /*   lcd1->display(Rouge);
        lcd2->display(Vert);
        lcd3->display(Bleu);
        lcd4->display(Teinte);
        lcd5->display(Saturation);
        lcd6->display(Luminance);*/
        destroyWindow("Choix Pixel");



            MinX = contour[contour.size()-1][0];
            MaxX = contour[contour.size()-1][0];
            MinY = contour[contour.size()-1][1];
            MaxY = contour[contour.size()-1][1];

            nb = contour.size()-nb;

            for (i=nb;i<contour.size(); i++)
            {
                if (contour[i][0]<MinX)
                {
                    MinX = contour[i][0];
                }
                if (contour[i][0]>MaxX)
                {
                    MaxX = contour[i][0];
                }
                if (contour[i][1]<MinY)
                {
                    MinY = contour[i][1];
                }
                if (contour[i][1]>MaxY)
                {
                    MaxY = contour[i][1];
                }
              //  contoure.push_back(Point(contour[i][0],contour[i][1]));
            }
            //augmenter l'image de 10*5micromètres du front 10*15,197

            MinX=MinX-distanceExtFront;
            MinY=MinY-distanceExtFront;
            MaxX=MaxX+distanceExtFront;
            MaxY=MaxY+distanceExtFront;

            int nbcolonne = MaxX - MinX;
            int nbligne = MaxY - MinY;

            /*
            int nbcolonne = Xmax - Xmin;
            int nbligne = Ymax - Ymin;*/

            // Creer le boite englobante de l'annotation front tumorale
            Mat imageboiteRGB(nbligne,nbcolonne,CV_8UC3);
            for (i=0;i<nbligne; i++)
            {
                for (j=0;j<nbcolonne;j++)
                {
                    ////////////////////////////////////
                    Vec3b rgb=img.at<Vec3b>(i+MinY,j+MinX);
                    imageboiteRGB.at<Vec3b>(i,j)=rgb;
                    ////////////////////////////////////////
                }
            }

            //nouveaux coordonnées sur petite image des points du polygone
        //    ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
            ofstream fichier1(fichierstd +".txt");

                 for (i=nb;i<contour.size(); i++)
                 {
                     contour[i][0] = contour[i][0]-MinX;
                     contour[i][1] = contour[i][1]-MinY;
                     contoure.push_back(Point(contour[i][0],contour[i][1]));
                     fichier1 << contour[i][0]; fichier1 << " ";fichier1 << contour[i][1] << endl;
                 }

                 img.release();


///////////////////////////////////////////////////
            const cv::Point *pts = (const cv::Point*) Mat(contoure).data;
                int npts = Mat(contoure).rows;

                std::cout << "Number of polygon vertices: " << npts << std::endl;
                std::cout << contour.size() << std::endl;

                imwrite(fichierstd,imageboiteRGB);
                polylines(imageboiteRGB, &pts,&npts, 1,
                                true, 			// draw closed contour (i.e. joint end to start)
                                Scalar(0,255,0),// colour RGB ordering (here = green)
                                1, 		        // line thickness
                                CV_AA, 0);
             //   imwrite(fichierstd,imageboiteRGB);

                for(int i=0; i<contour.size()+1; i++)
                {
                    contour.pop_back();
                }
                page1->setPixmap(QPixmap(nomFichier));
                page1->setScaledContents(true);
                page1->adjustSize();


    }
    else
    {
      QMessageBox::information( this, "Information"," Pas d'image sélectionnée ");
    }
}




void Fenetre::selectionPixel()//cette fonction permet la selection d'une couleur puis une transformation 1,2,ou 3 est effectuée
{
    if(!nomFichier.isNull())
    {
        vector<double> TabCourbe;
        string fichierstd = nomFichier.toStdString();
        Mat img = imread(fichierstd);
        namedWindow("Choix Pixel", 1);
        setMouseCallback("Choix Pixel", mouseEvent, &img);
        imshow("Choix Pixel", img);
        waitKey(0);
        //traitement image puis affichage dans page2
        lcd1->display(Rouge);
        lcd2->display(Vert);
        lcd3->display(Bleu);
        lcd4->display(Teinte);
        lcd5->display(Saturation);
        lcd6->display(Luminance);
        destroyWindow("Choix Pixel");

        ///////////////////////////////////
        ///////////////////////

            const cv::Point *pts = (const cv::Point*) Mat(contour).data;
                int npts = Mat(contour).rows;

                std::cout << "Number of polygon vertices: " << npts << std::endl;

                polylines(img, &pts,&npts, 1,
                                true, 			// draw closed contour (i.e. joint end to start)
                                Scalar(0,255,0),// colour RGB ordering (here = green)
                                1, 		        // line thickness
                                CV_AA, 0);
                imwrite("imageOrig1.bmp",img);
        /////////////////////////////
        //////////////////////////////

int choix =2;

        //////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////
    /*  if (choix==1)
      {
          fonctionNicolas();
      }*/
       if (choix==2)
      {
          fonctionNicolasArmand();
      }
      if (choix==3)
      {
          fonctionCarron();
      }
          imwrite( "imageC1.bmp", imageC1 );
          page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
          page2->setScaledContents(true);
          page2->adjustSize();
          //////////////////////////////////////////////
          ////////////////////////////////////////////
          // Create a structuring element
                int erosion_size = 1;
                Mat element = getStructuringElement(cv::MORPH_CROSS,
                       cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                       cv::Point(-1, -1) );

          //detection contoures
              //noyaux

                medianBlur(imageC1,imageC2,5);
                Canny(imageC2,imageC2,10,350);
                bitwise_not ( imageC2, imageC2 );
                threshold(imageC1, imageC3, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
  /*
              //contours
                medianBlur(imageC1,imageC2,3);
                //dilate(imageC2,imageC2,element);
                Canny(imageC2,imageC2,10,350);
                //erode (imageC2,imageC2,element); */

          //imshow( "canny", imageC2);
         imwrite( "canny.bmp", imageC2 );
         imwrite("Otsu.bmp",imageC3);
         page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/Otsu.bmp"));
         page3->setScaledContents(true);
         page3->adjustSize();
    }
    else
    {
      QMessageBox::information( this, "Information"," Pas d'image sélectionnée ");
    }
}

void Fenetre::selectionMarqueur()//cette fonction permet le selection d'un marqueur puis fait une transformation couleur en fonction
{
    if(!nomFichier.isNull())
    {

        //vector<double> TabCourbe;
        marqueur = "";
        bool ok;
        QStringList items;
        items << "Rouge" << "Jaune" << "Vert" << "Cyan"<< "Bleu"<< "Magenta";
        marqueur = QInputDialog::getItem(this, "Seletion de Marqueur","Marqueurs:", items, 0, false, &ok);

        string itemstd = marqueur.toStdString();
        if (ok && !marqueur.isEmpty())
     //   string nomteinte = itemstd;
        string fichierstd = nomFichier.toStdString();

        //Teinte Rouge
        if (itemstd == "Rouge")
        {
            Teinte = 0;
            lcd1->display(1);
            lcd2->display(0);
            lcd3->display(0);
            lcd4->display(0);
            lcd5->display(255);
            lcd6->display(0);
        }

        //Teinte Jaune
        if (itemstd == "Jaune")
        {
            Teinte = 60;
            lcd1->display(1);
            lcd2->display(1);
            lcd3->display(0);
            lcd4->display(60);
            lcd5->display(255);
            lcd6->display(0);
        }

        //Teinte Verte
        else if (itemstd == "Vert")
        {
            Teinte = 120;
            lcd1->display(0);
            lcd2->display(1);
            lcd3->display(0);
            lcd4->display(120);
            lcd5->display(255);
            lcd6->display(0);
        }

        //Teinte Cyan
        else if (itemstd == "Cyan")
        {
            Teinte = 180;
            lcd1->display(0);
            lcd2->display(1);
            lcd3->display(1);
            lcd4->display(180);
            lcd5->display(255);
            lcd6->display(0);
        }

        //Teinte Bleu
        else if (itemstd == "Bleu")
        {
            Teinte = 240;
            lcd1->display(0);
            lcd2->display(0);
            lcd3->display(1);
            lcd4->display(240);
            lcd5->display(255);
            lcd6->display(0);
        }

        //Teinte Magenta
        else if (itemstd == "Magenta")
        {
            Teinte = 300;
            lcd1->display(1);
            lcd2->display(0);
            lcd3->display(1);
            lcd4->display(300);
            lcd5->display(255);
            lcd6->display(0);
        }

        fonctionNicolasArmand();

        cout<< "Taille Image : "; cout<< imageC1.rows; cout << " "; cout << imageC1.cols <<endl;

        imwrite( "imageC1.bmp", imageC1 );
        page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
        page2->setScaledContents(true);
        page2->adjustSize();
        /////////////////////////////////////////////////////////
        // Create a structuring element
        /*      int erosion_size = 1;
              Mat element = getStructuringElement(cv::MORPH_CROSS,
                     cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                     cv::Point(-1, -1) );

        //detection contoures
            //noyaux

              medianBlur(imageC1,imageC2,5);
              Canny(imageC2,imageC2,10,350);
              bitwise_not ( imageC2, imageC2 );
              threshold(imageC1, imageC3, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
          //    imwrite( "Otsu.bmp", imageC3 );

            //  threshold(imageC1, imageC3, 75, 255, CV_THRESH_BINARY);
              /*
              distanceTransform(imageC3, imageC3, CV_DIST_L2, 3);
              normalize(imageC3, imageC3, 0, 1., NORM_MINMAX);
              imshow("Distance Transform Image", imageC3);*/
/*
            //contours
              medianBlur(imageC1,imageC2,3);
              //dilate(imageC2,imageC2,element);
              Canny(imageC2,imageC2,10,350);
              //erode (imageC2,imageC2,element); */

        //imshow( "canny", imageC2);
   /*    imwrite( "canny.bmp", imageC2 );
       imwrite( "Otsu.bmp", imageC3 );
       page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/Otsu.bmp"));
       page3->setScaledContents(true);
       page3->adjustSize();*/

    }
    else
    {
      QMessageBox::information( this, "Information"," Pas d'image sélectionnée ");
    }
}
/////////////////////////////////////////////////////////////////////////
void Fenetre::Traitement()
{
    if(!nomFichier.isNull())
    {
        bool ok;
        string itemstd = marqueur.toStdString();
        if (ok && !marqueur.isEmpty())
     //   string nomteinte = itemstd;
        string fichierstd = nomFichier.toStdString();

        //Teinte Rouge
        if (itemstd == "Rouge")
        {
            Teinte = 0;
        }

        //Teinte Jaune
        if (itemstd == "Jaune")
        {
            Teinte = 60;
        }

        //Teinte Verte
        else if (itemstd == "Vert")
        {
            Teinte = 120;
        }

        //Teinte Cyan
        else if (itemstd == "Cyan")
        {
            Teinte = 180;
        }

        //Teinte Bleu
        else if (itemstd == "Bleu")
        {
            Teinte = 240;
        }

        //Teinte Magenta
        else if (itemstd == "Magenta")
        {
            Teinte = 300;
        }

        fonctionNicolasArmand();

        cout<< "Taille Image : "; cout<< imageC1.rows; cout << " "; cout << imageC1.cols <<endl;

        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageC1.bmp", imageC1 );
        page2->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/imageC1.bmp"));
        page2->setScaledContents(true);
        page2->adjustSize();
        /////////////////////////////////////////////////////////

    //   imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/fibrose.bmp", imageC2 );
    //   imwrite("/media/djiro/38A09B49A09B0D0E/PROGRAMME/lyphocytes.bmp", imageC3);

       imageC1.release();
       //imageC2.release();

      // page3->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/Otsu.bmp"));
       page3->setPixmap(QPixmap("/media/djiro/38A09B49A09B0D0E/PROGRAMME/seuillage.bmp"));
       page3->setScaledContents(true);
       page3->adjustSize();
    }

}


//void Fenetre::seuillage(bool cocher)
//void Fenetre::seuillage(int seuil)
void Fenetre::seuillage()
{
  if(cocheseuil->isChecked())
 // if (cocher == true)
  {
   if(!nomFichier.isNull() && traitement == true && slider->value() != 255)
   {

      // int seuil= lcd->intValue(); ou
       int seuil = slider->value();
       int tampon,i,j;
       Mat imageseuil;
       cvtColor( image, imageseuil, CV_BGR2GRAY );

       for ( i=0; i<image.rows; i++)
          {
            for ( j=0; j<image.cols; j++)
            {
               tampon = imageC1.at<uchar>(i,j);
               if (tampon > seuil)
               {
                   imageseuil.at<uchar>(i,j) = 255;
                 //  imageC1.at<uchar>(i,j) = 255;
               }
               else
                   imageseuil.at<uchar>(i,j) = imageC1.at<uchar>(i,j);

            }
          }
       imwrite( "imageSeuil.bmp", imageseuil );
       page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageSeuil.bmp"));
       page2->setScaledContents(true);
       page2->adjustSize();

       // Create a structuring element
             int erosion_size = 1;
             Mat element = getStructuringElement(cv::MORPH_CROSS,
                    cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                    cv::Point(-1, -1) );

       //detection contoures
           //noyaux
             medianBlur(imageseuil,imageC2,5);
             Canny(imageC2,imageC2,10,350);
             bitwise_not ( imageC2, imageC2 );
             threshold(imageC1, imageC3, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
/*
           //contours
             medianBlur(imageC1,imageC2,3);
             //dilate(imageC2,imageC2,element);
             Canny(imageC2,imageC2,10,350);
             //erode (imageC2,imageC2,element);*/

       //imshow( "canny", imageC2);
      imwrite( "canny.bmp", imageC2 );
      imwrite("Otsu", imageC3);
      page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/canny.bmp"));
      page3->setScaledContents(true);
      page3->adjustSize();

      page4->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
      page4->setScaledContents(true);
      page4->adjustSize();

      page6->setPixmap(QPixmap("/home/djiro/annotations/ima.png"));
      page6->setScaledContents(true);
      page6->adjustSize();

       ////////////////////
      // cvShowImage("image RGB",image2);
      // cvSaveImage("Image.bmp",image2);
   }
   else
   {
     QMessageBox::critical(this, "Information"," Pas d'image ou de marqueur sélectionnée ");
   }
   }
}

void Fenetre::fonctionPrincipale()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << nomFichier;
}

void Fenetre::courbes()
{
    if (traitement == true)
    {
        seuillage();
        nbCourbe += 1;
        vector<double> TabCourbe;
        //recuperer le nombre de pixels du marqueur par bandelette de 5um(15pixels)car 1mm = 3040pixels
        int pixelMarq=0;int nbcols = 0;
        for (int j=0; j<imageC2.cols; j++)
           {
             nbcols +=1;
             for (int i=0; i<imageC2.rows; i++)
             {
                // if(imageC2.at<uchar>(i,j)==0)//Canny
                 if(imageC3.at<uchar>(i,j)==0)//Otsu
                // if(imageC2.at<uchar>(i,j)==0 && imageC3.at<uchar>(i,j)==0)//Canny et Otsu
                 {
                     pixelMarq += 1;
                 }

             }

            // if (nbcols == 15)//si on a 15 cols == 5 um
               if (((j+1)%(3*bandelette))==0)//à chaque bandelette de 5 um créer cellule tableauCourbe et y insérer le nb objets biologique détecté
             {
                 TabCourbe.push_back(pixelMarq);//conserve nb pixels marqueurs
               //  TabCourbe.push_back(pixelMarq/(nbcols*imageC2.rows));//conserve le nb pixels marqueurs/surface tranche analysée
                 pixelMarq = 0;
                 nbcols = 0;

             }

           }

         int x = -ceil((TabCourbe.size()-1)/2);
         ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
         ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
         ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

         for (int i=0;i<TabCourbe.size();i++)
         {
             fichier1 << x; fichier1 << " "; fichier1 << TabCourbe[i] << endl;
             fichier2 << x << endl;
             fichier3 << TabCourbe[i] << endl;
             x += 1;
         }

         fichier1.close();fichier2.close();fichier3.close();
         system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
         page4->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
         page4->setScaledContents(true);
         page4->adjustSize();
    }
}

/////////////////////////////////////////
void Fenetre::mouseEvent(int evt, int x, int y, int flags, void* param)
{
    Mat* rgb = (Mat*) param;
    if (evt == CV_EVENT_LBUTTONDOWN)
    {
        printf("%d %d BGR: %d, %d, %d\n",
        x, y,
        (int)(*rgb).at<Vec3b>(y, x)[0],
        (int)(*rgb).at<Vec3b>(y, x)[1],
        (int)(*rgb).at<Vec3b>(y, x)[2]);
       // contour.push_back(Point(x,y));

    Bleu =(int)(*rgb).at<Vec3b>(y, x)[0];
    Vert =(int)(*rgb).at<Vec3b>(y, x)[1];
    Rouge =(int)(*rgb).at<Vec3b>(y, x)[2];

          Mat HSV;
          Mat RGB=(*rgb)(Rect(x,y,1,1));
          cvtColor(RGB, HSV,CV_BGR2HLS);

            Vec3b hsv=HSV.at<Vec3b>(0,0);
    Teinte =2*hsv.val[0];
    Luminance =hsv.val[1];
    Saturation =hsv.val[2];

            printf("%d %d HLS: %d, %d, %d\n",
                   x, y,2*hsv.val[0],hsv.val[1],hsv.val[2]);
    }
}

void Fenetre::mouseAnnotation(int evt, int x, int y, int flags, void* param)
{
    if (evt == CV_EVENT_LBUTTONDOWN)
    {
        printf("X= %d  Y= %d \n",
        x, y);
        contour.push_back(vector<int>(2));
        contour[contour.size()-1][0]=x;
        contour[contour.size()-1][1]=y;
        nb+=1;

    }
}

void Fenetre::fonctionNicolasArmand()
{
    //traitement par teinte
        double maxC1,minC1,Teinte1,distance,e;

        image = imread(fichierstd);
        IplImage *image2 = cvLoadImage(fichierstd.c_str());
        IplImage* hls = cvCloneImage(image2);
        cvCvtColor(image2, hls, CV_BGR2HLS);
        cvtColor( image, imageC1, CV_BGR2GRAY );
        cvtColor( image, imageC2, CV_BGR2GRAY );
        cvtColor( image, imageC3, CV_BGR2GRAY );
        cvtColor( image, imageInt, CV_BGR2GRAY );
        cvtColor( image, imageExt, CV_BGR2GRAY );
        cvtColor( image, imageZone, CV_BGR2GRAY );
        double pi = 3.14159265358979323846;double delta = 0;
        int i,j;
        CvScalar pixel;
        //////////////////
        e=0.001;
        pixel=cvGet2D(hls,0,0);
        Teinte1 = 2* pixel.val[0];

        //calcule distance de teinte
        delta = abs(Teinte1-Teinte)*2*pi/360;
        distance = 255*(exp((cos(delta)-1)/(cos(delta)+1+e)));//3
        maxC1 = 255-((distance*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));minC1 =maxC1;//3

        for ( i=0; i<image.rows; i++)
          {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];

                 delta = abs(Teinte1-Teinte)*2*pi/360;
                 distance = 255*(exp((cos(delta)-1)/(cos(delta)+1+e)));//3
                 distance = 255-((distance*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));//3


                 if (distance>maxC1)
                 {
                     maxC1 = distance;
                 }
                 if (distance<minC1)
                 {
                     minC1 = distance;
                 }
             }
        }

        for ( i=0; i<image.rows; i++)
           {
             for ( j=0; j<image.cols; j++)
             {
                pixel=cvGet2D(hls,i,j);
                Teinte1 = 2*pixel.val[0];

                delta = abs(Teinte1-Teinte)*2*pi/360;
                distance = 255*(exp((cos(delta)-1)/(cos(delta)+1+e)));//3
                distance = 255-((distance*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));//3
                imageC1.at<uchar>(i,j) = 255*(distance-minC1)/(maxC1-minC1);

             }
        }
        traitement = true;

        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/GrisArmand.bmp", imageC1 );
        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/GrisNormal.bmp", imageC2 );
        threshold(imageC1, imageC2, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Otsu.bmp", imageC2 );
        threshold(imageC1, imageC3, 75, 255, CV_THRESH_BINARY);
        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Seuil75.bmp", imageC3 );
        threshold(imageC1, imageC3, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
        ////////////////////////////////////////////
        int centre1 = 255; double centre2 = 0.;int centre3 = 0;double nbpixel = 0.;

        for ( i=0; i<imageC3.rows; i++)
           {
             for ( j=0; j<imageC3.cols; j++)
             {
                if (imageC3.at<uchar>(i,j) == 0)
                {
                    centre2 += imageC1.at<uchar>(i,j);
                    nbpixel += 1;
                    if (imageC1.at<uchar>(i,j) < centre1)
                    {
                        centre1 = imageC1.at<uchar>(i,j);
                    }
                    if (imageC1.at<uchar>(i,j) > centre3)
                    {
                        centre3 = imageC1.at<uchar>(i,j);
                    }

                }

             }
        }
        centre2 /= nbpixel;
        cout<< "Centre1 : "; cout<< centre1; cout << " ";cout<< "Centre2 : "; cout << centre2; cout << " ";cout<< "Centre3 : "; cout << centre3 <<endl;


        for ( i=0; i<imageC3.rows; i++)
           {
             for ( j=0; j<imageC3.cols; j++)
             {
                if (imageC3.at<uchar>(i,j)==0)
                {
                    if (abs(imageC1.at<uchar>(i,j)-centre1)<abs(imageC1.at<uchar>(i,j)-centre2))
                    {
                        imageC3.at<uchar>(i,j)=0;//image correspondant aux lymphocytes
                        imageC2.at<uchar>(i,j)=255;//image correspondant a la fibrose
                    }
                   // else if (abs(imageC1.at<uchar>(i,j)-centre1)>abs(imageC1.at<uchar>(i,j)-centre2) && abs(imageC1.at<uchar>(i,j)-centre3)>abs(imageC1.at<uchar>(i,j)-centre2))
                    else if (imageC1.at<uchar>(i,j)<centre2 && abs(imageC1.at<uchar>(i,j)-centre1)>abs(imageC1.at<uchar>(i,j)-centre2))
                    {
                        imageC3.at<uchar>(i,j)=255;//image correspondant aux lymphocytes
                        imageC2.at<uchar>(i,j)=0;//image correspondant a la fibrose
                    }
                    else
                    {
                        imageC3.at<uchar>(i,j)=255;//image correspondant aux lymphocytes
                        imageC2.at<uchar>(i,j)=255;//image correspondant a la fibrose
                    }
                }
             }
          }
        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Lymphocytes.bmp", imageC3 );
        imwrite( "/media/djiro/38A09B49A09B0D0E/PROGRAMME/Fibrose.bmp", imageC2 );

       // imageC1.release();
        cvReleaseImage(&image2);cvReleaseImage(&hls);

        ////////////////////////////////////////////

}

void Fenetre::fonctionCarron()
{
    //Teinte = 240; Saturation = 255; Luminance = 0;
    //traitement par teinte

    // traitement image Nicolas
        double maxC1,minC1,Teinte1,Luminance1,Saturation1,distance;

        image = imread(fichierstd);
        //Mat imageC1;
        IplImage *image2 = cvLoadImage(fichierstd.c_str());
        IplImage* hls = cvCloneImage(image2);
        cvCvtColor(image2, hls, CV_BGR2HLS);
        cvtColor( image, imageC1, CV_BGR2GRAY );
        cvtColor( image, imageC2, CV_BGR2GRAY );
        cvtColor( image, imageC3, CV_BGR2GRAY );
        double pi = 3.14159265358979323846;
        int i,j;
        CvScalar pixel;
        //////////////////

        //int TeinteRef=0;
        double rate = 0.07;
        int offset = 50;
        //calcule distance de teinte
        maxC1 = 0;minC1 =maxC1;//3
        double A0 = ((pi/2)+atan(rate*(Saturation-offset)))/pi;
        double A;


        for ( i=0; i<image.rows; i++)
          {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];
                 Luminance1 = pixel.val[1];
                 Saturation1 = pixel.val[2];

                 A = ((pi/2)+atan(rate*(Saturation1-offset)))/pi;
                 double alpha = sqrt(A0*A);
                 distance = alpha*min(abs(Teinte1-Teinte),(1-abs(Teinte1-Teinte)))+(1-alpha)*abs(Luminance1-Luminance);

                 if (distance>maxC1)
                 {
                     maxC1 = distance;
                 }
                 if (distance<minC1)
                 {
                     minC1 = distance;
                 }
             }
        }

        for ( i=0; i<image.rows; i++)
           {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];
                 Luminance1 = pixel.val[1];
                 Saturation1 = pixel.val[2];

                 A = ((pi/2)+atan(rate*(Saturation1-offset)))/pi;
                 double alpha = sqrt(A0*A);

                 distance = alpha*min(abs(Teinte1-Teinte),(1-abs(Teinte1-Teinte)))+(1-alpha)*abs(Luminance1-Luminance);
                 imageC1.at<uchar>(i,j) = 255*(distance-minC1)/(maxC1-minC1);
             }
        }
        traitement = true;
}
