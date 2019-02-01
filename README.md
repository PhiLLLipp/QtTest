Code mit QT-Inhalten compilieren
```bash
qmake -project
```
In die .pro Datei irgendwo `QT += widgets` einfügen und dann
```bash
qmake
```
ausführen. Zu guter letzt noch `make` ausführen und fertig.
