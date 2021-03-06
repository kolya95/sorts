#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "highlighter.h"
#include "actorinterface.h"
#include "kumirinterface.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    friend class Runner;
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
public Q_SLOTS:
    void fileSave();
    void fileOpen();
    void Run();
    void output(const QString & text);
    void errOutput(const QString & text);
    void reEnabled();
    void Stop();

private:
    Ui::MainWindow *ui;
    class Runner * runner_;
    Highlighter* highlighter;

    QTextCursor* cursor_, *cur;
    bool undoAv, redoAv;


    class kumirInterface* k;

    void readSettings();
    void writeSettings();

};


#endif // MAINWINDOW_H
