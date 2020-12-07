#include <iostream>
#include <string>
#include<fstream>
#include<locale.h>

#define M 30

using namespace std;

void escribir();
void lectura();


struct libroaux{
	string nombre_libro1; // Nombre del libro
	int a_estreno1; // Año de estreno
	int pag1; // Cantidad de paginas del libro
	string genero1; // Genero del libro
	int premios_ganados1; //Cantidad de premios ganados
	libroaux *sig_libro1; // Puntero del siguiente libro
};


struct nodoaux{
	string autor1; // Nombre del autor
	int a_n1; // Año de nacimiento
	int a_m1; // Año de fallecimiento (en caso de seguir vivo  poner 0).
	string libro_destacado1; // Nombre de su libro mas destacado.
	int libros_a1;
	nodoaux *sig1; // Puntero al siguiente autor
	libroaux *sub1; // Puntero a los libros del autor. 
};


struct libro{
	string nombre_libro; // Nombre del libro
	int a_estreno; // Año de estreno
	int pag; // Cantidad de paginas del libro
	string genero; // Genero del libro
	int premios_ganados; //Cantidad de premios ganados
	libro *sig_libro; // Puntero del siguiente libro
};

struct nodo{
	string autor; // Nombre del autor
	int a_n; // Año de nacimiento
	int a_m; // Año de fallecimiento (en caso de seguir vivo  poner 0).
	string libro_destacado; // Nombre de su libro mas destacado.
	int libros_a;
	nodo *sig; // Puntero al siguiente autor
	libro *sub; // Puntero a los libros del autor. 
};

class lista{
	private:
		nodo *h;
	public:
		lista();
		~lista();
		void i_autor(string autor,int a_n,int a_m,string libro_destacado,int libros_a); // Ingresar autor a la lista  -xxx
		void e_autor(string autor); // Eliminar autor de la lista -xx-
		void i_libro(string n_libro,int a_estreno,int pag, string genero,int p_ganados); // Ingresar un libro a la lista -xx-
		void e_libro(string autor,string n_libro); // Eliminar un libro de la lista -xx-
		void m_autores(); // mostrar a todos los autores -xx-
		void m_libros(string autor); // Mostrar todos los libros de un autor y el mismo autor. -xx-
};
void salida_a(nodo *q);
void salida_l(libro *q);


lista::lista(){
	h = NULL;
}

lista::~lista(){
	//Funcion destructora de los nodos

}

void lista::i_autor(string autor,int a_n,int a_m,string libro_destacado,int libros_a){
	nodo *q,* r;
	q->autor=autor;
	q->a_n = a_n;
	q->a_m = a_m;
	q->libro_destacado=libro_destacado; 
	q->libros_a = libros_a;
	q->sig = h;
	if(!h)
		h = q;
	else
	{
		r = h;
		while (r->sig)
		{
			r = r->sig;
		}
		
		r->sig = q;
		q->sig = NULL;
	}
}

void lista::e_autor(string autor){
	//Funcion que elimina un autor y todos sus libros de la lista;
	//A esta funcion le llega el nombre del autor el cual se va a eliminar

}

void lista::i_libro(string n_libro,int a_estreno,int pag, string genero,int p_ganados){
//Ingreso de los libros como sub lista comprobando si pertenecen al autor
	libro *q,* r;
	nodo *c;
	q->nombre_libro=n_libro;
	q->a_estreno = a_estreno;
	q->pag = pag;
	q->genero=genero; 
	q->premios_ganados = p_ganados;
	q->sig_libro = q;
	c->sub = q;
	if(h->sub)
		h->sub = q;
	else
	{
		r = q;
		while (r->sig_libro)
		{
			r = r->sig_libro;
		}
		
		r->sig_libro = q;
		q->sig_libro = NULL;
	}
}


void lista::e_libro(string autor, string n_libro){
	//Funcion que elimina un libro de un autor en especifico
	//Esta funcion necesita 2 parametros el nombre del autor del libr y el nombre del libro a eliminar

}

void lista::m_autores(){
//funcion que muestra a todos los autores.
	nodo *q;
    q = h;
    while (q)
    {
        salida_a(q);
        q = q->sig;
    }
}

