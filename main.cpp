#include <iostream>
#include <fstream>
using namespace std;
//FUNCIONES
void escribir();
void leer();
int menu(int );

int main()
{
  int op,x;

   do{
   switch (menu(op))
   {
    case 1:
    escribir();
    system("read -p 'Presiona Enter para continuar...' var"); 
    break;
    case 2:
    leer();
    system("read -p 'Presiona Enter para continuar...' var"); 
    break;
    case 3:
    cout<<"------GRACIAS-----\n";
      x=3;
      system("read -p 'Presiona Enter para continuar...' var"); 
    break;
   }
system("clear");
  }while(x !=3);
  return 0;

}

//FUNCION MENU
int menu(int op)
{
  op= -1;
  while((op< 0) || (op>3)) 
  {
    cout<<"***************************"<<endl;
    cout<<"*  1- INGRESAR DATOS      *" << endl;
    cout<<"*  2- LEER DATOS          *" << endl;
    cout<<"*  3- SALIR               *" << endl;
    cout<<"***************************"<<endl;
    cout<<"Digite la opción: ";
    cin>>op;
    if((op< 0) || (op> 3)) 
    {
      cout << "Opción no válida" << endl;
    }
  }
  return op;
}

//FUNCION ESCRIBIR
void escribir()
{
  ofstream archivoUno;
  string nombreArchivo;
  string nombre;
  string apellido;
  char r; 
  int e;
    cout<<"INGRESA EL NOMBRE DEL ARCHIVO: ";
    cin.ignore();
    getline(cin,nombreArchivo);

    archivoUno.open(nombreArchivo.c_str(),ios::app);
      do
    {
        cout<<"\tINGRESE EL NOMBRE: ";
        getline(cin,nombre,'\n');

        cout<<"\tINGRESE EL APELLIDO: ";
        getline(cin,apellido,'\n');

        cout<<"\tINGRESA LA EDAD:";
        cin>>e;

        archivoUno<<nombre<<" "<<apellido<<" "<<e<<"\n";
        cout<<"DESEA AGREGAR OTRO CONTACTO s/n: ";
        cin>>r;
        cin.ignore();

    }while(r=='s');
  archivoUno.close();
}

//FUNCION LEER
void leer()
{
    ifstream archivoLectura ("hola.txt");
    string texto;
    string nombre;
    string apellido;
     int e;
        while(!archivoLectura.eof())
        {
            archivoLectura>>nombre>>apellido>>e;
            if (!archivoLectura.fail())
                {
                    getline(archivoLectura,texto);
                    cout<<"**********************"<<endl;
                    cout<<"El nombre es: "<<nombre<<endl;
                    cout<<"El apellido es: "<<apellido<<endl;
                    cout<<"La edad es: "<<e<<endl;
                    cout<<"**********************"<<endl;
                }
        }
    archivoLectura.close();
    
}

