#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

const string VEHICULOS_FILE = "bin/vehiculos.csv";
const string CLIENTES_FILE = "bin/clientes.csv";
const string REPUESTOS_FILE = "bin/repuestos.csv";

const int MAX_VEHICULOS = 100;
const int MAX_CLIENTES = 100;
const int MAX_REPUESTOS = 100;

struct Vehiculo {
    string modelo;
    string marca;
    string placa;
    string color;
    int year;
    float kilometraje;
    bool rentado;
    float precio_renta;
    string ced_cliente;
    string fecha_de_entrega;
};

struct Cliente {
    string cedula;
    string nombre;
    string apellido;
    string email;
    int cantidad_vehiculos_rentados;
    string direccion;
    bool activo;
};

struct Repuesto {
    string modelo;
    string marca;
    string nombre;
    string modelo_carro;
    int anio_carro;
    float precio;
    int existencias;
};

int cargarVehiculos(Vehiculo vehiculos[]) {
    ifstream file(VEHICULOS_FILE);
    string line;
    getline(file, line); // Saltar la primera línea

    int count = 0;
    while (getline(file, line) && count < MAX_VEHICULOS) {
        stringstream ss(line);
        Vehiculo v;
        string rentado;

        getline(ss, v.modelo, ',');
        getline(ss, v.marca, ',');
        getline(ss, v.placa, ',');
        getline(ss, v.color, ',');
        ss >> v.year;
        ss.ignore();
        ss >> v.kilometraje;
        ss.ignore();
        getline(ss, rentado, ',');
        v.rentado = (rentado == "true");
        ss >> v.precio_renta;
        ss.ignore();
        getline(ss, v.ced_cliente, ',');
        getline(ss, v.fecha_de_entrega);

        vehiculos[count++] = v;
    }
    file.close();
    return count;
}

int cargarClientes(Cliente clientes[]) {
    ifstream file(CLIENTES_FILE);
    string line;
    getline(file, line); // Saltar la primera línea

    int count = 0;
    while (getline(file, line) && count < MAX_CLIENTES) {
        stringstream ss(line);
        Cliente c;

        getline(ss, c.cedula, ',');
        getline(ss, c.nombre, ',');
        getline(ss, c.apellido, ',');
        getline(ss, c.email, ',');
        ss >> c.cantidad_vehiculos_rentados;
        ss.ignore();
        getline(ss, c.direccion, ',');
        string activo;
        getline(ss, activo);
        c.activo = (activo == "true");

        clientes[count++] = c;
    }
    file.close();
    return count;
}

int cargarRepuestos(Repuesto repuestos[]) {
    ifstream file(REPUESTOS_FILE);
    string line;
    getline(file, line); // Saltar la primera línea

    int count = 0;
    while (getline(file, line) && count < MAX_REPUESTOS) {
        stringstream ss(line);
        Repuesto r;

        getline(ss, r.modelo, ',');
        getline(ss, r.marca, ',');
        getline(ss, r.nombre, ',');
        getline(ss, r.modelo_carro, ',');
        ss >> r.anio_carro;
        ss.ignore();
        ss >> r.precio;
        ss.ignore();
        ss >> r.existencias;

        repuestos[count++] = r;
    }
    file.close();
    return count;
}

void mostrarVehiculo(const Vehiculo& v) {
    cout << "Modelo: " << v.modelo << ", Marca: " << v.marca << ", Placa: " << v.placa
         << ", Color: " << v.color << ", Año: " << v.year << ", Kilometraje: " << v.kilometraje
         << ", Rentado: " << (v.rentado ? "Si" : "No") << ", Precio Renta: $" << v.precio_renta << ", Cedula Cliente: " << v.ced_cliente
         << ", Fecha de Entrega: " << v.fecha_de_entrega << endl;
}

void mostrarCliente(const Cliente& c) {
    cout << "Cedula: " << c.cedula << ", Nombre: " << c.nombre << ", Apellido: " << c.apellido
         << ", Email: " << c.email << ", Cantidad Vehiculos Rentados: " << c.cantidad_vehiculos_rentados
         << ", Direccion: " << c.direccion << ", Activo: " << (c.activo ? "Si" : "No") << endl;
}

