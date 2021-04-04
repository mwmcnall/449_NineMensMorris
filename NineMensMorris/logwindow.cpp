#include "logwindow.h"

LogWindow::LogWindow()
{
    QPlainTextEdit::setReadOnly(true);
    this->setMaximumSize(800, 75);
}

void LogWindow::appendMessage(const QString& text) {
    // Adds message
    this->appendPlainText(text);
}

void LogWindow::resizeEvent(QResizeEvent *e) {
    // Scrolls to bottom
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
}
