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
| File IO implementierung    | jklepp    |  2013-11-12  |  19:30  |  20:20  |     0:50  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Makefile                   | jklepp    |  2013-11-12  |  21:40  |  22:25  |     0:45  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Sudoku                     | mhaidn    |  2013-11-13  |  15:00  |  16:05  |     1:05  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| testsudokus                | jklepp    |  2013-11-13  |  15:20  |  22:30  |     0:10  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Änderungen an File IO      | jklepp    |  2013-11-13  |  15:30  |  22:45  |     0:15  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| X-Sudoku                   | mhaidn    |  2013-11-13  |  16:10  |  17:00  |     0:50  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Änderung X-Sudoku          | mhaidn    |  2013-11-13  |  17:10  |  17:45  |     0:35  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Fehlersuche                | jklepp    |  2013-11-13  |  17:45  |  21:00  |     3:15  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Fehlersuche                | mhaidn    |  2013-11-13  |  17:45  |  21:00  |     3:15  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Fehler lösen               | jklepp    |  2013-11-13  |  21:40  |  21:45  |     0:05  |
+----------------------------+-----------+--------------+---------+---------+-----------+
| Dokument fertigstellen     | jklepp    |  2013-11-13  |  21:45  |  21:55  |     0:10  |
+----------------------------+-----------+--------------+---------+---------+-----------+

=======
Testing
=======
Tests werden automatisch durch das Makefile durchgeführt. Es werden eine Reihe
von Testfällen durchgeführt. 3 funktionierende normale Sudokus, ein nicht 
lösbares normales Sudoku und 2 X-Sudokus.

