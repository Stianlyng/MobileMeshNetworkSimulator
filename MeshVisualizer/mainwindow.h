#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>   

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refreshNetworkVisualization();
    void setInfoLabelText(const QString& text); 

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QLabel* infoLabel;  
};

#endif // MAINWINDOW_H