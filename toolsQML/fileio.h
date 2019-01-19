#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QFile>

/**
 * @brief The FileIO class provides functionality for reading and writing files
 */

class FileIO : public QObject
{
    Q_OBJECT

    //******************************PROPERTIES******************************//
    Q_PROPERTY(QString writeFile READ writeFile WRITE setWriteFile NOTIFY writeFileChanged)
    Q_PROPERTY(QString readFile READ readFile WRITE setReadFile NOTIFY readFileChanged)
public:
    explicit FileIO(QObject *parent = 0);
    ~FileIO();

     //******************************PUBLIC METHODS***************************//

    /**
      *@brief initialize initializes the fields for this FileIO object
      * @param m_writeFile the writing file name
      * @param m_readFile the reading file name
      */
   Q_INVOKABLE void initialize(QString m_writeFile, QString m_readFile);

    /**
     * @brief writeFile returns this FileIO's writingFile
     * @return the fileNmae of the Writing File
     */
    QString writeFile() const;

    /**
     * @brief readFile returns this FileIO's readingFile
     * @return the fileNmae of the Reading File
     */
    QString readFile() const;

    /**
     * @brief write writes text to the m_writeFile
     * @param text the text to write to the file
     */
   Q_INVOKABLE void write(QString text);

    /**
     * @brief write reads text from the m_readFile
     */
   Q_INVOKABLE void read();


signals:
    void writeFileChanged(QString fileName);
    void readFileChanged(QString fileName);

public slots:
    void setWriteFile(QString fileName);
    void setReadFile(QString fileName);

private:
    QString m_writeFile; //file name for writing
    QString m_readFile;  //file name for reading
};

#endif // FILEIO_H
