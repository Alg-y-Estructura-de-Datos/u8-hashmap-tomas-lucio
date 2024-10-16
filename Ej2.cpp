#include <iostream>
#include <string>
#include "HashMap/HashMap.h" // Asegúrate de que la ruta sea correcta

using namespace std;

int main() {
    unsigned int tamanoTabla = 11; // Tamaño de la tabla hash
    HashMap<int, string> empleados(tamanoTabla);

    int opcion;
    int clave;
    string nombre;

    do {
        cout << "1. Agregar empleado\n";
        cout << "2. Buscar empleado\n";
        cout << "3. Eliminar empleado\n";
        cout << "4. Ver todos los empleados\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la clave: ";
                cin >> clave;
                cout << "Ingrese el nombre: ";
                cin.ignore(); // Para ignorar el salto de línea
                getline(cin, nombre);
                try{
                    empleados.put(clave, nombre);
                    cout << "empleado agregado correctamente.\n";
                }catch(int e){
                    if(e==409)
                        cout << "colision, intente otra.\n";
                }


                break;

            case 2:
                cout << "Ingrese la clave a buscar: ";
                cin >> clave;
                try {
                    nombre = empleados.get(clave);
                    cout << "clave del empleado " << clave << ": nombre del empleado: " << nombre << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "empleado no encontrada.\n";
                    } else {
                        cout << "Error: Conflicto en la búsqueda.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese el empleado a eliminar: ";
                cin >> clave;
                empleados.remove(clave);
                cout << "empleado eliminado correctamente (si existia).\n";
                break;

            case 4:
                cout << "Todos los empleados:\n";
                empleados.print(); // Imprimir todas las entradas
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }

        cout << endl;

    } while (opcion != 0);

    return 0;
}