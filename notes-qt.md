

### MISC

* uic ==> mainwindow.ui --> mainwindow.h
* moc ==> mainwindow.h  --> mainwindow.cpp
* g++ ==>

```bash
uic mainwindow.ui -o mainwindow.h
moc mainwindow.h  -o mainwindow.cpp
g++ main.cpp mainwindow.cpp  moc_mainwindow.cpp \
-IC:\Qt\4.8.4\include \
-LC:\Qt\4.8.4\lib \
-lQtCore4 \
-lQtGui4 \
-o main
```
