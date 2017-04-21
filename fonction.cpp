#include "fonction.h"
#include <QTextStream>
double Teinte = 0;double Luminance = 0;double Saturation = 0;double Rouge = 1;double Vert = 0;double Bleu = 0;
Mat image,imageC1,imageC2;
string fichierstd;


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
    /////////////////////////////////////////////////////////////////////////

    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(bouton4, SIGNAL(clicked()), this, SLOT(ouvrirDialogueChoisir()));
    QObject::connect(bouton5, SIGNAL(clicked()), this, SLOT(selectionPixel()));
    QObject::connect(bouton6, SIGNAL(clicked()), this, SLOT(selectionMarqueur()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), lcd,SLOT(display(int))) ;
    QObject::connect(slider, SIGNAL(valueChanged(int)), this,SLOT(seuillage(int))) ;
//    QObject::connect(cocheseuil, SIGNAL(toggled(bool)), this,SLOT(seuillage(bool))) ;
}

void Fenetre::ouvrirDialogueChoisir()
{
   nomFichier = "";marqueur = "";
   nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier",QString(), "Images (*.tif *.bmp *.png *.gif *.jpg *.jpeg)");

   if(!nomFichier.isNull())
   {
       ///////////////////////////////////////////////
       fichierstd = nomFichier.toStdString();
       IplImage *imag = cvLoadImage(fichierstd.c_str());
       cvSaveImage("imageOrig.bmp",imag);

    // page1->setPixmap(QPixmap(nomFichier));//n'affiche pas les fichiers .tif
       page1->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageOrig.bmp"));
       page1->setScaledContents(true);
       page1->adjustSize();

  ////////////////////////////////////////////////////

       ifstream fichier("/home/djiro/annotations/fichier.txt");//où le fichier texte est enregistré
       if(fichier)
       {
            string ligne,mot;
            double coord;//recupère les coordonnées annotation
            int taille,i;
            int TermFront;//2 recherche par Term
            vector<vector<double> > TabImage;//1 tableau des coordonnées du polygone image
            //vector<vector<double> > TabFront;//2 tableau des coordonnées du polygone front tumoral

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
                fichier2 >> mot;//1
                //fichier2 >> mot;//2

                if (fichierstd=="/home/djiro/annotations/3478753/"+mot+".png")//1 Recherche par Nom
               // if (TermFront ==mot)//2 Recherche par Term
                {
                    fichier2 >> mot;//1
                    fichier2 >> mot;//a partir d'ici, remplir le tableau
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
/*
                    //verifier le tableau sur le terminal
                    for (i=0; i<taille;i++)
                    {
                        cout << TabImage[i][0]; cout << "  "; cout<< TabImage[i][1]<<endl;
                    }
*/
                }

                fichier2.close();
            }
            fichier.close();
       }

       else
       {
       cout << "ERREUR: Impossible d'ouvrir le fichier en lecture."<< endl;
       }
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
        string fichierstd = nomFichier.toStdString();
        Mat img = imread(fichierstd);
        namedWindow("Choix Pixel", 1);
        setMouseCallback("Choix Pixel", mouseEvent, &img);
        imshow("Choix Pixel", img);
        waitKey(0);
        destroyWindow("Choix Pixel");
int choix =3;
        //traitement image puis affichage dans page2
        lcd1->display(Rouge);
        lcd2->display(Vert);
        lcd3->display(Bleu);
        lcd4->display(Teinte);
        lcd5->display(Saturation);
        lcd6->display(Luminance);
        //////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////
      if (choix==1)
      {
          fonctionNicolas();
      }
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
        /////////////////////////////////
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
        bool ok;
        QStringList items;
        items << "Rouge" << "Orange" << "Jaune" << "Vert" << "Cyan"<< "Bleu"<< "Violet"<< "Rose";
        marqueur = QInputDialog::getItem(this, "Seletion de Marqueur","Marqueurs:", items, 0, false, &ok);
        string itemstd = marqueur.toStdString();
        if (ok && !marqueur.isEmpty())
        string nomteinte = itemstd;
        string fichierstd = nomFichier.toStdString();
        Mat img = imread(fichierstd);
        //traitement image puis affichage dans page2
        // traitement image transformation couleur
            double maxC1,minC1,Teinte1,tampon,TRouge,TVert,TBleu;
            //Mat image = imread (fichierstd);
            image = imread (fichierstd);
            //Mat imageC1;
            IplImage *image2 = cvLoadImage(fichierstd.c_str());
            IplImage* hls = cvCloneImage(image2);
            cvCvtColor(image2, hls, CV_BGR2HLS);
            cvtColor( image, imageC1, CV_BGR2GRAY );
            cvtColor( image, imageC2, CV_BGR2GRAY );
            double pi = 3.14159265358979323846;
            int i,j;
            CvScalar pixel;
            pixel=cvGet2D(hls,0,0);
            Teinte = 2*pixel.val[0];
            Luminance = pixel.val[1];
            Saturation = pixel.val[2];

            //Teinte Rouge
        if (itemstd == "Rouge")
        {
                //initialisation du min max pour la normalisation
            TRouge =255*exp(((cos(Teinte*2*pi/360)-0.5)/0.5)-1);
            maxC1 = 255-((TRouge*Saturation*(255-Luminance))/(255*(Saturation+1)));minC1 = maxC1;
                //recherche du min max pour la normalisation
            for ( i=0; i<image.rows; i++)
              {
                 for ( j=0; j<image.cols; j++)
                 {
                     pixel=cvGet2D(hls,i,j);
                     Teinte1 = 2* pixel.val[0];
                     TRouge =255*exp(((cos(Teinte1*2*pi/360)-0.5)/0.5)-1);
                     tampon = 255-((TRouge*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));
                     if (tampon>maxC1)
                     {
                         maxC1 = tampon;
                     }
                     if (tampon<minC1)
                     {
                         minC1 = tampon;
                     }
                 }
            }
                //calcul de la transformation couleur normalisée
            for ( i=0; i<image.rows; i++)
               {
                 for ( j=0; j<image.cols; j++)
                 {
                    pixel=cvGet2D(hls,i,j);
                    Teinte1 = 2*pixel.val[0];
                    TRouge =255*exp(((cos(Teinte1*2*pi/360)-0.5)/0.5)-1);
                    tampon = 255-((TRouge*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));
                    imageC1.at<uchar>(i,j) = 255*(tampon-minC1)/(maxC1-minC1);

                 }
            }
           // imshow( "Rouge", imageC1);
            imwrite( "imageC1.bmp", imageC1 );
        }

        //Teinte Verte
        else if (itemstd == "Vert")
        {

        TVert = 255*exp(((-pow(Teinte,2)+(Teinte*240)-10800)/3600)-1);
        maxC1 = 255-((TVert*Saturation*(255-Luminance))/(255*(Saturation+1)));minC1 = maxC1;

        for ( i=0; i<image.rows; i++)
          {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];
                 TVert = 255*exp(((-pow(Teinte1,2)+(Teinte1*240)-10800)/3600)-1);
                 tampon = 255-((TVert*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));
                 if (tampon>maxC1)
                 {
                     maxC1 = tampon;
                 }
                 if (tampon<minC1)
                 {
                     minC1 = tampon;
                 }
             }
        }
        for ( i=0; i<image.rows; i++)
           {
             for ( j=0; j<image.cols; j++)
             {
                pixel=cvGet2D(hls,i,j);
                Teinte1 = 2*pixel.val[0];
                TVert = 255*exp(((-pow(Teinte1,2)+(Teinte1*240)-10800)/3600)-1);
                tampon = 255-((TVert*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));
                imageC1.at<uchar>(i,j) = 255*(tampon-minC1)/(maxC1-minC1);

             }
        }
        //imshow( "Vert", imageC1);
        imwrite( "imageC1.bmp", imageC1 );
        }

        //Teinte Bleu
        else if (itemstd == "Bleu")
        {

        TBleu = 255*exp(((-pow(Teinte,2)+(Teinte*480)-54000)/3600)-1);
        maxC1 = 255-((TBleu*Saturation*(255-Luminance))/(255*(Saturation+1)));minC1 = maxC1;

        for ( i=0; i<image.rows; i++)
          {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];
                 TBleu = 255*exp(((-pow(Teinte1,2)+(Teinte1*480)-54000)/3600)-1);
                 tampon = 255-((TBleu*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));
                 if (tampon>maxC1)
                 {
                     maxC1 = tampon;
                 }
                 if (tampon<minC1)
                 {
                     minC1 = tampon;
                 }
             }
        }
        for ( i=0; i<image.rows; i++)
           {
             for ( j=0; j<image.cols; j++)
             {
                pixel=cvGet2D(hls,i,j);
                Teinte1 = 2*pixel.val[0];
                TBleu = 255*exp(((-pow(Teinte1,2)+(Teinte1*480)-54000)/3600)-1);
                tampon = 255-((TBleu*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));
                imageC1.at<uchar>(i,j) = 255*(tampon-minC1)/(maxC1-minC1);
                tampon = 255*(tampon-minC1)/(maxC1-minC1);

             }
        }
        //imshow( "Bleu", imageC1);
        imwrite( "imageC1.bmp", imageC1 );
        }
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

