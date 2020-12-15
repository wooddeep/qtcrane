#ifndef CRANEOVERLOOK_H
#define CRANEOVERLOOK_H

#include <QWidget>

namespace Ui {
class CraneOverlook;
}

class CraneOverlook : public QWidget
{
    Q_OBJECT

private:
    float rotate = 45;
    //float bigArmLen = ;

public:
    explicit CraneOverlook(QWidget *parent = nullptr);
    ~CraneOverlook();

    void resize(QResizeEvent* event);
    void resize(int w, int h);
    QSize size();
    void paintEvent(QPaintEvent *);

    void setAttribute(float rotate, float bigArmLen, float shortArmLen);

private:
    Ui::CraneOverlook *ui;
};

#endif // CRANEOVERLOOK_H
