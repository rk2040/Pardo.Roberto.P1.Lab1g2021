#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eEmpresa;

#endif // EMPRESA_H_INCLUDED

int cargarDescripcionEmpresa(eEmpresa empresas[], int tamEmpresa, int idEmpresa, char descripcion[]);

int mostrarEmpresas(eEmpresa empresas[], int tamEmpresa);

int validarEmpresa(int id, eEmpresa empresas[], int tamEmpresa);
