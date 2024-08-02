#include <iostream>
#include <string>
#include <stdexcept>
#include "peliculas.h"
#include "usuarios.h"
#include "prestamos.h"

using namespace std;

int main()
{
    int opcion;
    do
    {
        cout << "Menu:\n";
        cout << "--------- Peliculas ---------\n";
        cout << "1. Agregar Pelicula\n";
        cout << "2. Eliminar Pelicula\n";
        cout << "3. Buscar Pelicula\n";
        cout << "4. Actualizar Pelicula\n";
        cout << "5. Listar Peliculas\n";
        cout << "6. Guardar Peliculas en Archivo\n";
        cout << "7. Cargar Peliculas desde Archivo\n";
        cout << "---------- Usuarios ---------\n";
        cout << "8. Agregar Usuario\n";
        cout << "9. Eliminar Usuario\n";
        cout << "10. Listar Usuarios\n";
        cout << "11. Guardar Usuarios en Archivo\n";
        cout << "12. Cargar Usuarios desde Archivo\n";
        cout << "--------- Prestamos ---------\n";
        cout << "13. Establecer Prestamo\n";
        cout << "14. Establecer Devolucion\n";
        cout << "15. Listar Prestamos\n";
        cout << "16. Guardar Prestamos en Archivo\n";
        cout << "17. Cargar Prestamos desde Archivo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        try
        {
            switch (opcion)
            {
            case 1:
            {
                Pelicula pelicula;
                cout << "Titulo: ";
                getline(cin, pelicula.titulo);
                cout << "Director: ";
                getline(cin, pelicula.director);
                cout << "Anio de Estreno: ";
                cin >> pelicula.anioEstreno;
                cout << "Calificacion: ";
                cin >> pelicula.calificacion;
                cout << "Esta en Cartelera (1-Si, 0-No): ";
                cin >> pelicula.estaEnCartelera;
                cin.ignore();
                agregarPelicula(pelicula);
                break;
            }
            case 2:
            {
                string titulo;
                cout << "Titulo de la Pelicula a eliminar: ";
                getline(cin, titulo);
                eliminarPelicula(titulo);
                break;
            }
            case 3:
            {
                string titulo;
                cout << "Titulo de la Pelicula a buscar: ";
                getline(cin, titulo);
                Pelicula pelicula = buscarPelicula(titulo);
                cout << "Pelicula encontrada:\n";
                cout << "Titulo: " << pelicula.titulo << ", Director: " << pelicula.director
                     << ", Año de Estreno: " << pelicula.anioEstreno
                     << ", Calificacion: " << pelicula.calificacion
                     << ", En Cartelera: " << (pelicula.estaEnCartelera ? "Si" : "No") << endl;
                break;
            }
            case 4:
            {
                Pelicula pelicula;
                cout << "Titulo de la Pelicula a actualizar: ";
                getline(cin, pelicula.titulo);
                cout << "Nuevo Director: ";
                getline(cin, pelicula.director);
                cout << "Nuevo Año de Estreno: ";
                cin >> pelicula.anioEstreno;
                cout << "Nueva Calificacion: ";
                cin >> pelicula.calificacion;
                cout << "Esta en Cartelera (1-Si, 0-No): ";
                cin >> pelicula.estaEnCartelera;
                cin.ignore();
                actualizarPelicula(pelicula);
                break;
            }
            case 5:
                listarPeliculas();
                break;
            case 6:
            {
                string nombreArchivo;
                cout << "Nombre del archivo para guardar peliculas: ";
                getline(cin, nombreArchivo);
                guardarPeliculasEnArchivo(nombreArchivo);
                cout << "Peliculas guardadas en el archivo '" << nombreArchivo << "' exitosamente." << endl;
                break;
            }
            case 7:
            {
                string nombreArchivo;
                cout << "Nombre del archivo para cargar peliculas: ";
                getline(cin, nombreArchivo);
                cargarPeliculasDesdeArchivo(nombreArchivo);
                cout << "Peliculas cargadas desde el archivo '" << nombreArchivo << "' exitosamente." << endl;
                break;
            }
            case 8:
            {
                Usuario usuario;
                cout << "DNI: ";
                getline(cin, usuario.dni);
                cout << "Nombre: ";
                getline(cin, usuario.nombre);
                cout << "Email: ";
                getline(cin, usuario.email);
                cout << "Telefono: ";
                getline(cin, usuario.telefono);
                agregarUsuario(usuario);
                break;
            }
            case 9:
            {
                string dni;
                cout << "DNI del Usuario a eliminar: ";
                getline(cin, dni);
                eliminarUsuario(dni);
                break;
            }
            case 10:
                listarUsuarios();
                break;
            case 11:
            {
                string nombreArchivo;
                cout << "Nombre del archivo para guardar usuarios: ";
                getline(cin, nombreArchivo);
                guardarUsuariosEnArchivo(nombreArchivo);
                cout << "Usuarios guardados en el archivo '" << nombreArchivo << "' exitosamente." << endl;
                break;
            }
            case 12:
            {
                string nombreArchivo;
                cout << "Nombre del archivo para cargar usuarios: ";
                getline(cin, nombreArchivo);
                cargarUsuariosDesdeArchivo(nombreArchivo);
                cout << "Usuarios cargados desde el archivo '" << nombreArchivo << "' exitosamente." << endl;
                break;
            }
            case 13:
            {
                Prestamo prestamo;
                cout << "Codigo de Registro: ";
                cin >> prestamo.codigoRegistro;
                cin.ignore();
                cout << "DNI del Usuario: ";
                getline(cin, prestamo.dniUsuario);
                cout << "Fecha de Prestamo: ";
                getline(cin, prestamo.fechaPrestamo);
                cout << "Fecha de Devolucion: ";
                getline(cin, prestamo.fechaDevolucion);
                establecerPrestamo(prestamo);
                break;
            }
            case 14:
            {
                int codigoRegistro;
                cout << "Codigo de Registro del Prestamo a devolver: ";
                cin >> codigoRegistro;
                establecerDevolucion(codigoRegistro);
                break;
            }
            case 15:
                listarPrestamos();
                break;
            case 16:
            {
                string nombreArchivo;
                cout << "Nombre del archivo para guardar prestamos: ";
                getline(cin, nombreArchivo);
                guardarPrestamosEnArchivo(nombreArchivo);
                cout << "Prestamos guardados en el archivo '" << nombreArchivo << "' exitosamente." << endl;
                break;
            }
            case 17:
            {
                string nombreArchivo;
                cout << "Nombre del archivo para cargar prestamos: ";
                getline(cin, nombreArchivo);
                cargarPrestamosDesdeArchivo(nombreArchivo);
                cout << "Prestamos cargados desde el archivo '" << nombreArchivo << "' exitosamente." << endl;
                break;
            }
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    } while (opcion != 0);

    return 0;
}
