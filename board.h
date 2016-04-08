#ifndef BOARD_H
#define BOARD_H

#include <QObject>

class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
public:
    explicit Board(QObject *parent = 0);
    void setTitle(const QString &a) {
        if (a != m_title) {
            m_title = a;
            emit titleChanged();
        }
    }
    QString title() const {
        return m_title;
    }
signals:
    void titleChanged();
public slots:

private:
    QString m_title;
};

#endif // BOARD_H
