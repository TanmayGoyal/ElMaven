#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QDir>
#include <QtDebug>
#include <QProcess>
//#include "include/qs3/qs3.h"
#include <QDateTime>
#include <QEventLoop>
#include <QStatusBar>
#include <QStatusBar>

#ifdef Q_OS_WIN
class FileUploader;
#endif

class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT

public:

#ifdef Q_OS_WIN
    explicit MainWindow(QWidget *parent,FileUploader* uploader);
#endif

#if defined(Q_OS_UNIX)
    MainWindow(QWidget* parent, const QString& path);
#endif

    ~MainWindow();
    QString restartApplicationPath;
    QString accessKey;
    QString secretKey;
    QString bucketName;
    QString logInformation;
    int windowState;
    void onStart();

protected:
    virtual void closeEvent(QCloseEvent *event) override;

public slots:
    void readOutput();
    void readError();
    void finished(int exitCode);
    void started();
    void processError(QProcess::ProcessError perr);
    void uploadLogs();

private:
    Ui::MainWindow *ui;
    void startElMaven();

private Q_SLOTS:

    void on_cancel_clicked();

    void on_reportRestart_clicked();

private:
#ifdef Q_OS_WIN
    FileUploader* uploader;
#endif

#if defined (Q_OS_UNIX)
    QString logsPath;
#endif
    QProcess* _process;
    QString _script;
    QString _logs;
    QStringList _logsPath;
};

#endif // MAINWINDOW_H
