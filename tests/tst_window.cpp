#include <QTest>
#include <window.h>
class tst_Window : public QObject
{
    Q_OBJECT
public slots:
    void labelText();
};



void tst_Window::labelText()
{
    Window win;
    QCOMPARE(win.labelText(), QStringLiteral("I am a Window"));
    win.setLabelText(QStringLiteral("I am a Window too"));
    QCOMPARE(win.labelText(), QStringLiteral("I am a Window too"));
}

QTEST_MAIN(tst_Window)
#include "tst_window.moc"
