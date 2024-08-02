#include "prestamos.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "usuarios.h" 

using namespace std;

vector<Prestamo> prestamos;

void establecerPrestamo(const Prestamo &prestamo)
{
    if (!usuarioExiste(prestamo.dniUsuario))
    {
        cout << "El usuario con DNI '" << prestamo.dniUsuario << "' no existe." << endl;
        return;
    }
    prestamos.push_back(prestamo);
    cout << "Prestamo establecido con exito." << endl;
}

void establecerDevolucion(int codigoRegistro)
{
    auto it = find_if(prestamos.begin(), prestamos.end(), [codigoRegistro](const Prestamo &p)
                      { return p.codigoRegistro == codigoRegistro; });
    if (it != prestamos.end())
    {
        cout << "Devolucion establecida para el prestamo con codigo: " << codigoRegistro << endl;
    }
    else
    {
        cout << "Prestamo no encontrado." << endl;
    }
}

void listarPrestamos()
{
    cout << left << setw(20) << "Codigo Registro"
         << setw(30) << "DNI Usuario (Nombre)"
         << setw(20) << "Fecha de Prestamo"
         << setw(20) << "Fecha de Devolucion" << endl;
    cout << string(90, '-') << endl;

    for (const auto &prestamo : prestamos)
    {
        cout << left << setw(20) << prestamo.codigoRegistro
             << setw(30) << prestamo.dniUsuario + " (" + obtenerNombreUsuario(prestamo.dniUsuario) + ")"
             << setw(20) << prestamo.fechaPrestamo
             << setw(20) << prestamo.fechaDevolucion << endl;
    }
}

void guardarPrestamosEnArchivo(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo para guardar prestamos.");
    }
    for (const auto &prestamo : prestamos)
    {
        archivo << prestamo.codigoRegistro << ','
                << prestamo.dniUsuario << ','
                << prestamo.fechaPrestamo << ','
                << prestamo.fechaDevolucion << endl;
    }
}

void cargarPrestamosDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo para cargar prestamos.");
    }
    prestamos.clear();
    string linea;
    while (getline(archivo, linea))
    {
        Prestamo prestamo;
        stringstream ss(linea);
        string codigoRegistro;
        getline(ss, codigoRegistro, ',');
        prestamo.codigoRegistro = stoi(codigoRegistro);
        getline(ss, prestamo.dniUsuario, ',');
        getline(ss, prestamo.fechaPrestamo, ',');
        getline(ss, prestamo.fechaDevolucion);
        prestamos.push_back(prestamo);
    }
}

bool tienePrestamosActivo(const string &dni)
{
    return any_of(prestamos.begin(), prestamos.end(), [&dni](const Prestamo &p)
                  { return p.dniUsuario == dni; });
}

string obtenerNombreUsuario(const string &dni)
{
    auto it = find_if(usuarios.begin(), usuarios.end(), [&dni](const Usuario &u)
                      { return u.dni == dni; });
    if (it != usuarios.end())
    {
        return it->nombre;
    }
    return "Usuario no encontrado";
}
