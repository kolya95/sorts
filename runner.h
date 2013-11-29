#ifndef RUNNER_H
#define RUNNER_H
#include <QThread>
#include <QtCore>
#include <QtGui>
#include <Python.h>
class Runner : public QThread
{
    Q_OBJECT
public:
    explicit Runner(class MainWindow *parent);

    void init(const QString& lines);
    
    void run();

    void stop();
    ~Runner();

    static PyObject* pythonPrint(PyObject*,PyObject* args);
    static void pyImport();
Q_SIGNALS:
    void doOutput(const QString &);
    
public Q_SLOTS:

private:
    PyObject * runModule;
    class MainWindow * mw_;
    QStringList lines;
    char* programmText;
    PyThreadState* interpretator;
    QTextEdit * out;
    bool mustrun_;
    QMutex * mutex_;
//    static PyObject* init_functions();
};
static PyObject* init_functions();
static Runner* RUN;
#endif // RUNNER_H
