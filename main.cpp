#include "fonction.h"


int main(int argc, char *argv[])
{
//interface graphique
///////////////////////////////////////////////////////////////////////
QApplication app(argc, argv);
Fenetre fenetre;
fenetre.show();
return app.exec();

//waitKey(0);
//return 0;
}
