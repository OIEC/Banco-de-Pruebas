Sesion 0: Herramientas
======================


# Terminal y comandos de UNIX

## Basicas (15min)

* ls - listar
* cd - cambiar directorio
* mkdir - crear directorio (make directory)
* pwd - imprimir donde estas (print current directory)
* cat - mostrar contenido un archivo
* cp - copiar archivo
* mv - mover archivo
* Copiar: Ctrl + Shift + c
* pegar: Ctrl + Shift + v
* Ctrl + c: en terminal mandas sigterm que es para terminar el programa que esta corriendo
* TAB para autocompletar

## Editor de texto (5min)
(Palabras sobre herramientas e IDEs)
(Filosofia UNIX)

Para abrir editor de text desde terminal:
```code nombre_del_archivo```

## Editar y compilar programas (10 min)
Compilar:
```g++ -Wall -Werror nombre_del_archivo.cpp```

Opciones: -Wall es para mostrar warnings
          -Werror es para convertir warning en error para que falla de compilar
          si tienes warnings.

## IO Streams
* stdout / stderr : corresponde a lo que sale impreso al terminal. 
  secorresponde cout y cer en c++. Redirecta con > y 2>
* stdin: corresponde a lo que tipea en el terminal, corresponde cin, redirecta con <
* diff: compara 2 archivos

```./a.out < input.txt > output.txt```




# gdb (15 min)
* break b: poner un break point
* next n: siguiente linea saltando funciones
* step s: siguiente linea entrando funciones
* bt: ver stacktrace
* run: correr el programa

Session 1: Basicas de C++ (1 hora)
=========================
Meta: cubrir lo mismo que tutorial de Omega Up; pero
con enfasis en quirks de C++

# Tipos
* Notas sobre shadowing
* Decl-assign
## Enteros
* `int64_t` y `uint64_t`
## float
* Usar double

# Operaciones matematicas
* Overflow
* Modulo de negativos
##

# Condicionales / Ciclos / Funciones
* Igual dentro del if
* break / continue / return

# Arreglos / Punteros / Cadenas
* Arreglos de varias dimensiones

# Vector vs. Arreglos, cstring vs string / referencias

# Miscelaneos
* Globales y const
* macros
* plantillas de funciones

# Recomendaciones generales
* Mantener curiosidad
* Leer codigos
* Si no sabe, intentas
* [Como ser hacker](https://sindominio.net/biblioweb/telematica/hacker-como.html)
   de Eric Reymond



