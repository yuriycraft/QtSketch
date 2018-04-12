#ifndef SKETCHFILE_H
#define SKETCHFILE_H

#include <QObject>

class QGraphicsScene;

class QuaZip;

class Document;
class Page;
class Layer;

class SketchFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filename READ filename NOTIFY filenameChanged)
    Q_PROPERTY(Document* document READ document NOTIFY documentChanged)

public:
    explicit SketchFile(QObject *parent = nullptr);

    const QString &filename() const;
    Document *document() const;

    void open(const QString &filename);
    Page *loadPage(const QString &filename);
    QGraphicsScene *createScene(const QString &filename, QObject *parent = Q_NULLPTR);
    QGraphicsScene *createScene(Page *page, QObject *parent = Q_NULLPTR);

Q_SIGNALS:
    void filenameChanged(const QString &filename);
    void documentChanged(Document *document);

private:
    template<typename T>
    T* createContainerZip(const QString &filename, QObject *parent = Q_NULLPTR);

    static void getBoundsRecursive(Layer *layer, double &minX, double &minY, double &maxX, double &maxY, double xOffset, double yOffset);
    void renderItemsRecursive(QGraphicsScene *scene, Layer *layer,double xOffset, double yOffset);

    QString m_filename;
    Document *m_document;

    QuaZip *m_zip;
};

#endif // SKETCHFILE_H
