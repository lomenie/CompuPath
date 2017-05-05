#include "fonction.h"
#include <QTextStream>
double Teinte = 0;double Luminance = 0;double Saturation = 0;double Rouge = 0;double Vert = 0;double Bleu = 0;
Mat image,imageC1,imageC2;
string fichierstd;
bool traitement = false;
int nbCourbe = 0;
vector<vector<int> > TabCourbeMoy;
vector<vector<int> > TabCourbeMoy2;


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
    bouton7 = new QPushButton("Cytomine", this);
    bouton7->setGeometry(750, 260, 110, 30);
    bouton7->setToolTip("Texte d'aide");
    bouton7->setFont(QFont("Comic Sans MS", 8, QFont::Bold, true));
    bouton7->setCursor(Qt::PointingHandCursor);

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
    onglets->addTab(page4, "Courbe");
    onglets->addTab(page6, "Courbe Lissée");
    /////////////////////////////////////////////////////////////////////////

    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(bouton4, SIGNAL(clicked()), this, SLOT(ouvrirDialogueChoisir()));
    QObject::connect(bouton5, SIGNAL(clicked()), this, SLOT(selectionPixel()));
    QObject::connect(bouton6, SIGNAL(clicked()), this, SLOT(selectionMarqueur()));
    QObject::connect(bouton7, SIGNAL(clicked()), this, SLOT(imageCytomine()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), lcd,SLOT(display(int)));
    QObject::connect(bouton2, SIGNAL(clicked()), this,SLOT(courbes()));
    QObject::connect(bouton1, SIGNAL(clicked()), this,SLOT(seuillage()));
  //  QObject::connect(slider, SIGNAL(valueChanged(int)), this,SLOT(seuillage(int))) ;
