Integrador de Diagramas de Flujo (IDF)
========

Integrador de Diagramas de Flujo (IDF) es una aplicaci�n visual para Windows XP o superior para el dise�o y ejecuci�n de diagramas de flujo a trav�s de herramientas visuales,
el comportamiento est� codificado en C++ y cargado din�micamente a trav�s de DLLs.

Es una aplicaci�n terminada en 1998 con alguna peque�a modificaci�n posterior.

Descarga e Instalaci�n
------

Descarga el archivo zip de distribuci�n en [SourceForge.net](https://sourceforge.net/projects/integdiagflujo/files/)

Crea una carpeta en el lugar que quieras y descomprime el zip dentro de ella. El ejecutable es Idf.exe.

Desinstalaci�n
------

Elimina la carpeta que creaste en la instalaci�n. Puede interesarte eliminar la asociaci�n de archivos .dds y .dex

1. Windows XP: sigue estas [instrucciones](https://www.microsoft.com/resources/documentation/windows/xp/all/proddocs/en-us/win_fcab_reg_filetype_modify.mspx?mfr=true)

2. Windows Vista y superiores: ejecutar unassoc.exe incluido en la distribuci�n


Funcionamiento
------

IDF (Idf.exe) es una aplicaci�n Windows tipo MDI (Multi Document Interface), lo habitual de la �poca, tiene dos modos de funcionamiento:

1. Archivos (documentos) de dise�o de diagramas 

   El resultado del dise�o de un diagrama es un archivo XML llamado L.D.D. que describe el "layout" del diagrama y sus bindings con las librer�as DLL que contienen el c�digo a ejecutar.

   La herramienta permite el dise�o visual de los diagramas (bloques y conectores) partiendo de cero o de un L.D.D. ya existente, generando si se quiere el LDD resultado del dise�o, 
tambi�n es posible guardar el resultado en binario (serializado) con la extensi�n .dds asociada autom�ticamente a la aplicaci�n en su primera ejecuci�n.

   Es posible la creaci�n de bloques-diagrama que tienen asociado otro diagrama que ser� otro documento en la aplicaci�n, IDF se encarga de vincular autom�ticamente el ciclo 
de vida de ambos documentos abiertos (esta coordinaci�n es at�pica en una aplicaci�n MFC). 

   A trav�s del UI se obtiene el c�digo .h y .cpp que servir� de punto de entrada al c�digo del usuario del bloque programado en la DLL que lo contiene, dicha DLL se programa usando IDF headers y lib
creados con este fin (es posible programar m�ltiples bloques en una misma DLL y usar varias DLLs a la vez).

![Captura Dise�o](img/captura_disenyo.png)

2. Archivos (documentos) de ejecuci�n de diagramas

   A partir de un LDD es posible crear un diagrama "ejecutable", este diagrama no modificable a nivel de dise�o, cargar� las DLLs declaradas as� como los bindings a las clases. 
Es posible guardar el resultado en binario (serializado) con la extensi�n .dex asociada autom�ticamente a la aplicaci�n en su primera ejecuci�n.

   De la misma manera que en dise�o, en ejecuci�n pueden estar dos o m�s documentos vinculados cuando hay una relaci�n de jer�rquica por la existencia de bloques-diagrama.

![Captura Ejecuci�n](img/captura_ejecucion.png)


Documentaci�n
------

Documentaci�n en detalle se encuentra en la memoria de mi fin de carrera, es posible que algunos cambios realizados posteriormente no est�n documentados tal y como
los nuevos nombres de las extensiones .dds y .dex, pero dichos cambios son menores.

[Portada](docs/Portada.doc?raw=true)

[Proyecto](docs/Proyecto.doc?raw=true)

[Diapositivas](docs/IDF_proy.ppt?raw=true)


Ejemplos
------

En el archivo de distribuci�n se encuentran una serie de LDDs as� como una DLL, DLLDiag.dll, con el c�digo en C++ descrito en los LDDs.

Se recomienda usar el ejemplo Newton.xml y el ejemplo con subdiagramas Nwbase.xml (que se vincula a su vez a Newton.xml). Es posible que haya que cambiar paths (para localizar la DLL) 
para poder ejecutar ambos ejemplos.


Licencias
------

* C�digo fuente de Idf.exe: GNU GPL v3.0

* C�digo fuente de IdfLib (necesario para el desarrollo de DLLs): GNU LGPL v3.0

* C�digo fuente de DLLDiag : MIT, Apache v2, la que te de la gana


Autor y Copyright
------

Jose Mar�a Arranz Santamar�a (Spanish citizen)


Historia
------

IDF fue mi proyecto fin de carrera desarrollado en la Escuela T�cnica Superior de Ingenieros Industriales de Madrid (ETSIIM), no recuerdo el a�o en el que lo comenc� en el 
Departamento de Electr�nica, la finalidad era poder simular algoritmos a trav�s de diagramas de flujo con el fin de ser �til para la programaci�n de circuitos digitales.

IDF fue la aplicaci�n que me inclin� de forma definitiva hacia el desarrollo software en el sentido m�s abierto en vez de seguir el camino de la micro-electr�nica digital
(que hoy d�a es tambi�n b�sicamente software). El desarrollo software de prop�sito general me mostraba un mundo much�s�simo m�s abierto y de alto nivel que la programaci�n
de circuitos electr�nicos, pronto IDF se convirti� en una herramienta totalmente gen�rica sin ninguna vinculaci�n directa con la microelectr�nica, al mismo tiempo
que me aportaba experiencia para acceder a trabajos de "programador". Despu�s de tantos a�os no me arrepiento a pesar del usual maltrato de la profesi�n de programador,
en muchos casos considerado como un "pe�n alba�il" o un transitorio entretenimiento para ni�os avispados.

IDF fue mi primer contacto "serio" con el desarrollo software aunque en el instituto de secundaria diera mis primeros pasos con el BASIC de un Amstrad, GWBASIC en PCs y un 
poquito de TurboPascal 3.0 en dichos PCs. Ese primer contacto fue entrar por la puerta grande, programaci�n de GUIs (Win32 y MFC) orientado a objetos en C++,  estrenando el flamante 
Microsoft Visual C++ 1.0 que empez� a convertir a Microsoft en el l�der indiscutible en herramientas de desarrollo software para Windows desplazando a Borland.

Pero la puerta grande ten�a un enorme agujero, el sistema operativo, creo recordar Windows 95 o anterior, Windows 95 era un sistema operativo mediocre, mediocre no tanto debido a la incompetencia de los 
programadores de Microsoft sino a la herencia envenenada de construir un sistema operativo moderno sobre MSDOS, por ejemplo era incapaz de liberar las DLLs enlazadas din�micamente
cuando la aplicaci�n cargadora mor�a, ello me obligaba a apagar el ordenador y volver a cargar el sistema CADA VEZ que ejecutaba la aplicaci�n y �sta fallaba. Afortunadamente fui capaz de
desarrollar un sencillo programa que descargaba "manualmente" dichas DLLs, tiempo m�s tarde Windows NT sac� a Windows de la mediocridad poniendo MSDOS en su sitio (encima de Windows 
no debajo).

Por razones de necesidad econ�mica acept� becas y posteriormente contratos de trabajo en el Laboratorio de Inform�tica de la ETSIIM donde me dediqu� fundamentalmente a hacer webs en C++ (s� en C++)
usando ObjectStore y su extensi�n para el desarrollo web y posteriormente en Java (en torno al a�o 1999 quiz�s). IDF qued� parado durante algunos a�os.

Posteriormente con el fin de terminar la carrera retom� IDF y lo termin� en el Laboratorio de Inform�tica y lo present� como fin de carrera a trav�s de dicho departamento en 1998.

A�os despu�s intent� continuarlo con el fin incluso de llegar a venderlo pero no me interesaba suficiente.

El estado actual del c�digo compila al menos en Visual C++ 2005 y requiere Windows XP como m�nimo (ajustes realizados antes de subir a GitHub).

A la hora de valorar la calidad del c�digo fuente, se benevolente y ten en cuenta que es el resultado de un jovencito aprendiz de programador, aunque no se si hoy d�a soy mucho mejor
t�cnico que en aquel entonces :) 
