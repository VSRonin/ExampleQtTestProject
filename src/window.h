#include <QLabel>
class Window : public QLabel
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    QString labelText() const;
public slots:
    void setLabelText(const QString& txt);
};