//    QObject::connect(cocheseuil, SIGNAL(toggled(bool)), this,SLOT(seuillage(bool))) ;
}
//////////////////////////////////////////
//////////////////////////////////////////
void Fenetre::imageCytomine()
{
    string ligne,mot;
    double coord;//recupère les coordonnées annotation
    int taille,i,term; int premier = 0;
    bool ok;
    double demipatch;// = 3040/2; //longueur patch 1mm = 3040 pixels
    int TermFront = 4903197;//2 recherche par Term
    vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image

  int idImage = QInputDialog::getInt(this,tr("Integer"),tr("Entrer Id Image :"),3452832,0,100000000,1,&ok );
  string idimage = "python /home/djiro/spyder/djiro/client/examples/get_Front_Cord.py "+to_string(idImage);
  system(idimage.c_str());

 // system("python /home/djiro/spyder/djiro/client/examples/get_Front_Cord.py");
  ifstream fichier("/home/djiro/annotations/fichier.txt");//où le fichier texte est enregistré

       if(fichier)
       {
            int value = QInputDialog::getInt(this,tr("Integer"),tr("Entrer longueur patch en µm:"),1000,5,4000,1,&ok );
            demipatch = value*3040/2000;//calcule la demilongueur du patch

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

                    while(fichier2 >> coord)
                      {

                        TabImage.push_back(vector<double>(2));
                        TabImage[taille][0]=coord;

                        fichier2 >> coord;
                        TabImage[taille][1]=coord;

                        taille+=1;
                      }

                    //pour chaque segment du Front trouver les coordonnées du path

                    for (i=1;i<taille; i++)
                    {
                     //   cout<< TabImage[i][0]; cout<<" "; cout<<TabImage[i][1] <<endl;

                        double a,b,c,x1,x2,x3,x4,y1,y2,y3,y4;
                        int X1,X2,X3,X4,Y1,Y2,Y3,Y4;
                        a=1;
                        b=(-2*TabImage[i-1][0]);
                        c=pow(TabImage[i-1][0],2)-(pow(demipatch,2)*pow((TabImage[i-1][1]-TabImage[i][1]),2)/(pow((TabImage[i-1][1]-TabImage[i][1]),2)+pow((TabImage[i-1][0]-TabImage[i][0]),2)));
                        x1=(-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
                        x2=(-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);

                        a=1;
                        b=(-2*TabImage[i-1][1]);
                        c=pow(TabImage[i-1][1],2)-(pow(demipatch,2)*pow((TabImage[i-1][0]-TabImage[i][0]),2)/(pow((TabImage[i-1][0]-TabImage[i][0]),2)+pow((TabImage[i-1][1]-TabImage[i][1]),2)));
                        y1=(-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
                        y2=(-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);

                        //rechercher le Y correspondant à x1
                        int orthog = ((x1 - TabImage[i-1][0])*(TabImage[i][0]-TabImage[i-1][0]))+((y1-TabImage[i-1][1])*(TabImage[i][1]-TabImage[i-1][1]));
                        if(orthog == 0)
                        {
                            Y1 = y1;
                            Y2 = y2;
                        }
                        else
                        {
                            Y1 = y2;
                            Y2 = y1;
                        }

                        X1 = x1;
                        X2 = x2;


                        a=1;
                        b=(-2*TabImage[i][0]);
                        c=pow(TabImage[i][0],2)-(pow(demipatch,2)*pow((TabImage[i-1][1]-TabImage[i][1]),2)/(pow((TabImage[i-1][1]-TabImage[i][1]),2)+pow((TabImage[i-1][0]-TabImage[i][0]),2)));
                        x3=(-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
                        x4=(-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);

                        a=1;
                        b=(-2*TabImage[i][1]);
                        c=pow(TabImage[i][1],2)-(pow(demipatch,2)*pow((TabImage[i-1][0]-TabImage[i][0]),2)/(pow((TabImage[i-1][0]-TabImage[i][0]),2)+pow((TabImage[i-1][1]-TabImage[i][1]),2)));
                        y3=(-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
                        y4=(-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);

                        orthog = ((x4 - TabImage[i][0])*(TabImage[i-1][0]-TabImage[i][0]))+((y4-TabImage[i][1])*(TabImage[i-1][1]-TabImage[i][1]));
                        if(orthog == 0)
                        {
                            Y4 = y4;
                            Y3 = y3;
                        }
                        else
                        {
                            Y4 = y3;
                            Y3 = y4;
                        }  // maxC1 = 255-((255*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));minC1 =maxC1;//3

                        X4 = x4;
                        X3 = x3;

                        string commande = "python /home/djiro/spyder/djiro/client/examples/create_annotation.py "+to_string(idImage)+" "+to_string(X1)+" "+to_string(Y1)+" "+to_string(X2)+" "+to_string(Y2)+" "+to_string(X4)+" "+to_string(Y4)+" "+to_string(X3)+" "+to_string(Y3);
                        system(commande.c_str());

                        idimage = "python /home/djiro/spyder/djiro/client/examples/get_annotations.py "+to_string(idImage);
                        system(idimage.c_str());

                        //////////////////
                        idimage = "python /home/djiro/spyder/djiro/client/examples/delete_annotations.py "+to_string(idImage);
                        system(idimage.c_str());
                        /////////////////

                        ////////////////////////////////
                        //////////////////
                        //ouverture des images
                        ifstream fichier3("/home/djiro/annotations/fichier.txt");
                        if(fichier3)
                        {

                           //  while(getline(fichier3, ligne)) //traiter les images les unes après les autres
                             {
                                 /*
                                 ofstream fichier1("/home/djiro/annotations/fichier1.txt");
                                 fichier1 <<ligne;
                                 fichier1.close();

                                 //retrouver les coordonnées du polygone image selectionné dans le texte
                                 ifstream fichier2("/home/djiro/annotations/fichier1.txt");
                                 fichier2 >> mot;//1,2 */

                                 fichier3 >> mot;

                                 fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";//1 Recherche par Nom
                                 nomFichier = QString::fromStdString(fichierstd);

                                     IplImage *imag = cvLoadImage(fichierstd.c_str());
                                     cvSaveImage("imageOrig.bmp",imag);
                                     cvSaveImage(fichierstd.c_str(),imag);

                                     //rotation
                                     Mat orig_image = imread(fichierstd.c_str(),1);

                                     if (abs(TabImage[i][0]-TabImage[i-1][0])<abs(TabImage[i][1]-TabImage[i-1][1]))
                                     {
                                         if ((TabImage[i][1]-TabImage[i-1][1])>0)
                                         {
                                             fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";
                                             rotation180(orig_image);
                                         }
                                     }

                                     if (abs(TabImage[i][0]-TabImage[i-1][0])>abs(TabImage[i][1]-TabImage[i-1][1]))
                                     {
                                         if ((TabImage[i][0]-TabImage[i-1][0])>0)
                                         {
                                             fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";
                                             rotationM90(orig_image);
                                         }
                                         if ((TabImage[i][0]-TabImage[i-1][0])<0)
                                         {
                                             fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";
                                             rotation90(orig_image);
                                         }
                                     }

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

                                  //   selectionMarqueur();
                                     Traitement();
                                     courbes();
                             }
                             fichier3.close();
                        }

                    }

                    //courbe moyenne
              /*      for (int i=0; i<TabCourbeMoy.size();i++)
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
                        if (nbSomme == nbCourbe)
                        {
                            TabCourbeMoy2.push_back(vector<int>(2));
                            TabCourbeMoy2[TabCourbeMoy2.size()-1][0]=TabCourbeMoy[i][0];
                            TabCourbeMoy2[TabCourbeMoy2.size()-1][1]=TabCourbeMoy[i][1];
                        }
                    }

                    for (int i=0; i<TabCourbeMoy.size()-1; i++)//pour ordonner le tableau
                    {
                        for (int j=i+1; j<TabCourbeMoy.size();j++)
                        {
                            if (TabCourbeMoy[i][0] > TabCourbeMoy[j][0])
                            {
                                int tampX, tampY;
                                tampX = TabCourbeMoy[i][0];
                                tampY = TabCourbeMoy[i][1];
                                TabCourbeMoy[i][0] = TabCourbeMoy[j][0];
                                TabCourbeMoy[i][1] = TabCourbeMoy[j][1];
                                TabCourbeMoy[j][0] = tampX;
                                TabCourbeMoy[j][1] = tampY;
                            }
                        }
                    }

                    ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
                    ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
                    ofstream fichier4("/home/djiro/annotations/fichierCourbeY.txt");

                    for (int i=0;i<TabCourbeMoy2.size();i++)
                    {
                        fichier1 << TabCourbeMoy2[i][0]; fichier1 << " "; fichier1 << TabCourbeMoy2[i][1] << endl;
                        fichier2 << TabCourbeMoy2[i][0] << endl;
                        fichier4 << TabCourbeMoy2[i][1] << endl;
                    }
                    fichier1.close();fichier2.close();fichier4.close();
                    system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
                   // waitKey(0);
                    page4->setPixmap(QPixmap("/home/djiro/annotations/Courbe.png"));
                    page4->setScaledContents(true);
                    page4->adjustSize();
*/
                    ///////////////////////

                }

                fichier2.close();
            }
            fichier.close();

   }

       else
       {
       cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
       }
      ////////////////////////////////////////////////////////////////////
       ///////////////////////////////////////////////////////////////////
       /*
  //ouverture des images
  ifstream fichier3("/home/djiro/annotations/fichier.txt");
  if(fichier3)
  {

       while(getline(fichier3, ligne)) //traiter les images les unes après les autres
       {
           ofstream fichier1("/home/djiro/annotations/fichier1.txt");
           fichier1 <<ligne;
           fichier1.close();

           //retrouver les coordonnées du polygone image selectionné dans le texte
           ifstream fichier2("/home/djiro/annotations/fichier1.txt");
           fichier2 >> mot;//1,2

           fichierstd= "/home/djiro/annotations/3478753/"+mot+".png";//1 Recherche par Nom
           string am = "/home/djiro/annotations/3478753/"+mot+".bmp";
           nomFichier = QString::fromStdString(fichierstd);

               IplImage *imag = cvLoadImage(fichierstd.c_str());
               cvSaveImage("imageOrig.bmp",imag);
/////////
              // string maman = "/home/djiro/annotations/3478753/"+mot+".bmp";
               cvSaveImage(am.c_str(),imag);
             //  cvSaveImage(maman.c_str(),imag);
/////////
              // page1->setPixmap(QPixmap(fichierstd.c_str()));
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

               selectionMarqueur();
           //    courbes();

           fichier2.close();
          //traitemement de l'image: selection pixel ou Marqueur
          // selectionMarqueur();

            waitKey(0);
       }
       fichier3.close();
  }

  else
  {
  cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
  }
*/
//////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
}

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
  /*
              //contours
                medianBlur(imageC1,imageC2,3);
                //dilate(imageC2,imageC2,element);
                Canny(imageC2,imageC2,10,350);
                //erode (imageC2,imageC2,element); */

          //imshow( "canny", imageC2);
         imwrite( "canny.bmp", imageC2 );
         page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/canny.bmp"));
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

        cout<< imageC1.rows; cout << " "; cout << imageC1.cols <<endl;

        imwrite( "imageC1.bmp", imageC1 );
        page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
        page2->setScaledContents(true);
        page2->adjustSize();
        /////////////////////////////////////////////////////////
        // Create a structuring element
              int erosion_size = 1;
              Mat element = getStructuringElement(cv::MORPH_CROSS,
                     cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                     cv::Point(-1, -1) );

        //detection contoures
            //noyaux

              medianBlur(imageC1,imageC2,5);
              Canny(imageC2,imageC2,10,350);
/*
            //contours
              medianBlur(imageC1,imageC2,3);
              //dilate(imageC2,imageC2,element);
              Canny(imageC2,imageC2,10,350);
              //erode (imageC2,imageC2,element); */

        //imshow( "canny", imageC2);
       imwrite( "canny.bmp", imageC2 );
       page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/canny.bmp"));
       page3->setScaledContents(true);
       page3->adjustSize();
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

        cout<< imageC1.rows; cout << " "; cout << imageC1.cols <<endl;

        imwrite( "imageC1.bmp", imageC1 );
        page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
        page2->setScaledContents(true);
        page2->adjustSize();
        /////////////////////////////////////////////////////////
        // Create a structuring element
              int erosion_size = 1;
              Mat element = getStructuringElement(cv::MORPH_CROSS,
                     cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                     cv::Point(-1, -1) );

        //detection contoures
            //noyaux

              medianBlur(imageC1,imageC2,5);
              Canny(imageC2,imageC2,10,350);
/*
            //contours
              medianBlur(imageC1,imageC2,3);
              //dilate(imageC2,imageC2,element);
              Canny(imageC2,imageC2,10,350);
              //erode (imageC2,imageC2,element); */

        //imshow( "canny", imageC2);
       imwrite( "canny.bmp", imageC2 );
       page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/canny.bmp"));
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
/*
           //contours
             medianBlur(imageC1,imageC2,3);
             //dilate(imageC2,imageC2,element);
             Canny(imageC2,imageC2,10,350);
             //erode (imageC2,imageC2,element);*/

       //imshow( "canny", imageC2);
      imwrite( "canny.bmp", imageC2 );
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
        vector<double> TabCourbe;
        //recuperer le nombre de pixels du marqueur par bandelette de 5um(15pixels)car 1mm = 3040pixels
        int pixelMarq=0;int nbcols = 0;
        for (int j=0; j<imageC2.cols; j++)
           {
             nbcols +=1;
             for (int i=0; i<imageC2.rows; i++)
             {
                 if(imageC2.at<uchar>(i,j)>127)
                 {
                     pixelMarq += 1;
                 }

             }

            // if (nbcols == 15)//si on a 15 cols == 5 um
               if (((j+1)%15)==0)//à chaque bandelette de 5 um créer cellule tableauCourbe et y insérer le nb objets biologique détecté
             {
                 TabCourbe.push_back(pixelMarq);//conserve nb pixels marqueurs
               //  TabCourbe.push_back(pixelMarq/(nbcols*imageC2.rows));//conserve le nb pixels marqueurs/surface tranche analysée
                 pixelMarq = 0;
                 nbcols = 0;

             }

           }
        /*
        if (pixelMarq!=0 || nbcols != 0)
        {
            TabCourbe.push_back(pixelMarq);//la bandelette restante n'atteingnant pas les 5 um
          //  TabCourbe.push_back(pixelMarq/(nbcols*imageC2.rows));
            pixelMarq = 0;
            nbcols = 0;
        }*/

         int x = -ceil((TabCourbe.size()-1)/2);
         ofstream fichier1("/home/djiro/annotations/fichierCourbe.txt");
         ofstream fichier2("/home/djiro/annotations/fichierCourbeX.txt");
         ofstream fichier3("/home/djiro/annotations/fichierCourbeY.txt");

         for (int i=0;i<TabCourbe.size();i++)
         {
             fichier1 << x; fichier1 << " "; fichier1 << TabCourbe[i] << endl;
             fichier2 << x << endl;
             fichier3 << TabCourbe[i] << endl;
             TabCourbeMoy.push_back(vector<int>(2));//ajoute tout les points des courbes afin de les trier
             TabCourbeMoy[TabCourbeMoy.size()-1][0]=x;
             TabCourbeMoy[TabCourbeMoy.size()-1][1]=TabCourbe[i];
             nbCourbe += 1;
             x += 1;
         }
         fichier1.close();fichier2.close();fichier3.close();
         system("python /home/djiro/spyder/djiro/client/examples/courbe.py");
        // waitKey(0);
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
/*
void Fenetre::fonctionNicolas()
{
    // traitement image Nicolas
        double maxC1,minC1,Teinte1,delta,distance,e;

        image = imread(fichierstd);
        //Mat imageC1;
        IplImage *image2 = cvLoadImage(fichierstd.c_str());
        IplImage* hls = cvCloneImage(image2);
        cvCvtColor(image2, hls, CV_BGR2HLS);
        cvtColor( image, imageC1, CV_BGR2GRAY );
        cvtColor( image, imageC2, CV_BGR2GRAY );
        double pi = 3.14159265358979323846;
        int i,j;
        CvScalar pixel;
        //////////////////
        e=0.001;

        int TeinteRef=Teinte;
        //calcule distance de teinte
          maxC1 =0;minC1 =0;//1

        for ( i=0; i<image.rows; i++)
          {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];

                 delta = abs(Teinte1-TeinteRef)*2*pi/360;
                 distance =1-exp((cos(delta)-1)/(cos(delta)+1+e));//1

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

                delta = abs(Teinte1-TeinteRef)*2*pi/360;
                distance =1-exp((cos(delta)-1)/(cos(delta)+1+e));//1
                imageC1.at<uchar>(i,j) = 255*(distance-minC1)/(maxC1-minC1);

             }
        }
        /*
        imwrite( "imageC1.bmp", imageC1 );
        page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
        page2->setScaledContents(true);
        page2->adjustSize();
}*/

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

void Fenetre::rotation90(Mat& image)
{
    Mat rotated_img(Size(image.rows, image.cols), image.type());
    int i,j;
   // Vec3b intensity;
    for ( i=0; i<image.rows; i++)
       {
         for ( j=0; j<image.cols; j++)
         {
             rotated_img.at<Vec3b>((image.cols-1-j),i) = image.at<Vec3b>(i,j);

         }
       }
    imwrite(fichierstd.c_str(), rotated_img);

}

void Fenetre::rotation180(Mat& image)
{
    Mat rotated_img(Size(image.cols, image.rows), image.type());
    int i,j;
   // Vec3b intensity;
    for ( i=0; i<image.rows; i++)
       {
         for ( j=0; j<image.cols; j++)
         {
             rotated_img.at<Vec3b>((image.rows-1-i),(image.cols-1-j)) = image.at<Vec3b>(i, j);

         }
       }
    imwrite(fichierstd.c_str(), rotated_img);

}

void Fenetre::rotationM90(Mat& image)
{
    Mat rotated_img(Size(image.rows, image.cols), image.type());
    int i,j;
   // Vec3b intensity;
    for ( i=0; i<image.rows; i++)
       {
         for ( j=0; j<image.cols; j++)
         {
             rotated_img.at<Vec3b>(j,(image.rows-1-i)) = image.at<Vec3b>(i, j);

         }
       }
    imwrite(fichierstd.c_str(), rotated_img);

}
