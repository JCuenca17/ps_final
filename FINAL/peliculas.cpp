#include "peliculas.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<Pelicula> peliculas;

void agregarPelicula(const Pelicula &pelicula)
{
    peliculas.push_back(pelicula);
    cout << "Pelicula agregada con exito." << endl;
}

void eliminarPelicula(const string &titulo)
{
    auto it = find_if(peliculas.begin(), peliculas.end(), [&titulo](const Pelicula &p)
                      { return p.titulo == titulo; });
    if (it != peliculas.end())
    {
        peliculas.erase(it);
        cout << "Pelicula eliminada con exito." << endl;
    }
    else
    {
        cout << "Pelicula no encontrada." << endl;
    }
}

Pelicula buscarPelicula(const string &titulo)
{
    auto it = find_if(peliculas.begin(), peliculas.end(), [&titulo](const Pelicula &p)
                      { return p.titulo == titulo; });
    if (it != peliculas.end())
    {
        return *it;
    }
    else
    {
        throw runtime_error("Pelicula no encontrada.");
    }
}

void actualizarPelicula(const Pelicula &pelicula)
{
    auto it = find_if(peliculas.begin(), peliculas.end(), [&pelicula](const Pelicula &p)
                      { return p.titulo == pelicula.titulo; });
    if (it != peliculas.end())
    {
        *it = pelicula;
        cout << "Pelicula actualizada con exito." << endl;
    }
    else
    {
        cout << "Pelicula no encontrada." << endl;
    }
}

void listarPeliculas()
{
    cout << left << setw(50) << "Titulo"
         << setw(30) << "Director"
         << setw(20) << "Año de Estreno"
         << setw(15) << "Calificacion"
         << setw(15) << "En Cartelera" << endl;
    cout << string(150, '-') << endl;

    for (const auto &pelicula : peliculas)
    {
        cout << left << setw(50) << pelicula.titulo
             << setw(30) << pelicula.director
             << setw(20) << pelicula.anioEstreno
             << setw(15) << pelicula.calificacion
             << setw(15) << (pelicula.estaEnCartelera ? "Si" : "No") << endl;
    }
}

void guardarPeliculasEnArchivo(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo para guardar peliculas.");
    }
    for (const auto &pelicula : peliculas)
    {
        archivo << pelicula.titulo << ','
                << pelicula.director << ','
                << pelicula.anioEstreno << ','
                << pelicula.calificacion << ','
                << pelicula.estaEnCartelera << endl;
    }
}

void cargarPeliculasDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo para cargar peliculas.");
    }
    peliculas.clear();
    string linea;
    while (getline(archivo, linea))
    {
        Pelicula pelicula;
        stringstream ss(linea);
        string calificacion, estaEnCartelera;

        getline(ss, pelicula.titulo, ',');
        getline(ss, pelicula.director, ',');
        ss >> pelicula.anioEstreno;
        ss.ignore();
        getline(ss, calificacion, ',');
        pelicula.calificacion = stod(calificacion);
        getline(ss, estaEnCartelera);
        pelicula.estaEnCartelera = stoi(estaEnCartelera);
        peliculas.push_back(pelicula);
    }
}
