#include <iostream>
#include <string>
#include "HashMap/HashMapList.h" // Asegúrate de que la ruta sea correcta

using namespace std;

int main() {
    unsigned int tamanoTabla = 11; // Tamaño de la tabla hash
    HashMapList<int, string> votantes(tamanoTabla);

    int opcion;
    int clave;
    string candidato;

    do {
        cout << "1. Agregar voto\n";
        cout << "2. Buscar voto\n";
        cout << "3. Eliminar voto\n";
        cout << "4. Ver todos los votos\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la clave: ";
                cin >> clave;
                cout << "Ingrese el candidato: ";
                cin.ignore(); // Para ignorar el salto de línea
                getline(cin, candidato);
                try{
                    votantes.put(clave, candidato);
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
                    candidato = votantes.get(clave);
                    cout << "clave del votante " << clave << ": nombre del candidato: " << candidato << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "votante no encontrada.\n";
                    } else {
                        cout << "Error: Conflicto en la búsqueda.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese el voto a eliminar: ";
                cin >> clave;
                votantes.remove(clave);
                cout << "voto eliminado correctamente (si existia).\n";
                break;

            case 4:
                cout << "Todos los votos:\n";
                votantes.print(); // Imprimir todas las entradas
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