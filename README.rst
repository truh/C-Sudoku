###########
Sudoku in C
###########
================
Aufgabenstellung
================
~~~~~~~~~~~~
Beschreibung
~~~~~~~~~~~~
Erstellen Sie einen Algorithmus zur Lösung von Sudokurätseln. Dabei sollen 
nicht nur klassische Sudokus gelöst werden können, sondern zumindest ein 
ähnliches Rätsel (z.B. X-Sudoku oder Squiggly) [1]_. Die Eingabe der Rätsel 
erfolgt zwingend über Dateien (csv) [2]_. Optional kann es auch händisch über 
die Konsolenapplikation eingegeben werden (zusätzlich zum Ladevorgang aus 
einer Datei), wobei dann das Rätsel auch abspeicherbar sein soll.

Das Menü soll somit die gewählten zwei Rätselalgorithmen anzeigen, eine 
Lademöglichkeit anbieten und optional eine Eingabemöglichkeit.

~~~~~~~~
Teamwork
~~~~~~~~
Diese Aufgabenstellung MUSS von zwei Schülern gelöst werden, um das Trennen von
Funktionen und Arbeitsteilung zu trainieren. Verwenden Sie auf jeden Fall 
selbsterstellte Headerdateien und lagern Sie zumindest den 
Berechnungsalgorithmus in eine eigene .c-Datei aus! Es muss ein Headerfile für 
das Kompilieren und Linken sowie Ausführen und Aufräumen bereitgestellt werden.

~~~~~~
Abgabe
~~~~~~
Es ist auf jeden Fall ein Protokoll über die Arbeitsschritte und die verwendete
Logik zu erstellen. Dabei sind auch Testfälle zu beschreiben. Das Protokoll 
muss als PDF-Dokument den Sources beigegeben und als ZIP Archiv abgegeben 
werden.

~~~~~
Links
~~~~~
.. _1:

[1] `Sudoku <http://en.wikipedia.org/wiki/Sudoku>`_ 

.. _2: 

[2] `Formatiertes Einlesen/Ausgeben von Streams mit fprintf() und fscanf() 
<http://openbook.galileocomputing.de/c_von_a_bis_z/016_c_ein_ausgabe_
funktionen_009.htm#mje5a9730700783816c72f0f4556b59d10>`_

=======
Planung
=======
~~~~~~~~~~~~~~~~~~~~~~
Ablauf implementierung
~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~
Aufwandsschätzung
~~~~~~~~~~~~~~~~~
+-------------------------------+---------------+-------------+
|            Schritt            | Geplante Zeit |   Aufwand   |
|                               |     [H:MM]    |             |
+===============================+===============+=============+
| Prototypen                    |      0:30     |   Mittel    |
+-------------------------------+---------------+-------------+
| Sudoku Struct                 |      0:10     |   Gering    |
+-------------------------------+---------------+-------------+
| CLI                           |      0:20     |   Gering    |
+-------------------------------+---------------+-------------+
| Makefile                      |      0:30     |   Mittel    |
+-------------------------------+---------------+-------------+
| File IO                       |      1:30     |    Hoch     |
+-------------------------------+---------------+-------------+
| Anpassen Sudoku Algorithmus   |      0:30     |   Mittel    |
+-------------------------------+---------------+-------------+
| XSudoku                       |      1:30     |    Hoch     |
+-------------------------------+---------------+-------------+
| Testen                        |      0:15     |   Gering    |
+-------------------------------+---------------+-------------+
| Dokumentation                 |      1:00     |   Mittel    |
+-------------------------------+---------------+-------------+

===============
Implementierung
===============
~~~~~~~~~~~~~~~~
Zeitaufzeichnung
~~~~~~~~~~~~~~~~
+----------------------------+-----------+--------------+---------+---------+-----------+
| Task                       | By        | Date         | From    | To      | Duration  |
+----------------------------+-----------+--------------+---------+---------+-----------+
|                            |           | [YYYY-MM-DD] | [HH:MM] | [HH:MM] |    [H:MM] |
+============================+===========+==============+=========+=========+===========+
| Dokument vorbereiten       | jklepp    |  2013-11-12  |  13:10  |  13:30  |     0:20  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Prototypen                 | jklepp    |  2013-11-12  |  18:50  |  19:10  |     0:20  |
+----------------------------+-----------+--------------+---------+---------+-----------+

=======
Testing
=======

.. header::
	+--------+---------------------------------+
	| Autor  | Martin Haidn & Jakob Klepp      |
	+--------+---------------------------------+
	| Titel  | ###Title###                     |
	+--------+---------------------------------+
	| Datum  | 12.11.2013                      |
	+--------+---------------------------------+
	
.. footer::
	###Page### / ###Total###