void mostrarRepuesto(const Repuesto& r) {
    cout << "Modelo: " << r.modelo << ", Marca: " << r.marca << ", Nombre: " << r.nombre
         << ", Modelo Carro: " << r.modelo_carro << ", Año Carro: " << r.anio_carro
         << ", Precio: $" << r.precio << ", Existencias: " << r.existencias << endl;
}

void consultarVehiculo(Vehiculo vehiculos[], int count) {
    int index;
    cout << "Ingrese el indice del vehiculo a consultar (0 a " << count - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < count) {
        mostrarVehiculo(vehiculos[index]);
    } else {
        cout << "Indice invalido." << endl;
    }
}

void consultarCliente(Cliente clientes[], int count) {
    int index;
    cout << "Ingrese el indice del cliente a consultar (0 a " << count - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < count) {
        mostrarCliente(clientes[index]);
    } else {
        cout << "Indice invalido." << endl;
    }
}

void consultarRepuesto(Repuesto repuestos[], int count) {
    int index;
    cout << "Ingrese el indice del repuesto a consultar (0 a " << count - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < count) {
        mostrarRepuesto(repuestos[index]);
    } else {
        cout << "Indice invalido." << endl;
    }
}

void guardarCambios(Vehiculo vehiculos[], int vehiculoCount, Cliente clientes[], int clienteCount, Repuesto repuestos[], int repuestoCount) {
    ofstream vehiculosFile(VEHICULOS_FILE);
    for (int i = 0; i < vehiculoCount; i++) {
        vehiculosFile << vehiculos[i].modelo << "," << vehiculos[i].marca << "," << vehiculos[i].placa << ","
                      << vehiculos[i].color << "," << vehiculos[i].year << "," << vehiculos[i].kilometraje << ","
                      << (vehiculos[i].rentado ? "true" : "false") << "," << vehiculos[i].precio_renta << "," << vehiculos[i].ced_cliente << ","
                      << vehiculos[i].fecha_de_entrega << endl;
    }
    vehiculosFile.close();

    ofstream clientesFile(CLIENTES_FILE);
    for (int i = 0; i < clienteCount; i++) {
        clientesFile << clientes[i].cedula << "," << clientes[i].nombre << "," << clientes[i].apellido << ","
                     << clientes[i].email << "," << clientes[i].cantidad_vehiculos_rentados << ","
                     << clientes[i].direccion << "," << (clientes[i].activo ? "true" : "false") << endl;
    }
    clientesFile.close();

    ofstream repuestosFile(REPUESTOS_FILE);
    for (int i = 0; i < repuestoCount; i++) {
        repuestosFile << repuestos[i].modelo << "," << repuestos[i].marca << "," << repuestos[i].nombre << ","
                      << repuestos[i].modelo_carro << "," << repuestos[i].anio_carro << ","
                      << repuestos[i].precio << "," << repuestos[i].existencias << endl;
    }
    repuestosFile.close();
}

int main() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    Cliente clientes[MAX_CLIENTES];
    Repuesto repuestos[MAX_REPUESTOS];

    int vehiculoCount = cargarVehiculos(vehiculos);
    int clienteCount = cargarClientes(clientes);
    int repuestoCount = cargarRepuestos(repuestos);

    char opcion;
    do {
        cout << "Seleccione una opcion:\n1. Consultar Vehiculo\n2. Consultar Cliente\n3. Consultar Repuesto\n4. Guardar Cambios\n5. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                consultarVehiculo(vehiculos, vehiculoCount);
                break;
            case '2':
                consultarCliente(clientes, clienteCount);
                break;
            case '3':
                consultarRepuesto(repuestos, repuestoCount);
                break;
            case '4':
                guardarCambios(vehiculos, vehiculoCount, clientes, clienteCount, repuestos, repuestoCount);
                cout << "Cambios guardados." << endl;
                break;
            case '5':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != '5');

    return 0;
}