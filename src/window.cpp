#include "window.h"
Window::Window(QWidget *parent)
    :QLabel(parent)
{
    setLabelText(QStringLiteral("I am a Window"));
}

QString Window::labelText() const
{
    return text();
}

void Window::setLabelText(const QString &txt)
{
    setText(txt);
}
