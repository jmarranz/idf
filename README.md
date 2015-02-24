Integrador de Diagramas de Flujo (IDF)
========

Integrador de Diagramas de Flujo (IDF) es aplicaci�n visual para Windows XP o superior para el dise�o a trav�s de herramientas visuales y ejecuci�n de diagramas de flujo 
cuyo comportamiento est� codificado en C++ y cargado din�micamente a trav�s de DLLs.

Historia
------

IDF fue mi proyecto fin de carrera desarrollado en la Escuela T�cnica Superior de Ingenieros Industriales de Madrid (ETSIIM), no recuerdo el a�o en el que lo comenc� en el 
Departamento de Electr�nica, la finalidad era poder simular algoritmos a trav�s de diagramas de flujo con el fin de ser �til para la programaci�n de circuitos digitales.

IDF fue mi primer contacto "serio" con el desarrollo software aunque en el instituto de secundaria diera mis primeros pasos con el BASIC de un Amstrad, GWBASIC en PCs y un 
poquito de TurboPascal 3.0. Ese primer contacto fue entrar por la puerta grande, programaci�n de GUIs (Win32 y MFC) orientado a objetos en C++,  estrenando el flamante 
Microsoft Visual C++ 1.0 que empez� a convertir a Microsoft en el l�der indiscutible en herramientas de desarrollo software para Windows desplazando a Borland.

Pero la puerta grande ten�a un enorme agujero, el sistema operativo, creo recordar Windows 95, Windows 95 era un sistema operativo mediocre, mediocre no tanto debido a la incompetencia de los 
programadores de Microsoft sino a la herencia envenenada de construir un sistema operativo moderno sobre MSDOS, por ejemplo era incapaz de liberar las DLLs enlazadas din�micamente
cuando la aplicaci�n cargadora mor�a, ello me obligaba a apagar el ordenador y volver a cargar el sistema cada vez que ejecutaba la aplicaci�n. Afortunadamente fui capaz de
desarrollar un sencillo programa que descargaba "manualmente" dichas DLLs, tiempo m�s tarde Windows NT sac� a Windows de la mediocridad poniendo MSDOS en su sitio (encima de Windows 
no debajo).

Por razones econ�micas acept� becas y posteriormente contratos de trabajo en el Laboratorio de Inform�tica de la ETSIIM donde me dediqu� fundamentalmente a hacer webs en C++ (s� en C++)
usando ObjectStore y su extensi�n para el desarrollo web. IDF qued� parado durante algunos a�os.

Posteriormente con el fin de terminar la carrera retom� IDF y lo termin� en el Laboratorio de Inform�tica y lo present� a trav�s de dicho departamento.

A�os despu�s intent� continuarlo con el fin incluso de llegar a venderlo pero no me interesaba suficiente.

El estado actual del c�digo compila al menos en Visual C++ 2005 y requiere Windows XP como m�nimo.

Funcionamiento
------

IDF es una aplicaci�n Windows tipo MDI (Multi Document Interface), lo habitual de la �poca, tiene dos modos de funcionamiento:

1. Archivos (documentos) de dise�o de diagramas 

   El resultado del dise�o de un diagrama es un archivo XML o L.D.D. que describe el "layout" del diagrama y sus bindings con las librer�as DLL que contienen el c�digo a ejecutar.
   La herramienta permite el dise�o visual de los diagramas (bloques y conectores) partiendo de cero o de un L.D.D. ya existente, generando si se quiere el LDD resultado del dise�o, 
tambi�n es posible guardar el resultado en binario (serializado) con la extensi�n .dds asociada autom�ticamente a la aplicaci�n en su primera ejecuci�n.
   Es posible la creaci�n de bloques-diagrama que tienen asociado otro diagrama que ser� otro documento en la aplicaci�n, IDF se encarga de vincular autom�ticamente el ciclo 
de vida de ambos documentos abiertos. 

![Captura Dise�o](img/captura_disenyo.png "Captura")

2. Archivos (documentos) de ejecuci�n de diagramas