.. code:: bash

    $ make test

    ./csudoku.out < res/sudoku_01.txt # sudoku #1
    0 5 9 0 0 1 4 2 0 
    7 3 0 0 4 2 9 6 5 
    6 0 0 0 9 0 0 0 0 
    0 0 4 0 3 0 0 0 0 
    9 0 0 6 0 4 0 0 7 
    0 0 0 0 8 0 6 0 0 
    0 0 0 0 1 0 0 0 2 
    2 1 6 4 5 0 0 8 9 
    0 9 3 2 0 0 5 1 0 

    Geschaft? true
    8 5 9 7 6 1 4 2 3 
    7 3 1 8 4 2 9 6 5 
    6 4 2 3 9 5 8 7 1 
    1 6 4 5 3 7 2 9 8 
    9 8 5 6 2 4 1 3 7 
    3 2 7 1 8 9 6 5 4 
    5 7 8 9 1 6 3 4 2 
    2 1 6 4 5 3 7 8 9 
    4 9 3 2 7 8 5 1 6 

    ./csudoku.out < res/sudoku_02.txt # sudoku #2
    0 0 0 4 0 1 0 2 0 
    0 0 0 0 0 2 0 0 0 
    0 7 0 0 0 5 3 0 4 
    4 0 7 0 0 0 1 3 0 
    6 0 0 0 0 9 5 0 0 
    0 0 0 0 7 0 0 0 9 
    0 0 0 0 9 0 8 0 0 
    7 0 1 0 0 3 0 0 0 
    0 5 4 0 0 0 0 0 0 

    Geschaft? true
    5 3 9 4 8 1 7 2 6 
    8 4 6 7 3 2 9 5 1 
    1 7 2 9 6 5 3 8 4 
    4 9 7 2 5 6 1 3 8 
    6 1 8 3 4 9 5 7 2 
    3 2 5 1 7 8 6 4 9 
    2 6 3 5 9 4 8 1 7 
    7 8 1 6 2 3 4 9 5 
    9 5 4 8 1 7 2 6 3 

    ./csudoku.out < res/sudoku_03.txt # Unschaffbares Sudoku
    0 3 7 5 1 9 8 0 4 
    8 0 5 7 2 9 1 3 6 
    0 2 1 3 0 8 5 7 0 
    3 6 0 1 9 5 7 0 2 
    2 0 4 6 3 0 9 5 8 
    5 7 9 8 4 2 0 6 1 
    7 8 6 0 5 1 2 9 3 
    0 5 3 2 8 6 4 0 7 
    1 4 2 9 0 3 6 8 5 

    Geschaft? false
    0 3 7 5 1 9 8 0 4 
    8 0 5 7 2 9 1 3 6 
    0 2 1 3 0 8 5 7 0 
    3 6 0 1 9 5 7 0 2 
    2 0 4 6 3 0 9 5 8 
    5 7 9 8 4 2 0 6 1 
    7 8 6 0 5 1 2 9 3 
    0 5 3 2 8 6 4 0 7 
    1 4 2 9 0 3 6 8 5 

    ./csudoku.out < res/sudoku_04.txt # Sudoku aus dem Beispielcode
    3 0 6 5 0 8 4 0 0 
    5 2 0 0 0 0 0 0 0 
    0 8 7 0 0 0 0 3 1 
    0 0 3 0 1 0 0 8 0 
    9 0 0 8 6 3 0 0 5 
    0 5 0 0 9 0 6 0 0 
    1 3 0 0 0 0 2 5 0 
    0 0 0 0 0 0 0 7 4 
    0 0 5 2 0 6 3 0 0 

    Geschaft? true
    3 1 6 5 7 8 4 9 2 
    5 2 9 1 3 4 7 6 8 
    4 8 7 6 2 9 5 3 1 
    2 6 3 4 1 5 9 8 7 
    9 7 4 8 6 3 1 2 5 
    8 5 1 7 9 2 6 4 3 
    1 3 8 9 4 7 2 5 6 
    6 9 2 3 5 1 8 7 4 
    7 4 5 2 8 6 3 1 9 

    ./csudoku.out x < res/xsudoku_01.txt # X-Sudoku
    5 0 0 3 2 0 0 0 7 
    0 0 0 0 0 0 0 0 4 
    0 0 0 0 8 0 0 0 0 
    0 8 0 0 7 0 0 0 0 
    6 3 0 8 4 0 0 7 0 
    9 0 0 0 3 1 4 0 0 
    0 0 5 0 0 0 0 0 0 
    0 0 0 9 5 8 0 6 0 
    0 0 1 0 0 0 0 0 0 

    Geschaft? true
    5 1 6 3 2 4 9 8 7 
    3 7 8 5 9 6 2 1 4 
    2 4 9 1 8 7 3 5 6 
    1 8 4 2 7 9 6 3 5 
    6 3 2 8 4 5 1 7 9 
    9 5 7 6 3 1 4 2 8 
    7 6 5 4 1 3 8 9 2 
    4 2 3 9 5 8 7 6 1 
    8 9 1 7 6 2 5 4 3 

    ./csudoku.out x < res/xsudoku_02.txt # X-Sudoku
    0 0 0 2 8 0 0 0 0 
    0 3 0 0 6 0 0 0 0 
    0 2 0 0 0 0 6 0 0 
    0 0 0 0 0 5 0 2 0 
    0 4 0 0 0 9 0 1 0 
    8 0 0 0 4 0 0 0 0 
    1 9 0 3 0 0 0 0 2 
    0 0 7 0 2 6 0 0 0 
    0 0 5 0 0 0 7 0 0 

    Geschaft? true
    9 7 6 2 8 1 5 4 3 
    5 3 8 7 6 4 2 9 1 
    4 2 1 5 9 3 6 8 7 
    7 1 9 6 3 5 4 2 8 
    6 4 2 8 7 9 3 1 5 
    8 5 3 1 4 2 9 7 6 
    1 9 4 3 5 7 8 6 2 
    3 8 7 4 2 6 1 5 9 
    2 6 5 9 1 8 7 3 4 

Wie zu sehen ist konnten alle Sudokus bis auf das unlösbare mit der Nummer 3
gelöst werden.

.. header::
    +--------+---------------------------------+
    | Autor  | Martin Haidn & Jakob Klepp      |
    +--------+---------------------------------+
    | Titel  | ###Title###                     |
    +--------+---------------------------------+
    | Datum  | 13.11.2013                      |
    +--------+---------------------------------+
    
.. footer::
    ###Page### / ###Total###
