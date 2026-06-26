#ifndef WK_DICOM_1_H
#define WK_DICOM_1_H

#include <QObject>

class WK_Dicom_1 : public QObject
{
    Q_OBJECT
public:
    explicit WK_Dicom_1(QObject *parent = nullptr);

signals:
};

#endif // WK_DICOM_1_H
