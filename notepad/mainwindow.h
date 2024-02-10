#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_close_file_triggered();

    void on_action_4_triggered();

    void on_color_triggered();

    void on_shrift_triggered();

    void on_open_triggered();

    void on_Create_triggered();

    void on_save_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