////////////////////////////////////////////////////////////////////
    }
    else
    {
      QMessageBox::information( this, "Information"," Pas d'image sélectionnée ");
    }
}
/////////////////////////////////////////////////////////////////////////
//void Fenetre::seuillage(bool cocher)
void Fenetre::seuillage(int seuil)
{

  if(cocheseuil->isChecked())
 // if (cocher == true)
  {
   if(!nomFichier.isNull() && !marqueur.isNull())
   {

      // int seuil= lcd->intValue();
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

             medianBlur(imageseuil,imageseuil,5);
             Canny(imageseuil,imageseuil,10,350);
/*
           //contours
             medianBlur(imageC1,imageC2,3);
             //dilate(imageC2,imageC2,element);
             Canny(imageC2,imageC2,10,350);
             //erode (imageC2,imageC2,element);*/

       //imshow( "canny", imageC2);
      imwrite( "canny.bmp", imageseuil );
      page3->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/canny.bmp"));
      page3->setScaledContents(true);
      page3->adjustSize();

       ////////////////////
      // cvShowImage("image RGB",image2);
      // cvSaveImage("Image.bmp",image2);
   }
   else
   {
     QMessageBox::information( this, "Information"," Pas d'image ou de marqueur sélectionnée ");
   }
   }
}

