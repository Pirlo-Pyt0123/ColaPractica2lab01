
#include <iostream>
using namespace std;

template <typename T>
class Cola
{
private:
	T* cola;
	int frente;
	int fin;
	int tamano;
public:
	Cola(int tamano);
	~Cola();
	void encolar(T dato);
	T desencolar();
	T getFrente();
	bool estaVacia();
	bool estaLlena();
	void imprimir();
};

template<typename T>
inline Cola<T>::Cola(int _tamano)
{
	tamano = _tamano;
	cola = new T[tamano];
	frente = 0;
	fin = -1;
}

template<typename T>
inline Cola<T>::~Cola()
{
	delete[] cola;
}

template<typename T>
inline void Cola<T>::encolar(T dato)
{
	if (!estaLlena())
	{
		fin = (fin + 1) % tamano;
		cola[fin] = dato;
	}
	else
	{
		cout << "La cola esta llena" << endl;
	}
}

template<typename T>
inline T Cola<T>::desencolar()
{
	if (!estaVacia())
	{
		T dato = cola[frente];
		frente = (frente + 1) % tamano;
		return dato;
	}
	else
	{
		cout << "La cola esta vacia" << endl;
	}
}

template<typename T>
inline T Cola<T>::getFrente()
{
	return cola[frente];
}

template<typename T>
inline bool Cola<T>::estaVacia()
{
	return (fin == -1);
}

template<typename T>
inline bool Cola<T>::estaLlena()
{
	return ((fin + 1) % tamano == frente && fin != -1);
}

template<typename T>
inline void Cola<T>::imprimir()
{
    if (!estaVacia()) {
        int i = frente;
        do {
            cout << cola[i] << " ";
            i = (i + 1) % tamano;
        } while (i != (fin + 1) % tamano);
        cout << endl;
    } else {
        cout << "La cola está vacía" << endl;
    }
}