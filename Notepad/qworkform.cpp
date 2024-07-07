#include "qworkform.h"
#include <QFileDialog>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QMessageBox>

QWorkForm::QWorkForm(QWidget* parent) : QTextEdit(0){}


void QWorkForm::slotLoad()
{
    QString str = QFileDialog::getOpenFileName(0, "Открыть", "", tr("Text files(*.txt);;Binary files(*.bin);;All files(*)"));
    if (str.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Имя файла не указано");
        return;
    }

    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        if (str.contains(".txt"))
        {
            QTextStream stream(&file);
            setPlainText(stream.readAll());
            f_pos = file.pos();
            f_size = file.size();
            file.close();
        }

        if (str.contains(".bin"))
        {
            // char m_buffer[512];
            // QDataStream stream(&file);
            // while (!file.atEnd())
            // {
            //     memset(m_buffer, '\0', sizeof(m_buffer) + 1);
            //     file.read(sizeof(m_buffer));
            //     setPlainText(QString::fromUtf8(m_buffer));
            // }

            // stream.setVersion(QDataStream::Qt_6_2);
            // QString text;
            // stream >> text;
            // setPlainText(text);
            // if (stream.status() != QDataStream::Ok)
            //     qDebug() << "Ошибка чтения файла";

            QDataStream stream(&file);
            QByteArray bytes = file.readAll();
            // stream << bytes;
            QString text = QString::fromLocal8Bit(bytes);
            // QString text = QString::fromUtf8(bytes);
            setPlainText(text);
            f_pos = file.pos();
            f_size = file.size();
            file.close();
        }

        filename = str;
        emit ChangeTitle(filename);
        emit ChangeSize(f_pos, f_size);
    }
}


void QWorkForm::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(nullptr, filename);
    if (!str.isEmpty())
    {
        filename = str;
        slotSave();
    }
}


void QWorkForm::slotSave()
{
    if (filename.isEmpty())
    {
        slotSaveAs();
        return;
    }

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        if (filename.contains(".txt"))
        {
            QTextStream(&file) << toPlainText();
            file.close();
            emit ChangeTitle(filename);
        }

        if (filename.contains(".bin"))
        {
            // QDataStream out(&file);
            // out.setVersion(QDataStream::Qt_6_2);
            // QString text = toPlainText();
            // out << text;
            // if (out.status() != QDataStream::Ok)
            //     qDebug() << "Ошибка записи";

            // QDataStream out(&file);
            // const char *c_text = ba.data();
            // out.writeBytes(c_text, sizeof(ba));
            // out << ba;

            // QDataStream out(&file);
            // QString text = toPlainText();
            // out << text;
            // qDebug() << &out;
            // file.close();



            // The last version
            QString text = toPlainText();
            QByteArray ba = text.toLocal8Bit();
            QDataStream in(&ba, QIODevice::WriteOnly);
            qDebug() << &in;
            QDataStream out(&file);
            qDebug() << file.write(ba);
            file.close();

            // file.write(ba);
            // file.close();

            // QDataStream out(&file);
            // QString text = toPlainText();
            // QByteArray ba = text.toLocal8Bit();
            // out << ba;
            // file.close();
            emit ChangeTitle(filename);
        }
    }
}