void Fenetre::fonctionPrincipale()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << nomFichier;
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
          //  QLCDNumber lcd7(Fenetre::);
          //  lcd7.setSegmentStyle(QLCDNumber::Flat);
          //  lcd7.move(860, 110);
          //  lcd7.display(Luminance);

            //Fenetre::lcd1->display(Rouge);

            /*
            lcd1->display(Rouge);
            lcd2->display(Vert);
            lcd3->display(Bleu);
            lcd4.display(Teinte);
            lcd5.display(Saturation);
            lcd6.display(Luminance);*/
    }
}

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
        page2->adjustSize();*/
}

void Fenetre::fonctionNicolasArmand()
{
    //traitement par teinte

    // traitement image Nicolas
        double maxC1,minC1,Teinte1,distance,e;

        image = imread(fichierstd);
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
        //int TeinteRef=0;
        int TeinteRef=Teinte;
        //calcule distance de teinte
        maxC1 = 255-((255*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));minC1 =maxC1;//3


        for ( i=0; i<image.rows; i++)
          {
             for ( j=0; j<image.cols; j++)
             {
                 pixel=cvGet2D(hls,i,j);
                 Teinte1 = 2* pixel.val[0];

                 double delta = abs(Teinte1-TeinteRef)*2*pi/360;
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

                double delta = abs(Teinte1-TeinteRef)*2*pi/360;
                distance = 255*(exp((cos(delta)-1)/(cos(delta)+1+e)));//3
                distance = 255-((distance*pixel.val[2]*(255-pixel.val[1]))/(255*(pixel.val[2]+1)));//3
                imageC1.at<uchar>(i,j) = 255*(distance-minC1)/(maxC1-minC1);

             }
        }
/*
    imwrite( "imageC1.bmp", imageC1 );
    page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
    page2->setScaledContents(true);
    page2->adjustSize();*/
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
        int TeinteRef=Teinte;
        int luminanceRef=Luminance;
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
/*
                imwrite( "imageC1.bmp", imageC1 );
                page2->setPixmap(QPixmap("/home/djiro/build-Qt_teste-Sans_nom-Debug/imageC1.bmp"));
                page2->setScaledContents(true);
                page2->adjustSize();*/
             }
        }
}
