Integrador de Diagramas de Flujo (IDF)
========

Integrador de Diagramas de Flujo (IDF) es aplicación visual para Windows XP o superior para el diseño a través de herramientas visuales y ejecución de diagramas de flujo 
cuyo comportamiento está codificado en C++ y cargado dinámicamente a través de DLLs.

Historia
------

IDF fue mi proyecto fin de carrera desarrollado en la Escuela Técnica Superior de Ingenieros Industriales de Madrid (ETSIIM), no recuerdo el año en el que lo comencé en el 
Departamento de Electrónica, la finalidad era poder simular algoritmos a través de diagramas de flujo con el fin de ser útil para la programación de circuitos digitales.

IDF fue mi primer contacto "serio" con el desarrollo software aunque en el instituto de secundaria diera mis primeros pasos con el BASIC de un Amstrad, GWBASIC en PCs y un 
poquito de TurboPascal 3.0. Ese primer contacto fue entrar por la puerta grande, programación de GUIs (Win32 y MFC) orientado a objetos en C++,  estrenando el flamante 
Microsoft Visual C++ 1.0 que empezó a convertir a Microsoft en el líder indiscutible en herramientas de desarrollo software para Windows desplazando a Borland.

Pero la puerta grande tenía un enorme agujero, el sistema operativo, creo recordar Windows 95, Windows 95 era un sistema operativo mediocre, mediocre no tanto debido a la incompetencia de los 
programadores de Microsoft sino a la herencia envenenada de construir un sistema operativo moderno sobre MSDOS, por ejemplo era incapaz de liberar las DLLs enlazadas dinámicamente
cuando la aplicación cargadora moría, ello me obligaba a apagar el ordenador y volver a cargar el sistema cada vez que ejecutaba la aplicación. Afortunadamente fui capaz de
desarrollar un sencillo programa que descargaba "manualmente" dichas DLLs, tiempo más tarde Windows NT sacó a Windows de la mediocridad poniendo MSDOS en su sitio (encima de Windows 
no debajo).

Por razones económicas acepté becas y posteriormente contratos de trabajo en el Laboratorio de Informática de la ETSIIM donde me dediqué fundamentalmente a hacer webs en C++ (sí en C++)
usando ObjectStore y su extensión para el desarrollo web. IDF quedó parado durante algunos años.

Posteriormente con el fin de terminar la carrera retomé IDF y lo terminé en el Laboratorio de Informática y lo presenté como fin de carrera a través de dicho departamento en 1998.

Años después intenté continuarlo con el fin incluso de llegar a venderlo pero no me interesaba suficiente.

El estado actual del código compila al menos en Visual C++ 2005 y requiere Windows XP como mínimo.

Funcionamiento
------

IDF es una aplicación Windows tipo MDI (Multi Document Interface), lo habitual de la época, tiene dos modos de funcionamiento:

1. Archivos (documentos) de diseño de diagramas 

   El resultado del diseño de un diagrama es un archivo XML o L.D.D. que describe el "layout" del diagrama y sus bindings con las librerías DLL que contienen el código a ejecutar.

   La herramienta permite el diseño visual de los diagramas (bloques y conectores) partiendo de cero o de un L.D.D. ya existente, generando si se quiere el LDD resultado del diseño, 
también es posible guardar el resultado en binario (serializado) con la extensión .dds asociada automáticamente a la aplicación en su primera ejecución.

   Es posible la creación de bloques-diagrama que tienen asociado otro diagrama que será otro documento en la aplicación, IDF se encarga de vincular automáticamente el ciclo 
de vida de ambos documentos abiertos. 

   A través de la interfase se genera el código .h y .cpp que servirá de punto de entrada al código del usuario programado en una (o varias) DLL (dicha DLL se programa usando IDF headers y lib
creados con este fin).

![Captura Diseño](img/captura_disenyo.png)

2. Archivos (documentos) de ejecución de diagramas

   A partir de un LDD es posible crear un diagrama "ejecutable", este diagrama no modificable a nivel de diseño, cargará las DLLs declaradas así como los bindings a las clases 
Es posible guardar el resultado en binario (serializado) con la extensión .dex asociada automáticamente a la aplicación en su primera ejecución.

   De la misma manera que en diseño, en ejecución pueden estar dos o más documentos vinculados cuando hay una relación de jerárquica por la existencia de bloques-diagrama.

![Captura Ejecución](img/captura_ejecucion.png)


Documentación
------

Documentación en detalle se encuentra en la memoria de mi fin de carrera, es posible que algunos cambios realizados posteriormente no se correspondan.

[Portada](docs/Portada.doc)

[Proyecto](docs/Proyecto.doc)

[Diapositivas](docs/IDF_proy.ppt)


