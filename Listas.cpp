// Listas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>

#include "listaSimple.h"


using namespace std;

void menu() {
    listaSimple* lista = new listaSimple();
    int opc = -1;
    int dato = 0;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar al inicio" << endl;
        cout << "(2) Agregar al final " << endl;
        cout << "(3) Agregar antes de...  " << endl;
        cout << "(4) Agregar despues de...  " << endl;
        cout << "(5) Remover todos los nodos de la lista" << endl;
        cout << "(6) Remover todos datos elegidos" << endl;
        cout << "(7) Remover un dato de la lista" << endl;
        cout << "(8) Eliminar datos repetidos" << endl;
        cout << "(10) Desplegar la lista" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1: {
            cout << "Dato que desea agregar al inicio: ";
            cin >> dato;
            lista->agregarInicio(dato);
            break;
        }
        case 2: {
            cout << "Dato que desea agregar al final: ";
            cin >> dato;
            lista->agregarFinal(dato);
            break;
        }
        case 3: {
            int ref = 0;
            cout << "Dato de referencia en la lista?->";
            cin >> ref;
            cout << "Dato que desea agregar antes de " << ref << " ->";
            cin >> dato;
            if (lista->agregarAntesDe(dato, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }

        case 4: {
            int ref = 0;
            cout << "Dato de referencia en la lista?->";
            cin >> ref;
            cout << "Dato que desea agregar desoues de " << ref << " ->";
            cin >> dato;
            if (lista->agregarDespuesDe(dato, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }

        case 5: {
            cout << "Eliminado los nodos de la lista" << endl;
            lista->eliminarLista();
            break;
        }
        case 6: {
            cout << "Elije el dato por eliminar. \n";
            cin >> dato;
            if(lista->eliminarTodos(dato))
                cout << "El numero " << dato << " ha sido eliminado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no esta en la lista" << endl;
            break;
        }
        
        
        case 7: {
            cout << "Dato que desea eliminar de la lista: ";
            cin >> dato;
            if (lista->eliminar(dato))
                cout << "El numero " << dato << " ha sido eliminado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no está en la lista" << endl;

            break;
        }
        case 8: {
            cout << "Se estan borrando los datos \n";
            lista->eliminarRepetidos();
            break;
        }
        case 10:
            cout << "Desplegando los valores de la lista" << endl;
            lista->desplegarLista();
            break;
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }


}

int main()
{
    menu();

}
