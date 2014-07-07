msp430-cmasmas
==============

##Programacion de msp430 en c++ con codeblocks:

###Descripción:
*En este repositorio se plasman mi proceso de aprendizaje en la programación de los microcontroladores msp430 de Texas Instruments con el entorno de desarrollo Code::Block en C++*

###Description
*In this repository are learning process are reflected in the programming of microcontrollers from Texas Instruments msp430 development environment with Code :: Block in C + +*

###Instalando y configurando Code::Blocks:

####configuración del tool chain para el msp430:

####Instalación de paquetes necesarios:

`` ``
``sudo apt-get install binutils-msp430 gcc-msp430 gdb-msp430 msp430-libc msp430mcu mspdebug``
`` ``
``sudo nano /etc/udev/rules.d/60-tilaunchpad.rules``
`` ``
Con esto habilitamos el acceso sin necesidad de ser root:

`` ``
``sudo touch /etc/udev/rules.d/60-tilaunchpad.rules``
`` ``

escribimos lo siguiente:

`` ``
``SUBSYSTEM=="usb",ATTR{idVendor}=="0451",ATTR{idProduct =="f432",GROUP="dialout",MODE="666"``
`` ``
reiniciamos udev:

`` ``
``sudo /etc/init.d/udev restart``
`` ``

Es conveniente instalar el codeblocks luego de haber instalado el tool chain de msp430, ya que de esta forma vamos a lograr que este lo reconzca.

vamos a settings-> compilers&debugers

###en selected compiler:

GNU GCC compiler for MSP430

Linker settings:
- Link libraries:
- /usr/msp430/lib/libc.a
- /usr/msp430/lib/libfp.a
- /usr/msp430/lib/libm.a
- /usr/msp430/lib/mcpu-430x/libc.a
- /usr/msp430/lib/mcpu-430x/libfp.a
- /usr/msp430/lib/mcpu-430x/libm.a

search directories:
- /opt/mspgcc/include
- /usr/msp430/include

en Toolchain executables:
El Code::Blocks encuentra sólo los siguientes binarios

- C Compiler msp430-gcc
- C++ Compiler msp430-gcc
- Linker for Dynamic Links msp430-gcc
- Linker for Static Links msp430-ar
- Debugger msp430-gdb
- Resource Compiler -
- Make Program make

En Project-> settings
En debuger
- ip: localhost port:2000

- aditional GDB commands:
- erase
- load
- continue

project->build option
chequear:
- Produce debugging symbols
- Enable all compiler warnings
- Optimize even more
- Optimize generated code

En Other options:
- -mmcu=msp430x2553
- -fdata-sections
- -ffunction-sections
- -print-gc-sections


Para correr el mspdedebug y que se conecte con el code::blocks el cual está corriendo el msp430-gdb abrimos una consola y ejecutamos lo siguiente:

`` ``
``mspdebug rf2500 "gdb"``
`` ``
