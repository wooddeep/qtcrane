#include "craneoverlook.h"
#include "ui_craneoverlook.h"

#include <QPainter>
#include <QtMath>
#include <QDebug>

CraneOverlook::CraneOverlook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CraneOverlook)
{
    ui->setupUi(this);

}

void CraneOverlook::resize(QResizeEvent* event)
{
    //QWidget::resize(size);
    //this->_label->resize(size);
    //this->resize(size);

    this->resize(event);

    qDebug() << "resize[0]" << endl;
}


// QT 画图：
// https://blog.csdn.net/weixin_39609623/article/details/90670204

void CraneOverlook::paintEvent(QPaintEvent *)
{
    float penWidth = 3;
    QPainter painter(this);
    QBrush brush(Qt::blue);
    QBrush brushArm(Qt::yellow);
    QPen pen(brush, penWidth, Qt::SolidLine, Qt::RoundCap);
    QPen penArm(brushArm, penWidth, Qt::SolidLine, Qt::RoundCap);
    /**********************启用抗锯齿功能**************************/

    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(penArm);

    float shortArmLen = 10;
    float longArmLen = height() / 2;

    float radius = longArmLen - penWidth;
    float centerX = width() / 2;
    float centerY = height() / 2;

    float startX = centerX - radius;
    float startY = centerY - radius;

    float recWidth = 2 * radius;
    float recHeight = 2 * radius;

    qreal angle = this->rotate;

    float endpointX = centerX + (longArmLen - penWidth) * qCos(M_PI * angle / 180);
    float endpointY = centerY - (longArmLen - penWidth) * qSin(M_PI * angle / 180);

    //画字体
    //painter.drawText(QRectF(20, 280, 100, 100), "这是一行文字");

    //画一条启用反锯齿的线
    painter.drawLine(centerX, centerY, endpointX, endpointY);

    //画一个圆
    painter.setPen(pen);
    //painter.setBrush(brush); // 圆的填充物
    //painter.drawEllipse(width()/2 - 75, height()/2 - 75, 150, 150); // x, y, width, height

    painter.drawEllipse(startX, startY, recWidth, recHeight);
}

void CraneOverlook::setAttribute(float rotate, float bigArmLen, float shortArmLen){
    this->rotate = rotate;
}


CraneOverlook::~CraneOverlook()
{
    delete ui;
}