void lista::m_libros(string autor){
//Funcion que muestra todos los libros de un autor.
//A esta funcion le llega el valor del autor que se quiere mostrar

}
 void escribir(){
	 //Esta funcion es la que escribe los datos ingresados a un archivo binario.
	libroaux y;
	nodoaux x;
	ofstream arch;
	int i = 0,total=0,j=0;
	arch.open("libros.txt");
	cout<<"Cuantos autores va a ingresar?: ";
	cin>>total;
	while(j < total){
		cout<<"Ingrese un autor: ";
		getline(cin,x.autor1,'\n');
		getline(cin,x.autor1,'\n');
		cout<<"Ingrese el año de nacimiento: ";
		cin>>x.a_n1;
		cout<<"ingrese el año de fallecimiento (en caso de que siga vivo introduzca 0)";
		cin>>x.a_m1;
		cout<<"Ingrese su libro mas destacado: ";
		//cin.ignore(); elimina la primera letra de la palabra
		getline(cin,x.libro_destacado1,'\n');
		getline(cin,x.libro_destacado1,'\n');
		cout<<"Ingrese cuantos libros del autor va a ingresar: ";
		cin>>x.libros_a1;
			if(x.libros_a1 != -1)
				arch.write((char *)(&x),sizeof(nodoaux));
		cout<<"---------------------------------------------"<<endl;
		j++;
		 while(i < x.libros_a1){
			cout<<"Ingrese el nombre del libro del autor: ";
			getline(cin,y.nombre_libro1, '\n');
			getline(cin,y.nombre_libro1, '\n');
			cout<<"Ingrese el año de estreno del libro: ";
			cin>>y.a_estreno1;	 
			cout<<"Ingrese la cantidad de paginas del libro: ";
			cin>>y.pag1;
			cout<<"Ingrere el genero del libro: ";
			getline(cin,y.genero1,'\n');
			getline(cin,y.genero1,'\n');
			cout<<"Ingrese los premios ganados: ";
			cin>>y.premios_ganados1;
			if(y.premios_ganados1 != -1)
				arch.write((char *)(&y),sizeof(libroaux));
			i++;
			cout<<"---------------------------------------------"<<endl;
	}
 }
 	arch.close();
}

void lectura(){
	//Esta funcion lee los datos de un archivo binario y los ingresa a la lista de autores y libros segun corresponda
	lista L;
	nodoaux x;
	libroaux y;
	ifstream arch_lee;
	int cant,ch;
	string autor;
	arch_lee.open("libros.txt");
	while(!arch_lee.eof()){
		arch_lee.read((char *)(&x),sizeof(nodoaux));
		//if(arch_lee.eof())
		//	break;
		L.i_autor(x.autor1,x.a_n1,x.a_m1,x.libro_destacado1,x.libros_a1);
		cin>>cant;
		for(int i = 0; i < cant ; i++){
			arch_lee.read((char *)(&y),sizeof(libroaux));
			L.i_libro(y.nombre_libro1,y.a_estreno1,y.pag1,y.genero1,y.premios_ganados1);
		}
	}
	arch_lee.close();
	cout<<"Que desea ver? "<<endl;
	cout<<"1.-AUTORES ( presione 1 )          2.- LIBROS DE UN AUTOR( presione 2 )         3.-SALIR( presione 3 )"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			L.m_autores();
			break;
		case 2:
			cout<<"Ingrese el apellido del autor del cual quiere ver los libros: ";
			getline(cin,autor,'\n');
			L.m_libros(autor);
			break;
		case 3:
			cout<<"\nPrograma Terminado"<<endl;
			break;
		default:
			cout<<"OPCION NO VALIDA "<<endl;
			break;
			}
}

void salida_a(nodo *q){
	cout << q->autor<< endl;
    cout << q->a_n<< endl;
    cout << q->a_m << endl;
	cout << q->libro_destacado << endl;
	cout<<"---------------------------------------------"<<endl;
}

void salida_l(libro *q){
	cout << q->nombre_libro<< endl;
    cout << q->a_estreno<< endl;
    cout << q->pag << endl;
	cout << q->genero << endl;
	cout << q->premios_ganados << endl;
	cout<<"---------------------------------------------"<<endl;
}


int main(){

     int ch, ch2;
	 lista L;
     setlocale(LC_ALL, "es_ES");

    cout<<"\n\tEste programa crea listas con autores y sub listas con los libros de los autores, estos datos se obtinen de un archivo bianrio."<<endl;
    do
    {
        cout<<"\nTiene un archivo Binario?"<<endl;
        cout <<"1.-SI ( presione 1 )          2.- NO( presione 2 )         3.-SALIR( presione 3 )"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            /* Leer el archivo Binario */
			lectura();
            break;
        case 2:
            cout<<"Desea crear un archivo Binario?"<<endl;
            cout <<"1.-SI ( presione 1 )          2.- NO( presione 2 )        3.-SALIR( presione 3 )"<<endl;
            cin>>ch2;
            switch (ch2)
            {
            case 1:
                escribir();
                break;
            case 2:
                /* code */
                break;
            case 3:
                cout<<"\nPrograma Terminado"<<endl;
                system("pause");
                return 0;
                break;
            
            default:
            cout<<"OPCION NO VALIDA "<<endl;
            system("pause");
            return 0;
                break;
            }

            break;
			case 3:
				cout<<"\nPrograma Terminado"<<endl;
                system("pause");
                return 0;
				break;
        default:
            cout<<"OPCION NO VALIDA "<<endl;
            system("pause");
            return 0;
            break;
        }
        
    } while (ch != 3);
    
    cout<<"Saliendo del programa"<<endl;
    system("pause");

}