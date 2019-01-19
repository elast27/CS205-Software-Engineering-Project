#include "fileio.h"

FileIO::FileIO(QObject *parent) : QObject(parent)
{

}


FileIO::~FileIO()
{

}

void FileIO::initialize(QString m_writeFile, QString m_readFile)
{
        this->m_writeFile = m_writeFile;
        this->m_readFile = m_readFile;
}

void FileIO::setReadFile(QString fileName)
{
    if(m_readFile != fileName)
    {
        m_readFile = fileName;
        emit readFileChanged(fileName);
    }
}

void FileIO::setWriteFile(QString fileName)
{
    if(m_writeFile != fileName)
    {
        m_writeFile = fileName;
        emit writeFileChanged(fileName);
    }
}

QString FileIO::writeFile() const
{
    return m_writeFile;
}

QString FileIO::readFile() const
{
    return m_readFile;
}

void FileIO::write(QString text)
{
    QFile mFile(m_writeFile);

    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "ERROR: could not open " << m_writeFile << " for writing. Failed to initialize?\n";
        return;
    }

    QTextStream out(&mFile);
    out << text << "\n";

    mFile.flush();
    mFile.close();
}

void FileIO::read()
{
    QFile mFile(m_readFile);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "ERROR: could not open " << m_readFile << " for writing. Failed to initialize?\n";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;
    mFile.close();

}
