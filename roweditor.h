#ifndef ROWEDITOR_H
#define ROWEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include "elementeditor.h"

class RowEditor : public QWidget
{
    Q_OBJECT

public:
    RowEditor();

private:
    QGridLayout *m_layout;
    QRect m_highlightedRect;
};

#endif // ROWEDITOR_H
