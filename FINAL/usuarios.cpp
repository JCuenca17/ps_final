#include "usuarios.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "prestamos.h"

using namespace std;

vector<Usuario> usuarios;

void agregarUsuario(const Usuario &usuario)
{
    usuarios.push_back(usuario);
    cout << "Usuario agregado con exito." << endl;
}

void eliminarUsuario(const string &dni)
{
    auto it = find_if(usuarios.begin(), usuarios.end(), [&dni](const Usuario &u)
                      { return u.dni == dni; });
    if (it != usuarios.end())
    {
        // Verificar si el usuario tiene préstamos activos
        if (tienePrestamosActivo(dni))
        {
            cout << "No se puede eliminar el usuario porque tiene préstamos activos." << endl;
        }
        else
        {
            usuarios.erase(it);
            cout << "Usuario eliminado con exito." << endl;
        }
    }
    else
    {
        cout << "Usuario no encontrado." << endl;
    }
}

void listarUsuarios()
{
    cout << left << setw(20) << "DNI (Nombre)"
         << setw(30) << "Nombre"
         << setw(30) << "Email"
         << setw(15) << "Telefono" << endl;
    cout << string(95, '-') << endl;

    for (const auto &usuario : usuarios)
    {
        cout << left << setw(20) << usuario.dni + " (" + usuario.nombre + ")"
             << setw(30) << usuario.nombre
             << setw(30) << usuario.email
             << setw(15) << usuario.telefono << endl;
    }
}

void guardarUsuariosEnArchivo(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo para guardar usuarios.");
    }
    for (const auto &usuario : usuarios)
    {
        archivo << usuario.dni << ','
                << usuario.nombre << ','
                << usuario.email << ','
                << usuario.telefono << endl;
    }
}

void cargarUsuariosDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo para cargar usuarios.");
    }
    usuarios.clear();
    string linea;
    while (getline(archivo, linea))
    {
        Usuario usuario;
        stringstream ss(linea);
        getline(ss, usuario.dni, ',');
        getline(ss, usuario.nombre, ',');
        getline(ss, usuario.email, ',');
        getline(ss, usuario.telefono);
        usuarios.push_back(usuario);
    }
}

bool usuarioExiste(const string &dni)
{
    auto it = find_if(usuarios.begin(), usuarios.end(), [&dni](const Usuario &u)
                      { return u.dni == dni; });
    return it != usuarios.end();
}
