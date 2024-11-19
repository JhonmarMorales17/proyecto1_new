Parte 1 del Proyecto de Programacion 2 de Jhonmar Morales.

Este programa fue desarrollado para gestionar el inventario de vehículos, clientes y repuestos en una tienda. Proporciona funcionalidades como consultar información, asignar/quitar vehículos, vender repuestos y guardar cambios realizados en los datos almacenados en archivos CSV. A continuación, se describe el proceso de creación del proyecto.

// Estructura del Código: //

El programa está dividido en funciones específicas para cada tarea, lo que permite un diseño modular y fácil de mantener.

1. Definición de estructuras:

Se definieron tres estructuras principales (Vehiculo, Cliente y Repuesto) que encapsulan los datos relacionados con cada entidad.
Se utilizaron constantes como MAX_VEHICULOS, MAX_CLIENTES, y MAX_REPUESTOS para limitar la cantidad de datos que el programa puede manejar.

2. Cargar datos desde archivos CSV:

Se crearon funciones para leer datos desde archivos CSV (cargarVehiculos, cargarClientes, cargarRepuestos).
Estas funciones utilizan ifstream y stringstream para manejar los datos de forma eficiente y validar la entrada.

3. Consultas de datos:

Se implementaron funciones para consultar datos individuales de vehículos, clientes y repuestos con índices específicos (consultarVehiculo, consultarCliente, consultarRepuesto).
Esto permitió mostrar información detallada de cada entidad.

4. Asignar o quitar vehículos a clientes:

La función asignarQuitarVehiculo permitió asignar vehículos disponibles a clientes activos y quitar vehículos rentados si fuese necesario.
Se incluyó lógica para validar clientes y vehículos, actualizando las relaciones entre ambas entidades.

5. Venta de repuestos:

La función venderRepuesto permite reducir la cantidad en inventario de un repuesto seleccionado por el usuario.
Se añadió una confirmación antes de procesar la venta para evitar errores.

6. Guardar cambios:

La función guardarCambios sobrescribe los archivos CSV con los datos actualizados.
Esto asegura que las modificaciones hechas en memoria (como asignaciones de vehículos o ventas de repuestos) se persistan en el almacenamiento.

// Flujo del Programa: //

Al iniciar, el programa carga datos desde los archivos CSV correspondientes a vehículos, clientes y repuestos.

El menú principal permite al usuario seleccionar entre varias opciones:
- Consultar información de vehículos, clientes o repuestos.
- Asignar/quitar vehículos a clientes.
- Vender repuestos.
- Guardar los cambios realizados.

Las acciones realizadas en el programa solo se guardan al seleccionar la opción "Guardar Cambios".

El programa sigue ejecutándose hasta que el usuario selecciona "Salir".

// Cómo Usar el Programa: //

1. Asegúrate de que los archivos CSV estén ubicados en la carpeta bin:
- vehiculos.csv
- clientes.csv
- repuestos.csv

2. Compila el programa usando un compilador de C++, como g++:
"g++ -o .\bin\main.exe .\src\main.cpp"

3. Ejecuta el programa:
".\bin\main.exe"

4. Sigue las opciones del menú para realizar las operaciones deseadas.
