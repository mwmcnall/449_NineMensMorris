#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QPlainTextEdit>
#include <QScrollBar>

class LogWindow : public QPlainTextEdit
{
    Q_OBJECT
public:
    LogWindow();
    void appendMessage(const QString& text);

    // QPlainTextEdit interface
protected:
    void resizeEvent(QResizeEvent *e);
};

#endif // LOGWINDOW_H
