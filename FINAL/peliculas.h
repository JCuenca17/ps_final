#ifndef PELICULAS_H
#define PELICULAS_H

#include <string>
#include <vector>

using namespace std;

struct Pelicula
{
    string titulo;
    string director;
    int anioEstreno;
    double calificacion;
    bool estaEnCartelera;
};

void agregarPelicula(const Pelicula &pelicula);
void eliminarPelicula(const string &titulo);
Pelicula buscarPelicula(const string &titulo);
void actualizarPelicula(const Pelicula &pelicula);
void listarPeliculas();
void guardarPeliculasEnArchivo(const string &nombreArchivo);
void cargarPeliculasDesdeArchivo(const string &nombreArchivo);

#endif // PELICULAS_H
