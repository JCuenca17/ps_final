#ifndef PRESTAMOS_H
#define PRESTAMOS_H

#include <string>
#include <vector>
#include "usuarios.h"

struct Prestamo
{
    int codigoRegistro;
    std::string dniUsuario;
    std::string fechaPrestamo;
    std::string fechaDevolucion;
};

extern std::vector<Prestamo> prestamos;

void establecerPrestamo(const Prestamo &prestamo);
void establecerDevolucion(int codigoRegistro);
void listarPrestamos();
void guardarPrestamosEnArchivo(const std::string &nombreArchivo);
void cargarPrestamosDesdeArchivo(const std::string &nombreArchivo);

bool tienePrestamosActivo(const std::string &dni);
std::string obtenerNombreUsuario(const std::string &dni); // Declaración de la función

#endif // PRESTAMOS_H
