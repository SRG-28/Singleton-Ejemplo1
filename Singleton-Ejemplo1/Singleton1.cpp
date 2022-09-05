#include <iostream>
using namespace std;

class Singleton {
private:
	int valor; //lo que guarda el singleton
	static Singleton* mi_instancia; //variable, se crea un atributo de la misma clase
									// Las instancias static siempre deben ser inicializadas en el cpp ya que son variables globales...

	Singleton(int v = 0) {     //el constructor es privado...
		valor = v;
	}

public:
	void setValor(int v) {
		valor = v;
	}
	int getValor() {
		return valor;
	}
	//este metodo revisa si la instancia esta hecha o no
	//siempre se hace static
	static Singleton* getInstance() { //este metodo devulve el singleton
		if (mi_instancia == NULL) {  //si no exite mi_instancia, crea la nueva instancia y la retorna...
			mi_instancia = new Singleton;
			//REVISAR ESTO IMP.... ->PARA EL EXAMEN
			//atexit(& destroySingleton); //esto ayuda a destruir el Singleton   =====>Ya sirve pero da una EXCEPCION....

			//metodo que espera que uno se salga del programa para borrar el Singleton
		}
		return mi_instancia; //else... No lo crea porque ya existe solo lo retorna
	}

	static void destroySingleton() {
		if (mi_instancia != NULL)
			delete mi_instancia;
		cout << "Singleton destruido" << endl;
	}
};

        Singleton*  Singleton::mi_instancia = NULL;  //Puntero, estoy diciendo que la flecha vea a NULL ==> INICIALIZACION... 
		//IMP = TODAS LAS VARIABLES STATIC DEBEN SER INICIALIZADAS...
		//Mota = note que atexit recibe un puntero a una funcion 
		//sin parametros y que nada devuelve 
		//esta funcion se encarga de llamar a la funcion que se le pasa como parametro  al final del programa
		//si no se quiere utilizar atexit siemplemente se llama al metodo destroySingleton() al final del programa. 


//-------------------------------- MAIN ----------------------------------------

int main() {
	cout << "----------------------- Patron Singleton -----------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Creando un Singleton sing1..." << endl;
	Singleton* sing1 = Singleton::getInstance(); //Aqui es donde se crea el Singleton
	cout << "----------------------------------------------------------------" << endl;
	cout << "La info que tiene la instancia es: " << sing1->getValor() <<endl ;
	cout << "Se puede setter al Singleton(cambiar el valor)... " << endl;
	sing1->setValor(10);
	cout << "La nueva info que tiene la instancia es: " << sing1->getValor() << endl;
	cout << endl << endl;
	//puedo cambiar el valor del Singleton, lo que no puedo es crear un Singleton nuevo...
	cout << "Trata de hacer otro Singleton .....sing2....." << endl;
	Singleton* sing2 = Singleton::getInstance(); //Creo que puedo hacer otro Singleton - ERROR
	cout << "Ver que es lo que tiene adentro sing2...." << sing2->getValor() << endl;  //Lo que muestra es sing 1
	cout << endl << endl;
	cout << "Setteando a sing2... (valor = 20)..." << endl;
	sing2->setValor(20);
	cout << "Si sing1 y sing2 son el mism0 objeto entonces deben tener lo mismo internamente" << endl;
	cout << "La info que tiene sing1 es...." <<sing1->getValor() <<endl;
	cout << "La info que tiene sing2 es...." << sing2->getValor() << endl;
	//al crear dos sing(sing1 y sing2) los dos estan viendo el mismo objeto y los dos lo pueden cambiar....
	sing1->destroySingleton();  //solo se destruye una vez o sino da una excepcion
	//solo crear sing1 NO SING2 eso es un error !!!!!!!!!!!
	system("pause");
	return 0;
}