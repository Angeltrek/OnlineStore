# Tienda Online
## Prerrequisitos
Haber instalado un [compilador de c++](https://sourceforge.net/projects/mingw/files/latest/download)

>compilar con: "g++ main.cpp"
>1- correr en windows: "a.exe"
> 2- correr en windows: "g++ -o a main.cpp"

>correr en linux: "/a.out"

Este proyecto trata de simular el proceso lógico de una tienda en linea en donde se pueden registrar clientes que pueden comprar distintos productos de diferentes vendedores, el proyecto debe ser capaz de almacenar los datos de diversos usuarios y tener una lista de diversos productos que pueden ser adquiridos por los clientes. Cada cliente tendrá la posibilidad de registrar una tarjeta de crédito y tenrá la capacidad de agregar distintos productos en distintas cantidades a un carrito de compras.

## Objetivos

 1. Capacidad de registrar diversos usuarios
 2. Los clientes pueden adquirir diversos productos
 3. Los productos se deben de almacenar en un carrito de compras
 4. Calcular el costo total del carrito de compras
 5. Implementar un sistema de pago
 6. Implementar un sistema de inicio de sesión

## Funcionalidad

El programa está orientado a funcionar en la parte lógica del cliente.
Para poder empezar a usar el programa se requiere iniciar sesión.
Existen 2 opciones para iniciar sesión

 1. Registrar una nueva cuenta y después ingresar a la cuenta registrada

 
```bash
(1) Registrarse <-
(2) Ingresar
(3) Ver productos
(4) Agregar al carrito
(5) Ver carrito
(6) Check out
(7) Cerrar sesion
(8) Salir del programa
```

 2. Ingresar con una cuenta predeterminada de administrador

> Proporciona tu email
admin
Proporciona tu contrase±a:
admin
Has iniciado sesion!

¿A qué opciones no se pueden acceder si no se inicia sesión?
```
(4) Agregar al carrito
(5) Ver carrito
(6) Check out
```
## Consideraciones

 - No se cuenta con una base de datos por lo que todo lo que se genera se borra después de terminar de ejecutar el programa
 - El dinero que tienen las tarjetas de crédito es proporcionado por el usuario (No es realista)
 - Solo se pueden asignar números cuando se pide una opción a elegir
 - Al registrar una cuenta solo se pueden dar números cuando se pide ingresar la cantidad de dinero que tiene el cliente

***

## Correcciones

***Los commits del proyecto fueron más descriptivos
***Se cambió check_login() por set_login() en la clase Users
***En el diagrama UML la clase Product pasó de ser composición de Shopping_cart a ser agregación.
***El codigo no compilaba fuera de Visual studio debido a que se incluía mal la clase Seller en Shopping_cart
***Se comentaron todas las lineas de código importantes y se le dió un mejor orden al código
