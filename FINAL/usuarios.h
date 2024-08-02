#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <vector>

struct Usuario
{
    std::string dni;
    std::string nombre;
    std::string email;
    std::string telefono;
};

extern std::vector<Usuario> usuarios;

void agregarUsuario(const Usuario &usuario);
void eliminarUsuario(const std::string &dni);
void listarUsuarios();
void guardarUsuariosEnArchivo(const std::string &nombreArchivo);
void cargarUsuariosDesdeArchivo(const std::string &nombreArchivo);

bool usuarioExiste(const std::string &dni);

#endif // USUARIOS_H
